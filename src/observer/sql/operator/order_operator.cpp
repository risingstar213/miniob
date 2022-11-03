#include "sql/parser/parse_defs.h"
#include "common/log/log.h"
#include "sql/operator/order_operator.h"
#include "util/util.h"
#include <algorithm>

RC OrderOperator::open() {
    if (children_.size() != 1) {
        LOG_WARN("order operator must has one child");
        return RC::INTERNAL;
    }

    Operator *child = children_[0];
    RC rc = child->open();
    if (rc != RC::SUCCESS) {
        LOG_WARN("failed to open child operator: %s", strrc(rc));
        return rc;
    }

    std::vector<Tuple *> tuples;
    while (RC::SUCCESS == (rc = child->next())) {
        tuples = child->current_tuples();
        LOG_INFO("=== 接受数据 ===");
        int m = tuples.size();
        if (m == 0) {
            rc = RC::INTERNAL;
            LOG_WARN("failed to get current record. rc=%s", strrc(rc));
            break;
        }
        std::vector<TupleCell> row;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < tuples[j]->cell_num(); i++) {
                TupleCell tupleCell1;
                tuples[j]->cell_at(i, tupleCell1);
                TupleCell tupleCell2;
                tupleCell2.set_type(tupleCell1.attr_type());
                tupleCell2.set_length(tupleCell1.length());
                char* temp = new char[sizeof(char )*tupleCell2.length() + 1];
                memcpy(temp, tupleCell1.data(), tupleCell2.length());
                tupleCell2.set_data((const char*)temp);
                // LOG_INFO("=====data:%s", tupleCell2.data());
                row.push_back(tupleCell2);
            }
        }
        orderTuple.getOrderTable().push_back(row);
        //LOG_INFO("row的data:%s", row[2].data());
        //LOG_INFO("table的data:%s", orderTuple.getOrderTable()[0][2].data());
        // LOG_INFO("取出的data:%s", orderTuple.getOrderTable()[0][0].data());
        // LOG_INFO("取出的data:%s", orderTuple.getOrderTable()[0][1].data());
        // LOG_INFO("取出的data:%s", orderTuple.getOrderTable()[0][2].data());
    }
    if (rc != RC::RECORD_EOF) {
        LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
        child->close();
        return rc;
    } else {
        if (cols_.size() == 0) { // if don't order 
            return RC::SUCCESS;
        }
        // sort the table
        int n = cols_.size(), index = -1;
        OrderCol *cur_col;
        std::vector<int> compare_indexes;
        std::vector<int> flags; // 1:升序，0：降序
        int p = orderTuple.getOrderTable().size();
        if (p == 0) {
            return RC::SUCCESS;
        }
        for (int i = 0; i < n; i++) {
            TupleCell cell;
            index = 0;
            cur_col = cols_[i];
            flags.push_back(cur_col->asc);
            for (int j = 0; j < tables_.size(); j++) {
                if ( strcmp( tables_[j]->name(), fields_[i].table()->name()) != 0 ) { // not the table craved
                    LOG_INFO(tables_[j]->name());
                    LOG_INFO(fields_[i].table()->name());
                    index += tables_[j]->table_meta().field_num()-1;
                } else {
                    int offset = fields_[i].table()->table_meta().field_index(fields_[i].field_name());
                    if (offset == -1) {
                        LOG_WARN("===index and cell ordered by are not found");
                        return RC::INVALID_ARGUMENT;
                    }
                    index += offset;
                    break;
                }
            }
            index--;
            if (index == -1) {
                LOG_WARN("===index and cell ordered by are not found");
                return RC::INVALID_ARGUMENT;
            }
            compare_indexes.push_back(index);
        }

        std::sort(orderTuple.getOrderTable().begin(), orderTuple.getOrderTable().end(), [&](std::vector<TupleCell> &a, std::vector<TupleCell> &b) {
            int m = flags.size();
            for (int i = 0; i < m; i++) {
            TupleCell a1 = a[compare_indexes[i]];
            TupleCell b1 = b[compare_indexes[i]];
            if (a1.is_null() && b1.is_null()) {
                continue;
            }
            if ( (!a1.is_null() && b1.is_null()) || a1.compare(b1)>0 ) {
                if (flags[i] == 1) {
                    return false;
                } else {
                    return true;
                }
            } else if ( (a1.is_null() && !b1.is_null()) || a1.compare(b1)<0 ) {
                if (flags[i] == 1) {
                    return true;
                } else {
                    return false;
                }
            }
            }
            return true; // if all the same, don't swap
        });
        rc = RC::SUCCESS;
    }
    return rc;
} 

// bool OrderOperator::cmp(std::vector<TupleCell> &a, std::vector<TupleCell> &b) {
//     int m = flags_.size();
//     for (int i = 0; i < m; i++) {
//         TupleCell a1 = a[compare_indexes_[i]];
//         TupleCell b1 = b[compare_indexes_[i]];
//         if ( (!is_null(a1.data()) && is_null(b1.data())) || a1.compare(b1)>0 ) {
//             if (flags_[i] == 1) {
//                 return false;
//             } else {
//                 return true;
//             }
//         } else if ( (is_null(a1.data()) && !is_null(b1.data())) || a1.compare(b1)<0 ) {
//             if (flags_[i] == 1) {
//                 return true;
//             } else {
//                 return false;
//             }
//         }
//     }
//     return true; // if all the same, don't swap
// }

RC OrderOperator::next(std::vector<Tuple *> *context) {
    return RC::SUCCESS;
}

std::vector<Tuple *> OrderOperator::current_tuples() {
    std::vector<Tuple *> temp;
    temp.push_back(&orderTuple);
    return temp;
}

RC OrderOperator::close()
{
  children_[0]->close();
  orderTuple.delete_tuple();
  return RC::SUCCESS;
}
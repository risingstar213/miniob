#include "sql/parser/parse_defs.h"
#include "common/log/log.h"
#include "sql/operator/order_operator.h"

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

    while (RC::SUCCESS == (rc = child->next())) {
        Tuple *tuple = child->current_tuples()[0];
        if (nullptr == tuple) {
            rc = RC::INTERNAL;
            LOG_WARN("failed to get current record. rc=%s", strrc(rc));
            break;
        }
        tuples_.push_back(*tuple);
    }
    if (rc != RC::RECORD_EOF) {
        LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
        child->close();
    } else {
        rc = RC::SUCCESS;
    }
    return rc;
} 
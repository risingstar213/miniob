#ifndef _OPERATOR_HELPER_H
#define _OPERATOR_HELPER_H
class Operator;
class SelectStmt;

Operator*  get_select_operator(SelectStmt *select_stmt);


#endif
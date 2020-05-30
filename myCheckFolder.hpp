#pragma once
#include "mySyntaxTree.hpp"
#include "mySymbolTable.hpp"

class CheckFolder {
public:
    static bool checkAssignable(Types type1, Types type2);

    static bool checkLogicalOp(Node *node, Types type1, Types type2, Oper op);
    static bool checkRelationOp(Node *node, Types type1, Types type2, Oper op);
    static bool checkArithemticOp(Node *node, Types type1, Types type2, Oper op);

    static bool checkNegOp(Node *node, Types type);
    static bool checkNotOp(Node *node, Types type);

};

void typeCheckAndConstFold(Node *root, SymbolTable *global);


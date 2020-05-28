#include "myCheckFolder.hpp"
#include "mySyntaxTree.hpp"
#include <iostream>
#include <string>

using namespace std;

bool CheckFolder::checkAssignable(Types type1, Types type2) {
    if (type1 == ENUME || type2 == ENUME)
        return false;
    if (type1 == ARRA || type2 == ARRA)
        return false;
    if (type1 == type2)
        return true;
    if (type1 ==  STR || type2 == STR)
        return false;
    if (type1 == CHARA || type2 == CHARA)
        return false;
    return true;
}

bool CheckFolder::checkLogicalOp(Node *node, Types type1, Types type2, Oper op) {
    int res;
    int num1, num2;

    if (type1 != INTEGE && type1 != BOOLEA)
        return false;
    
    if (type2 != INTEGE && type2 != BOOLEA)
        return false;

    node->resultType = newType(BOOLEA, nullptr, nullptr);

    num1 = node->children[0]->attr.intNum;
    num2 = node->children[1]->attr.intNum;

    switch(op) {
        case AND_OP:
            if (node->children[0]->resultConstant && !node->children[0]->attr.intNum) {
                node->resultConstant = true;
                node->attr.intNum = 0;
            }
            else if (node->children[1]->resultConstant && !node->children[1]->attr.intNum) {
                node->resultConstant = true;
                node->attr.intNum = 0;
            }
            else if (node->children[0]->resultConstant && node->children[1]->resultConstant) {
                node->resultConstant = true;
                node->attr.intNum = 1;
            }
            break;
        case OR_OP:
            if (node->children[0]->resultConstant && node->children[0]->attr.intNum) {
                node->resultConstant = true;
                node->attr.intNum = 1;
            }
            else if (node->children[1]->resultConstant && node->children[1]->attr.intNum) {
                node->resultConstant = true;
                node->attr.intNum = 1;
            }
            else if (node->children[0]->resultConstant && node->children[1]->resultConstant) {
                node->resultConstant = true;
                node->attr.intNum = 0;
            }
            break;
        default:
            return false;
    }

    return true;
}

bool CheckFolder::checkRelationOp(Node *node, Types type1, Types type2, Oper op) {
    
    bool ires, cres, fres, sres;

    int    inum1, inum2;
    char   cnum1, cnum2;
    float  fnum1, fnum2;
    string snum1, snum2;

    if (type1 == ENUME || type2 == ENUME)
        return false;
    if (type1 == ARRA || type2 == ARRA)
        return false;
    if (type1 == RECOR || type2 == RECOR)
        return false;
    if (type1 ==  STR && type2 != STR || type1 != STR && type2 == STR)
        return false;
    if (type1 == CHARA && type2 != CHARA || type1 != CHARA && type2 == CHARA)
        return false;

    node->resultType = newType(BOOLEA, nullptr, nullptr);
    node->resultConstant = node->children[0]->resultConstant && node->children[1]->resultConstant;

    if (!node->resultConstant)
        return true;

    cnum1 = node->children[0]->attr.intNum;
    cnum2 = node->children[1]->attr.intNum;
    
    snum1 = node->children[0]->attr.strVal;
    snum2 = node->children[1]->attr.strVal;

    inum1 = node->children[0]->attr.intNum;
    inum2 = node->children[1]->attr.intNum;

    if (type1 == INTEGE || type1 == BOOLEA)
        fnum1 = node->children[0]->attr.intNum;
    else
        fnum1 = node->children[0]->attr.realNum;

    if (type2 == INTEGE || type2 == BOOLEA)
        fnum2 = node->children[1]->attr.intNum;
    else
        fnum2 = node->children[1]->attr.realNum;
        
    switch(op) {
        case GE_OP:
            cres = cnum1 >= cnum2;
            sres = snum1 >= snum2;
            fres = fnum1 >= fnum2;
            ires = inum1 >= inum2;
            break;
        case GT_OP:
            cres = cnum1 > cnum2;
            sres = snum1 > snum2;
            fres = fnum1 > fnum2;
            ires = inum1 > inum2;
            break;
        case LE_OP:
            cres = cnum1 <= cnum2;
            sres = snum1 <= snum2;
            fres = fnum1 <= fnum2;
            ires = inum1 <= inum2;
            break;
        case LT_OP:
            cres = cnum1 < cnum2;
            sres = snum1 < snum2;
            fres = fnum1 < fnum2;
            ires = inum1 < inum2;
            break;
        case EQ_OP:
            cres = cnum1 == cnum2;
            sres = snum1 == snum2;
            fres = fnum1 == fnum2;
            ires = inum1 == inum2;
            break;
        case UEQ_OP:
            cres = cnum1 != cnum2;
            sres = snum1 != snum2;
            fres = fnum1 != fnum2;
            ires = inum1 != inum2;
            break;
        default:
            return false;
    }

    if (type1 == CHARA) 
        node->attr.intNum = cres;
    else if (type1 == STR) 
        node->attr.intNum = sres;
    else {
        if (type1 != REA && type2 != REA)
            node->attr.intNum = ires;
        else
            node->attr.intNum = fres;
    }

    return true;
}

bool CheckFolder::checkArithemticOp(Node *node, Types type1, Types type2, Oper op) {
    float res;
    float num1, num2;

    
    if (type1 != INTEGE && type1 != BOOLEA && type1 != REA)
        return false;
    
    if (type2 != INTEGE && type2 != BOOLEA && type2 != REA)
        return false;

    if (op == MOD_OP && (type1 == REA || type2 == REA))
        return false;

    if (type1 == REA || type2 == REA)
        node->resultType = newType(REA, nullptr, nullptr);
    else
        node->resultType = newType(INTEGE, nullptr, nullptr);

    node->resultConstant = node->children[0]->resultConstant && node->children[1]->resultConstant;

    if (!node->resultConstant)
        return true;

    if (type1 == INTEGE || type1 == BOOLEA)
        num1 = node->children[0]->attr.intNum;
    else
        num1 = node->children[0]->attr.realNum;

    if (type2 == INTEGE || type2 == BOOLEA)
        num2 = node->children[1]->attr.intNum;
    else
        num2 = node->children[1]->attr.realNum;

    if (op == DIV_OP) {
        if (node->resultType->pattern.type == INTEGE) {
            if ((int)num2 == 0)
                cout << "Error: line " << node->lineNo << " can not divided by zero" << endl;
            else
                res = (int)num1 / (int)num2;
        }
        else {
            if (num2 == 0.0)
                cout << "Error: line " << node->lineNo << " can not divided by zero" << endl;
            else
                res = num1 / num2;
        }
    }
    else {
        switch(op) {
            case PLUS_OP:
                res = num1 + num2;
                break;
            case MINUS_OP:
                res = num1 - num2;
                break;
            case MUL_OP:
                res = num1 * num2;
                break;
            case MOD_OP:
                res = (int)num1 % (int)num2;
                break;
            default:
                return false;
        }
    }

    if (node->resultType->pattern.type == INTEGE)
        node->attr.intNum = res;
    else 
        node->attr.realNum = res;
       
    return true;
}

bool CheckFolder::checkNegOp(Node *node, Types type) {
    if (type != INTEGE && type != REA)
        return false;

    node->resultType = newType(type, nullptr, nullptr);

    node->resultConstant = node->children[0]->resultConstant;

    if (!node->resultConstant)
        return true;

    if (type == INTEGE)
        node->attr.intNum = -node->children[0]->attr.intNum;
    else
        node->attr.realNum = -node->children[0]->attr.realNum;

    return true;
}

bool CheckFolder::checkNotOp(Node *node, Types type) {

    if (type != INTEGE && type != BOOLEA)
        return false;

    node->resultType = newType(BOOLEA, nullptr, nullptr);
    node->resultConstant = node->children[0]->resultConstant;

    if (!node->resultConstant)
        return true;

    node->attr.intNum = !node->children[0]->attr.intNum;
    return true;
}


void typeCheckAndConstFold(Node *node, SymbolTable *table) {

    if (node == nullptr)
        return;

    Node *type;
    Node *type1, *type2;

    Node *symbol;
    Node *paras, *fpara, *apara;

    Types types;
    Types types1, types2;

    SymbolTable *childTable;

    static bool first = true;

    node->resultConstant = false;
    switch(node->nodes) {
        case ROUTINE:
            typeCheckAndConstFold(node->children[0], table);
            typeCheckAndConstFold(node->children[1], table);
            typeCheckAndConstFold(node->sibling, table);
            break;
        case CONSTANT:
            typeCheckAndConstFold(node->children[0], table);
            node->attr = node->children[0]->attr;
            node->resultType = node->children[0]->resultType;
            node->resultConstant = true; 
            typeCheckAndConstFold(node->sibling, table);
            break;
        case VARI:
            typeCheckAndConstFold(node->dtype, table);
            for (Node *temp = node->children[0]; temp; temp = temp->sibling)
                temp->resultType = node->dtype;
            typeCheckAndConstFold(node->sibling, table);
            break;
        case TYPES:
            switch(node->pattern.type) {
                case DECL:
                    typeCheckAndConstFold(node->dtype, table);
                    break;
                case ARRA:
                    typeCheckAndConstFold(node->children[0], table);
                    type = table->getActualType(node->children[0]);
                    if (type->pattern.type != ENUME || type->children[1] == nullptr)
                        cout << "Error: line " << node->lineNo << " not array range type" << endl;
                    else {
                        typeCheckAndConstFold(type->children[0], table);
                        typeCheckAndConstFold(type->children[1], table);
                        
                        types1 = type->children[0]->resultType->pattern.type;
                        types2 = type->children[1]->resultType->pattern.type;
                        if (types1 != INTEGE)
                            cout << "Error: line " << node->lineNo << " left array range not integer type" << endl;
                        else if (types2 != INTEGE)
                            cout << "Error: line " << node->lineNo << " right array range not integer type" << endl;
                        else if (type->children[0]->attr.intNum > type->children[1]->attr.intNum)
                            cout << "Error: line " << node->lineNo << " array range can not be empty" << endl;
                    }
                    typeCheckAndConstFold(node->children[1], table);
                    break;
                case RECOR:
                    typeCheckAndConstFold(node->children[0], table);
                    break;
                case SELFDEFINE:
                    symbol = table->findSymbol(node->name);
                    if (symbol->nodes != TYPES)
                        cout << "Error: line " << node->lineNo << " " << node->name << " not a type" << endl;
                    break;
                default:
                    break;
            }
            typeCheckAndConstFold(node->sibling, table);
            break;
        case SUB:
            switch(node->pattern.routine) {
                case FUNC:
                case PROC:
                    if (!first) {
                        childTable = table->getChildren(node->name);
                        typeCheckAndConstFold(node->children[0], childTable);
                        typeCheckAndConstFold(node->children[1], childTable);
                        typeCheckAndConstFold(node->dtype, table);
                    }
                    else {
                        first = false;
                        typeCheckAndConstFold(node->children[0], table);
                        typeCheckAndConstFold(node->children[1], table);
                        typeCheckAndConstFold(node->dtype, table);
                    }
                    break;
                case PARAM_VAR:
                case PARAM_VAL:
                    typeCheckAndConstFold(node->dtype, table);
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling)
                        temp->resultType = node->dtype;
                    break;
                default:
                    break;
            }
            typeCheckAndConstFold(node->sibling, table);
            break;
        case STMT:
            switch(node->pattern.stmt) {
                case ASSIGN_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    typeCheckAndConstFold(node->children[1], table);
                    type1 = table->getActualType(node->children[0]->resultType);
                    type2 = table->getActualType(node->children[1]->resultType);

                    if (!CheckFolder::checkAssignable(type1->pattern.type, type2->pattern.type))
                        cout << "Error: line " << node->lineNo << " incompatible assign statement type" << endl;
                    break;
                case IF_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    type = table->getActualType(node->children[0]->resultType);

                    types = type->pattern.type;
                    if (types != BOOLEA && types != INTEGE) 
                        cout << "Error: line " << node->lineNo << " incompatible condition type" << endl;

                    typeCheckAndConstFold(node->children[1], table);
                    typeCheckAndConstFold(node->children[2], table);
                    break;
                case REPEAT_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    typeCheckAndConstFold(node->children[1], table);
                    type = table->getActualType(node->children[1]->resultType);

                    types = type->pattern.type;
                    if (types != BOOLEA && types != INTEGE) 
                        cout << "Error: line " << node->lineNo << " incompatible condition type" << endl;
                    break;
                case WHILE_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    type = table->getActualType(node->children[0]->resultType);

                    types = type->pattern.type;
                    if (types != BOOLEA && types != INTEGE) 
                        cout << "Error: line " << node->lineNo << " incompatible condition type" << endl;

                    typeCheckAndConstFold(node->children[1], table);
                    break;
                case FOR_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    typeCheckAndConstFold(node->children[1], table);
                    type1 = table->getActualType(node->children[0]->resultType);
                    type2 = table->getActualType(node->children[1]->resultType);

                    types1 = type1->pattern.type;
                    types2 = type2->pattern.type;

                    if (!(types1 == INTEGE && types2 == INTEGE) && !(types1 == CHARA && types2 == CHARA))
                        cout << "Error: line " << node->lineNo << " incompatible for range type" << endl;

                    typeCheckAndConstFold(node->children[2], table);
                    break;
                case CASE_STMT:
                    typeCheckAndConstFold(node->children[0], table);
                    type = table->getActualType(node->children[0]->resultType);

                    types = type->pattern.type;
                    if (types != INTEGE && types != CHARA && types != BOOLEA && types != STR)
                        cout << "Error: line " << node->lineNo << " incompatible case type" << endl;

                    for (Node *temp = node->children[1]; temp; temp = temp->sibling) {
                        typeCheckAndConstFold(temp->children[0], table);
                        if (!temp->children[0]->resultConstant) {
                            cout << "Error: line " << temp->lineNo << " incompatible case label type" << endl;
                            continue;
                        }

                        types = temp->children[0]->resultType->pattern.type;

                        if (types != INTEGE && types != CHARA && types != BOOLEA && types != STR)
                            cout << "Error: line " << temp->lineNo << " incompatible case label type" << endl;
                        typeCheckAndConstFold(temp->children[1], table);
                    }
                    break;
                case PROC_STMT:
                    if (node->system)
                        break;

                    symbol = table->findSymbol(node->name);
                    if (symbol->nodes != SUB) {
                        cout << "Error: line " << node->lineNo << " " << node->name << " not function type " << endl;
                        return;
                    }

                    fpara = nullptr;
                    apara = node->children[0];

                    if (symbol->children[1] == nullptr)
                        paras = nullptr;
                    else 
                        paras = symbol->children[0];

                    while (paras && apara) {
                        if (fpara == nullptr)
                            fpara = paras->children[0];

                        typeCheckAndConstFold(apara, table);
                        type1 = table->getActualType(fpara->resultType);
                        type2 = table->getActualType(apara->resultType);

                        if (!CheckFolder::checkAssignable(type1->pattern.type, type2->pattern.type))
                            cout << "Error: line " << node->lineNo << " incompatible to parameter " << fpara->name << "\'s type" << endl;
                        apara = apara->sibling;
                        fpara = fpara->sibling;

                        if (fpara == nullptr)
                            paras = paras->sibling;
                    }
                    if (paras || apara)
                        cout << "Error: line " << node->lineNo << " incompatible parameter number" << endl;
                    break;
                default:
                    break;
            }
            typeCheckAndConstFold(node->sibling, table);
            break;
        case EXPR:
            switch(node->pattern.expr) {
                case ID_EXPR:
                    switch(node->subexpr.iden) {
                        case BASIC_ID:
                            symbol = table->findSymbol(node->name);

                            if (table->getTableName() == node->name) {
                                node->resultType = symbol->dtype;
                                break;
                            }

                            if (symbol->nodes != EXPR && symbol->nodes != CONSTANT)
                                cout << "Error: line " << node->lineNo << " " << node->name << " not a variable or constant" << endl;

                            node->resultType = symbol->resultType;
                            node->resultConstant = symbol->resultConstant;
                            node->attr = symbol->attr;
                            break;
                        case ARRAY_ID:
                            symbol = table->findSymbol(node->name);
                            type1 = table->getActualType(symbol->resultType);

                            if (symbol->nodes != EXPR || type1->pattern.type != ARRA)
                                cout << "Error: line " << node->lineNo << " " << node->name << " not array type" << endl;

                            typeCheckAndConstFold(node->children[0], table);
                            type2 = table->getActualType(node->children[0]->resultType);

                            if (type2->pattern.type != INTEGE)
                                cout << "Error: line " << node->lineNo << " not integer array index type" << endl; 

                            node->resultType = type1->children[1];
                            break;
                        case RECORD_ID:
                            symbol = table->findSymbol(node->name);
                            type = table->getActualType(symbol->resultType);

                            if (symbol->nodes != EXPR || type->pattern.type != RECOR) {
                                cout << "Error: line " << node->lineNo << " " << node->name << " not record type" << endl;
                                return;
                            }

                            childTable = table->getRecordTable(symbol->resultType);
                            symbol = childTable->findSymbol(node->children[0]->name);
                            if (symbol == nullptr) 
                                cout << "Error: line " << node->lineNo << " undefine " << node->children[0]->name << endl;
                            else 
                                node->resultType = symbol->resultType;
                            break;
                        default:
                            break;
                    }
                    break;
                case CON_EXPR:
                    node->resultType = node->dtype;
                    node->resultConstant = true;
                    break;
                case OP_EXPR:
                    typeCheckAndConstFold(node->children[0], table);
                    typeCheckAndConstFold(node->children[1], table);

                    if (node->children[0] != nullptr) {
                        type1 = table->getActualType(node->children[0]->resultType);
                        types1 = type1->pattern.type;
                    }
                    if (node->children[1] != nullptr) {
                        type2 = table->getActualType(node->children[1]->resultType);
                        types2 = type2->pattern.type;
                    }

                    switch(node->subexpr.oper) {
                        case PLUS_OP:
                            if (!CheckFolder::checkArithemticOp(node, types1, types2, PLUS_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater +" << endl;
                            break;
                        case MINUS_OP:
                            if (!CheckFolder::checkArithemticOp(node, types1, types2, MINUS_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater -" << endl;
                            break;
                        case MUL_OP:
                            if (!CheckFolder::checkArithemticOp(node, types1, types2, MUL_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater *" << endl;
                            break;
                        case DIV_OP:
                            if (!CheckFolder::checkArithemticOp(node, types1, types2, DIV_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater /" << endl;
                            break;
                        case MOD_OP:
                            if (!CheckFolder::checkArithemticOp(node, types1, types2, MOD_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater mod" << endl;
                            break;
                        case AND_OP:
                            if (!CheckFolder::checkLogicalOp(node, types1, types2, AND_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater and" << endl;
                            break;
                        case OR_OP:
                            if (!CheckFolder::checkLogicalOp(node, types1, types2, OR_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater or" << endl;
                            break;
                        case GE_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, GE_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater >=" << endl;
                            break;
                        case GT_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, GT_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater >" << endl;
                            break;
                        case LE_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, LE_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater <=" << endl;
                            break;
                        case LT_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, LT_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater <" << endl;
                            break;
                        case EQ_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, EQ_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater =" << endl;
                            break;
                        case UEQ_OP:
                            if (!CheckFolder::checkRelationOp(node, types1, types2, UEQ_OP))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater !=" << endl;
                            break;
                        case NEG_OP:
                            if (!CheckFolder::checkNegOp(node, types1))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater neg" << endl;
                            break;
                        case NOT_OP:
                            if (!CheckFolder::checkNotOp(node, types1))
                                cout << "Error: line " << node->lineNo << " incompatible type for operater not" << endl;
                            break;
                        defualt:
                            break;
                    }
                    break;
                case FN_EXPR:
                    if (node->system)
                        break;

                    symbol = table->findSymbol(node->name);
                    if (symbol->nodes != SUB) {
                        cout << "Error: line " << node->lineNo << " " << node->name << " not function type " << endl;
                        return;
                    }

                    fpara = nullptr;
                    apara = node->children[0];

                    if (symbol->children[1] == nullptr)
                        paras = nullptr;
                    else 
                        paras = symbol->children[0];

                    while (paras && apara) {
                        if (fpara == nullptr) 
                            fpara = paras->children[0];

                        typeCheckAndConstFold(apara, table);
                        type1 = table->getActualType(fpara->resultType);
                        type2 = table->getActualType(apara->resultType);

                        if (!CheckFolder::checkAssignable(type1->pattern.type, type2->pattern.type))
                            cout << "Error: line " << node->lineNo << " incompatible to parameter " << fpara->name << "\'s type" << endl;

                        apara = apara->sibling;
                        fpara = fpara->sibling;

                        if (fpara == nullptr) 
                            paras = paras->sibling;
                    }
                    if (paras || apara)
                        cout << "Error: line " << node->lineNo << " incompatible parameter number" << endl;
                    node->resultType = symbol->dtype;
                    break;
                default:
                    break;
            }
            break;
        default:
            typeCheckAndConstFold(node->sibling, table);
            break;
    }
}

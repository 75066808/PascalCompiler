#include <string>
#include <iostream>
#include "myIRGenerator.hpp"


using namespace std;

int IRGenerator::tempLabelCount = 0;
int IRGenerator::tempNameCount = 0;
int IRGenerator::tempPtrNameCount = 0;

priority_queue<int, vector<int>, greater<int> > IRGenerator::tempNameHeap;
priority_queue<int, vector<int>, greater<int> > IRGenerator::tempPtrNameHeap;

string IRGenerator::IRGenerator::generateTempLabel(void) {
    string label = ".L" + to_string(tempLabelCount);
    ++tempLabelCount;
    return label;
}

string IRGenerator::IRGenerator::generateTempName(void) {
    int count;
    string name;

    if (tempNameHeap.empty()) {
        name = "_t" + to_string(tempNameCount);
        ++tempNameCount;
    }
    else {
        count = tempNameHeap.top();
        name = "_t" +  to_string(count);
        tempNameHeap.pop();
    }
    return name;
}

string IRGenerator::IRGenerator::generateTempPtrName(void) {
    int count;
    string name;

    if (tempPtrNameHeap.empty()) {
        name = "_p" + to_string(tempPtrNameCount);
        ++tempPtrNameCount;
    }
    else {
        count = tempPtrNameHeap.top();
        name = "_p" +  to_string(count);
        tempPtrNameHeap.pop();
    }
    return name;
}

void IRGenerator::IRGenerator::generatePrint(ofstream &out, string s0, string s1, string s2, string s3) {
    if (s0 != "label" && s0 != "entry")
        out << "    ";
    out << s0 << " " << s1 << " " << s2 << " " << s3 << endl;
}
    
void IRGenerator::IRGenerator::generateAssignPrint(ofstream &out, string s0, string s1, string s2, string s3) {
    if (s0 == s1 && s2 == "" && s3 == "")
        return;
    out << "    ";
    out << s0 << " = " << s1 << " " << s2 << " " << s3 <<endl;
}

string IRGenerator::IRGenerator::generateResultName(ofstream &out, Node *node, bool needIndirect) {
    if (!node->resultIndirect)
        return node->resultName;

    if (!needIndirect)
        return "*" + node->resultName;

   string tempName = IRGenerator::generateTempName(); 

   IRGenerator::generateAssignPrint(out, tempName, "*" + node->resultName);
   IRGenerator::recycleTempName(node->resultName);

   return tempName;
}

string IRGenerator::IRGenerator::generateResultValue(Node *node) {
    switch(node->resultType->pattern.type) {
        case INTEGE:
        case BOOLEA:
            return to_string(node->attr.intNum);
        case REA:
            return to_string(node->attr.realNum);
        case CHARA:
            return "\'" + string(1, (char)(node->attr.intNum)) + "\'";
        case STR:
            return "\'" + string(node->attr.strVal) + "\'";
        default:
            return "";
    }
}

void IRGenerator::recycleTempName(string name) {
    if (name[0] != '_')
        return;

    if (name[1] == 't')
        tempNameHeap.push(stoi(name.substr(2)));
    else if (name[1] == 'p')
        tempPtrNameHeap.push(stoi(name.substr(2)));
}

bool IRGenerator::checkConstEqual(Node *const1, Node *const2) {
    Types type1, type2;

    type1 = const1->resultType->pattern.type;
    type2 = const2->resultType->pattern.type;


    if (type1 == REA && type2 != REA || type1 != REA && type2 == REA)
        return false;

    if (type1 == INTEGE && type2 == BOOLEA || type1 == BOOLEA && type2 == INTEGE)
        return const1->attr.intNum == const2->attr.intNum;

    if (type1 != type2)
        return false;

    if (type1 == CHARA)
        return const1->attr.intNum == const2->attr.intNum; 
    else if (type1 == STR)
        return string(const1->attr.strVal) == string(const2->attr.strVal);
    else
        return const1->attr.intNum == const2->attr.intNum;
}

void generateIR(ofstream &out, Node *node, SymbolTable *table, string assignName) {
    if (node == nullptr)
        return;

    Node *symbol, *types;

    SymbolTable *childTable;

    string resultName;
    string resultName1, resultName2;

    string tempPtrName;
    string tempName;

    string tempLabel;
    string tempLabel1, tempLabel2;

    int size, start;
    static bool first = true;

    node->resultIndirect = false;

    switch(node->nodes) {
        case ROUTINE:
            if (node->children[1] == nullptr) {
                IRGenerator::generatePrint(out, "entry", table->getConnectTableName());
                generateIR(out, node->children[0], table);
            }
            else {
                generateIR(out, node->children[0], table);
                IRGenerator::generatePrint(out, "entry", table->getConnectTableName());
                generateIR(out, node->children[1], table);
            }
            generateIR(out, node->sibling, table);
            break;
        case SUB:
            switch(node->pattern.routine) {
                case FUNC:
                    childTable = table->getChildren(node->name);
                    generateIR(out, node->children[0], childTable);
                    generateIR(out, node->children[1], childTable);
                    IRGenerator::generatePrint(out, "return", "__" + childTable->getConnectTableName());
                    break;
                case PROC:
                    if (first) {
                        first = false;
                        generateIR(out, node->children[0], table);
                        generateIR(out, node->children[1], table);
                    }
                    else {
                        childTable = table->getChildren(node->name);
                        generateIR(out, node->children[0], childTable);
                        generateIR(out, node->children[1], childTable);
                    }
                    IRGenerator::generatePrint(out, "return");
                    break;
                default:
                    break;
            }
            generateIR(out, node->sibling, table);
            break;
        case STMT:
            if (node->label)
                IRGenerator::generatePrint(out, "label", to_string(node->label)); 
            switch(node->pattern.stmt) {
                case ASSIGN_STMT:
                    generateIR(out, node->children[0], table);
                    if (node->children[1]->resultConstant) {
                        resultName1 = IRGenerator::generateResultName(out, node->children[0], false);
                        resultName2 = IRGenerator::generateResultValue(node->children[1]);
                        if (node->children[0]->resultIndirect) 
                            IRGenerator::recycleTempName(node->children[0]->resultName);
                    }
                    else {
                        if (!node->children[0]->resultIndirect)
                            generateIR(out, node->children[1], table, node->children[0]->resultName);
                        else {
                            generateIR(out, node->children[1], table);
                            IRGenerator::recycleTempName(node->children[0]->resultName);
                        }
                        if (node->children[0]->resultIndirect && node->children[1]->resultIndirect) {
                            resultName1 = IRGenerator::generateResultName(out, node->children[0], false);
                            resultName2 = IRGenerator::generateResultName(out, node->children[1], true);
                            IRGenerator::recycleTempName(resultName2);
                        }
                        else {
                            resultName1 = IRGenerator::generateResultName(out, node->children[0], false);
                            resultName2 = IRGenerator::generateResultName(out, node->children[1], false);
                            IRGenerator::recycleTempName(node->children[1]->resultName);
                        }
                    }

                    IRGenerator::generateAssignPrint(out, resultName1, resultName2);
                    break;
                case IF_STMT:
                    if (node->children[0]->resultConstant) {
                        if (node->children[0]->attr.intNum)
                            generateIR(out, node->children[1], table);
                        else 
                            generateIR(out, node->children[2], table);
                    }
                    else {
                        tempLabel1 = IRGenerator::generateTempLabel(); 

                        generateIR(out, node->children[0], table);
                        resultName = IRGenerator::generateResultName(out, node->children[0]);

                        IRGenerator::generatePrint(out, "if_f", resultName, "goto", tempLabel1);
                        IRGenerator::recycleTempName(resultName);

                        generateIR(out, node->children[1], table);

                        if (node->children[2] != nullptr) {
                            tempLabel2 = IRGenerator::generateTempLabel();
                            IRGenerator::generatePrint(out, "goto", tempLabel2);
                            IRGenerator::generatePrint(out, "label", tempLabel1);
                            generateIR(out, node->children[2], table);
                            IRGenerator::generatePrint(out, "label", tempLabel2);
                        }
                        else 
                            IRGenerator::generatePrint(out, "label", tempLabel1);
                       
                    }
                    break;
                case REPEAT_STMT:
                    if (node->children[1]->resultConstant) {
                        if (node->children[1]->attr.intNum)
                            generateIR(out, node->children[0], table);
                        else {
                            tempLabel = IRGenerator::generateTempLabel();
                            IRGenerator::generatePrint(out, "label", tempLabel);
                            generateIR(out, node->children[0], table);
                            IRGenerator::generatePrint(out, "goto", tempLabel);
                        }
                    }
                    else {
                        tempLabel = IRGenerator::generateTempLabel();
                        IRGenerator::generatePrint(out, "label", tempLabel);
                        generateIR(out, node->children[0], table);
                        generateIR(out, node->children[1], table);

                        resultName = IRGenerator::generateResultName(out, node->children[1]);
                        IRGenerator::generatePrint(out, "if_f", resultName, "goto", tempLabel);
                        IRGenerator::recycleTempName(resultName);
                    }
                    break;
                case WHILE_STMT:
                    if (node->children[0]->resultConstant) {
                        if (!node->children[0]->attr.intNum)
                            break;
                        tempLabel = IRGenerator::generateTempLabel();

                        IRGenerator::generatePrint(out, "label", tempLabel);
                        generateIR(out, node->children[1], table);
                        IRGenerator::generatePrint(out, "goto", tempLabel);
                    }
                    else {
                        tempLabel1 = IRGenerator::generateTempLabel();
                        tempLabel2 = IRGenerator::generateTempLabel();

                        IRGenerator::generatePrint(out, "label", tempLabel1);
                        generateIR(out, node->children[0], table);
                        resultName = IRGenerator::generateResultName(out, node->children[0]);

                        IRGenerator::generatePrint(out, "if_f", resultName, "goto", tempLabel2);
                        IRGenerator::recycleTempName(resultName);

                        generateIR(out, node->children[1], table);
                        IRGenerator::generatePrint(out, "goto", tempLabel1);
                        IRGenerator::generatePrint(out, "label", tempLabel2);
                    }
                    break;
                case FOR_STMT:
                    tempLabel1 = IRGenerator::generateTempLabel();
                    tempLabel2 = IRGenerator::generateTempLabel();

                    resultName = IRGenerator::generateResultValue(node->children[0]);
                    IRGenerator::generateAssignPrint(out, node->name, resultName);
                    IRGenerator::recycleTempName(resultName);

                    IRGenerator::generatePrint(out, "label", tempLabel1);

                    resultName = IRGenerator::generateResultValue(node->children[1]);

                    IRGenerator::recycleTempName(resultName);
                    tempName = IRGenerator::generateTempName();

                    if (node->attr.intNum == 1)
                        IRGenerator::generateAssignPrint(out, tempName, node->name, "<=", resultName);
                    else
                        IRGenerator::generateAssignPrint(out, tempName, node->name, ">=", resultName);
                        
                    IRGenerator::generatePrint(out, "if_f", tempName, "goto", tempLabel2);
                    IRGenerator::recycleTempName(tempName);

                    generateIR(out, node->children[2], table);

                    if (node->attr.intNum == 1)
                        IRGenerator::generateAssignPrint(out, node->name, node->name, "+", "1");
                    else
                        IRGenerator::generateAssignPrint(out, node->name, node->name, "-", "1");
                    
                    IRGenerator::generatePrint(out, "goto", tempLabel1);
                    IRGenerator::generatePrint(out, "label", tempLabel2);
                    break;
                case CASE_STMT:
                    if (node->children[0]->resultConstant) {
                        for (Node *temp = node->children[1]; temp; temp = temp->sibling) {
                            if (IRGenerator::checkConstEqual(node->children[0], temp->children[0])) {
                                generateIR(out, temp->children[1], table);
                                break;
                            }
                        }
                    }
                    else {
                        generateIR(out, node->children[0], table);
                        resultName1 = IRGenerator::generateResultName(out, node->children[0]);

                        for (Node *temp = node->children[1]; temp; temp = temp->sibling) {
                            tempLabel = IRGenerator::generateTempLabel();
                            generateIR(out, temp->children[0], table);
                            resultName2 = IRGenerator::generateResultName(out, temp->children[0]);

                            IRGenerator::recycleTempName(resultName2);

                            tempName = IRGenerator::generateTempName();
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "!=", resultName2);

                            IRGenerator::generatePrint(out, "if_f", tempName, "goto", tempLabel);
                            IRGenerator::recycleTempName(tempName);

                            temp->resultName = tempLabel;  
                        }

                        IRGenerator::recycleTempName(resultName1);

                        tempLabel = IRGenerator::generateTempLabel();
                        IRGenerator::generatePrint(out, "goto", tempLabel);

                        for (Node *temp = node->children[1]; temp; temp = temp->sibling) {
                            IRGenerator::generatePrint(out, "label", temp->resultName);
                            generateIR(out, temp->children[1], table);
                            if (temp->sibling)
                                IRGenerator::generatePrint(out, "goto", tempLabel);
                        }
                        IRGenerator::generatePrint(out, "label", tempLabel);
                    }
                    break;
                case GOTO_STMT:
                    IRGenerator::generatePrint(out, "goto", to_string(node->attr.intNum));
                    break;
                case PROC_STMT:
                    IRGenerator::generatePrint(out, "begin_args");
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                        if (!temp->resultConstant)
                            generateIR(out, temp, table);
                    }

                    for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                        if (temp->resultConstant)
                            resultName = IRGenerator::generateResultValue(temp);
                        else 
                            resultName = IRGenerator::generateResultName(out, temp);

                        IRGenerator::generatePrint(out, "arg", resultName);
                        IRGenerator::recycleTempName(resultName);
                    }

                    if (node->system) 
                        IRGenerator::generatePrint(out, "call", string("@sys_") + node->name);
                    else {
                        childTable = table->findSymbolTable(node->name); 
                        IRGenerator::generatePrint(out, "call", childTable->getConnectTableName());
                    }
                    break;
                default:
                    break;
            }
            generateIR(out, node->sibling, table);
            break;
        case EXPR:
            switch(node->pattern.expr) {
                case ID_EXPR:
                    switch(node->subexpr.iden) {
                        case BASIC_ID:
                            if (table->getTableName() == node->name) {
                                tempName = "__" + table->getConnectTableName();
                                node->resultName = tempName;
                            }
                            else
                                node->resultName = node->name; 
                            break;
                        case ARRAY_ID:
                            symbol = table->findSymbol(node->name);
                            types = table->getActualType(symbol->resultType);

                            start = types->children[0]->children[0]->attr.intNum;

                            tempPtrName = IRGenerator::generateTempPtrName();
                            IRGenerator::generateAssignPrint(out, tempPtrName, string("&") + node->name);

                            if (node->children[0]->resultConstant) {
                                size = node->children[0]->attr.intNum - start;
                                size *= table->getTypeSize(types->children[1]);
                                if (size != 0)
                                    IRGenerator::generateAssignPrint(out, tempPtrName, tempPtrName, "+", to_string(size));
                            }
                            else {
                                generateIR(out, node->children[0], table);
                                resultName = IRGenerator::generateResultName(out, node->children[0]);

                                IRGenerator::recycleTempName(resultName);
                                tempName = IRGenerator::generateTempName();

                                size = table->getTypeSize(types->children[1]);
                                if (start != 0) {
                                    IRGenerator::generateAssignPrint(out, tempName, resultName, "-", to_string(start));
                                    IRGenerator::generateAssignPrint(out, tempName, tempName, "*", to_string(size));
                                }
                                else
                                    IRGenerator::generateAssignPrint(out, tempName, resultName, "*", to_string(size));

                                IRGenerator::generateAssignPrint(out, tempPtrName, tempPtrName, "+", tempName);
                                IRGenerator::recycleTempName(tempName);
                            }

                            node->resultName = tempPtrName; 
                            node->resultIndirect = true;
                            break;
                        case RECORD_ID:
                            symbol = table->findSymbol(node->name);

                            generateIR(out, node->children[0], table);
                            tempPtrName = IRGenerator::generateTempPtrName();

                            IRGenerator::generateAssignPrint(out, tempPtrName, string("&") + node->name);

                            size = table->getRecordOffset(symbol->resultType, node->children[0]->name);

                            if (size != 0) 
                                IRGenerator::generateAssignPrint(out, tempPtrName, tempPtrName, "+", to_string(size));

                            node->resultName = tempPtrName; 
                            node->resultIndirect = true;
                            break;
                        default:
                            break;
                    }
                    break;
                case OP_EXPR:
                    if (node->subexpr.oper == AND_OP) {
                        if (node->children[0]->resultConstant) {
                            generateIR(out, node->children[1], table);
                            resultName = IRGenerator::generateResultName(out, node->children[1]);
                            node->resultName = resultName;
                        }
                        else if (node->children[1]->resultConstant) {
                            generateIR(out, node->children[0], table);
                            resultName = IRGenerator::generateResultName(out, node->children[0]);
                            node->resultName = resultName;
                        }
                        else {
                            generateIR(out, node->children[0], table);
                            resultName = IRGenerator::generateResultName(out, node->children[0]);

                            tempLabel1 = IRGenerator::generateTempLabel();
                            tempLabel2 = IRGenerator::generateTempLabel();

                            IRGenerator::generatePrint(out, "if_f", resultName, "goto", tempLabel1);
                            IRGenerator::recycleTempName(resultName);

                            generateIR(out, node->children[1], table);
                            resultName = IRGenerator::generateResultName(out, node->children[1]);

                            IRGenerator::recycleTempName(resultName);

                            if (assignName == "")
                                tempName = IRGenerator::generateTempName();
                            else
                                tempName = assignName;

                            IRGenerator::generateAssignPrint(out, tempName, resultName);
                            IRGenerator::generatePrint(out, "goto", tempLabel2);

                            IRGenerator::generatePrint(out, "label", tempLabel1);
                            IRGenerator::generateAssignPrint(out, tempName, "0");
                            IRGenerator::generatePrint(out, "label", tempLabel2);

                            node->resultName = tempName;
                        }
                        break;
                    }
                    if (node->subexpr.oper == OR_OP) {
                        if (node->children[0]->resultConstant) {
                            generateIR(out, node->children[1], table);
                            resultName = IRGenerator::generateResultName(out, node->children[1]);
                            node->resultName = resultName;
                        }
                        else if (node->children[1]->resultConstant) {
                            generateIR(out, node->children[0], table);
                            resultName = IRGenerator::generateResultName(out, node->children[0]);
                            node->resultName = resultName;
                        }
                        else {
                            generateIR(out, node->children[0], table);
                            resultName = IRGenerator::generateResultName(out, node->children[0]);

                            tempLabel1 = IRGenerator::generateTempLabel();
                            tempLabel2 = IRGenerator::generateTempLabel();

                            IRGenerator::generatePrint(out, "if_f", resultName, "goto", tempLabel1);
                            IRGenerator::recycleTempName(resultName);

                            if (assignName == "")
                                tempName = IRGenerator::generateTempName();
                            else
                                tempName = assignName;

                            IRGenerator::generateAssignPrint(out, tempName, "1");
                            IRGenerator::generatePrint(out, "goto", tempLabel2);

                            IRGenerator::generatePrint(out, "label", tempLabel1);

                            generateIR(out, node->children[1], table);
                            resultName = IRGenerator::generateResultName(out, node->children[1]);

                            IRGenerator::generateAssignPrint(out, tempName, resultName);
                            IRGenerator::recycleTempName(resultName);

                            IRGenerator::generatePrint(out, "label", tempLabel2);

                            node->resultName = tempName;
                        }
                        break;
                    }

                    if (node->children[0] != nullptr) {
                        if (node->children[0]->resultConstant) 
                            resultName1 = IRGenerator::generateResultValue(node->children[0]);
                        else {
                            generateIR(out, node->children[0], table);
                            resultName1 = IRGenerator::generateResultName(out, node->children[0]);
                        } 
                    }

                    if (node->children[1] != nullptr) {
                        if (node->children[1]->resultConstant) 
                            resultName2 = IRGenerator::generateResultValue(node->children[1]);
                        else {
                            generateIR(out, node->children[1], table);
                            resultName2 = IRGenerator::generateResultName(out, node->children[1]);
                        } 
                    }

                    IRGenerator::recycleTempName(resultName1);
                    IRGenerator::recycleTempName(resultName2);

                    if (assignName == "")
                        tempName = IRGenerator::generateTempName();
                    else
                        tempName = assignName;

                    switch(node->subexpr.oper) {
                        case PLUS_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "+", resultName2);
                            break;
                        case MINUS_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "-", resultName2);
                            break;
                        case MUL_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "*", resultName2);
                            break;
                        case DIV_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "/", resultName2);
                            break;
                        case MOD_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "%", resultName2);
                            break;
                        case GE_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, ">=", resultName2);
                            break;
                        case GT_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, ">", resultName2);
                            break;
                        case LE_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "<=", resultName2);
                            break;
                        case LT_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "<", resultName2);
                            break;
                        case EQ_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "==", resultName2);
                            break;
                        case UEQ_OP:
                            IRGenerator::generateAssignPrint(out, tempName, resultName1, "!=", resultName2);
                            break;
                        case NOT_OP:
                            IRGenerator::generateAssignPrint(out, tempName, "!" + resultName1);
                            break;
                        case NEG_OP:
                            IRGenerator::generateAssignPrint(out, tempName, "-" + resultName1);
                            break;
                        defualt:
                            break;
                    }
                    node->resultName = tempName;
                    break;
                case FN_EXPR:
                    IRGenerator::generatePrint(out, "begin_args");
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                        if (!temp->resultConstant) 
                            generateIR(out, temp, table);
                     }

                    for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                        if (temp->resultConstant)
                            resultName = IRGenerator::generateResultValue(temp);
                        else
                            resultName = IRGenerator::generateResultName(out, temp);

                        IRGenerator::generatePrint(out, "arg", resultName);
                        IRGenerator::recycleTempName(resultName);
                    }

                    if (assignName == "")
                        tempName = IRGenerator::generateTempName();
                    else
                        tempName = assignName;

                    if (node->system)
                        IRGenerator::generateAssignPrint(out, tempName, "call", string("@sys_") + node->name);
                    else {
                        childTable = table->findSymbolTable(node->name);
                        IRGenerator::generateAssignPrint(out, tempName, "call", childTable->getConnectTableName());
                    }
                    node->resultName = tempName; 
                    break;
                default:
                    break;

            }
            break;
        default:
            generateIR(out, node->sibling, table);
            break;
    }
}



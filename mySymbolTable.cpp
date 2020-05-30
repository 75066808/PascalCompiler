#include "mySymbolTable.hpp"
#include "mySyntaxTree.hpp"
#include <fstream>
#include <iostream>

using namespace std;

SymbolTable *global = nullptr;

SymbolTable::SymbolTable(string tableName, SymbolTable *parent) : tableName(tableName), parent(parent) {
    if (parent != nullptr)
        parent->children[tableName] = this;
}

SymbolTable::~SymbolTable() {

}

Node* SymbolTable::findSymbol(string symbolName) {
    SymbolTable *table = this;

    while (table != nullptr) {
        auto iter = table->symbolMap.find(symbolName);
        if (iter == table->symbolMap.end())
            table = table->parent;
        else
            return iter->second;
    }

    return nullptr;
} 

SymbolTable* SymbolTable::findSymbolTable(string tableName) {
    SymbolTable *table = this;

    while (table != nullptr) {
        auto iter = table->children.find(tableName);
        if (iter == table->children.end())
            table = table->parent;
        else
            return iter->second;
    }
    return nullptr;
} 

bool SymbolTable::insertSymbol(string symbolName, Node *symbolVal) {
    auto iter = symbolMap.find(symbolName);
    if (iter != symbolMap.end()) 
        return false;
    
    symbolMap[symbolName] = symbolVal;
    return true;
}

string SymbolTable::getTableName(void) {
    return tableName;
}

string SymbolTable::getConnectTableName(void) {
    if (parent == nullptr)
        return tableName;
    else
        return parent->getConnectTableName() + "_" + tableName;
}

SymbolTable* SymbolTable::getParent(void) {
    return parent;
}

SymbolTable* SymbolTable::getChildren(string name) {
    return children[name];
}

SymbolTable* SymbolTable::getRecordTable(Node *type) {
    Node *define = findSymbol(type->name);

    while (define->dtype->pattern.type == SELFDEFINE)
        define = findSymbol(define->dtype->name);

    return findSymbolTable(define->name);
}

Node* SymbolTable::getActualType(Node *type) {
    if (type == nullptr)
        return nullptr;

    if (type->nodes != TYPES)
        return nullptr;

    Node *define;

    while (type != nullptr && type->pattern.type == SELFDEFINE) {
        define = findSymbol(type->name);
        if (define == nullptr)
            return nullptr;
        type = define->dtype;
    }

    return type;
}

size_t SymbolTable::getTypeSize(Node *type) {
    
    int left, right;
    int size, count;

    type = getActualType(type);
    switch(type->pattern.type) {
        case INTEGE:
            return 2;
        case CHARA:
            return 1;
        case BOOLEA:
            return 1;
        case REA:
            return 6;
        case STR:
            return 256;
        case ARRA:
            left  = type->children[0]->children[0]->attr.intNum;
            right = type->children[0]->children[1]->attr.intNum;
            return (right - left + 1) * getTypeSize(type->children[1]);
        case RECOR:
            size = 0;
            for (Node *var = type->children[0]; var; var = var->sibling) {
                count = 0;
                for (Node *name = var->children[0]; name; name = name->sibling)
                    ++count;
                size += count * getTypeSize(var->dtype);
            }
            return size;
        default:
            return 0;
    }
}

size_t SymbolTable::getRecordOffset(Node *type, string name) {
    int count;
    int offset = 0;

    type = getActualType(type);
    for (Node *var = type->children[0]; var; var = var->sibling) {
        count = 0;
        for (Node *names = var->children[0]; names; names = names->sibling) {
            if (name == names->name)
                return offset + count * getTypeSize(var->dtype);
            else
                ++count;
        }
        offset += count * getTypeSize(var->dtype);
    }
    return offset;
}

void SymbolTable::printTable(ofstream& out, int level) {
    for (int i = 0;i < level;i++) 
        out << " ";

    out << "---" << tableName << "---" << endl;

    for (auto &x : symbolMap) {
        for (int i = 0; i < level;i++)
            out << " ";
        out << x.first << endl;
    }

    for (auto &x : children)
        x.second->printTable(out, level + 1);
        
}


void buildSymbolTable(Node *node, SymbolTable *table) {
    if (node == nullptr)
        return;

    SymbolTable *childTable;

    switch(node->nodes) {
        case ROUTINE:
            buildSymbolTable(node->children[0], table);
            buildSymbolTable(node->children[1], table);
            buildSymbolTable(node->sibling, table);
            break;
        case CONSTANT:
            if (!table->insertSymbol(node->name, node))
                cout << "Error: line "<< node->lineNo << " redefine " << node->name << endl;
            buildSymbolTable(node->sibling, table);
            break;
        case TYPES:
            switch(node->pattern.type) {
                case DECL:
                    if (!table->insertSymbol(node->name, node))
                        cout << "Error: line "<< node->lineNo << " redefine " << node->name << endl;
                    if (node->dtype->pattern.type == RECOR) {
                        childTable = new SymbolTable(node->name, table);
                        buildSymbolTable(node->dtype, childTable);
                    }
                    else 
                        buildSymbolTable(node->dtype, table);
                    break;
                case RECOR:
                    buildSymbolTable(node->children[0], table); 
                    break;
                case ARRA:
                    buildSymbolTable(node->children[0], table);
                    buildSymbolTable(node->children[1], table);
                    break;
                case SELFDEFINE:
                    if (table->findSymbol(node->name) == nullptr)
                        cout << "Error: line "<< node->lineNo << " undefine " << node->name << endl;
                    break;
                default:
                    break;
            }
            buildSymbolTable(node->sibling, table);
            break;
        case VARI:
            for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                if (!table->insertSymbol(temp->name, temp))
                    cout << "Error: line "<< temp->lineNo << " redefine " << temp->name << endl;
            }
            buildSymbolTable(node->dtype, table);
            buildSymbolTable(node->sibling, table);
            break;
        case SUB:
            switch(node->pattern.routine) {
                case FUNC:
                case PROC:
                    if (table && !table->insertSymbol(node->name, node))
                        cout << "Error: line "<< node->lineNo << " redefine " << node->name << endl;

                    childTable = new SymbolTable(node->name, table); 
                    if (table == nullptr)
                        global = childTable;
                    buildSymbolTable(node->children[0], childTable);
                    buildSymbolTable(node->children[1], childTable);
                    buildSymbolTable(node->dtype, table);
                    break;
                case PARAM_VAR:
                case PARAM_VAL:
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling) {
                        if (!table->insertSymbol(temp->name, temp))
                            cout << "Error: line "<< temp->lineNo << " redefine " << temp->name << endl;
                    }
                    buildSymbolTable(node->dtype, table);
                    break;
                default:
                    break;
            }
            buildSymbolTable(node->sibling, table);
            break;
        case STMT:
            switch(node->pattern.stmt) {
                case FOR_STMT:
                    if (table->findSymbol(node->name) == nullptr) 
                        cout << "Error: line "<< node->lineNo << " undefine " << node->name << endl;
                    break;
                case PROC_STMT:
                    if (table->findSymbol(node->name) == nullptr && !node->system) 
                        cout << "Error: line "<< node->lineNo << " undefine " << node->name << endl;
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling)
                        buildSymbolTable(temp, table);
                    break;
                default:
                    break;
            }
            buildSymbolTable(node->children[0], table);
            buildSymbolTable(node->children[1], table);
            buildSymbolTable(node->children[2], table);
            buildSymbolTable(node->sibling, table);
            break;
        case EXPR:
            switch(node->pattern.expr) {
                case ID_EXPR:
                    if (table->findSymbol(node->name) == nullptr)
                        cout << "Error: line "<< node->lineNo << " undefine " << node->name << endl;
                       
                    if (node->subexpr.iden == ARRAY_ID) 
                        buildSymbolTable(node->children[0], table);
                    /*
                    if (node->subexpr.iden == RECORD_ID) {
                        value = table->findSymbol(node->name);
                        table = table->findSymbolTable(value->dtype->name);
                        
                        if (value->nodes == SUB || table == nullptr || 
                                table->findSymbol(node->children[0]->name) == nullptr) {
                            cout << "Error: line "<< node->lineNo << " undefine " << node->children[0]->name << endl;
                            return;
                        }
                    }*/
                    break;
                case FN_EXPR:
                    if (table->findSymbol(node->name) == nullptr && !node->system) 
                        cout << "Error: line "<< node->lineNo << " undefine " << node->name << endl;
                    for (Node *temp = node->children[0]; temp; temp = temp->sibling)
                        buildSymbolTable(temp, table);
                    break;
                default:
                    buildSymbolTable(node->children[0], table);
                    buildSymbolTable(node->children[1], table);
                    buildSymbolTable(node->children[2], table);
                    break;
            }
            break;
        default:
            buildSymbolTable(node->sibling, table);
            break;
    }     
}

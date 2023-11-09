#ifndef AST_NODE_H
#define AST_NODE_H
#include "AST.h"
#include "Data.h"
#include <string>
#include <map>

using namespace std;

class AST_Node {
    public:
    AST_Node* left;
    AST_Node* right;
    AST_Node* parent;
    Token* data;
    string data_type;
    bool single_val;
    bool is_number;
    Data val;
    AST_Node();
    AST_Node(Token* in_data);
    virtual ~AST_Node();
    virtual Data get_value(Data& left_val, Data& right_val) = 0;
    virtual bool is_variable(Data& a) const;
    virtual bool invalid_variable(Data& a) const;
    static map<string, Data> prev_variables; 
    static bool runtime_error;
};

class Double_Operation: public AST_Node{
    public:
    Double_Operation(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

class Direct_Val: public AST_Node{
    public:
    Direct_Val(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

class Variable_Val: public AST_Node{
    public:
    Variable_Val(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

class Assign: public AST_Node{
    public:
    Assign(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);

};

class Boolean_Operation: public AST_Node {
    public:
    Boolean_Operation(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

class Equality_Val: public AST_Node {
    public:
    Equality_Val(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

class Comparison_Val: public AST_Node {
    public:
    Comparison_Val(Token* in_data);
    Data get_value(Data& left_val, Data& right_val);
};

#endif
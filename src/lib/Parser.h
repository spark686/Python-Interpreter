#ifndef PARSER_H
#define PARSER_H
#include "AST.h"
#include "Node.h"
#include <string>
using namespace std;

class Parser {
    private:
    Node* root;
    void print_help(Node* in_node, bool parenthesis) const;
    double calculate_help(Node* operator_node) const;
    void delete_help(Node* current_node);
    public:
    Parser();
    void read_tokens(vector<Token*> tokens_list);
    void print() const;
    double calculate() const;
    void print_error_2(Token* error_token);
    ~Parser();


};

#endif

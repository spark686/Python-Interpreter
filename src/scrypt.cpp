#include <iostream>
#include "lib/Lexer.h"
#include "lib/Scrypter.h"
#include <string>

using namespace std; 

int main(){
    Lexer lexer; 
    lexer.create_endtokens();
    // lexer.print_endtokens();
    Scrypter scrypt(lexer.multi_end_tokens);

    scrypt.buildASTs();
    scrypt.printFormated();
    // // lexer.delete_endtokens();
    // // cout << formater.ASTHeads.size();
    // formater.deleteStatements();
    return 0;
}
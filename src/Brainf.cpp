#include <iostream>
#include <vector>
#include <fstream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"

using namespace std;

int main(int argc, char *argv[]) {
  string code;

  ifstream myfile (argv[1]);
  string line;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      for (int i=0;i<line.length();i++){
        if (line[i]=='>'||line[i]=='<'||line[i]=='+'||line[i]=='-'||line[i]=='.'||line[i]==','||line[i]=='['||line[i]==']'){
          code+=line[i];
        }
      }
    }
    myfile.close();
  }
  vector<Token> lexed = Lexer(code).lex();
  Parser p = Parser(lexed);
  while (p.i_p != lexed.size()){
    p.parse();
  }  
}
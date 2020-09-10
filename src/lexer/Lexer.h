#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include "Token.h"

using namespace std;

class Lexer {
  private :
  // Code source
  string src;

  protected:
  // Helper functions

  // checkRegex
  // Checks if the string matches a certain regex
  int checkRegex(string code, regex regexToken){
    string currentToken = "";

    // While there is not a match, add to currentToken
    for (int i=0;i<code.length();++i){
      currentToken += code[i];
      // If there is a match and the next char does not also match, return the length of the match
      try {
        if (regex_match(currentToken,regexToken) && !(regex_match(currentToken+code[i+1],regexToken))) {
          return currentToken.length();
        }
      } catch (...) {
      
      }  
    }
    // If there is no match, return -1
    return -1;
  }

  // getToken
  // Gets the first possible token and returns it
  Token getToken(){
    Token token;
    bool isMatched = false;
    // Clearing off unnecessary whitespace
    while (src[0]==' '||src[0]=='\n'){
      src = src.substr(1,src.size());
    }
    // Try all the regexes
    for (int i=0;i<TokenType.size();i++){
      int isTrue = checkRegex(src,regex(TokenRegexes[i]));
      // Try each regex
      if (isTrue>0){
        isMatched = true;
        // Edit the token type
        token.type = TokenType[i];
        token.value = src.substr(0,isTrue);
        // Break src off
        src = src.substr(isTrue,src.size());
        break;
      }
    }
    // If there was no match, the token is unknown
    if (!isMatched){
      token.value = src;
      token.type = -1;
    }

    return token;
  }
  public:
  // Lexing methods
  vector<Token> lex(){
    vector<Token> tokens = {};
    // Get the token and append it to the list
    while (src.size()>0){
      tokens.push_back(getToken());
    }
    return tokens;
  }

  // Constructors
  Lexer(){

  }
  Lexer(string inp){
    src = inp;
  }
};
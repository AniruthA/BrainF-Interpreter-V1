#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int LEFT = 1;
int RIGHT = 2;
int PLUS = 3;
int MINUS = 4;
int OPEN = 5;
int CLOSE = 6;
int COMMA = 7;
int PERIOD = 8;

vector<int> TokenType = {
  LEFT,
  RIGHT,
  PLUS,
  MINUS,
  OPEN,
  CLOSE,
  COMMA,
  PERIOD
};

vector<string> TokenRegexes = {
  "\\<",
  "\\>",
  "\\+",
  "\\-",
  "\\[",
  "\\]",
  "\\,",
  "\\."
};

struct Token {
  string value;
  int type;
  Token (string token_value,int token_type){
    value = token_value; 
    type = token_type;
    
  }
  Token (){
    
  }
};
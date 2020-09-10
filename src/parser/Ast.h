#include "./Errors.h"
#include <map>

int ptr = 1;
vector<int> memory = {0,0,0,0,0,0,0,0,0,0};


class Left {
  public:
  Left(){}
  void execute(){
    ptr -= 1;
    if (ptr<0){
      Error("PointerError","invalid position for pointer",3);
    }
  }
};
class Right {
  public: 
  Right(){}
  void execute(){
    ptr += 1;
    if (ptr>memory.size() and ptr<100000){
      memory.push_back(0);
    }
  }
};
class Plus {
  public:
  Plus(){}
  void execute(){
    memory[ptr-1] += 1;
  }
};
class Minus {
  public:
  Minus(){}
  void execute(){
    memory[ptr-1] -= 1;
    if (memory[ptr-1]<0){
      Error("ValueError","cell value cannot be less than 0",2);
    }
  }
};
class Period {
  public:
  Period(){}
  void execute(){
    try {
      int value = memory[ptr-1];
      cout << (char)value;
    } catch(...) {
      Error("DisplayError","cannot display",5);
    }
  }
};
class Comma {
  public:
  Comma(){}
  void execute(){
    char character;
    cin >> character;
    int c = character;
    memory[ptr-1] = c;
  }
};
class OpenBracket {
  public :
  int matching=0;
  OpenBracket(){ }
  OpenBracket(int matched){
    matching = matched;
  }
  void execute(int& i_p){
    if (memory[ptr-1]==0){
      i_p = matching+1;
    }
  }
};
class CloseBracket {
  public :
  int matching=0; 
  CloseBracket(){ }
  CloseBracket(int matched){
    matching = matched;
  }
  void execute(int& i_p){
    if (memory[ptr-1]!=0){
      i_p = matching+1;
    }
  }
};
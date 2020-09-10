#include "./Ast.h"
#include <variant>

using namespace std;

class Parser {
  private:
  bool get(vector<Token>& stream, int token_type, int& i_p){
    if (stream[i_p].type==token_type){
      i_p+=1;
      return true;
    }
    return false;
  }

  protected:
  vector<Token> stream;

  public:
  int i_p = 0;
  Parser(){}
  Parser(vector<Token> lexed){
    stream = lexed;
  }
  void parse(){
    if (get(stream,LEFT,i_p)){
      Left left;
      left.execute();
    } else if (get(stream,RIGHT,i_p)){
      Right right;
      right.execute();
    } else if (get(stream,PLUS,i_p)){
      Plus plus;
      plus.execute();
    } else if (get(stream,MINUS,i_p)){
      Minus minus;
      minus.execute();
    } else if (get(stream,PERIOD,i_p)){
      Period period;
      period.execute();
    } else if (get(stream,COMMA,i_p)){
      Comma comma;
      comma.execute();
    } else if (get(stream,OPEN,i_p)){
      int matching = -1;
      int pos = -1;
      int priority = 0;
      for (int g=0;g<stream.size();g++){
        if (stream[g].type==OPEN){
          if (i_p == g){
            pos = g;
            break;
          } else {
            priority += 1;
          }
        }
      }
      int priority2 = 1;
      for (int g=stream.size();g>0;g--){
        if (stream[g].type==CLOSE){
          if (priority==priority2){
            matching = g;
            break;
          } else {
            priority2 += 1;
          }
        }
      }
      if (matching<0){
        Error("MatchError","unmatched open bracket",4);
      }
      OpenBracket op = OpenBracket(matching);
      op.execute(i_p);

    } else if (get(stream,CLOSE,i_p)){
      int matching = -1;
      int pos = -1;
      int priority = 0;
      for (int g=stream.size();g>0;g--){
        if (stream[g].type==CLOSE){
          if (i_p-1 == g){
            pos = g;
            break;
          } else {
            priority += 1;
          }
        }
      }
      int priority2 = 0;
      for (int g=0;g<stream.size();g++){
        if (stream[g].type==OPEN){
          if (priority==priority2){
            matching = g;
            break;
          } else {
            priority2 += 1;
          }
        }
      }
      if (matching<0){
        Error("MatchError","unmatched closing bracket",4);
      }
      CloseBracket op = CloseBracket(matching);
      op.execute(i_p);
    }
  }
};
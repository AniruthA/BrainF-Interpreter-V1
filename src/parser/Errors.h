#include <stdlib.h>

class Error{
  protected:
  string name = "Error";
  string cause = "";
  public:
  Error(){}
  Error(string errorname, string reason="", int exitcode=1){
    name = errorname;
    cause = reason;
    cout << errorname << ": " << reason << "\n";
    exit(exitcode);
  }
};
#include <vector>
#include <string>

using namespace std;

class ExeObj{
  public:
    ExeObj(vector<string>);

    ~ExeObj();
    int run();
  private:
   const char* cmd;
   char* args[255]; 




};

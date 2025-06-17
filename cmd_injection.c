#include <iostream>
#include <string>
using namespace std;

void executeCommand(const string& cmd){
    int res = system(cmd.c_str()); // Use c_str() to get const char* from string

    if (res == -1) {
        perror("Error executing command");
    } else {
      cout << "Execution successful" << endl;
    }
}

int main(){
   string input;
   cout<<"Enter your command:"<<endl;
   cin>>input;
   executeCommand(input);
   return 0;
}

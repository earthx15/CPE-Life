#include <iostream>
#include <string>

using namespace std;

int main () {
    int age,i=0;
    char command;
    string comall; 

    //cout << "comall : " << comall << "A" << endl;
    for (;;) {
        cout << "Enter your command : ";
        do {
            command = getchar();
            comall += command; 
        } while (command != '\n');
        //cout << "comall : " << comall << endl; 
        if (comall == "\n") {
            age++;
            cout << "your age : " << age << endl;
            comall = "";
            command = '\0';  
        }
        if (comall == "end\n")  break;
    }
    
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random (int n) {
        return  rand()%n;        
}

int main () {
    srand(time(0));
    random(100); // random 0 to 100;
}
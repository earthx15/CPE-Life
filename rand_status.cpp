#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int random (int n) {
        return  rand()%n;        
}

int main () {
    srand(time(0));
    int Happiness = random(101);
    int Health = random(101);
    int Smart = random(101);
    int Look = random(101);
    int Moral = random(101);
    string sexual;
    if (random(101) == 0) sexual = "male";
    else sexual = "female";

    cout << "sexual : " << sexual << endl;
    cout << "Happiness : " << Happiness << endl;
    cout << "Health : " << Health << endl;
    cout << "Smart : " << Smart << endl;
    cout << "Look : " << Look << endl;
    cout << "Moral : " << Moral << endl;
}


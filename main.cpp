#include <iostream>
using namespace std;

int main(){
    int powerLevel = 90000;
    int* powerPointer = &powerLevel;
    cout << powerLevel << " ";
    *powerPointer = 90001;
    cout << powerLevel << " ";

    int health = 100;
    int& healthAlies = health;
    cout << health << " \n";
    healthAlies = 50;
    cout << health << " \n";
    return 0;
}
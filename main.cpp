#include <iostream>
#include <string>
using namespace std;

template <typename T>
T getMaximum(T a, T b){
    return (a > b) ? a: b;
}

int main(){
    cout << getMaximum(4,55) << " \n";
    cout << getMaximum(4.44,55.55) << " \n";
    cout << getMaximum('z','a') << " \n";
    return 0;
}
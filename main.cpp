#include <iostream>
using namespace std;

int main(){
    int* heapInt = new int; 
    *heapInt = 42;
    delete heapInt; 
    heapInt = nullptr;
    return 0;
}
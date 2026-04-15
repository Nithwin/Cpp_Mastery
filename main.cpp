#include <iostream>
using namespace std;

void swapWithPointers(int* ptr1, int* ptr2){
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void swapWithReferences(int& ref1, int& ref2){
    int tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}
int main(){
    int a = 10; int b = 20;
    cout << a << " " << b << " \n";
    swapWithPointers(&a,&b);
    cout << a << " " << b << " \n";
    swapWithReferences(a, b);
    cout << a << " " << b << " \n";
    return 0;
}
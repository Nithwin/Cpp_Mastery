#include <iostream>
using namespace std;

int main(){
    cout << "Size of Array: ";
    int size; cin >> size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i]= i+1;
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
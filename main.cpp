#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class NetworkPair {
    private:
        T1 first;
        T2 second;
    public:
        NetworkPair(T1 a, T2 b){
            first = a;
            second = b;
        }
        void print(){
            cout << first << " " << second << "\n";
        }
};

int main(){
    NetworkPair np(3,5);
    np.print();
    NetworkPair np2("Hello","World");
    np2.print();
    return 0;
}
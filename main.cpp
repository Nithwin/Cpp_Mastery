#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>
class NetworkPair {
    public:
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
    vector<NetworkPair<string,int>> servers;
    servers.push_back({"10.0.0.1", 8080});
    servers.push_back({"192.168.1.5", 22});
    servers.push_back({"172.16.0.1", 443});

    sort(servers.begin(), servers.end(), [](const NetworkPair<string,int> &a,const NetworkPair<string,int> &b){
        return a.second < b.second;
    });
    for(auto &server: servers){
        server.print();
    }
    return 0;
}
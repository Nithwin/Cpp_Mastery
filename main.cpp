#include <iostream>
using namespace std;

class NetworkDevice{
    public:
    virtual void processPacket(){
        cout << "Process Packet default...";
    }

    virtual ~NetworkDevice(){
        cout << "Network Device Destroyed...";
    }
};

class Firewall: public NetworkDevice {
    public:
    void processPacket() override {
        cout << "Firewall Packet...";
    }

    ~Firewall(){
        cout << "Firewall Destroyed...";
    }

};

class Switch: public NetworkDevice {
    public:
    void processPacket() override {
        cout << "Switch Packet Processor...";
    }

    ~Switch(){
        cout << "Switch Destoryed...";
    }
};

int main(){
    NetworkDevice** arr = new NetworkDevice*[2];
    arr[0] = new Firewall;
    arr[1]  = new Switch;
    for(int i = 0; i < 2; i++){
        arr[i]->processPacket();
    }
    for(int i = 0; i < 2; i++){
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
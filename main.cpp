#include <iostream>
#include <memory>
#include <vector>
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
    vector<unique_ptr<NetworkDevice>> devices;
    devices.push_back(make_unique<Firewall>());
    devices.push_back(make_unique<Switch>());
    for(auto& device: devices){
        device->processPacket();
    }
    return 0;
}
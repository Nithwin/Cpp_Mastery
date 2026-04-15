#include <iostream>
#include <string>
#include <vector>

using namespace std;

// The Base Class
class Packet {
public:
    virtual ~Packet() {} // Virtual destructor is REQUIRED for dynamic_cast to work!
};

// Derived Class 1
class PingPacket : public Packet {
public:
    int getPing() { return 42; }
};

// Derived Class 2
class DataPacket : public Packet {
public:
    string getPayload() { return "Secure Video Stream"; }
};

// YOUR TRIAL: Complete this function
void inspectPacket(Packet* genericPacket) {
    // TODO: Use dynamic_cast<PingPacket*>(genericPacket) to check if it's a PingPacket.
    // If it is, call getPing() and print it.
    PingPacket* pp = dynamic_cast<PingPacket*>(genericPacket);
    if(pp != nullptr){
        cout << pp->getPing() << "\n";
    }
    
    // TODO: Use dynamic_cast<DataPacket*>(genericPacket) to check if it's a DataPacket.
    // If it is, call getPayload() and print it.
    DataPacket* dp = dynamic_cast<DataPacket*>(genericPacket);

    if(dp != nullptr){
        cout << dp->getPayload() << "\n";
    }
}

int main() {
    PingPacket p1;
    DataPacket p2;

    cout << "Inspecting Packet 1...\n";
    inspectPacket(&p1);

    cout << "Inspecting Packet 2...\n";
    inspectPacket(&p2);

    return 0;
}
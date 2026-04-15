#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int totalPackets = 0;
mutex packetMutex;

void processPacket(){
    for(int i = 0; i < 10000000; i++){
        lock_guard<mutex> lock(packetMutex);
        totalPackets++;
    }
}

int main() {
    thread worker1(processPacket);
    thread worker2(processPacket);

    worker1.join();
    worker2.join();
    // processPacket();
    // processPacket();
    cout << totalPackets << " ";
    return 0;
}
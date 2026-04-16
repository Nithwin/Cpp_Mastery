#include <iostream>
#include <thread>
#include <future>

using namespace std;


int analyzeNetworkTraffic(int packetCount){
    this_thread::sleep_for(chrono::seconds(2));
    return packetCount * 10;
}

int main(){
    int totalPackets = 500;
    future<int> ticket = async(launch::async, analyzeNetworkTraffic, totalPackets);

    cout << "Fetching....\n";

    int res = ticket.get();
    cout << res << " ";
    return 0;
}
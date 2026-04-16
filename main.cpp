#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// 1. The Box, the Key, and the Doorbell
bool packageDelivered = false; 
mutex boxKey;                  
condition_variable doorbell;   

// 2. You (The Consumer)
void homeowner() {
    cout << "Homeowner: Going to sleep until the doorbell rings...\n";
    
    // You grab your key
    unique_lock<mutex> lock(boxKey);
    
    // You go to sleep. The wait() function automatically drops your key while you sleep.
    // It says: "Wake me up ONLY IF packageDelivered becomes true."
    doorbell.wait(lock, []{ return packageDelivered; }); 
    
    // ... YOU ARE ASLEEP HERE ...
    
    // When the doorbell rings, you wake up, and wait() automatically grabs the key again!
    cout << "Homeowner: Woke up! Grabbing the package.\n";
}

// 3. The Driver (The Producer)
void deliveryDriver() {
    this_thread::sleep_for(chrono::seconds(3)); // Simulate driving to your house
    
    {
        // Driver grabs their key, opens the box, and puts the package in
        lock_guard<mutex> lock(boxKey);
        packageDelivered = true;
        cout << "Driver: Package is in the box.\n";
    } // Driver locks the box and leaves
    
    // Driver rings the doorbell!
    doorbell.notify_one(); 
}

int main(){
    thread worker1(homeowner);
    thread worker2(deliveryDriver);
    worker1.join();
    worker2.join();
    return 0;
}
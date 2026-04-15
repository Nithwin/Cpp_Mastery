#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void downloadFirmware() {
    cout << "Background: Downloading...\n";
    this_thread::sleep_for(chrono::seconds(2)); // Simulate hard work
    cout << "Background: Download Complete!\n";
}

int main() {
    cout << "Main: Starting program.\n";
    
    // 1. Spawn the thread. It starts running immediately!
    thread worker(downloadFirmware); 
    
    cout << "Main: Doing other things while downloading...\n";
    
    // 2. The Golden Rule of Threads: You MUST join() or detach() before the thread object is destroyed.
    // join() means "Main thread will pause here and wait for the worker to finish."
    worker.join(); 
    
    cout << "Main: Shutting down.\n";
    return 0;
}
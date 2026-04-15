#include <iostream>
#include <utility>
using namespace std;

class PacketBuffer {
public:
    int* data;
    int size;

    // 1. Standard Constructor
    PacketBuffer(int s) {
        size = s;
        data = new int[size];
        cout << "Allocated " << size << " bytes.\n";
    }

    // 2. Destructor
    ~PacketBuffer() {
        if (data != nullptr) {
            delete[] data;
            cout << "Destroyed buffer.\n";
        }
    }

    // 3. YOUR TRIAL: THE MOVE CONSTRUCTOR
    // It takes an Rvalue reference to another PacketBuffer (using &&)
    PacketBuffer(PacketBuffer&& source) noexcept {
        // TODO: Steal the 'data' pointer and 'size' from 'source'.
        // TODO: Set 'source.data' to nullptr and 'source.size' to 0 so its destructor doesn't delete your stolen data!
        //PacketBuffer tmp = move(source);
        this->data = source.data;
        this->size = source.size;
        source.data = nullptr;
        source.size = 0;
        cout << "Stole buffer of size " << size << "!\n";
    }
};

int main() {
    PacketBuffer original(100); // Calls standard constructor
    
    // Calls your Move Constructor! original is cast to an Rvalue.
    PacketBuffer stolen = std::move(original); 
    
    // If your code works, only ONE destruction of data should occur, 
    // because 'original' will safely destruct with a nullptr.
    return 0;
}
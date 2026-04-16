#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>
#include <chrono>

using namespace std;

class ThreadPool {
private:
    vector<thread> workers;
    queue<function<void()>> tasks; // A queue of generic functions!
    
    mutex queue_mutex;
    condition_variable condition;
    bool stop;

    // This is the infinite loop that every worker thread runs
    void worker_loop() {
        while (true) {
            function<void()> task;
                    
            {
                // TODO 1: Create a unique_lock on the queue_mutex
                unique_lock<mutex> lock(queue_mutex);
                // TODO 2: Tell the condition variable to wait. 
                // The wake-up condition lambda should return TRUE if 'stop == true' OR '!tasks.empty()'
                condition.wait(lock, [this]{
                        return stop == true || !tasks.empty();
                });
                // TODO 3: If stop is true AND the tasks queue is empty, return; (to kill the thread)
                 if(stop == true && tasks.empty()){
                        return;
                    }   
                // TODO 4: Grab the front task from the queue: task = tasks.front();
                
                task = tasks.front();
                // TODO 5: Remove that task from the queue: tasks.pop();
                tasks.pop();
            } // The lock automatically unlocks here, allowing other workers to grab tasks!

            // Execute the task!
            task(); 
        }
    }

public:
    ThreadPool(int numThreads) : stop(false) {
        for (int i = 0; i < numThreads; ++i) {
            // Spawn the workers and point them to the worker_loop
            workers.push_back(thread(&ThreadPool::worker_loop, this));
        }
    }

    // Add a new task to the queue
    void enqueueTask(function<void()> newTask) {
        {
            lock_guard<mutex> lock(queue_mutex);
            tasks.push(newTask);
        }
        condition.notify_one(); // Wake up one idle worker!
    }

    ~ThreadPool() {
        {
            lock_guard<mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all(); // Wake up EVERYONE so they can see 'stop == true' and exit
        for (thread &worker : workers) {
            worker.join();
        }
    }
};

// --- DO NOT CHANGE MAIN ---
int main() {
    cout << "Starting Thread Pool with 4 workers...\n";
    ThreadPool pool(4);

    // Give the pool 10 tasks to complete
    for (int i = 1; i <= 10; ++i) {
        pool.enqueueTask([i]() {
            cout << "Worker executing task " << i << "...\n";
            this_thread::sleep_for(chrono::seconds(1)); // Simulate hard work
        });
    }

    cout << "Main: All 10 tasks enqueued. Waiting for workers to finish...\n";
    this_thread::sleep_for(chrono::seconds(5)); 
    cout << "Main: Shutting down.\n";
    
    return 0; // Destructor runs here and cleans up the threads!
}
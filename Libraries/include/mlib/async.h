#ifndef _ASYNC_H_
#define _ASYNC_H_

#include <vector>
#include <thread>

// EXAMPLE USAGE:
// sync {
//     // task 1
// }
// end_sync
#define sync for(bool keepGoing = true; keepGoing; keepGoing = false)
#define end_sync

// EXAMPLE USAGE:
// async {
//     // task 1
// }
// end_async
#define async std::thread([&](){
#define end_async }).detach();

std::vector<std::thread> threads;

// Wait for all asynchronous code on all threads to complete
void waitForCompletion() {
    for(auto& t : threads) {
        if(t.joinable()) {
            t.join();
        }
    }
}

// Join a subset of threads in the threads vector
void joinThreads(std::vector<std::thread>::iterator begin, std::vector<std::thread>::iterator end) {
    for(auto it = begin; it != end; ++it) {
        if(it->joinable()) {
            it->join();
        }
    }
}

// 

/// <summary>
/// Define a Thread class to simplify thread management.
/// thread.asynchronous([](){
///     async {
///         // task 1
///     }
///     end_async
/// });
/// thread.asynchronous([](){
///     async {
///         // task 2
///     }
///     end_async
/// });
/// thread.asynchronous([](){
///     async {
///         // task 3
///     }
///     end_async
/// });
/// thread.waitForCompletion();
/// </summary>
class Thread {
public:
    Thread() {}

    // Launch an asynchronous task on a new thread
    void asynchronous(const std::function<void()>& task) {
        threads.push_back(std::thread(task));
    }

    // Join a subset of the threads in the threads vector
    void join(const std::vector<std::thread>::iterator& begin, const std::vector<std::thread>::iterator& end) {
        joinThreads(begin, end);
    }

    // Wait for all asynchronous code on all threads to complete
    void waitForCompletion() {
        ::waitForCompletion();
    }

    // Wait for all asynchronous code on all threads to complete, and then join a subset of the threads in the threads vector
    void waitForCompletionAndJoin(const std::vector<std::thread>::iterator& begin, const std::vector<std::thread>::iterator& end) {
        waitForCompletion();
        joinThreads(begin, end);
    }
};



#endif
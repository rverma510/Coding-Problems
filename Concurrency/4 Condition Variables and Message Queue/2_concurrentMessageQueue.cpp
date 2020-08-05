#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include <algorithm>
#include <queue>

template <class T>
class MessageQueue {
  public:
    T receive() {
        // perform queue modification under lock
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_messages.empty(); });

        // remove last vector from queue
        T msg = std::move(_messages.back());
        _messages.pop_back();

        return msg;
    }
    void send(T &&msg) {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under lock
        std::lock_guard<std::mutex> lck(_mutex);
        
        // add vector to queue 
        std::cout << "  Message " << msg << " has been sent to the queue" << std::endl;
        _messages.push_back(std::move(msg));
        _cond.notify_one(); 
    }

  private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _messages;

};

int main() {
    // create monitor object as shared pointer to enable access by multiple threads
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; i++) {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
    }
    std::cout << "Collecting results..." << std::endl;
    while (true) {
        int message = queue->receive();
        std::cout << "Message #" << message << " has been removed from the queue" << std::endl;
    }
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr){
        ftr.wait();
    });

    std::cout << "Finished" << std::endl;

    return 0;
}
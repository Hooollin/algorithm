#include <iostream>
#include <vector>
#include <chrono>

#include "threadpool.hpp"

int main()
{
    
    ThreadPool pool(4);
    std::vector< std::future<int> > results;
    std::mutex mu;

    for(int i = 0; i < 20; ++i) {
        results.emplace_back(
            pool.Enqueue([i, &mu] {
                mu.lock();
                std::cout << "hello " << i << std::endl;
                mu.unlock();
                std::this_thread::sleep_for(std::chrono::seconds(1));
                mu.lock();
                std::cout << "world " << i << std::endl;
                mu.unlock();
                return i*i;
            })
        );
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    for(auto && result: results) {
      std::cout << result.get() << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}
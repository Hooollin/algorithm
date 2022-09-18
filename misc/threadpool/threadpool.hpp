#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <future>
#include <condition_variable>
#include <functional>

namespace {
  class ThreadPool {
    public:
      ThreadPool(size_t t);
      ~ThreadPool();
      
      ThreadPool(const ThreadPool&) = delete;
      ThreadPool(const ThreadPool&&) = delete;

      ThreadPool& operator=(const ThreadPool&) = delete;

      template <class F, class ...Args>
      inline auto Enqueue(F&& f, Args&& ...args) -> std::future<typename std::result_of<F(Args...)>::type>;

    private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> task_queue_;

    // synchronizaiton
    std::mutex queue_mutex_;
    std::condition_variable cv_;
    bool stop_; // threadpool aliveness
  };

ThreadPool::ThreadPool(size_t t): stop_(false) {
  for(size_t i = 0; i < t; i++) {
    workers_.emplace_back(
      [this] {
        while(true) {
          std::function<void()> task;

          {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            cv_.wait(lock, 
                    [this]{ return this->stop_ || !this->task_queue_.empty();} );
            task = std::move(task_queue_.front());
            if(stop_) {
              return;
            }
            task_queue_.pop();
          }

          task();
        }
      }
    );
  }
}

template<class F, class ...Args>
inline auto ThreadPool::Enqueue(F&& f, Args&& ...args) 
      -> std::future<typename std::result_of<F(Args...)>::type> {
  using return_type = typename std::result_of<F(Args...)>::type;
  auto task = std::make_shared<std::packaged_task<return_type()>>(
    std::bind(std::forward<F>(f), std::forward<Args>(args)...)
  );
  std::future<return_type> rev = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    if(stop_) {
      throw std::runtime_error("Enqueue on stopped ThreadPool");
    }
    task_queue_.emplace([task]{ (*task)(); });
  }
  cv_.notify_one();
  return rev;
}

ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop_ = true;
    cv_.notify_all();
  }

  for(auto &worker: workers_) {
    worker.join();
  }
}
} //anonymous namespace
#endif
#include "TaskScheduler.h"
#include <thread>
#include <chrono>

TaskScheduler::TaskScheduler(){}
void TaskScheduler::addTask(int number, std::function<void(int)> task, std::time_t timestamp)
{
    count++;
    std::thread thread
    {
        [timestamp, task, number, this] 
        {
            std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(timestamp));
            try {
                task(number);
            } 
            catch (const std::exception& e)
            {
                std::cout << "Exception: " << e.what() << std::endl;
            }
            condition.notify_one();
            count--;
        }
    };
    thread.detach();
}
void TaskScheduler::waitTasks()
{
    std::unique_lock<std::mutex> ulock(this->mutex);
    condition.wait(ulock, [this] { return this->count == 0; });
}
TaskScheduler::~TaskScheduler(){}

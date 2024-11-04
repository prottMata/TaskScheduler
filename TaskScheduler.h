#include <functional>
#include <ctime>
#include <condition_variable>
#include <mutex>
#include <iostream>

class TaskScheduler
{
private:
    time_t timestamp;
    std::condition_variable condition;
    std::mutex mutex;
    size_t count{};
public:
    TaskScheduler();
    static void createTask(int number){printf("Task %d\n",number);}
    void addTask(int, std::function<void(int)>, std::time_t);
    void waitTasks();
    ~TaskScheduler();
};
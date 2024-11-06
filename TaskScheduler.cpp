#include "TaskScheduler.h"
#include <thread>
#include <chrono>

//конструктор
TaskScheduler::TaskScheduler(){}
//добавление задачи и времени выполнения задачи
void TaskScheduler::addTask(int number, std::function<void(int)> task, std::time_t timestamp)
{
    //подсчет количества задач
    count++;
    //создание потоков для задач
    std::thread thread
    {
        [timestamp, task, number, this] 
        {
            //ожидание времени выполнения задач
            std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(timestamp));
            //проверка на исключения
            try {
                task(number);
            } 
            catch (const std::exception& e)
            {
                std::cout << "Exception: " << e.what() << std::endl;
            }
            //оповещение остальных потоков
            condition.notify_one();
            count--;
        }
    };
    thread.detach();
}
//ожидание добаления всех задач
void TaskScheduler::waitTasks()
{
    std::unique_lock<std::mutex> ulock(this->mutex);
    condition.wait(ulock, [this] { return this->count == 0; });
}
//деструктор
TaskScheduler::~TaskScheduler(){}

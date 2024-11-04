#include <iostream>
#include "TaskScheduler.h"

using namespace std;

int main(int argc, char* argv[])
{
    TaskScheduler TaskSchedular;
    time_t now = time(0);
    TaskSchedular.addTask(11, TaskSchedular.createTask, now + 5);
    TaskSchedular.addTask(22, TaskSchedular.createTask, now + 1);
    TaskSchedular.addTask(33, TaskSchedular.createTask, now + 3);
    TaskSchedular.waitTasks();
    return 0;
}
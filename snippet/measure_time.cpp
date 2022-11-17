#include <iostream>
#include <chrono>
#include <string>
#include <thread>

class MeasureTime
{
public:
    MeasureTime()
    {
        this->start = std::chrono::high_resolution_clock::now();
    }

    void stopMilliSecond(std::string &&message)
    {
        std::cout << message << " : " << std::chrono::duration_cast<std::chrono::milliseconds>(stopTimer() - this->start) << std::endl;
    }

    void stopMicroSecond(std::string &&message)
    {
        std::cout << message << " : " << std::chrono::duration_cast<std::chrono::microseconds>(stopTimer() - this->start) << std::endl;
    }

    void stopNanoSecond(std::string &&message)
    {
        std::cout << message << " : " << std::chrono::duration_cast<std::chrono::nanoseconds>(stopTimer() - this->start) << std::endl;
    }

    void startAgain()
    {
        this->start = std::chrono::high_resolution_clock::now();
    }

private:
    std::chrono::high_resolution_clock::time_point start;

    auto stopTimer() -> std::chrono::high_resolution_clock::time_point
    {
        return std::chrono::high_resolution_clock::now();
    }
};

int main()
{
    MeasureTime timer;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    timer.stopMilliSecond("10 second in millisecond");

    timer.startAgain();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    timer.stopMicroSecond("10 second in microsecond");

    timer.startAgain();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    timer.stopNanoSecond("10 second in nanosecond");

    return 0;
}
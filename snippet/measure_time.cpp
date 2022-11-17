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

    void stopMillisecond(std::string &&message)
    {
        std::cout << message << " : " << std::chrono::duration_cast<std::chrono::milliseconds>(stopTimer() - this->start) << std::endl;
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
    timer.stopMillisecond("10 second timer");

    return 0;
}
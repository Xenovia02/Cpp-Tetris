#include <iostream>
#include <cmath>
#include <thread>

#include "Frame.hpp"
#include "graphics.hpp"
#include "random.hpp"


constexpr std::size_t HEIGHT = 5;
constexpr std::size_t WIDTH = 5;


using namespace std::chrono_literals;


std::chrono::milliseconds operator "" _fps(unsigned long long int n)
{
    using rep = typename std::chrono::milliseconds::rep;
    return std::chrono::milliseconds(rep((n) ? std::ceil(1000.0 / n) : n));
}


int main()
{
    using namespace tetris;
    using std::string;
    using std::size_t;

    // make IO faster
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); // unties cout from cin
    std::cout.tie(nullptr); // unties cin from cout
    std::nounitbuf(std::cout); // disables automatic flushing

    Frame<HEIGHT, WIDTH> frame;
    frame.fill('0');

    for (size_t i = 0; i < HEIGHT; i++)
    {
        frame.downshift(make_rand_line<WIDTH>({ '|', '-' }));
    }

    size_t i = 0;
    for (char c = '0' ;; c++, i++)
    {
        display_frame(frame, 5_fps);
        frame.rotate();
    }
}


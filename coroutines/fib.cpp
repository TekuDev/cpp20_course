// g++ -std=c++23 -Wall -Wpedantic -O2 fib.cpp -o fib
// https://godbolt.org/

#include <generator>
#include <iostream>
#include <ranges>

std::generator<int> fib () {
    int prev = 0;
    int curr = 1;
    co_yield curr;

    for (;;) {
        int fut = prev+curr;
        co_yield fut;
        prev = curr;
        curr = fut;
    }
}

int main() {

    for (int num : fib() 
        | std::views::filter([](auto fibN) { return fibN % 2 == 0; })
        | std::views::take(5)) {
            std::cout << "FIB Number in line: " << num << std::endl;
    }
}
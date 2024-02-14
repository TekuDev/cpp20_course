#include <vector>
#include <iostream>
#include <ranges>
#include <algorithm>

void printVec(auto vec) {
    for (auto e : vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main () {
    auto even = [](const int n) { return n % 2 == 0; };
    auto square = [](const int n) { return n * n; };

    std::vector<int> vec = {1,4,3,9,6,11,8,2,15,21,30,10,5};
    std::cout << "Init Vector:" << std::endl;
    printVec(vec);

    auto out = vec | std::views::filter(even) | std::views::transform(square);

    auto out2 = vec | std::views::take(5) | std::views::reverse;

    std::cout << "Take even numbers and square them:" << std::endl;
    printVec(out);

    std::cout << "Take 5 first elements and reverse:" << std::endl;
    printVec(out2);

    auto evenNums = vec | std::views::filter(even);
    std::ranges::fill(evenNums, 42);
    std::cout << "Replace even numbers by 42:" << std::endl;
    printVec(vec);
}
#include <concepts>
#include <iostream>

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T Average(T x, T y) {
  return (x + y) / 2;
}

int main() {
    //std::cout << "Average(2, 17): " << Average(2, 17) << std::end;
    //std::cout << "Average(4.2f, 8.1f): " << Average(4.2f, 8.1f) << std::end;
    //std::cout << "Average(12.2, 22.4): " << Average(12.2, 22.4) << std::end;

    Average(2, 17);
    Average(4.2f, 8.1f);
    Average(12.2, 22.4);
    Average("hello", "world");
}
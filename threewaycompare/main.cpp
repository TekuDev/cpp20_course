#include <iostream>
#include <set>

struct Entity {
    int id;

    /*friend bool operator<(const Entity& l, const Entity& r) {
        return l.id < r.id;
    }*/
    auto operator<=>(const Entity& r) const = default;
};

class Adress {
    private:
    int street;
    int city;

    public:
    Adress(int s, int c) : street(s), city(c) {};
    auto operator<=>(const Adress&) const = default;
};

int main() {
    std::set<Entity> entities = {Entity(3), Entity(5)};
    std::set<Entity> entities2 = {Entity(5), Entity(5)};
    std::set<Adress> valueObjects{Adress({1, 1}), Adress({1, 1})};
    std::set<Adress> valueObjects2{Adress({2, 1}), Adress({1, 2})};
    std::set<Adress> valueObjects3{Adress({1, 2}), Adress({2, 1})};


    std:: cout << entities.size() << std::endl;
    std:: cout << entities2.size() << std::endl;
    std:: cout << valueObjects.size() << std::endl;
    std:: cout << valueObjects2.size() << std::endl;
    std:: cout << valueObjects3.size() << std::endl;

    std:: cout << "Result of 4 <=> 4" << std::endl;
    auto res = 4 <=> 4;
    std:: cout << "is_eq(res): " << is_eq(res) << std::endl;
    std:: cout << "is_lt(res): " << is_lt(res) << std::endl;
    std:: cout << "is_gteq(res): " << is_gteq(res) << std::endl;
}
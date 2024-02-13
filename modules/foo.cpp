module;
#include <iostream>
export module foo;

//export module foo;
//import <iostream>;

namespace training {
    export void hello() {
        std::cout << "Hello World!" << std::endl;
    }

    export int ret0() {
        return 0;
    }
}
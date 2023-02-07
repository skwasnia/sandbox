#include <iostream>

#include "interfaceTarget.hpp"
#include "publicTarget.hpp"
#include "publicTarget2.hpp"
// #include "privateTarget.hpp" // fatal error: No such file or directory

int main(int argc, char** argv){
    std::cout << "Hello World" << std::endl;
    std::cout << std::endl;
    std::cout << interfaceTarget::getDescription() << std::endl;
    std::cout << std::endl;
    std::cout << publicTarget::getDescription() << std::endl;
    std::cout << std::endl;
    std::cout << publicTarget2::getDescription() << std::endl;
    std::cout << std::endl;

    // error: ‘privateTarget’ has not been declared
    // std::cout << privateTarget::getDescription() << std::endl;

    return 0;
}

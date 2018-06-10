#include <iostream>

#include "yourlib/yourlib.hpp"

int main() {
    std::cout << "My example works!\n";
    nukle::Yourlib<int> obj;
    std::cout << obj.return_cstring();
    return 0;
}

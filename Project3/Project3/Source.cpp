#include <iostream>
using namespace std;
#include <iostream>

int main() {
    int x = 10, y = 20;
    std::cout << "x = " << x++ << " and y = " << --y << std::endl;
    std::cout << "x = " << x-- << " and y = " << ++y << std::endl;
    return(0);
}
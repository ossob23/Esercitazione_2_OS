#include <iostream>
#include "complex_number.hpp"
int main(){
    using com = complex_number<double>;
    com c1(1,3);
    com c2(1,6);
    std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
    std::cout<<c1<<" * "<<c2<<" = "<<c1*c2<<std::endl;
    com c3 = c1+c2;
    std::cout << "The coniugato of " << c3 << " is " << c3.coniugato() << "; ";
//    com c5 = com(3,4) + 2.0;
//    std::cout << "3/4 + 2 = " << c5 << std::endl;
}
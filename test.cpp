#include"heap.hpp"
#include<iostream>

int main(){
    heap test(10);

    std::cout << "Out " << test.size()<< "\n";
    double tinf = -INFINITY;
    std::cout << "truth val" << (tinf == -INFINITY) << "\n";
    test.print();

    test.insert(3);
    test.insert(5);
    test.insert(7);

    test.print();

    return 0;
}
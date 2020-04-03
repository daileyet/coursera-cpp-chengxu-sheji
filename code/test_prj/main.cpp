#include <iostream>
#include "ConstTester.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    //常量指针
    const ConstTester* ptr1 = new ConstTester;
//    can not change the object member value
//    ptr1->a = 1;
    ptr1 = new ConstTester;

    //指针常量
    ConstTester* const ptr2 = new ConstTester;
//    can not change to new address value
//    ptr2 = new ConstTester;

    return 0;
}

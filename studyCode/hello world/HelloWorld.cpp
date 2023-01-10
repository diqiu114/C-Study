//
// Created by DACHI on 2022/12/30.
//

#include "HelloWorld.h"
#include <iostream>

void HelloWorld::TestPrint()
{
    TestStruct Struct;
    std::cout << Struct.i << Struct.j;
    int *pInt = new int [10];
//    delete pInt; // 只释放指针指 向的单一对象
//    delete [] pInt; // 对象全部释放（所有析构调用一遍）
}

HelloWorld::HelloWorld()
{
    this->i = 0;
    std::cout << "HelloWorld::HelloWorld() ";
    std::cout << "i = " << this->i << std::endl;
}

HelloWorld::~HelloWorld()
{
    std::cout << "HelloWorld::~HelloWorld()";
    std::cout << "i = " << this->i << std::endl;
}

void HelloWorld::set(int i)
{
    this->i = i;
}

void HelloWorld::f()
{
    std::cout << this->i;
}

void HelloWorld::g(HelloWorld *p)
{
    std::cout << "HelloWorld::g(), q->i=" << p->i << std::endl;
}

#include <iostream>
#include "HelloWorld.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    HelloWorld *pHelloWorld = new HelloWorld[10];
    for(int i = 0; i < 10; i++) {
        pHelloWorld[i].set(i);
    }
    HelloWorld *pG = new HelloWorld;
    pG->g(&pHelloWorld[9]);
//    delete pHelloWorld;
    delete []pHelloWorld;
    return 0;
}

//
// Created by DACHI on 2022/12/30.
//

#ifndef HELLO_WORLD_HELLOWORLD_H
#define HELLO_WORLD_HELLOWORLD_H


class HelloWorld
{
public:
    HelloWorld();
    ~HelloWorld();

    int i;
    struct X; // 前向声明
    struct Y {
        void
    }

    void set(int i);
    void f();
    void g(HelloWorld *p); // 访问别人的对象私有内容
private:
    struct TestStruct {
        int i;
        int j;
    };

    void TestPrint();
};

#endif //HELLO_WORLD_HELLOWORLD_H

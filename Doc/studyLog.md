### 1. hello world

蛋图：

![image-20221227165229978](studyLog.assets/image-20221227165229978.png)

面向对象：

1. 基本原则：数据保护

经典面向对象的总结

![image-20221227170127692](studyLog.assets/image-20221227170127692.png)

1. 告诉做什么而不是怎么做
2. 对象里还是对象
3. 每个对象都有一些基本的东西比如类型
4. （正读反读）一个特定类型的所有对象可以接收相同的消息（所有可以接收相同消息的对象可以被认为相同的类型）
5. 隐藏细节
6. 

### 2. 成员变量的秘密

1. 头文件中的大部分是声明
2. 示例化的对象中的变量只存在与对象中，但是对象中的函数并不属于对象，c++编译器通过机制让函数能够识别到这个对象中的成员（类似this指针）

### 3. 构析和析构

1. c++为了高效，不对数据的初始化进行清除（java会进行，vs的debug会填充一些东西（正好对应国标码的“烫”）），
2. constructor：构造函数、构造器
   1. 和类名相同
   2. 无返回类型
   3. 无法阻止的被调用（一定被调用）



3. destructor：析构函数
4. 结构体也可以有构造函数
5. 

### 4. 对象初始化



### 5. new和delete

实际是c/c++的运行库帮忙做了事情，程序运行，操作系统会给一段内存给运行库自己管理，

不够了才会向操作系统申请

new一个对象时，运行库中有一张表，用来记录申请的信息（比如申请的内存大小）



new了不释放，容易造成内存泄漏





带方括号和不带方括号的区别：调用所有析构和不调用区别，但是申请的内存会一点不差的收回

```c++
    int *pInt = new int [10];
//    delete pInt; // 只释放指针指向的单一对象
//    delete [] pInt; // 对象全部释放（所有析构调用一遍）
```

```
int main()
{
    std::cout << "Hello, World!" << std::endl;
    HelloWorld *pHelloWorld = new HelloWorld[10];
    for(int i = 0; i < 10; i++) {
        pHelloWorld[i].set(i);
    }
//    delete pHelloWorld;
    delete []pHelloWorld;
    return 0;
}
```

```
信息输出，居然是从大到小的排列
HelloWorld::~HelloWorld()i = 9
HelloWorld::~HelloWorld()i = 8
HelloWorld::~HelloWorld()i = 7
HelloWorld::~HelloWorld()i = 6
HelloWorld::~HelloWorld()i = 5
HelloWorld::~HelloWorld()i = 4
HelloWorld::~HelloWorld()i = 3
HelloWorld::~HelloWorld()i = 2
HelloWorld::~HelloWorld()i = 1
HelloWorld::~HelloWorld()i = 0
```

### 6. 访问限制

**C++的oop特性只存在于源代码阶段**

#### public:所有都能访问

private:只有自己（自己：这个类的成员函数）能够访问，**这种权限的限制仅仅处于编译阶段**，所有这个私有是可以通过手段访问的，例如：

```
class HelloWorld
{
public:
    int i;
    HelloWorld();
    ~HelloWorld();

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
```

```
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
```

#### protected:自己和子类能够访问



#### Friends：

基本原则：我让你访问，你才能访问

例如Friend.cpp

#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;

class Test
{
public:
//    Test();
    virtual void f(){
        cout << "base f()" << endl;
    }
    virtual void b(){
        cout << "base x()" << endl;
    }
    virtual void d(){
        cout << "base x()" << endl;
    }
};

#endif // TEST_H

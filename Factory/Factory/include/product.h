#ifndef PROJECT
#define PROJECT

#include <iostream>
using namespace std;

//Product接口抽象类
class SoftProduct{
public:
    virtual void DisplayProduct() = 0;  //实现具体所需功能的接口
};


//ConcreteProduct具体产品类
class BankCard : public SoftProduct{
public:
    void DisplayProduct(){
        cout << "项目名称：" << "银行卡业务" << endl;
    }
};

class IDCard : public SoftProduct{
public:
    void DisplayProduct(){
        cout << "项目名称：" << "身份证业务" << endl;
    }
};

class DrivelCard : public SoftProduct{
public:
    void DisplayProduct(){
        cout << "项目名称：" << "驾驶证业务" << endl;
    }
};
#endif //PROJECT
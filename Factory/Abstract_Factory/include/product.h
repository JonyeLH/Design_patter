#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY

#include <iostream>
#include "factory.h"

using namespace std;

// 抽象产品类类 Television(电视机类)
class Television{
public:
    virtual ~Television(){};
    virtual void Show() const = 0;
};
  
//具体产品类 HaierTelevision（海尔电视机类）
class HaierTelevision : public Television{
public:
    void Show() const override{
        cout<<"I'm HaierTelevision"<<endl;
    }
};

//具体产品类 TCLTelevision（TCL电视机类）
class TCLTelevision : public Television{
public:
    void Show() const override{
        cout<<"I'm TCLTelevision"<<endl;
    }
};


// 抽象产品类  AirCondition（空调类）
class AirCondition{
public:
    virtual ~AirCondition(){};
    virtual void Show() const = 0;
};

//具体产品类 HairAirCondition(海尔空调类)
class HaierAirCondition : public AirCondition{
public:
    void Show() const override{
        cout<<"I'm HairAirCondition"<<endl;
    }
};

//具体产品类 TCLAirCondition(TCL空调类)
class TCLAirCondition : public AirCondition{
public:
    void Show() const override{
        cout<<"I'm TCLAirCondition"<<endl;
    }
};

#endif //ABSTRACT_FACTORY
#ifndef ABSTRACT_FACTORY_fac
#define ABSTRACT_FACTORY_fac

#include <iostream>
#include "product.h"
using namespace std;

// 抽象工厂类 EFactory(电器工厂类)
class EFactory{
public:
    virtual Television *CreateTelevision() const = 0;
    virtual AirCondition *CreateAirCondition() const = 0;
};

 //具体工厂类 HairFactory(海尔工厂类)
class HairFactory : public EFactory{
public:
    Television *CreateTelevision() const override{
        return new HaierTelevision();
    }  
    AirCondition *CreateAirCondition() const override{
        return new HaierAirCondition();
    }
};

 //具体工厂类 TCLFactory(TCL工厂类) 
class TCLFactory : public EFactory{
public:
    Television * CreateTelevision() const override{
        return new TCLTelevision();
    } 
    AirCondition * CreateAirCondition() const override{
        return new TCLAirCondition();
    }
};


#endif //ABSTRACT_FACTORY_fac
#include <iostream>
#include "factory.h"
using namespace std;


void ClientCode(const EFactory &factory){
    const Television *product_a = factory.CreateTelevision();
    const AirCondition *product_b = factory.CreateAirCondition();
    product_a->Show();
    product_b->Show();
    delete product_a;
    delete product_b;
}

int main(int argc, char *argv[]){
    std::cout << "生产海尔产品" << endl;
    EFactory *hairFactory = new HairFactory ();/*实例化工厂抽象类*/
    ClientCode(*hairFactory);
    delete hairFactory;
    std::cout << std::endl;

    std::cout << "生产TCL产品" << endl;
    EFactory *tCLFactory = new TCLFactory ();
    ClientCode(*tCLFactory);
    delete tCLFactory;
    return 0;
}
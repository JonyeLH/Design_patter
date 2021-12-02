#include <iostream>
#include <vector>
using namespace std;
  
typedef enum ProductTypeTag
{
  Hair,
  Hisense,
}PRODUCTTYPE;
  
//抽象产品类 TV(电视机类)
class TV{
public:
  virtual void Show() = 0;
};

//具体产品类 HairTV(海尔电视类)
class HairTV : public TV{
public:
  void Show(){
    cout<<"I'm HairTV "<<endl;
  }
};

//具体产品类 HisenseTV(海信电视类)  
class  HisenseTV : public TV{
public:
  void Show(){
    cout<<"I'm HisenseTV"<<endl;
  }
};
  
// 工厂类 TVFactory(电视机工厂类)
class TVFactory{
public:
  TV* CreateTV(PRODUCTTYPE type){
    switch (type){
    case Hair:
      return new HairTV();
  
    case Hisense:
      return new HisenseTV();
    default:
      return NULL;
    }
  }
};
  
int main(int argc, char *argv[])
{
  // 创建工厂类对象
    TVFactory *myTVFactory = new TVFactory();

    TV *hairTV = myTVFactory->CreateTV(Hair);
    if (hairTV != NULL){
        hairTV->Show();
    }

    TV *hisenseTV = myTVFactory->CreateTV(Hisense);
    if (hisenseTV != NULL){
        hisenseTV->Show();
    }
    
    delete  myTVFactory;
    myTVFactory = NULL;

    delete hairTV;
    hairTV = NULL;

    delete hisenseTV;
    hisenseTV = NULL;    
  
    return 0;
}
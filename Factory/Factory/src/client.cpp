#include <iostream>
#include "product.h"
#include "factory.h"
using namespace std;
 
int main()
{
	SoftProduct * pSoftProduct = NULL;
	
	//创建银行卡识别项目
	pSoftProduct = ProductFactory::CreateProduct("银行卡识别项目");
	pSoftProduct->DisplayProduct();
	delete pSoftProduct;
	pSoftProduct = NULL;
 
	//创建身份证识别项目
	pSoftProduct = ProductFactory::CreateProduct("身份证识别项目");
	pSoftProduct->DisplayProduct();
	delete pSoftProduct;
	pSoftProduct = NULL;
 
 	//创建驾驶证识别项目
 	pSoftProduct = ProductFactory::CreateProduct("驾驶证识别项目");
 	pSoftProduct->DisplayProduct();
 	delete pSoftProduct;
 	pSoftProduct = NULL;
 
	return 0;
}
#ifndef _PRODUCT_FACTORY_H_
#define _PRODUCT_FACTORY_H_
 
#include <iostream>
#include <string.h>
#include "product.h"
 
using namespace std;

//产品工厂
class ProductFactory
{
 
public:
	//静态方法，根据类型创建具体产品
	static SoftProduct * CreateProduct(string strProductName)
	{
		SoftProduct * pSoftProduct = NULL;
 
		if( 0 == strcmp(strProductName.c_str(), "银行卡识别项目") )
		{
			pSoftProduct = new BankCard();
		}
		else if( 0 == strcmp(strProductName.c_str(), "身份证识别项目") )
		{
			pSoftProduct = new IDCard();
		}
		else if( 0 == strcmp(strProductName.c_str(), "驾驶证识别项目") )
		{
			pSoftProduct = new DrivelCard();
		}
 
		return pSoftProduct;
	}
};
#endif
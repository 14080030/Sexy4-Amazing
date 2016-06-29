#include "stdafx.h"
#include <string>
using namespace std;
#include "Item.h"

//	初始化
Item::Item( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount )
{
	no = No;
	name = Name;
	price = Price;
	count = Count;
	discount = Discount;
	promotion = Promotion;
	vipdiscount = Vipdiscount;
}
//  获得商品编号
string Item::getNo( ){
	return no;
}
//  获得商品名
string Item::getName( ){
	return name;
}
//  获得单价
float &Item::getPrice( ){
	return price;
}
//  获得总数
int &Item::getCount( ){
	return count;
}
//  获得折扣
float &Item::getDiscount( ){
	return discount;
}
//	获得促销
bool &Item::getPromotion( ){
	return promotion;
}
//	获得会员折扣
float &Item::getVipdiscount( ){
	return vipdiscount;
}
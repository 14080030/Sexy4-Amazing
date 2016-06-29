#include "stdafx.h"
#include <string>
using namespace std;
#include "Item.h"

//	初始化
Item::Item( string No, string Name, float Price, int Count, float Discount )
{
	no = No;
	name = Name;
	price = Price;
	count = Count;
	discount = Discount;
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
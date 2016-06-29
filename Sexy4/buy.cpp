#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "buy.h"
#include "exception.h"

Buy::Buy(){
	headb = NULL;
	value = 0;
	dis = 0;
}

Buy::~Buy(){
	;
}

//	新增货品
void Buy::AddGoods( string No, string Name, float Price, float Discount,int Count, bool Promotion, float Vipdiscount ){
	node *p = new node;						//  创建链表节点
	p->commodity = new Goods;
	p->commodity->no = No;
	p->commodity->name = Name;
	p->commodity->price = Price;
	p->commodity->discount = Discount;
	p->commodity->count = Count;
	p->commodity->promotion = Promotion;
	p->commodity->vipdiscount = Vipdiscount;
	p->commodity->val = 0;
	p->next = headb;
	headb = p;								//	插入到链表头部	
	/*cout<<"新增完成！\n";*/
}
//  删除商品
void Buy::RemoveGoods( string No ){
	node *p, **q = &headb;					//  当前链表节点地址
	for( p=headb; p!=NULL; p=p->next ) 
	{
		if( p->commodity->no == No)
			break;							//	找到
 		if( p->next == NULL ) throw Exception("未找到该商品！");
		q = &p->next;	
	}
	*q = p->next;							//	删除链表节点
	delete p;								//	释放链表节点
	cout<<"删除成功！"<<endl;
}
//	计算货品总价和折扣
void Buy::Sum(){
	node *p;					// 当前链表节点地址
	float v;
	float d;
	for( p=headb; p!=NULL; p=p->next ) 
	{
		v = p->commodity->count*p->commodity->price;
		if(p->commodity->discount!=1){
			d = v*p->commodity->discount;
			if(p->commodity->vipdiscount == 1){
				p->commodity->val = d;
				dis = dis + (v-d);
				value = value + d;
			}
			else{
				p->commodity->val = d*p->commodity->vipdiscount;
				dis = dis + (v-(d/p->commodity->vipdiscount));
				value = value + p->commodity->val;
			}
		}
		else{
			if(p->commodity->promotion == true && p->commodity->count >= 2 ){
				dis = dis + p->commodity->price;
				p->commodity->val = p->commodity->count*p->commodity->price;
				value = value + p->commodity->val;
				p->commodity->count++;
			}
			if(p->commodity->promotion == false && p->commodity->vipdiscount == 1){
				p->commodity->val = p->commodity->count*p->commodity->price;
				value = value + p->commodity->val;
			}
			if(p->commodity->promotion == false && p->commodity->vipdiscount != 1){
				p->commodity->val = p->commodity->count*p->commodity->price*p->commodity->vipdiscount;
				dis = dis + ((p->commodity->val/p->commodity->vipdiscount) - p->commodity->val);
				value = value + p->commodity->val;
			}
		}
	}
}
//	输出清单
void Buy::outputGoods( ){
	node *p;
	int flag=0;
	for( p=headb; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<"名称："<<p->commodity->name<<",数量："<<p->commodity->count<<",单价："<<p->commodity->price<<"(元)，小计："<<p->commodity->val<<"(元)"<<endl;
		if(p->commodity->promotion == true && p->commodity->count>=2 ) flag=1;
	}
	if(flag == 1){
		cout<< "----------------------"<<endl;
		cout<< "挥泪赠送商品："<< endl;
		for( p=headb; p!=NULL; p=p->next ) {
			if( p->commodity->promotion == true ) cout<<"名称："<<p->commodity->name<<",数量：1"<<endl;
		}
	}
}
//	查找商品
int Buy::search( string No, int Cou ){
	node *p;								// 当前链表节点地址
	for( p=headb; p!=NULL; p=p->next ) {
			if( p->commodity->no == No ){
				p->commodity->count = p->commodity->count + Cou;
				return 1;
			}
	}
	if(p==NULL)	return 0;
}
//	获取总价
float Buy::getValue( ){
	return value;
}
//	获取折扣
float Buy::getDis( ){
	return dis;
}
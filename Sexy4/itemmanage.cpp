#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "exception.h"
#include "itemmanage.h"

ItemManage::ItemManage(){
	head = NULL;
	code = 123456;
}

ItemManage::~ItemManage(){
	;
}

//	新增商品
void ItemManage::Add( string No, string Name, float Price, int Count, float Discount ){
	node *p = new node;						//  创建链表节点
	p->commodity = new Item( No, Name, Price, Count, Discount);
	p->next = head;
	head = p;								//	插入到链表头部	
	/*cout<<"新增完成！\n";*/
}
//  删除商品
void ItemManage::Remove( string No )	{
	node *p, **q = &head;					//  当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No)
			break;							//	找到
 		if( p->next == NULL ) throw Exception("未找到该商品！");
		q = &p->next;	
	}
	*q = p->next;							//	删除链表节点
	delete p->commodity;					//	释放Item对象
	delete p;								//	释放链表节点
	cout<<"删除成功！"<<endl;
}
//	获得商品名
string ItemManage::getName( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	string name;
	name = p->commodity->getName();
	return name;
}
//	获得商品单价
float ItemManage::getPrice( string No){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	return p->commodity->getPrice();
}
//	获得商品数量
int ItemManage::getCount( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity ->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("无该人信息！");
	return p->commodity->getCount();
}
//	获得商品折扣
float ItemManage::getDiscount( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	return p->commodity->getDiscount();
	
}
//	获取密码
int ItemManage::getCode(){
	return code;
}
//	输出库存
void ItemManage::output( ){
	node *p;
	for( p=head; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(20)<<p->commodity->getNo()<<setw(20)<<p->commodity->getName()<<setw(20)<<p->commodity->getPrice()<<setw(20)<<p->commodity->getCount()<<endl;
	}
}
//	查找商品
bool ItemManage::search( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
		return true;						//	找到
	}
	if(p==NULL)	return false;
}
////	重载输出商品的信息，使对象输出能之间间隔等距
//ostream& operator<<(ostream&out,Item&g){
//	out<<setw(20)<<g.getNo()<<setw(20)<<g.getName()<<setw(20)<<g.getPrice()<<setw(20)<<g.getCount()<<endl;
//	return out;
//}
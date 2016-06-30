#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
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
void ItemManage::Add( string No, string Name, float Price, int Count, float Discount, bool Promotion , float Vipdiscount ){
	if(Promotion == true){
		if(Discount != 1 || Vipdiscount != 1 ){
			cout<<"新增失败，促销不能叠加！"<<endl;
			return;
		}
	}
	node *p = new node;						//  创建链表节点
	p->commodity = new Item( No, Name, Price, Count, Discount, Promotion, Vipdiscount );
	p->next = head;
	head = p;								//	插入到链表头部	
	//cout<<"新增完成！\n";
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
float &ItemManage::getPrice( string No){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	return p->commodity->getPrice();
}
//	获得商品总数
int &ItemManage::getCount( string No ){
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
float &ItemManage::getDiscount( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	return p->commodity->getDiscount();
	
}
//	获得促销
bool &ItemManage::getPromotion( string No ){
	node *p;								// 当前链表节点地址
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该商品！");
	return p->commodity->getPromotion();
}
//	获得会员折扣
float &ItemManage::getVipdiscount( string No ){
	node *p;								//	当前链表节点地址
	for( p=head; p!=NULL; p=p->next){
		if( p->commodity->getNo( ) == No )
			break;							//	找到
	}
	if( p == NULL ) throw Exception("未找到该商品！");
	return p->commodity->getVipdiscount();
}				
//	输出库存
void ItemManage::output( ){
	node *p;
	for( p=head; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->commodity->getNo()<<setw(12)<<p->commodity->getName();
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->commodity->getPrice()<<setw(12)<<p->commodity->getCount();
		if(p->commodity->getDiscount()==1) cout<<setw(12)<<"不打折";
		else cout<<(int)(p->commodity->getDiscount()*10)<<setw(11)<<"折";
		if(p->commodity->getPromotion() == false )cout<<setw(12)<<"不促销";
		else cout<<setw(12)<<"买2赠1";
		if(p->commodity->getVipdiscount()==1) cout<<setw(12)<<"不打折"<<endl;
		else cout<<(int)(p->commodity->getVipdiscount()*10)<<setw(11)<<"折"<<endl;
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
//	获取密码
int &ItemManage::getCode(){
	return code;
}
//	读取Goods文档
void ItemManage::readfile( ItemManage &I ){
	ifstream infile;
	infile.open("Goods.txt");
	if(infile){
		Goods G;
		while (!infile.eof()) {
			infile >> G.no >> G.name >> G.price >> G.count >> G.discount >> G.promotion >> G.vipdiscount;
			I.Add(G.no,G.name,G.price,G.count,G.discount,G.promotion,G.vipdiscount);
		}
	}
	else cout<<"读取文本失败！";
	infile.close();
}
//	保存Goods文档
void ItemManage::savefile( ItemManage &I ){
    ofstream  save("Goods.txt");
        if(!save)
        {
            cout<<"不能保存：Goods.txt！！ "<<endl;
            system("pause");
            exit(1);
        }
    Goods G;
	node *p;
	for(p = head; p != NULL; p = p->next){
		G.no = p->commodity->getNo();
		G.name = p->commodity->getName();
		G.price = p->commodity->getPrice();
		G.count = p->commodity->getCount();
		G.discount = p->commodity->getDiscount();
		G.promotion = p->commodity->getPromotion();
		G.vipdiscount = p->commodity->getVipdiscount();
		if(p->next != NULL){
			save << G.no << " " << G.name << " " << G.price << " " << G.count << " " << G.discount << " " << G.promotion << " " << G.vipdiscount << "\n";
		}
		else save << G.no << " " << G.name << " " << G.price << " " << G.count << " " << G.discount << " " << G.promotion << " " << G.vipdiscount;
    }
    save.close();
}
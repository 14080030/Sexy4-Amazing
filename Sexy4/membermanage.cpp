#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "exception.h"
#include "membermanage.h"

MemberManage::MemberManage( ){
	headm = NULL;
	code = 123456789;
}
MemberManage::~MemberManage( ){
	;
}
//	新增商品
void MemberManage::Add( string No, string Name, /*long Phoneno, */bool IsVip, int Point ){
	//if(Phoneno ==0 ){
	//	cout<<"手机号不能为空，添加失败！"<<endl;
	//	return;
	//}
	node *p = new node;						//  创建链表节点
	p->user = new Member( No, Name, /*Phoneno, */IsVip, Point );
	p->next = headm;
	headm = p;								//	插入到链表头部	
	//cout<<"新增完成！\n";
}
//  删除商品
void MemberManage::Remove( string No )	{
	node *p, **q = &headm;					//  当前链表节点地址
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No)
			break;							//	找到
 		if( p->next == NULL ) throw Exception("未找到该会员！");
		q = &p->next;	
	}
	*q = p->next;							//	删除链表节点
	delete p->user;							//	释放Item对象
	delete p;								//	释放链表节点
	cout<<"删除成功！"<<endl;
}
//	获得商品名
string &MemberManage::getName( string No ){
	node *p;								// 当前链表节点地址
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该会员！");
	string name;
	name = p->user->getName();
	return name;
}
////  获得手机号
//long &MemberManage::getPhoneno( string No ){
//	node *p;								// 当前链表节点地址
//	for( p=headm; p!=NULL; p=p->next ) 
//	{
//		if( p->user->getNo( )== No )
//			break;							//	找到
//	}
//	if(p==NULL) throw Exception("未找到该会员！");
//	return p->user->getPhoneno();
//}
//	获得身份
bool &MemberManage::getIsVip( string No ){
	node *p;								// 当前链表节点地址
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该会员！");
	return p->user->getIsVip();
}
//	获得积分
int &MemberManage::getPoint( string No ){
	node *p;								// 当前链表节点地址
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该会员！");
	return p->user->getPoint();	
}
//	结算积分
void MemberManage::sumPoint( string No, float Value ){
	node *p;
	int poi;								//	当前积分
	int a;									//	粗算
	int v;									//	可积分点数
	v = (int)(Value/5);
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	找到
	}
	if(p==NULL) throw Exception("未找到该会员！");
	else{
		poi = getPoint( No );
		if( poi <0 ) cout<<"该会员积分有误，请到客户服务台进行查询！";
		if( poi >=0 && poi <=200){
			a = poi + v;
			if( a > 200){
				cout<<"adfd";
				v = a - 201;
				a = 201 + (v*3);
				if(a > 500){
					v = (a - 501)/3;
					p->user->getPoint() = 501 + ( v*5 );
				}
				else p->user->getPoint() = a;
			}
			else p->user->getPoint() = a;
		}
		if( poi >200 && poi <=500 ){
			a = poi + ( v*3 );
			if( a >501 ){
				v = (a - 501)/3;
				p->user->getPoint() = 501 + ( v*5 );
			}
			else p->user->getPoint() = a;
		}
		if( poi >500 ) p->user->getPoint() = poi + ( v*5 );
	}
}
//	输出会员列表
void MemberManage::output( ){
	node *p;
	for( p=headm; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->user->getNo()<<setw(12)<<p->user->getName();
		cout<<setiosflags(ios::fixed)<<setprecision(2)/*<<setw(12)<<p->user->getPhoneno()*/<<setw(12)<<p->user->getIsVip();
	}
}
//	查找会员
bool MemberManage::search( string No ){
	node *p;								// 当前链表节点地址
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
		return true;						//	找到
	}
	if(p==NULL)	return false;
}
//	密码
int &MemberManage::getCode(){
	return code;
}
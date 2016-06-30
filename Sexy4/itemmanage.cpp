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
//	������Ʒ
void ItemManage::Add( string No, string Name, float Price, int Count, float Discount, bool Promotion , float Vipdiscount ){
	if(Promotion == true){
		if(Discount != 1 || Vipdiscount != 1 ){
			cout<<"����ʧ�ܣ��������ܵ��ӣ�"<<endl;
			return;
		}
	}
	node *p = new node;						//  ��������ڵ�
	p->commodity = new Item( No, Name, Price, Count, Discount, Promotion, Vipdiscount );
	p->next = head;
	head = p;								//	���뵽����ͷ��	
	//cout<<"������ɣ�\n";
}
//  ɾ����Ʒ
void ItemManage::Remove( string No )	{
	node *p, **q = &head;					//  ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No)
			break;							//	�ҵ�
 		if( p->next == NULL ) throw Exception("δ�ҵ�����Ʒ��");
		q = &p->next;	
	}
	*q = p->next;							//	ɾ������ڵ�
	delete p->commodity;					//	�ͷ�Item����
	delete p;								//	�ͷ�����ڵ�
	cout<<"ɾ���ɹ���"<<endl;
}
//	�����Ʒ��
string ItemManage::getName( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	string name;
	name = p->commodity->getName();
	return name;
}
//	�����Ʒ����
float &ItemManage::getPrice( string No){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getPrice();
}
//	�����Ʒ����
int &ItemManage::getCount( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity ->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("�޸�����Ϣ��");
	return p->commodity->getCount();
}
//	�����Ʒ�ۿ�
float &ItemManage::getDiscount( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getDiscount();
	
}
//	��ô���
bool &ItemManage::getPromotion( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getPromotion();
}
//	��û�Ա�ۿ�
float &ItemManage::getVipdiscount( string No ){
	node *p;								//	��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next){
		if( p->commodity->getNo( ) == No )
			break;							//	�ҵ�
	}
	if( p == NULL ) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getVipdiscount();
}				
//	������
void ItemManage::output( ){
	node *p;
	for( p=head; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->commodity->getNo()<<setw(12)<<p->commodity->getName();
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->commodity->getPrice()<<setw(12)<<p->commodity->getCount();
		if(p->commodity->getDiscount()==1) cout<<setw(12)<<"������";
		else cout<<(int)(p->commodity->getDiscount()*10)<<setw(11)<<"��";
		if(p->commodity->getPromotion() == false )cout<<setw(12)<<"������";
		else cout<<setw(12)<<"��2��1";
		if(p->commodity->getVipdiscount()==1) cout<<setw(12)<<"������"<<endl;
		else cout<<(int)(p->commodity->getVipdiscount()*10)<<setw(11)<<"��"<<endl;
	}
}
//	������Ʒ
bool ItemManage::search( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
		return true;						//	�ҵ�
	}
	if(p==NULL)	return false;
}
//	��ȡ����
int &ItemManage::getCode(){
	return code;
}
//	��ȡGoods�ĵ�
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
	else cout<<"��ȡ�ı�ʧ�ܣ�";
	infile.close();
}
//	����Goods�ĵ�
void ItemManage::savefile( ItemManage &I ){
    ofstream  save("Goods.txt");
        if(!save)
        {
            cout<<"���ܱ��棺Goods.txt���� "<<endl;
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
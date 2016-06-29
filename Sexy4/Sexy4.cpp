// Sexy4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#include "exception.h"
#include "itemmanage.h"
#include "buy.h"

void print();
void login(ItemManage S);
void mainmenu();
void submenu();
void listpre();
void listsuf();

int _tmain(int argc, _TCHAR* argv[])
{
	ItemManage s;
	login(s);
	system("cls");
	mainmenu();
	s.Add("ITEM000000","可口可乐",3.00,5000,1,true);
	s.Add("ITEM000001","雪碧",3.00,2000,0.8,false);
	s.Add("ITEM000002","电池",2.00,100,1,false);
	print();
	s.output();
	submenu();
	Buy b;
	string chose;
	string num;
	while(chose != "Y" && chose != "y"){
		cout<<"请输入您要购买的商品编号：";
		cin>>num;
		if(s.search(num) == false) cout<<"您输入的商品不存在！"<<endl;
		else{
			int cou;
			cout<<"请输入您要购买的数量：";
			cin>>cou;
			if(cou > s.getCount(num)) cout<<"超出剩余数量！"<<endl;
			if(cou <= s.getCount(num) && b.search( num, cou ) == 1) s.getCount(num) = s.getCount(num) - cou;
			if(cou <= s.getCount(num) && b.search( num, cou ) == 0){
				b.AddGoods( num, s.getName(num),s.getPrice(num),s.getDiscount(num),cou,s.getPromotion(num));
				s.getCount(num) = s.getCount(num) - cou;
			}

		}
		cout<<"是否进行结算(Y结算)：";
		cin>>chose;
	}
	b.Sum();
	system("cls");
	listpre();
	b.outputGoods();
	listsuf();
	cout<<b.getValue()<<"(元)"<<endl;
	if(b.getDis()!=0 ) cout<<"节省："<<b.getDis()<<"(元)"<<endl;
	cout<<"**********************"<<endl;
	system("pause");
	return 0;
}
//	登陆
void login(ItemManage S){
	int code,incode;
	code = S.getCode();
	cout<<"————超市收银系统————"<<endl;
	cout<<"请输入密码：";
	cin>>incode;
	while (incode!=code){
		cout<<"密码错误！！！"<<endl;
		cout<<"请输入密码：";
		cin>>incode;
	}
}
//	打印商品的抬头
void print(){
	string title[6];
	title[0]="商品编号"; 
	title[1]="商品名"; 
	title[2]="单价"; 
	title[3]="数量"; 
	title[4]="折扣";
	title[5]="是否促销";
	for(int i=0;i<6;i++){
		cout.width(14);
		cout<<left<<title[i];
	}
	cout<<endl;
}
//	主菜单
void mainmenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"\n";
	cout<<"********************************欢迎来到SEXY4商店******************************"<<endl;
	cout<<"--------------------------------本商店有如下商品-------------------------------"<<endl;
}
//	副菜单
void submenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"*  *祝您购物愉快！                                                            *"<<endl;
	cout<<"*******************************************************************************"<<endl;
}
//	购物清单
void listpre(){
	cout<<"***商店购物清单***"<<endl;
	time_t t;
	time ( &t );
	cout<<"打印时间: "<<ctime(&t);
	cout<<"----------------------"<<endl;
}
void listsuf(){
	cout<<"----------------------"<<"\n"<<"总计：";
}
#include "stdafx.h"
#include <string>
using namespace std;
#include "member.h"

//	初始化
Member::Member( string No, string Name, /*long Phoneno, */bool IsVip, int Point )
{
	no = No;
	name = Name;
	//phoneno = Phoneno;
	isVip = IsVip;
	point = Point;
}
//  获得会员编号
string Member::getNo( ){
	return no;
}
//  获得会员名
string &Member::getName( ){
	return name;
}
////  获得手机号
//long &Member::getPhoneno( ){
//	return phoneno;
//}
//	获得身份
bool &Member::getIsVip( ){
	return isVip;
}
//	获得积分
int &Member::getPoint( ){
	return point;
}
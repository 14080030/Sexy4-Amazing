#include <string>
using namespace std;
class Member{
	string  no;			//  会员编号
	string name;		//  会员名
	//long phoneno;		//  手机号
	bool isVip;			//	身份
	int point;			//	积分
public:
	Member( string No, string Name, /*long Phoneno, */bool IsVip, int point );
								//	构造函数用于创建对象、初始化属性
	string getNo( );			//  获得会员编号
    string &getName( );			//  获得会员名
    //long &getPhoneno( );		//  获得手机号
	bool &getIsVip( );			//	获得身份
	int &getPoint( );			//	获得积分
};
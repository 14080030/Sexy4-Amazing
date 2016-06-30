#include "member.h"
class MemberManage{
    struct node{
		Member *user;
		node *next;
	} *headm;									//  链表表头指针
	int code;
public:
	MemberManage( );
	~MemberManage( );							//  完全隐蔽Member对象
    void Add( string No, string Name, /*long Phoneno, */bool IsVip,int point );
												//	新增会员
    void Remove( string No );					//	删除会员 
    string &getName( string No );				//	获得会员名
    //long &getPhoneno( string No );				//  获得手机号
	bool &getIsVip( string No );				//	获得身份
	int &getPoint( string No );					//	获得积分
	void sumPoint( string No, float Value );	//	结算积分
	void output( );								//	输出会员列表
	bool search( string No );					//	查找会员
	int &getCode();								//	密码
};
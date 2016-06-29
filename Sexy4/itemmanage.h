#include "item.h"
class ItemManage{
    struct node{
		Item *commodity;
		node *next;
	} *head;									//  链表表头指针
	int code;
public:
	ItemManage( );
	~ItemManage( );								//  完全隐蔽Item对象
    void Add( string No, string Name, float Price, int Count, float Discount );
												//	新增商品
    void Remove( string No );					//	删除商品 
    string getName( string No );				//	获得商品名
    float getPrice( string No );				//  获得单价
    int getCount( string No );					//  获得总数
    float getDiscount( string No );				//  获得折扣
	void output( );								//	输出库存
	bool search( string No );					//	查找商品
	int getCode();								//	密码
	//friend ostream & operator<<(ostream&,Item&);//	重载输出商品的信息
};
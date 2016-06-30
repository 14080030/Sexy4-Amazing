#include <string>
using namespace std;
class Buy{
	struct Goods{
		string  no;			//  商品编号
		string name;		//  商品名
		float price;		//  单价
		float discount;		//  折扣
		float vipdiscount;	//	会员折扣
		bool promotion;		//	促销
		int count;			//	购买数量
		float val;			//	小计
	};
	struct node{
		Goods*commodity;
		node *next;
	} *headb;
	float value;		//	总价
	float dis;			//	折价
public:
	Buy( );
	~Buy( );
    void AddGoods( string No, string Name, float Price, float Discount, int Count, bool Promotion, float Vipdiscount );
													//	新增货品
    void RemoveGoods( string No );					//	删除货品 
    void Sum( bool IsVip );							//	计算货品总价
	void outputGoods( );							//	输出清单
	int search( string No, int Cou );				//	查找商品
	float getValue( );								//	获取总价
	float getDis( );								//	获取折扣
};

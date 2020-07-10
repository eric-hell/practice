#include<graphics.h>
#include<Windows.h>
#include<math.h>
void Cirni(int X1, int Y1, int X2, int Y2, int X3, int Y3);
void Cirshun(int X1, int Y1, int X2, int Y2, int X3, int Y3);
void Cirthree(int X1, int Y1, int X2, int Y2, int X3, int Y3);
double HuDu(int x0, int y0, int x1, int y1);
int main(void) {
	//初始化图形
	initgraph(800,450);
	//设置背景为白色
	setbkcolor(RGB(255,255,255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	





	system("pause");
	return 0;
}
/// <summary>
/// 三点画圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirthree(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	//判断第一个点与第二个点的位置，确定是顺时针画还是逆时针画
	//一三象限逆时针
	if (((X2-X1)>0&&(Y2-Y1)>0)||((X2 - X1) < 0 && (Y2 - Y1) < 0)) {
		Cirni( X1,  Y1,  X2,  Y2,  X3,  Y3);
	}
	//二四象限顺时针
	if (((X2 - X1) < 0 && (Y2 - Y1) > 0) || ((X2 - X1) > 0 && (Y2 - Y1) < 0)) {
		Cirshun(X1, Y1, X2, Y2, X3, Y3);
	}
}
/// <summary>
/// 三点画逆时针圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirni(int X1,int Y1, int X2, int Y2, int X3, int Y3) {
	//求圆心
	//求L1  点斜式求交点
	int m = (X2-X1) / (Y1-Y2);
	int p = (X2+X1) / 2;
	int q = (Y2+Y1) / 2;
	int n = (X3-X2) / (Y2-Y3);
	int w = (X3+X2) / 2;
	int v = (Y3+Y2) / 2;//以上为过渡变量，解析后的结果
	//x和y为圆心坐标
	int x = (-m*p+q-v+n*w) / (n-m);
	int y = n * (x - w) + v;
	//求半径
	double r =sqrt(pow((X1-x),2)+ pow((Y1 - y), 2)) ;
	//求弧度需要分四个象限进行求 以圆心为原点 判断点相对于圆点的符号
	//画圆弧
	double hudu1 = HuDu(x, y, X1, Y1);//start hudu
	double hudu2 = HuDu(x, y, X3, Y3);//end hudu

	arc(x-r,y-r,x+r,y+r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// 三点画顺时针圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirshun(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	//求圆心
	//求L1  点斜式求交点
	int m = (X2 - X1) / (Y1 - Y2);
	int p = (X2 + X1) / 2;
	int q = (Y2 + Y1) / 2;
	int n = (X3 - X2) / (Y2 - Y3);
	int w = (X3 + X2) / 2;
	int v = (Y3 + Y2) / 2;//以上为过渡变量，解析后的结果
	//x和y为圆心坐标
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//求半径
	double r = sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//求弧度需要分四个象限进行求 以圆心为原点 判断点相对于圆点的符号
	//画圆弧
	double hudu1 = -HuDu(x, y, X1, Y1);//start hudu
	double hudu2 = -HuDu(x, y, X3, Y3);//end hudu

	arc(x - r, y - r, x + r, y + r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// 求弧度值
/// </summary>
/// <param name="x0">圆心横坐标</param>
/// <param name="y0">圆心纵坐标</param>
/// <param name="x1">点横坐标</param>
/// <param name="y1">点纵坐标</param>
/// <returns>弧度值</returns>
double HuDu(int x0,int y0,int x1,int y1) {
	const double PI = acos(-1);
	if ((x1 > x0) && (y1==y0))//x+轴上
	{
		double hudu = 0.0;
		return hudu;
	}
	if ((x1 <x0) && (y1==y0))//x-轴上
	{
		double hudu =  PI;
		return hudu;
	}
	if ((x1==x0) && (y1 >y0))//y+轴上
	{
		double hudu =PI / 2;
		return hudu;
	}
	if ((x1==x0) &&(y1< y0))//y-轴上
	{
		double hudu =PI * 3 / 2;
		return hudu;
	}
	if ((x1 > x0 )&& (y1 > y0 ))//第一象限内
	{
		double hudu= atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if ((x1 < x0) && (y1 > y0))//第二象限内
	{
		double hudu =PI-atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 < y0)));//第三象限内
	{
		double hudu = 3*(acos(-1))/2 - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if ((x1 > x0) && (y1 < y0))//第四象限内
	{
		double hudu =2*PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
}
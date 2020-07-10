#include<graphics.h>
#include<Windows.h>
#include<math.h>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3, double rongcha);
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double rongcha);
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3,double rongcha);
double HuDu(double x0, double y0, double x1, double y1);
void drawrabbit(double x, double y, double scale);
POINT convert(double x, double y, double X, double Y);
int main(void) {
	//初始化图形
	initgraph(800, 450);
	//设置背景为白色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	//画头部弧  X=0.438米  Y=0.484米  X=0.432米  Y=0.576米  X=0.383米  Y=0.653米 
	int x=  convert(258, 519, 400, 225).x;
	int y = convert(258, 519, 400, 225).y;
	double m = atan((136.0-263.0)/(520.0-385.0));
	double n = atan((136.0 - 263.0) / (520.0 - 385.0));
	drawrabbit(400,225,1.0);



	system("pause");
	return 0;
}
/// <summary>
/// 三点画圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3,double rongcha) {
	//判断第一个点与第二个点的位置，确定是顺时针画还是逆时针画
	//一三象限顺时针
	if (((X2 - X1) > 0 && (Y2 - Y1) > 0) || ((X2 - X1) < 0 && (Y2 - Y1) < 0)) {
		Cirshun(X1, Y1, X2, Y2, X3, Y3,rongcha);
	}
	//二四象限逆时针
	if (((X2 - X1) > 0 && (Y2 - Y1) < 0) || ((X2 - X1) < 0 && (Y2 - Y1) > 0)) {
		Cirni(X1, Y1, X2, Y2, X3, Y3,rongcha);
	}
}
/// <summary>
/// 三点画逆时针圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3,double rongcha) {
	//求圆心
	//求L1  点斜式求交点
	double m =(double)(X2-X1) / (Y1-Y2);//3.833333333
	double p =(double)(X2 + X1) / 2;//339.5
	double q =(double)(Y2 + Y1) / 2;//84
	double n =(double)(X3-X2) / (Y2-Y3);//1.75
	double w =(double)(X3 + X2) / 2;//317.5
	double v =(double)(Y3 + Y2) / 2;//93 以上为过渡变量，解析后的结果
	//x和y为圆心坐标
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//求半径
	double r =(double)sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//求弧度需要分四个象限进行求 以圆心为原点 判断点相对于圆点的符号
	//画圆弧  由于测量坐标与绘图坐标坐标轴不同，弧度相差π/2
	double hudu1 = HuDu(x, y, X1, Y1)-rongcha;//start hudu
	double hudu2 = HuDu(x, y, X3, Y3) +rongcha;//end hudu
	double hudu3 = 0.0;
	if (hudu1>hudu2)
	{
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}
	arc(x + r, y + r, x - r, y - r, hudu1, hudu2 );
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// 三点画顺时针圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double rongcha) {
	//求圆心
	//求L1  点斜式求交点
	double m = (double)(X2 - X1) / (Y1 - Y2);
	double p = (double)(X2 + X1) / 2;
	double q = (double)(Y2 + Y1) / 2;
	double n = (double)(X3 - X2) / (Y2 - Y3);
	double w = (double)(X3 + X2) / 2;
	double v = (double)(Y3 + Y2) / 2;//以上为过渡变量，解析后的结果
	//x和y为圆心坐标
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//求半径
	double r = (double)sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//求弧度需要分四个象限进行求 以圆心为原点 判断点相对于圆点的符号
	//画圆弧  由于测量坐标与绘图坐标坐标轴不同，弧度相差π/2
	double hudu1 = HuDu(x, y, X1, Y1) - rongcha;//start hudu
	double hudu2 = HuDu(x, y, X3, Y3) +rongcha;//end hudu
	double hudu3 = 0.0;
	if (hudu1 > hudu2)
	{
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}
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
double HuDu(double x0, double y0, double x1, double y1) {
	const double PI = acos(-1);
	x0 = (double)x0;
	y0 = (double)y0;
	x1 = (double)x1;
	y1 = (double)y1;
	if ((x1 > x0) && (y1 == y0))//x+轴上
	{
		double hudu = 0.0;
		return hudu;
	}
	if ((x1 < x0) && (y1 == y0))//x-轴上
	{
		double hudu = PI;
		return hudu;
	}
	if ((x1 == x0) && (y1 > y0))//y+轴上
	{
		double hudu = PI / 2;
		return hudu;
	}
	if ((x1 == x0) && (y1 < y0))//y-轴上
	{
		double hudu = PI * 3 / 2;
		return hudu;
	}
	if ((x1 > x0) && (y1 <y0))//第一象限内
	{
		double hudu =(double)atan((y1 - y0) / (x0 - x1));
		return hudu;
	}
	if ((x1 < x0) && (y1 < y0))//第二象限内
	{
		double hudu =PI-atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 > y0)));//第三象限内
	{
		double hudu = (double)3 * (acos(-1)) / 2 - atan(abs((int)((y1 - y0) / (x1 - x0))));
		return hudu;
	}
	if ((x1 > x0) && (y1 > y0))//第四象限内
	{
		double hudu = (double)2 * PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
}
/// <summary>
/// 绘制兔子图形
/// </summary>
/// <param name="x">鼻子中心的横坐标</param>
/// <param name="y">鼻子中心的纵坐标</param>
/// <param name="scale">缩放大小</param>
void drawrabbit(double x, double y, double scale) {
	const int delay = 500;
	//设置线型
	setlinestyle(PS_SOLID, 5);
	//设置线色
	setlinecolor(RGB(10, 10, 10));

	//绘制左边耳朵    X=0.455米  Y=0.464米  X=0.414米  Y=0.351米
	line((int)convert(455,464,x,y).x, convert(455, 464, x, y).y, convert(414, 351, x, y).x, convert(414, 351, x, y).y);
	Sleep(delay);
	// X=0.414米  Y=0.351米  X=0.506米  Y=0.454米
	line(convert(414, 351, x, y).x, convert(414, 351, x, y).y, convert(506, 454, x, y).x, convert(506, 454, x, y).y);
	Sleep(delay);
	// X=0.506米  Y=0.454米  X=0.438米  Y=0.484米
	line(convert(506, 454, x, y).x, convert(506, 454, x, y).y, convert(438, 484, x, y).x, convert(438, 484, x, y).y);
	Sleep(delay);
	//X=0.445米  Y=0.436米  X=0.420米  Y=0.440米
	line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	Sleep(delay);
	//X=0.451米  Y=0.453米   X=0.432米  Y=0.461米
	line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	Sleep(delay);

	//绘制右边耳朵 X=0.386米  Y=0.681米 X=0.283米  Y=0.747米
	line(convert(386, 681, x, y).x, convert(386, 681, x, y).y, convert(283, 747, x, y).x, convert(283, 747, x, y).y);
	Sleep(delay);
	// X=0.283米  Y=0.747米  X=0.419米  Y=0.718米
	line(convert(283, 747, x, y).x, convert(283,747, x, y).y, convert(419, 718, x, y).x, convert(419, 718, x, y).y);
	Sleep(delay);
	// X=0.419米  Y=0.718米 X=0.383米  Y=0.653米
	line(convert(419, 718, x, y).x, convert(419, 718, x, y).y, convert(383, 653, x, y).x, convert(383, 653, x, y).y);
	Sleep(delay);
	//X=0.378米  Y=0.686米 X=0.365米  Y=0.665米 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	Sleep(delay);
	// X=0.362米  Y=0.696米 X=0.341米  Y=0.676米
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	Sleep(delay);	

	//画头部弧  X=0.438米  Y=0.484米  X=0.432米  Y=0.461米  X=0.420米  Y=0.440米 
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,0.0);
	Sleep(delay);
	// X=0.420米  Y=0.440米  X=0.389米  Y=0.408米   X=0.351米  Y=0.388米 
	Cirthree(convert(420, 440, x, y).x, convert(420, 440, x, y).y, convert(389, 408, x, y).x, convert(389, 408, x, y).y, convert(351, 388, x, y).x, convert(351, 388, x, y).y,0.1);
	Sleep(delay);
	// X=0.438米  Y=0.484米  X=0.432米  Y=0.576米  X=0.383米  Y=0.653米
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 576, x, y).x, convert(432, 576, x, y).y, convert(383, 653, x, y).x, convert(383, 653, x, y).y, 0.0);
	Sleep(delay);
	//

}
POINT  convert(double x, double y, double X, double Y) {
	//第一步计算水平和竖值方向绝对距离
	//设置坐标参考点
	//X=0.294米  Y=0.533米
	const int x0 = 294;
	const int y0 = 533;
	int xx=0, yy=0;
	int distancesz = abs((int)x-x0);//计算竖直方向距离
	int distancesp = abs((int)y-y0);//计算水平方向距离
	//第二步判断相对方位
	//第一象限
	if (((x-x0 ) > 0 && (y-y0) > 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//第二象限
	if ((x-x0)>0 && (y-y0)<0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//第三象限
	if ((x-x0) < 0 && (y-y0) < 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//第四象限
	if ((x-x0) < 0 && (y-y0) > 0)
	{
		xx = X + distancesp;
		yy = Y + distancesz;
	}
	//第三步，确定转换后的坐标值
		POINT pt[1];
		pt[0] = { xx,yy };
		return pt[0];
}

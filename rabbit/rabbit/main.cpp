#include<graphics.h>
#include<Windows.h>
#include<math.h>
#include<string>
#include<iostream>
#include <conio.h>
using namespace std;
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
double HuDu(double x0, double y0, double x1, double y1);
double Cross(double X1, double Y1, double X2, double Y2, double X3, double Y3);
void drawrabbit(double x, double y, double scale);
double angle_to_radian(double degree, double min, double second);
POINT convert(double x, double y, double X, double Y);
int BoundaryFill(int x, int y, COLORREF rgb);
void FillLeftEar(int x, int y, COLORREF rgb);
void FillRightEar(int x, int y, COLORREF rgb);
void FillCarrot(int x, int y, COLORREF rgb);
void FillLeaf(int x, int y, COLORREF rgb);
void FillCheeks(int x, int y, COLORREF rgb);
void FillEyes(int x, int y, COLORREF rgb);
void FillNose(int x, int y, COLORREF rgb);
void FillMouth(int x, int y, COLORREF rgb);
void FillFoots(int x, int y, COLORREF rgb);
void SetColorCard(int x, int y);
void GameStart(int x,int y);
void DelText();
int main(void) {
	//初始化图形
	initgraph(1200, 700);
	//设置背景为白色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	//setlinecolor(RGB(255, 0, 0));
	////画头部弧  X=0.438米  Y=0.484米  X=0.432米  Y=0.576米  X=0.383米  Y=0.653米 
	/*int x = convert(294, 533, 400, 225).x;
	int y = convert(294, 533, 400, 225).y;*/
	//double m = atan((136.0-263.0)/(520.0-385.0));
	//double n = atan((136.0 - 263.0) / (520.0 - 385.0));
	//FillCheeks(400, 225, 254, 204, 203);
	//Sleep(10000);
	drawrabbit(300, 300, 1);
	SetColorCard(600,50);
	GameStart(300,300);

	system("pause");
	return 0;
}
/// <summary>
/// 三点画圆弧
/// </summary>
/// <param name="X1">第一个点横坐标</param>
/// <param name="Y1">第一个点纵坐标</param>
/// <param name="X2">第二个点横坐标</param>
/// <param name="Y2">第二个点纵坐标</param>
/// <param name="X3">第三个点横坐标</param>
/// <param name="Y3">第三个点纵坐标</param>
/// <param name="hudu1">起始弧度</param>
/// <param name="hudu2">结束弧度</param>
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
	//判断第一个点与第二个点的位置，确定是顺时针画还是逆时针画
	//一三象限顺时针
	if (Cross(X1, Y1, X2, Y2, X3, Y3) > 0)
	{
		Cirshun(X1, Y1, X2, Y2, X3, Y3, hudu1, hudu2);
	}
	if (Cross(X1, Y1, X2, Y2, X3, Y3) < 0)
	{
		Cirni(X1, Y1, X2, Y2, X3, Y3, hudu1, hudu2);
	}

	//int quadrant1 = 0;//第二点相对于第一个点的象限位置
	//int quadrant2 = 0;//第三个点相对于第二个点的象限位置
	////确定前两个点相对象限位置
	//if (((X2 - X1) > 0 && (Y2 - Y1) < 0))
	//{
	//	quadrant1 = 1;
	//}
	//if ((X2 - X1) < 0 && (Y2 - Y1) < 0)
	//{
	//	quadrant1 = 2;
	//}
	//if (((X2 - X1) < 0 && (Y2 - Y1) > 0))
	//{
	//	quadrant1 = 3;
	//}
	//if (((X2 - X1) > 0 && (Y2 - Y1) > 0))
	//{
	//	quadrant1 = 4;
	//}
	////确定后两个点相对象限位置
	//if (((X3 - X2) > 0 && (Y3 - Y2) < 0))
	//{
	//	quadrant2 = 1;
	//}
	//if ((X3 - X2) < 0 && (Y3 - Y2) < 0)
	//{
	//	quadrant2 = 2;
	//}
	//if (((X3 - X2) < 0 && (Y3 - Y2) > 0))
	//{
	//	quadrant2 = 3;
	//}
	//if (((X3 - X2) > 0 && (Y3 - Y2) > 0))
	//{
	//	quadrant2 = 4;
	//}

	//if (quadrant1==1&&quadrant2==1|| quadrant1 == 2 && quadrant2 == 1 
	//	|| quadrant1 == 2 && quadrant2 == 4
	//	|| quadrant1 == 3 && quadrant2 == 2 || quadrant1 == 3 && quadrant2 == 3 || quadrant1 == 4 && quadrant2 == 3
	//	|| quadrant1 == 4 && quadrant2 == 4) {
	//	Cirshun(X1, Y1, X2, Y2, X3, Y3,rongcha);
	//}
	////二四象限逆时针
	//if (quadrant1 == 1 && quadrant2 == 2 || quadrant1 ==1  && quadrant2 == 3
	//	|| quadrant1 == 1 && quadrant2 == 4 || quadrant1 == 2 && quadrant2 == 2
	//	|| quadrant1 == 2 && quadrant2 == 3 || quadrant1 == 3 && quadrant2 == 1
	//	|| quadrant1 == 3 && quadrant2 == 4
	//	|| quadrant1 == 4 && quadrant2 == 1 || quadrant1 == 4 && quadrant2 == 2) {
	//	Cirni(X1, Y1, X2, Y2, X3, Y3,rongcha);
	//}
}
/// <summary>
/// 三点逆时针绘制圆弧
/// </summary>
/// <param name="X1">第一个点的X</param>
/// <param name="Y1">第一个点的Y</param>
/// <param name="X2">第二个点的X</param>
/// <param name="Y2">第二个点的Y</param>
/// <param name="X3">第三个点的X</param>
/// <param name="Y3">第三个点的Y</param>
/// <param name="hudu1">起始弧度</param>
/// <param name="hudu1">结束弧度弧度</param>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
	//求圆心
	//求L1  点斜式求交点
	double m = (double)(X2 - X1) / (Y1 - Y2);//3.833333333
	double p = (double)(X2 + X1) / 2;//339.5
	double q = (double)(Y2 + Y1) / 2;//84
	double n = (double)(X3 - X2) / (Y2 - Y3);//1.75
	double w = (double)(X3 + X2) / 2;//317.5
	double v = (double)(Y3 + Y2) / 2;//93 以上为过渡变量，解析后的结果
	//x和y为圆心坐标
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//求半径
	double r = (double)sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	/*double hudu3 = 0.0;
	if (hudu1 > 2 * acos(-1) && hudu1 > hudu2)
	{
		hudu1 -= 2 * acos(-1);
	}*/
	/*if (hudu1 >= hudu2)
	{
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}*/
	//求弧度需要分四个象限进行求 以圆心为原点 判断点相对于圆点的符号
	//画圆弧  由于测量坐标与绘图坐标坐标轴不同，弧度相差π/2
	//double hudu1 = HuDu(x, y, X1, Y1)+rongcha;//start hudu
	//double hudu2 = HuDu(x, y, X3, Y3) -rongcha;//end hudu
	//double hudu3 = 0.0;
	if (hudu1 >= hudu2)
	{
		hudu2 += 2 * acos(-1);
	}
	////else//弧度大还要逆时针转那就小角加2π喽
	////{
	////	hudu3 = hudu1;
	////	hudu1 = hudu2;
	////	hudu2 = hudu3 + 2 * acos(-1);

	////}
	arc(x + r, y + r, x - r, y - r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// 三点逆时针绘制圆弧
/// </summary>
/// <param name="X1">第一个点的X</param>
/// <param name="Y1">第一个点的Y</param>
/// <param name="X2">第二个点的X</param>
/// <param name="Y2">第二个点的Y</param>
/// <param name="X3">第三个点的X</param>
/// <param name="Y3">第三个点的Y</param>
/// <param name="hudu1">起始弧度</param>
/// <param name="hudu1">结束弧度弧度</param>
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
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
	//画圆弧 
	//double hudu1 =HuDu(x, y, X1, Y1) - rongcha;//start hudu
	//double hudu2 =HuDu(x, y, X3, Y3) +rongcha;//end hudu
	double hudu3 = 0.0;
	if (hudu1 >= hudu2)
	{
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}
	/*if ((hudu2-(int)(hudu1/ acos(-1))* acos(-1))>0) {
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}*/
	else//弧度小还要顺时针转那就小角加2π喽
	{
		hudu2 -= 2 * acos(-1);
		hudu3 = hudu1;
		hudu1 = hudu2;
		hudu2 = hudu3;
	}
	arc(x - r, y - r, x + r, y + r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// 方位角角度转弧度
/// </summary>
/// <param name="degree">度数</param>
/// <param name="min">分数</param>
/// <param name="second">秒数</param>
/// <returns></returns>
double angle_to_radian(double degree, double min, double second)
{
	//450度减去x才是实际度数
	double Tsecond = degree * 3600 + min * 60 + second;//总秒数
	int Ysecond = 450 * 3600 - Tsecond;//剩余总秒数
	second = Ysecond % 60;
	min = ((int)(Ysecond - second) % 3600) / 60;
	degree = (Ysecond - min * 60 - second) / 3600;
	double flag = (degree < 0) ? -1.0 : 1.0;			//判断正负
	if (degree < 0)
	{
		degree = degree * (-1.0);
	}
	double angle = degree + min / 60 + second / 3600;
	double result = flag * (angle * acos(-1)) / 180;
	/*if (result>2* acos(-1))
	{
		result -= acos(-1);
	}*/
	return result;
	//cout<<result<<endl;
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
	if ((x1 > x0) && (y1 < y0))//第一象限内
	{
		double hudu = (double)atan((y1 - y0) / (x0 - x1));
		return hudu;
	}
	if ((x1 < x0) && (y1 < y0))//第二象限内
	{
		double hudu = PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 > y0)))//第三象限内
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
	setaspectratio(scale,scale);
	const int delay = 100;
	setlinestyle(PS_SOLID, 5);
	//设置线色
	setlinecolor(RGB(10, 10, 10));
	//先绘制颜色填充的
	//左边耳朵
	//setlinestyle(PS_SOLID, 5);
	////设置线色
	//setlinecolor(RGB(255, 209, 208));
	////直线 X=0.445米  Y=0.436米    X=0.451米  Y=0.453米 
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
	////X=0.445米  Y=0.436米  X=0.420米  Y=0.440米
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	////X=0.451米  Y=0.453米   X=0.432米  Y=0.461米
	//line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	////X = 0.432米  Y = 0.461米 X=0.427米  Y=0.451米 X=0.420米  Y=0.440米 338度16分33.76秒 320度18分27.11秒
	//Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
	//	angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
	////填充颜色 X=0.437米  Y=0.447米 
	//BoundaryFill(convert(437, 447, x, y).x, convert(437, 447, x, y).y,255,209,208);
	////设置线型
	//setlinestyle(PS_SOLID, 5);
	////设置线色
	//setlinecolor(RGB(10, 10, 10));
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
	////X=0.445米  Y=0.436米  X=0.420米  Y=0.440米
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	////X=0.451米  Y=0.453米   X=0.432米  Y=0.461米
	//line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	////X = 0.432米  Y = 0.461米 X=0.427米  Y=0.451米 X=0.420米  Y=0.440米 338度16分33.76秒 320度18分27.11秒
	//Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
	//	angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));


	//绘制左边耳朵    X=0.455米  Y=0.464米  X=0.414米  Y=0.351米
	line((int)convert(455, 464, x, y).x, convert(455, 464, x, y).y, convert(414, 351, x, y).x, convert(414, 351, x, y).y);
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
	line(convert(283, 747, x, y).x, convert(283, 747, x, y).y, convert(419, 718, x, y).x, convert(419, 718, x, y).y);
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

	//1画头部弧  X=0.438米  Y=0.484米  X=0.432米  Y=0.461米  X=0.420米  Y=0.440米                                          方位角=354度58分9.06秒  320度18分27.11秒
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
		angle_to_radian(354, 58, 9.06), angle_to_radian(320, 18, 27.11));
	Sleep(delay);
	// X=0.420米  Y=0.440米  X=0.389米  Y=0.408米   X=0.351米  Y=0.388米 325度28分32.40秒 288度55分30.64秒
	//2
	Cirthree(convert(420, 440, x, y).x, convert(420, 440, x, y).y, convert(389, 408, x, y).x, convert(389, 408, x, y).y, convert(351, 388, x, y).x, convert(351, 388, x, y).y,
		angle_to_radian(325, 28, 32.4), angle_to_radian(288, 55, 30.64));
	Sleep(delay);
	// X=0.438米  Y=0.484米  X=0.432米  Y=0.576米  X=0.381米  Y=0.654米 方位角=349度14分56.30秒 47度34分39.20秒
	//3
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 576, x, y).x, convert(432, 576, x, y).y, convert(381, 654, x, y).x, convert(381, 654, x, y).y,
		angle_to_radian(349, 14, 56.3), angle_to_radian(47, 34, 39.20));
	Sleep(delay);
	//X=0.381米  Y=0.654米   X=0.341米  Y=0.676米   X=0.253米  Y=0.677米  50度17分43.28秒 108度32分50.81秒
	//4
	Cirthree(convert(381, 654, x, y).x, convert(381, 654, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y, convert(253, 677, x, y).x, convert(253, 677, x, y).y,
		angle_to_radian(50, 17, 43.28), angle_to_radian(108, 32, 50.81));
	Sleep(delay);
	//X=0.351米  Y=0.388米  X=0.287米  Y=0.354米   X=0.247米  Y=0.366米 325度9分39.56秒 238度54分56.29秒
	//5
	Cirthree(convert(351, 388, x, y).x, convert(351, 388, x, y).y, convert(287, 354, x, y).x, convert(287, 354, x, y).y, convert(247, 366, x, y).x, convert(247, 366, x, y).y,
		angle_to_radian(325, 9, 39.06), angle_to_radian(238, 54, 56.29));
	Sleep(delay);
	//右边腮帮子
	// X=0.253米  Y=0.677米   X=0.195米  Y=0.675米  X=0.165米  Y=0.641米 66度22分55.43秒 157度51分52.67秒
	//6
	Cirthree(convert(253, 677, x, y).x, convert(253, 677, x, y).y, convert(195, 675, x, y).x, convert(195, 675, x, y).y, convert(165, 641, x, y).x, convert(165, 641, x, y).y,
		angle_to_radian(66, 22, 55.43)+0.04, angle_to_radian(157, 51, 52.67));
	Sleep(delay);
	//左边腮帮子最下方
	//X=0.247米  Y=0.366米 X=0.227米  Y=0.394米 X=0.222米  Y=0.431米  227度7分42.41秒 175度45分26.43秒
	//7
	Cirthree(convert(247, 366, x, y).x, convert(247, 366, x, y).y, convert(227, 394, x, y).x, convert(227, 394, x, y).y, convert(222, 431, x, y).x, convert(222, 431, x, y).y,
		angle_to_radian(227, 7, 42.41)-0.1, angle_to_radian(175, 45, 26.43));
	Sleep(delay);
	//左边腰
	//X=0.227米  Y=0.394米   X=0.170米  Y=0.377米  X=0.129米  Y=0.371米   291度29分27.73秒 274度29分11.55秒
	//8
	Cirthree(convert(227, 394, x, y).x, convert(227, 394, x, y).y, convert(170, 377, x, y).x, convert(170, 377, x, y).y, convert(129, 371, x, y).x, convert(129, 371, x, y).y,
		angle_to_radian(291, 29, 27.73), angle_to_radian(274, 29, 11.55)-0.02);
	Sleep(delay);
	//右边腰
	//X=0.165米  Y=0.641米 X=0.146米  Y=0.645米  X=0.127米  Y=0.647米  73度18分18.31秒 89度29分55.92秒
	//9
	Cirthree(convert(165, 641, x, y).x, convert(165, 641, x, y).y, convert(146, 645, x, y).x, convert(146, 645, x, y).y, convert(127, 647, x, y).x, convert(127, 647, x, y).y,
		angle_to_radian(73, 18, 18.31)-0.04, angle_to_radian(89, 29, 55.92)+0.04);
	Sleep(delay);
	//左边脚
	// X=0.119米  Y=0.386米 X=0.129米  Y=0.371米  X=0.121米  Y=0.347米 52度48分1.85秒 311度29分2.75秒
	//10
	Cirthree(convert(119, 386, x, y).x, convert(119, 386, x, y).y, convert(129, 371, x, y).x, convert(129, 371, x, y).y, convert(121, 347, x, y).x, convert(121, 347, x, y).y,
		angle_to_radian(52, 48, 1.85), angle_to_radian(311, 29, 2.75));
	Sleep(delay);
	// X=0.121米  Y=0.347米 X=0.101米  Y=0.340米   X=0.078米  Y=0.349米 311度42分4.98秒 方位角=222度54分4.49秒
	//11
	Cirthree(convert(121, 347, x, y).x, convert(121, 347, x, y).y, convert(101, 340, x, y).x, convert(101, 340, x, y).y, convert(78, 349, x, y).x, convert(78, 349, x, y).y,
		angle_to_radian(311, 42, 4.98)+0.04, angle_to_radian(222, 54, 4.49));
	Sleep(delay);
	//  X=0.078米  Y=0.349米   X=0.065米  Y=0.365米  X=0.057米  Y=0.393米 229度41分26.93秒 180度56分32.95秒
	//12
	Cirthree(convert(78, 349, x, y).x, convert(78, 349, x, y).y, convert(65, 365, x, y).x, convert(65, 365, x, y).y, convert(57, 393, x, y).x, convert(57, 393, x, y).y,
		angle_to_radian(229, 41, 26.93), angle_to_radian(180, 56, 32.95));
	Sleep(delay);
	//X=0.057米  Y=0.393米  X=0.062米  Y=0.402米  X=0.071米  Y=0.405米  173度56分21.50秒  89度12分59.74秒
	//13
	Cirthree(convert(57, 393, x, y).x, convert(57, 393, x, y).y, convert(62, 402, x, y).x, convert(62, 402, x, y).y, convert(71, 405, x, y).x, convert(71, 405, x, y).y,
		angle_to_radian(173, 56, 21.5), angle_to_radian(89, 12, 59.74));
	Sleep(delay);
	//右边脚
	//  X=0.120米  Y=0.633米  X=0.127米  Y=0.657米   X=0.108米  Y=0.679米  316度53分49.63秒 71度47分24.51秒
	//14
	Cirthree(convert(120, 633, x, y).x, convert(120, 633, x, y).y, convert(127, 657, x, y).x, convert(127, 657, x, y).y, convert(108, 679, x, y).x, convert(108, 679, x, y).y,
		angle_to_radian(316, 53, 49.63), angle_to_radian(71, 47, 24.51));
	Sleep(delay);
	// X=0.108米  Y=0.679米   X=0.077米  Y=0.668米  X=0.057米  Y=0.642米 93度25分41.52秒 157度32分15.72秒
	//15
	Cirthree(convert(108, 679, x, y).x, convert(108, 679, x, y).y, convert(77, 668, x, y).x, convert(77, 668, x, y).y, convert(57, 642, x, y).x, convert(57, 642, x, y).y,
		angle_to_radian(93, 25, 41.52), angle_to_radian(157, 32, 15.72));
	Sleep(delay);
	//X=0.057米  Y=0.642米  X=0.059米  Y=0.621米 X=0.071米  Y=0.614米 150度13分35.04秒 261度36分49.06秒
	//16
	Cirthree(convert(57, 642, x, y).x, convert(57, 642, x, y).y, convert(59, 621, x, y).x, convert(59, 621, x, y).y, convert(71, 614, x, y).x, convert(71, 614, x, y).y,
		angle_to_radian(150, 13, 35.04), angle_to_radian(261, 36, 49.06));
	Sleep(delay);
	// X=0.071米  Y=0.405米    X=0.074米  Y=0.439米 X=0.071米  Y=0.614米 355度0分38.98秒  5度6分55.41秒
	//17
	Cirthree(convert(71, 405, x, y).x, convert(71, 405, x, y).y, convert(74, 439, x, y).x, convert(74, 439, x, y).y, convert(71, 614, x, y).x, convert(71, 614, x, y).y,
		angle_to_radian(355, 0, 38.98)+0.013, angle_to_radian(5, 6, 55.41)-0.013);
	Sleep(delay);
	//尾巴
	//  X=0.156米  Y=0.375米 X=0.173米  Y=0.365米  X=0.186米  Y=0.350米 66度49分20.73秒 33度32分0.09秒
	//18
	Cirthree(convert(156, 375, x, y).x, convert(156, 375, x, y).y, convert(173, 365, x, y).x, convert(173, 365, x, y).y, convert(186, 350, x, y).x, convert(186, 350, x, y).y,
		angle_to_radian(66, 49, 20.73) , angle_to_radian(33, 32, 0.09) );
	Sleep(delay);
	//  X=0.186米  Y=0.350米   X=0.187米  Y=0.339米  X=0.173米  Y=0.318米 15度53分44.36秒 299度55分11.23秒
	//19
	Cirthree(convert(186, 350, x, y).x, convert(186, 350, x, y).y, convert(187, 339, x, y).x, convert(187, 339, x, y).y, convert(173, 318, x, y).x, convert(173, 318, x, y).y,
		angle_to_radian(15, 53, 44.36), angle_to_radian(299, 55, 11.23));
	Sleep(delay);
	//  X=0.173米  Y=0.318米 X=0.160米  Y=0.315米 X=0.137米  Y=0.327米 299度20分26.10秒 213度6分45.52秒
	//20
	Cirthree(convert(173, 318, x, y).x, convert(173, 318, x, y).y, convert(160, 315, x, y).x, convert(160, 315, x, y).y, convert(137, 327, x, y).x, convert(137, 327, x, y).y,
		angle_to_radian(299, 20, 26.1), angle_to_radian(213, 6, 45.52));
	Sleep(delay);
	//  X = 0.137米  Y = 0.327米 X=0.132米  Y=0.340米  X=0.127米  Y=0.355米 208度4分4.71秒 192度11分57.10秒
	//21
	Cirthree(convert(137, 327, x, y).x, convert(137, 327, x, y).y, convert(132, 340, x, y).x, convert(132, 340, x, y).y, convert(127, 355, x, y).x, convert(127, 355, x, y).y,
		angle_to_radian(208, 4, 4.71)+0.1, angle_to_radian(192, 11, 57.1)-0.1);//前加减小 后减减小
	Sleep(delay);
	//左手
	//X=0.177米  Y=0.415米  X=0.182米  Y=0.435米    X=0.180米  Y=0.457米 338度9分26.11秒 13度17分49.62秒
	Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
		angle_to_radian(338, 9, 26.11) , angle_to_radian(13, 17, 49.62) );//前加减小 后减减小
	Sleep(delay);
	//X=0.180米  Y=0.456米  X=0.175米  Y=0.461米  X=0.162米  Y=0.458米 22度59分33.74秒 143度0分4.64秒
	Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
		angle_to_radian(22, 59, 33.74),angle_to_radian(143, 0, 4.64));//前加减小 后减减小
	Sleep(delay);
	// X=0.162米  Y=0.458米   X=0.148米  Y=0.437米 X=0.144米  Y=0.416米 132度54分8.27秒 181度56分3.85秒
	Cirthree(convert(162, 458, x, y).x, convert(162, 458, x, y).y, convert(148, 437, x, y).x, convert(148, 437, x, y).y, convert(144, 416, x, y).x, convert(144, 416, x, y).y,
		angle_to_radian(132, 54, 8.27) , angle_to_radian(181, 56, 3.85) );//前加减小 后减减小
	Sleep(delay);

	//右手
	//X=0.165米  Y=0.641米  X=0.159米  Y=0.617米 X=0.163米  Y=0.592米 154度17分9.23秒 200度39分3.32秒
	Cirthree(convert(165, 641, x, y).x, convert(165, 641, x, y).y, convert(159, 617, x, y).x, convert(159, 617, x, y).y, convert(163, 592, x, y).x, convert(163, 592, x, y).y,
		angle_to_radian(154, 17, 9.23), angle_to_radian(200, 39, 3.32));//前加减小 后减减小
	Sleep(delay);
	//X=0.163米  Y=0.592米 X=0.173米  Y=0.576米   X=0.178米  Y=0.557米 34度40分23.80秒 2度53分37.42秒
	Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
		angle_to_radian(34, 40, 23.8)-0.1, angle_to_radian(2, 53, 37.42));//前加减小 后减减小
	Sleep(delay);
	//X=0.178米  Y=0.557米  X=0.169米  Y=0.541米 X=0.146米  Y=0.541米 357度17分30.34秒 235度17分53.72秒
	Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
		angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//前加减小 后减减小
	Sleep(delay);
	//X=0.146米  Y=0.541米  X=0.128米  Y=0.556米   X=0.116米  Y=0.576米 236度32分55.32秒 204度36分28.89秒
	Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
		angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//前加减小 后减减小
	Sleep(delay);

	//逆时针 弧度1增加线开头变短 弧度2减小 末尾线变短
	//顺时针 弧度1减小线开头变短 弧度2增加 末尾线变短

	//胡萝卜先左后右先上后下
	//X=0.182米  Y=0.445米 X=0.196米  Y=0.443米 X=0.208米  Y=0.455米 235度10分22.80秒 347度4分4.18秒
	Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
		angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//前加减小 后减减小
	Sleep(delay);
	//X=0.208米  Y=0.455米  X=0.204米  Y=0.485米    X=0.202米  Y=0.488米 352度52分48.42秒 27度1分47.81秒
	Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
		angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//前加减小 后减减小
	Sleep(delay);
	// X=0.202米  Y=0.488米   X=0.197米  Y=0.545米    X=0.199米  Y=0.551米 204度52分26.34秒 160度30分24.25秒
	Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
		angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//前加减小 后减减小
	Sleep(delay);
	//4  X=0.199米  Y=0.551米  X=0.189米  Y=0.558米  X=0.177米  Y=0.559米  39度26分10.94秒 100度12分16.85秒
	Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//前加减小 后减减小
	Sleep(delay);
	//7   X=0.139米  Y=0.546米  X=0.152米  Y=0.493米  X=0.170米  Y=0.462米 184度30分26.61秒 216度49分29.37秒
	Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
		angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//前加减小 后减减小
	Sleep(delay);

	//绿叶
	//11  X=0.195米  Y=0.555米 X=0.204米  Y=0.565米 X=0.206米  Y=0.578米 304度0分44.27秒 2度14分2.70秒
	Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
		angle_to_radian(304, 0, 44.27)+0.2, angle_to_radian(2, 14, 2.7));//前加减小 后减减小
	Sleep(delay);
	//12  X=0.206米  Y=0.578米  X=0.200米  Y=0.586米  X=0.188米  Y=0.580米 9度59分48.96秒 158度8分5.94秒
	Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
		angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//前加减小 后减减小
	Sleep(delay);
	//13  X=0.188米  Y=0.580米  X=0.181米  Y=0.593米 X=0.168米  Y=0.586米 343度34分17.94秒 163度17分6.93秒
	Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
		angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//前加减小 后减减小
	Sleep(delay);
	
	//设置线型
	setlinestyle(PS_SOLID, 3);
	//左眼
	//14   X=0.320米  Y=0.476米 X=0.333米  Y=0.485米  X=0.336米  Y=0.493米 285度34分1.95秒 348度7分58.59秒
	Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(333, 485, x, y).x, convert(333, 485, x, y).y, convert(336, 493, x, y).x, convert(336, 493, x, y).y,
		angle_to_radian(285, 34, 1.95), angle_to_radian(348, 7, 58.59));//前加减小 后减减小
	Sleep(delay);
	//15   X=0.336米  Y=0.493米 X=0.332米  Y=0.503米 X=0.326米  Y=0.505米 355度19分23.78秒 90度28分44.97秒
	Cirthree(convert(336, 493, x, y).x, convert(336, 493, x, y).y, convert(332, 503, x, y).x, convert(332, 503, x, y).y, convert(326, 505, x, y).x, convert(326, 505, x, y).y,
		angle_to_radian(355, 19, 23.78), angle_to_radian(90, 28, 44.97));//前加减小 后减减小
	Sleep(delay);
	//16   X=0.326米  Y=0.505米  X=0.308米  Y=0.498米  X=0.301米  Y=0.480米  85度38分9.36秒 184度18分40.34秒
	Cirthree(convert(326, 505, x, y).x, convert(326, 505, x, y).y, convert(308, 498, x, y).x, convert(308, 498, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		angle_to_radian(85, 38, 9.36), angle_to_radian(184, 18, 40.34));//前加减小 后减减小
	Sleep(delay);
	//17   X=0.301米  Y=0.480米   X=0.314米  Y=0.474米  X=0.320米  Y=0.476米 222度52分32.60秒 294度24分49.26秒
	Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		angle_to_radian(222, 52, 32.6), angle_to_radian(294, 24, 49.26));//前加减小 后减减小
	Sleep(delay);
	//19    X=0.320米  Y=0.491米 X=0.327米  Y=0.488米 X=0.330米  Y=0.492米 197度24分32.69秒 352度36分56.48秒
	Cirthree(convert(320, 491, x, y).x, convert(320, 491, x, y).y, convert(327, 488, x, y).x, convert(327, 488, x, y).y, convert(330, 492, x, y).x, convert(330, 492, x, y).y,
		angle_to_radian(197, 24, 32.69), angle_to_radian(352, 36, 56.48)+1.7);//前加减小 后减减小
	Sleep(delay);
	// X=0.330米  Y=0.492米 X=0.328米  Y=0.496米  X=0.325米  Y=0.497米 1度22分48.28秒 93度16分57.13秒
	Cirthree(convert(330, 492, x, y).x, convert(330, 492, x, y).y, convert(328, 496, x, y).x, convert(328, 496, x, y).y, convert(325, 497, x, y).x, convert(325, 497, x, y).y,
		angle_to_radian(1, 22, 48.28)+1.3, angle_to_radian(93, 16, 57.13));//前加减小 后减减小
	Sleep(delay);
	// X=0.325米  Y=0.497米  X=0.321米  Y=0.494米  X=0.320米  Y=0.491米 98度35分16.88秒 方位角=174度23分34.16秒
	Cirthree(convert(325, 497, x, y).x, convert(325, 497, x, y).y, convert(321, 494, x, y).x, convert(321, 494, x, y).y, convert(320, 491, x, y).x, convert(320, 491, x, y).y,
		angle_to_radian(98, 35, 16.88), angle_to_radian(174, 23, 34.16));//前加减小 后减减小
	Sleep(delay);
	//18
	//X=0.320米  Y=0.476米 X=0.304米  Y=0.441米   X=0.301米  Y=0.480米  49度25分12.66秒 107度52分9.20秒
	Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		angle_to_radian(49, 25, 12.66)+0.3, angle_to_radian(107, 52, 9.2)+0.5);//前加减小 后减减小
	Sleep(delay);
	

	//右眼
	//23  X=0.297米  Y=0.571米  X=0.305米  Y=0.578米 X=0.307米  Y=0.589米   290度23分17.75秒 8度41分14.46秒  
	Cirthree(convert(297, 571, x, y).x, convert(297, 571, x, y).y, convert(305, 578, x, y).x, convert(305, 578, x, y).y, convert(307, 589, x, y).x, convert(307, 589, x, y).y,
		angle_to_radian(290, 23, 17.75), angle_to_radian(8, 41, 14.46));//前加减小 后减减小
	Sleep(delay);
	//20 X=0.307米  Y=0.589米  X=0.295米  Y=0.597米  X=0.281米  Y=0.594米 33度54分37.10秒 124度46分51.43秒   
	Cirthree(convert(307, 589, x, y).x, convert(307, 589, x, y).y, convert(295, 597, x, y).x, convert(295, 597, x, y).y, convert(281, 594, x, y).x, convert(281, 594, x, y).y,
		angle_to_radian(33, 54, 37.1), angle_to_radian(124, 46, 51.43));//前加减小 后减减小
	Sleep(delay);
	//21  X=0.281米  Y=0.594米  X=0.273米  Y=0.588米  X=0.270米  Y=0.576米 110度6分20.99秒 182度51分36.95秒  
	Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//前加减小 后减减小
	Sleep(delay);
	//22  X=0.270米  Y=0.576米  X=0.285米  Y=0.568米   X=0.297米  Y=0.571米 214度33分24.28秒 302度49分44.41秒  
	Cirthree(convert(270, 576, x, y).x, convert(270, 576, x, y).y, convert(285, 568, x, y).x, convert(285, 568, x, y).y, convert(297, 571, x, y).x, convert(297, 571, x, y).y,
		angle_to_radian(214, 33, 24.28), angle_to_radian(302, 49, 44.41));//前加减小 后减减小
	Sleep(delay);
	//24  X=0.300米  Y=0.583米  X=0.296米  Y=0.578米   X=0.291米  Y=0.583米 359度59分60.00秒 182度7分45.49秒   
	Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(296, 578, x, y).x, convert(296, 578, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49)-0.5);//前加减小 后减减小
	Sleep(delay);
	//X=0.300米  Y=0.583米  X=0.297米  Y=0.587米   X=0.291米  Y=0.583米 6度45分29.16秒 175度22分16.34秒
	Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(297, 587, x, y).x, convert(297, 587, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49)-0.2);//前加减小 后减减小
	Sleep(delay);
	// 25  X=0.281米  Y=0.594米 X=0.242米  Y=0.587米  X=0.270米  Y=0.576米  357度25分51.22秒 296度58分46.19秒
	Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		angle_to_radian(357, 25, 51.22)-0.2, angle_to_radian(296, 58, 46.19));//前加减小 后减减小
	Sleep(delay);
	
	//逆时针 弧度1增加线开头变短 弧度2减小 末尾线变短
	//顺时针 弧度1减小线开头变短 弧度2增加 末尾线变短
	
	//26 
	//X=0.298米  Y=0.525米  X=0.308米  Y=0.537米  X=0.293米  Y=0.541米  263度22分18.66秒 130度13分16.69秒
	Cirthree(convert(298, 525, x, y).x, convert(298, 525, x, y).y, convert(308, 537, x, y).x, convert(308, 537, x, y).y, convert(293, 541, x, y).x, convert(293, 541, x, y).y,
		angle_to_radian(263, 22, 18.66) , angle_to_radian(130, 13, 16.69));//前加减小 后减减小
	Sleep(delay);
	//27 
	//X=0.299米  Y=0.525米  X=0.295米  Y=0.531米  X=0.296米  Y=0.543米 229度4分22.30秒 150度0分22.36秒
	Cirthree(convert(299, 525, x, y).x, convert(299, 525, x, y).y, convert(295, 531, x, y).x, convert(295, 531, x, y).y, convert(296, 543, x, y).x, convert(293, 543, x, y).y,
		angle_to_radian(229, 4, 22.3), angle_to_radian(150, 0, 22.36)-0.5);//前加减小 后减减小
	Sleep(delay);

	//设置线型
	setlinestyle(PS_SOLID, 3);
	//28 
	//X=0.294米  Y=0.533米  X=0.284米  Y=0.514米  X=0.290米  Y=0.499米  122度50分28.32秒 223度27分28.35秒
	Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//前加减小 后减减小
	Sleep(delay);
	//29 
	//X=0.294米  Y=0.533米 X=0.280米  Y=0.540米  X=0.273米  Y=0.561米 257度43分39.66秒 174度6分13.43秒
	Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//前加减小 后减减小
	Sleep(delay);
	//30 
	// X=0.285米  Y=0.519米  X=0.270米  Y=0.516米   X=0.259米  Y=0.521米 297度57分10.55秒 235度54分32.11秒
	Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11)+0.2);//前加减小 后减减小
	Sleep(delay);
	//31
	// X=0.280米  Y=0.540米  X=0.268米  Y=0.534米  X=0.259米  Y=0.521米 103度26分12.32秒 162度30分12.91秒
	Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//前加减小 后减减小
	Sleep(delay);

	//逆时针 弧度1增加线开头变短 弧度2减小 末尾线变短
	//顺时针 弧度1减小线开头变短 弧度2增加 末尾线变短
	//左脚
	// X=0.102米  Y=0.353 X=0.095米  Y=0.352米 X=0.090米  Y=0.363米  297度41分28.87秒 161度26分56.78秒
	Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(95, 352, x, y).x, convert(95, 352, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		angle_to_radian(297, 41, 28.87) , angle_to_radian(161, 26, 56.78) );//前加减小 后减减小
	Sleep(delay);
	// X=0.102米  Y=0.353  X=0.098米  Y=0.362米 X=0.090米  Y=0.363米 352度46分12.08秒 106度22分13.57秒
	Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(98, 362, x, y).x, convert(98, 362, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		angle_to_radian(352, 46, 12.08) , angle_to_radian(106, 22, 13.57)-0.3 );//前加减小 后减减小
	Sleep(delay);

	// X=0.116米  Y=0.362米 X=0.108米  Y=0.360米  X=0.101米  Y=0.367米  317度39分8.35秒 187度5分41.70秒
	Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(108, 360, x, y).x, convert(108, 360, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		angle_to_radian(317, 39, 8.35) , angle_to_radian(187, 5, 41.7)-0.3 );//前加减小 后减减小
	Sleep(delay);
	// X=0.116米  Y=0.362米  X=0.111米  Y=0.369米 X=0.101米  Y=0.367米  X=0.101米  Y=0.367米=8度17分27.46秒  =136度27分22.58秒
	Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(111, 369, x, y).x, convert(111, 369, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		angle_to_radian(8, 17, 27.46) , angle_to_radian(136, 27, 22.58) );//前加减小 后减减小
	Sleep(delay);

	//X=0.117米  Y=0.376米   X=0.109米  Y=0.372米  X=0.101米  Y=0.381米 329度10分9.96秒 181度22分7.37秒
	Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(109, 372, x, y).x, convert(109, 372, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		angle_to_radian(329, 10, 9.96) , angle_to_radian(181, 22, 7.37) );//前加减小 后减减小
	Sleep(delay);
	//X=0.117米  Y=0.376米   X=0.111米  Y=0.383米  X=0.101米  Y=0.381米 15度26分31.36秒 135度5分45.98秒
	Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(111, 383, x, y).x, convert(111, 383, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		angle_to_radian(15, 26, 31.36), angle_to_radian(135, 5, 45.98));//前加减小 后减减小
	Sleep(delay);

	//X=0.096米  Y=0.372米 X=0.087米  Y=0.370米  X=0.074米  Y=0.386米 299度3分38.35秒 171度38分8.91秒
	Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(87, 370, x, y).x, convert(87, 370, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		angle_to_radian(299, 3, 38.35) , angle_to_radian(171, 38, 8.91) );//前加减小 后减减小
	Sleep(delay);
	//X=0.096米  Y=0.372米 X=0.090米  Y=0.387米   X=0.074米  Y=0.386米  343度40分27.29秒 127度1分19.97秒
	Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(90, 387, x, y).x, convert(90, 387, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		angle_to_radian(343, 40, 27.29), angle_to_radian(127, 1, 19.97));//前加减小 后减减小
	Sleep(delay);

	//右脚
	//  X=0.116米  Y=0.642米   X=0.111米  Y=0.636米   X=0.101米  Y=0.638米 341度40分12.79秒 222度43分32.33秒
	Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(111, 636, x, y).x, convert(111, 636, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		angle_to_radian(341, 40, 12.79), angle_to_radian(222, 43, 32.33));//前加减小 后减减小
	Sleep(delay);
	//X=0.116米  Y=0.642米   X=0.105米  Y=0.645米   X=0.101米  Y=0.638米 29度17分54.10秒 175度5分51.02秒
	Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(105, 645, x, y).x, convert(105, 645, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		angle_to_radian(29, 17, 54.1), angle_to_radian(175, 5, 51.02));//前加减小 后减减小
	Sleep(delay);

	// X=0.115米  Y=0.659米 X=0.109米  Y=0.649米 X=0.101米  Y=0.651米 11度34分2.18秒 226度10分24.04秒
	Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(109, 649, x, y).x, convert(109, 649, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		angle_to_radian(11, 34, 2.18), angle_to_radian(226, 10, 24.04));//前加减小 后减减小
	Sleep(delay);
	//X=0.115米  Y=0.659米  X=0.105米  Y=0.658米 X=0.101米  Y=0.651米 61度48分24.44秒 175度56分1.78秒
	Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(105, 658, x, y).x, convert(105, 658, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		angle_to_radian(61, 48, 24.44), angle_to_radian(175, 59, 1.78));//前加减小 后减减小
	Sleep(delay);

	// X=0.103米  Y=0.665米  X=0.096米  Y=0.656米  X=0.091米  Y=0.657米 7度6分59.98秒 242度31分15.10秒
	Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(96, 656, x, y).x, convert(96, 656, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		angle_to_radian(7, 6, 59.98), angle_to_radian(242, 31, 15.1));//前加减小 后减减小
	Sleep(delay);
	//X=0.103米  Y=0.665米  X=0.098米  Y=0.667米  X=0.091米  Y=0.657米 57度19分9.55秒 192度19分5.54秒
	Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(98, 667, x, y).x, convert(98, 667, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		angle_to_radian(57, 19, 9.55), angle_to_radian(192, 19, 5.54));//前加减小 后减减小
	Sleep(delay);

	//  X=0.096米  Y=0.648米  X=0.085米  Y=0.630米  X=0.074米  Y=0.632米 13度3分12.91秒 239度15分54.89秒
	Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(85, 630, x, y).x, convert(85, 630, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		angle_to_radian(13, 3, 12.91), angle_to_radian(239, 15, 54.89));//前加减小 后减减小
	Sleep(delay);
	//X=0.096米  Y=0.648米  X=0.087米  Y=0.650米   X=0.074米  Y=0.632米 59度0分34.03秒 193度18分33.76秒
	Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(87, 650, x, y).x, convert(87, 650, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		angle_to_radian(59, 0, 34.03), angle_to_radian(193, 18, 33.76));//前加减小 后减减小
	Sleep(delay);


	////填色
	//FillLeftEar(x,y,255,209,207);
	//Sleep(delay);
	//FillRightEar(x, y, 255, 209, 207);
	//Sleep(delay);
	//FillCarrot(x,y,238,95,0);
	//Sleep(delay);
	//FillLeaf(x,y,1,155,69);
	//Sleep(delay);
	//FillEyes(x,y,0,0,0);
	//Sleep(delay);
	//FillCheeks(x,y,254,204,203);
	//Sleep(delay);
	//FillNose(x,y,62,11,16);
	//Sleep(delay);
	//FillMouth(x,y,251,152,147);
	//Sleep(delay);
	//FillFoots(x,y,255,208,202);
	//Sleep(delay);

}
/// <summary>
/// 坐标转换，从cass坐标转为绘图坐标
/// </summary>
/// <param name="x">cass上坐标x</param>
/// <param name="y">cass上坐标y</param>
/// <param name="X">指定绘图坐标X</param>
/// <param name="Y">指定绘图坐标Y</param>
/// <returns></returns>
POINT  convert(double x, double y, double X, double Y) {
	//第一步计算水平和竖值方向绝对距离
	//设置坐标参考点
	//X=0.294米  Y=0.533米
	const int x0 = 294;
	const int y0 = 533;
	int xx = 0, yy = 0;
	int distancesz = abs((int)x - x0);//计算竖直方向距离
	int distancesp = abs((int)y - y0);//计算水平方向距离
	//第二步判断相对方位
	//第一象限
	if (((x - x0) >= 0 && (y - y0) >= 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//第二象限
	if ((x - x0) >= 0 && (y - y0) <= 0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//第三象限
	if ((x - x0) <= 0 && (y - y0) <= 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//第四象限
	if ((x - x0) <= 0 && (y - y0) >= 0)
	{
		xx = X + distancesp;
		yy = Y + distancesz;
	}

	//第三步，确定转换后的坐标值
	POINT pt[1];
	pt[0] = { xx,yy };
	return pt[0];
}
/// <summary>
/// 利用向量叉乘判断旋转方向，返回大于0是顺时针，小于0是逆时针。
/// </summary>
/// <param name="X1">第一个点X</param>
/// <param name="Y1">第一个点Y</param>
/// <param name="X2">第二个点X</param>
/// <param name="Y2">第二个点Y</param>
/// <param name="X3">第三个的X</param>
/// <param name="Y3">第三个的Y</param>
/// <returns>向量×值</returns>
double Cross(double X1, double Y1, double X2, double Y2, double X3, double Y3) {
	//利用向量叉乘判断旋转方向，返回大于0是顺时针，小于0是逆时针。
	return (X2 - X1) * (Y3 - Y2) - (Y2 - Y1) * (X3 - X2);
}
/// <summary>
/// 种子填充
/// </summary>
/// <param name="x">中心的横坐标</param>
/// <param name="y">中心的纵坐标</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
/// <returns></returns>
int BoundaryFill(int x, int y, COLORREF rgb)
{
	int c = 0;
	c = getpixel(x, y);
	if (c != rgb)
	{
		putpixel(x, y, rgb);
	}
	if (c == rgb)
		return 0;
	BoundaryFill(x + 1, y, rgb);
	BoundaryFill(x - 1, y, rgb);
	BoundaryFill(x, y + 1, rgb);
	BoundaryFill(x, y - 1, rgb);
}
 /// <summary>
 /// 填充左耳朵颜色
 /// </summary>
 /// <param name="x">指定坐标X</param>
 /// <param name="y">指定坐标Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillLeftEar(int x,int y, COLORREF rgb){
	/* 先绘制颜色填充的*/
		/*左边耳朵颜色填充*/
		setlinestyle(PS_SOLID, 5);
		//设置线色
		setlinecolor(rgb);
		//直线 X=0.445米  Y=0.436米    X=0.451米  Y=0.453米 
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
		//X=0.445米  Y=0.436米  X=0.420米  Y=0.440米
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
		//X=0.451米  Y=0.453米   X=0.432米  Y=0.461米
		line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
		//X = 0.432米  Y = 0.461米 X=0.427米  Y=0.451米 X=0.420米  Y=0.440米 338度16分33.76秒 320度18分27.11秒
		Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
			angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
		//填充颜色 X=0.437米  Y=0.447米 
		BoundaryFill(convert(437, 447, x, y).x, convert(437, 447, x, y).y,rgb);
		//设置线型
		setlinestyle(PS_SOLID, 5);
		//设置线色
		setlinecolor(RGB(10, 10, 10));
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
		//X=0.445米  Y=0.436米  X=0.420米  Y=0.440米
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
		//X=0.451米  Y=0.453米   X=0.432米  Y=0.461米
		line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
		//X = 0.432米  Y = 0.461米 X=0.427米  Y=0.451米 X=0.420米  Y=0.440米 338度16分33.76秒 320度18分27.11秒
		Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
			angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
 }
 /// <summary>
 /// 填充右耳朵颜色
 /// </summary>
 /// <param name="x">指定坐标X</param>
 /// <param name="y">指定坐标Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillRightEar(int x,int y, COLORREF rgb) {
	/* 右边耳朵颜色填充*/
	setlinestyle(PS_SOLID, 5);
	//设置线色
	setlinecolor(rgb);
	//直线  X=0.378米  Y=0.686米  X=0.362米  Y=0.696米 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(362, 696, x, y).x, convert(362, 696, x, y).y);
	//
	//X=0.378米  Y=0.686米 X=0.365米  Y=0.665米 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	// X=0.362米  Y=0.696米 X=0.341米  Y=0.676米
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	/*X=0.365米  Y=0.665米  X=0.354米  Y=0.671米   X=0.341米  Y=0.676米 59度45分41.34秒 70度36分34.68秒*/
	Cirthree(convert(365, 665, x, y).x, convert(365, 665, x, y).y, convert(354, 671, x, y).x, convert(354, 671, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y,
		angle_to_radian(59, 45, 41.34), angle_to_radian(70, 36, 34.68));
	//填充颜色  X=0.363米  Y=0.679米  
	BoundaryFill(convert(363, 679, x, y).x, convert(363, 679, x, y).y,rgb);
	//设置线型
	setlinestyle(PS_SOLID, 5);
	//设置线色
	setlinecolor(RGB(10, 10, 10));
	//直线  X=0.378米  Y=0.686米  X=0.362米  Y=0.696米 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(362, 696, x, y).x, convert(362, 696, x, y).y);
	//
	/*X=0.378米  Y=0.686米 X=0.365米  Y=0.665米 */
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	// X=0.362米  Y=0.696米 X=0.341米  Y=0.676米
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	//X=0.365米  Y=0.665米  X=0.354米  Y=0.671米   X=0.341米  Y=0.676米 59度45分41.34秒 70度36分34.68秒
	Cirthree(convert(365, 665, x, y).x, convert(365, 665, x, y).y, convert(354, 671, x, y).x, convert(354, 671, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y,
		angle_to_radian(59, 45, 41.34), angle_to_radian(70, 36, 34.68));
 }
 /// <summary>
 /// 填充胡萝卜颜色
 /// </summary>
 /// <param name="x">指定坐标X</param>
 /// <param name="y">指定坐标Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillCarrot(int x, int y, COLORREF rgb) {
	/* 胡萝卜填充*/
		setlinestyle(PS_SOLID, 5);
		//设置线色
		setlinecolor(rgb);
		Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
			angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//前加减小 后减减小
			//X=0.208米  Y=0.455米  X=0.204米  Y=0.485米    X=0.202米  Y=0.488米 352度52分48.42秒 27度1分47.81秒
		Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
			angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//前加减小 后减减小
			// X=0.202米  Y=0.488米   X=0.197米  Y=0.545米    X=0.199米  Y=0.551米 204度52分26.34秒 160度30分24.25秒
		Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
			angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//前加减小 后减减小
		//4  X=0.199米  Y=0.551米  X=0.189米  Y=0.558米  X=0.177米  Y=0.559米  39度26分10.94秒 100度12分16.85秒
		Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
			angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//前加减小 后减减小
		//X=0.163米  Y=0.592米 X=0.173米  Y=0.576米   X=0.178米  Y=0.557米 34度40分23.80秒 2度53分37.42秒
		Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
			angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//前加减小 后减减小
		//X=0.178米  Y=0.557米  X=0.169米  Y=0.541米 X=0.146米  Y=0.541米 357度17分30.34秒 235度17分53.72秒
		Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
			angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//前加减小 后减减小
		//X=0.146米  Y=0.541米  X=0.128米  Y=0.556米   X=0.116米  Y=0.576米 236度32分55.32秒 204度36分28.89秒
		Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
			angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//前加减小 后减减小
			//7   X=0.139米  Y=0.546米  X=0.152米  Y=0.493米  X=0.170米  Y=0.462米 184度30分26.61秒 216度49分29.37秒
		Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
			angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//前加减小 后减减小
		//X=0.177米  Y=0.415米  X=0.182米  Y=0.435米    X=0.180米  Y=0.457米 338度9分26.11秒 13度17分49.62秒
		Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
			angle_to_radian(338, 9, 26.11), angle_to_radian(13, 17, 49.62));//前加减小 后减减小
		//X=0.180米  Y=0.456米  X=0.175米  Y=0.461米  X=0.162米  Y=0.458米 22度59分33.74秒 143度0分4.64秒
		Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
			angle_to_radian(22, 59, 33.74), angle_to_radian(143, 0, 4.64));//前加减小 后减减小
		//填充颜色   X=0.178米  Y=0.497米
			BoundaryFill(convert(178, 497, x, y).x, convert(178, 497, x, y).y,rgb);
			//设置线型
			setlinestyle(PS_SOLID, 5);
			//设置线色
			setlinecolor(RGB(10, 10, 10));
	Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
			angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//前加减小 后减减小
			//X=0.208米  Y=0.455米  X=0.204米  Y=0.485米    X=0.202米  Y=0.488米 352度52分48.42秒 27度1分47.81秒
		Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
			angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//前加减小 后减减小
			// X=0.202米  Y=0.488米   X=0.197米  Y=0.545米    X=0.199米  Y=0.551米 204度52分26.34秒 160度30分24.25秒
		Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
			angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//前加减小 后减减小
		//4  X=0.199米  Y=0.551米  X=0.189米  Y=0.558米  X=0.177米  Y=0.559米  39度26分10.94秒 100度12分16.85秒
		Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
			angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//前加减小 后减减小
		//X=0.163米  Y=0.592米 X=0.173米  Y=0.576米   X=0.178米  Y=0.557米 34度40分23.80秒 2度53分37.42秒
		Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
			angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//前加减小 后减减小
		//X=0.178米  Y=0.557米  X=0.169米  Y=0.541米 X=0.146米  Y=0.541米 357度17分30.34秒 235度17分53.72秒
		Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
			angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//前加减小 后减减小
		//X=0.146米  Y=0.541米  X=0.128米  Y=0.556米   X=0.116米  Y=0.576米 236度32分55.32秒 204度36分28.89秒
		Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
			angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//前加减小 后减减小
			//7   X=0.139米  Y=0.546米  X=0.152米  Y=0.493米  X=0.170米  Y=0.462米 184度30分26.61秒 216度49分29.37秒
		Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
			angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//前加减小 后减减小
		//X=0.177米  Y=0.415米  X=0.182米  Y=0.435米    X=0.180米  Y=0.457米 338度9分26.11秒 13度17分49.62秒
		Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
			angle_to_radian(338, 9, 26.11), angle_to_radian(13, 17, 49.62));//前加减小 后减减小
		//X=0.180米  Y=0.456米  X=0.175米  Y=0.461米  X=0.162米  Y=0.458米 22度59分33.74秒 143度0分4.64秒
		Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
			angle_to_radian(22, 59, 33.74), angle_to_radian(143, 0, 4.64));//前加减小 后减减小
 }
 /// <summary>
 /// 填充绿叶颜色
 /// </summary>
 /// <param name="x">指定坐标X</param>
 /// <param name="y">指定坐标Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillLeaf(int x, int y, COLORREF rgb) {
	 //绿叶填充
	 setlinestyle(PS_SOLID, 5);
	 	//设置线色
	 	setlinecolor(rgb);
	 //绿叶
	 	//11  X=0.195米  Y=0.555米 X=0.204米  Y=0.565米 X=0.206米  Y=0.578米 304度0分44.27秒 2度14分2.70秒
	 Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
	 	angle_to_radian(304, 0, 44.27) + 0.2, angle_to_radian(2, 14, 2.7));//前加减小 后减减小
	 //12  X=0.206米  Y=0.578米  X=0.200米  Y=0.586米  X=0.188米  Y=0.580米 9度59分48.96秒 158度8分5.94秒
	 Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
	 	angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//前加减小 后减减小
	 //13  X=0.188米  Y=0.580米  X=0.181米  Y=0.593米 X=0.168米  Y=0.586米 343度34分17.94秒 163度17分6.93秒
	 Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
	 	angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//前加减小 后减减小
	 //X=0.163米  Y=0.592米 X=0.173米  Y=0.576米   X=0.178米  Y=0.557米 34度40分23.80秒 2度53分37.42秒
	 Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
	 	angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//前加减小 后减减小
	 //4  X=0.199米  Y=0.551米  X=0.189米  Y=0.558米  X=0.177米  Y=0.559米  39度26分10.94秒 100度12分16.85秒
		 Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		 	angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//前加减小 后减减小
	 //填充颜色    X=0.188米  Y=0.571米 
			 BoundaryFill(convert(188, 571, x, y).x, convert(188, 571, x, y).y,rgb);
			 //设置线型
			 setlinestyle(PS_SOLID, 5);
			 //设置线色
			 setlinecolor(RGB(10, 10, 10));
 //绿叶
	 	//11  X=0.195米  Y=0.555米 X=0.204米  Y=0.565米 X=0.206米  Y=0.578米 304度0分44.27秒 2度14分2.70秒
	 Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
	 	angle_to_radian(304, 0, 44.27) + 0.2, angle_to_radian(2, 14, 2.7));//前加减小 后减减小
	 //12  X=0.206米  Y=0.578米  X=0.200米  Y=0.586米  X=0.188米  Y=0.580米 9度59分48.96秒 158度8分5.94秒
	 Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
	 	angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//前加减小 后减减小
	 //13  X=0.188米  Y=0.580米  X=0.181米  Y=0.593米 X=0.168米  Y=0.586米 343度34分17.94秒 163度17分6.93秒
	 Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
	 	angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//前加减小 后减减小
	 //X=0.163米  Y=0.592米 X=0.173米  Y=0.576米   X=0.178米  Y=0.557米 34度40分23.80秒 2度53分37.42秒
	 Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
	 	angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//前加减小 后减减小
	 //4  X=0.199米  Y=0.551米  X=0.189米  Y=0.558米  X=0.177米  Y=0.559米  39度26分10.94秒 100度12分16.85秒
		 Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		 	angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//前加减小 后减减小
 }
 /// <summary>
/// 填充眼睛颜色
/// </summary>
/// <param name="x">指定坐标X</param>
/// <param name="y">指定坐标Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillEyes(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(rgb);
	 //左眼
	//14   X=0.320米  Y=0.476米 X=0.333米  Y=0.485米  X=0.336米  Y=0.493米 285度34分1.95秒 348度7分58.59秒
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(333, 485, x, y).x, convert(333, 485, x, y).y, convert(336, 493, x, y).x, convert(336, 493, x, y).y,
		 angle_to_radian(285, 34, 1.95), angle_to_radian(348, 7, 58.59));//前加减小 后减减小
	 //15   X=0.336米  Y=0.493米 X=0.332米  Y=0.503米 X=0.326米  Y=0.505米 355度19分23.78秒 90度28分44.97秒
	 Cirthree(convert(336, 493, x, y).x, convert(336, 493, x, y).y, convert(332, 503, x, y).x, convert(332, 503, x, y).y, convert(326, 505, x, y).x, convert(326, 505, x, y).y,
		 angle_to_radian(355, 19, 23.78), angle_to_radian(90, 28, 44.97));//前加减小 后减减小
	 //16   X=0.326米  Y=0.505米  X=0.308米  Y=0.498米  X=0.301米  Y=0.480米  85度38分9.36秒 184度18分40.34秒
	 Cirthree(convert(326, 505, x, y).x, convert(326, 505, x, y).y, convert(308, 498, x, y).x, convert(308, 498, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(85, 38, 9.36), angle_to_radian(184, 18, 40.34));//前加减小 后减减小
	 //17   X=0.301米  Y=0.480米   X=0.314米  Y=0.474米  X=0.320米  Y=0.476米 222度52分32.60秒 294度24分49.26秒
	 Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		 angle_to_radian(222, 52, 32.6), angle_to_radian(294, 24, 49.26));//前加减小 后减减小
	 //19    X=0.320米  Y=0.491米 X=0.327米  Y=0.488米 X=0.330米  Y=0.492米 197度24分32.69秒 352度36分56.48秒
	 Cirthree(convert(320, 491, x, y).x, convert(320, 491, x, y).y, convert(327, 488, x, y).x, convert(327, 488, x, y).y, convert(330, 492, x, y).x, convert(330, 492, x, y).y,
		 angle_to_radian(197, 24, 32.69), angle_to_radian(352, 36, 56.48) + 1.7);//前加减小 后减减小
	 // X=0.330米  Y=0.492米 X=0.328米  Y=0.496米  X=0.325米  Y=0.497米 1度22分48.28秒 93度16分57.13秒
	 Cirthree(convert(330, 492, x, y).x, convert(330, 492, x, y).y, convert(328, 496, x, y).x, convert(328, 496, x, y).y, convert(325, 497, x, y).x, convert(325, 497, x, y).y,
		 angle_to_radian(1, 22, 48.28) + 1.3, angle_to_radian(93, 16, 57.13));//前加减小 后减减小
	 // X=0.325米  Y=0.497米  X=0.321米  Y=0.494米  X=0.320米  Y=0.491米 98度35分16.88秒 方位角=174度23分34.16秒
	 Cirthree(convert(325, 497, x, y).x, convert(325, 497, x, y).y, convert(321, 494, x, y).x, convert(321, 494, x, y).y, convert(320, 491, x, y).x, convert(320, 491, x, y).y,
		 angle_to_radian(98, 35, 16.88), angle_to_radian(174, 23, 34.16));//前加减小 后减减小
	 //18
	 //X=0.320米  Y=0.476米 X=0.304米  Y=0.441米   X=0.301米  Y=0.480米  49度25分12.66秒 107度52分9.20秒
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(49, 25, 12.66) + 0.3, angle_to_radian(107, 52, 9.2) + 0.5);//前加减小 后减减小
	  //填充颜色    X=0.311米  Y=0.488米
	 BoundaryFill(convert(311, 488, x, y).x, convert(311, 488, x, y).y,rgb);
	 Sleep(100);

	 //右眼
	 //23  X=0.297米  Y=0.571米  X=0.305米  Y=0.578米 X=0.307米  Y=0.589米   290度23分17.75秒 8度41分14.46秒  
	 Cirthree(convert(297, 571, x, y).x, convert(297, 571, x, y).y, convert(305, 578, x, y).x, convert(305, 578, x, y).y, convert(307, 589, x, y).x, convert(307, 589, x, y).y,
		 angle_to_radian(290, 23, 17.75), angle_to_radian(8, 41, 14.46));//前加减小 后减减小
	 //20 X=0.307米  Y=0.589米  X=0.295米  Y=0.597米  X=0.281米  Y=0.594米 33度54分37.10秒 124度46分51.43秒   
	 Cirthree(convert(307, 589, x, y).x, convert(307, 589, x, y).y, convert(295, 597, x, y).x, convert(295, 597, x, y).y, convert(281, 594, x, y).x, convert(281, 594, x, y).y,
		 angle_to_radian(33, 54, 37.1), angle_to_radian(124, 46, 51.43));//前加减小 后减减小
	 //21  X=0.281米  Y=0.594米  X=0.273米  Y=0.588米  X=0.270米  Y=0.576米 110度6分20.99秒 182度51分36.95秒  
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//前加减小 后减减小
	 //22  X=0.270米  Y=0.576米  X=0.285米  Y=0.568米   X=0.297米  Y=0.571米 214度33分24.28秒 302度49分44.41秒  
	 Cirthree(convert(270, 576, x, y).x, convert(270, 576, x, y).y, convert(285, 568, x, y).x, convert(285, 568, x, y).y, convert(297, 571, x, y).x, convert(297, 571, x, y).y,
		 angle_to_radian(214, 33, 24.28), angle_to_radian(302, 49, 44.41));//前加减小 后减减小
	 //24  X=0.300米  Y=0.583米  X=0.296米  Y=0.578米   X=0.291米  Y=0.583米 359度59分60.00秒 182度7分45.49秒   
	 Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(296, 578, x, y).x, convert(296, 578, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		 angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49) - 0.5);//前加减小 后减减小
	 //X=0.300米  Y=0.583米  X=0.297米  Y=0.587米   X=0.291米  Y=0.583米 6度45分29.16秒 175度22分16.34秒
	 Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(297, 587, x, y).x, convert(297, 587, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		 angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49) - 0.2);//前加减小 后减减小
	 // 25  X=0.281米  Y=0.594米 X=0.242米  Y=0.587米  X=0.270米  Y=0.576米  357度25分51.22秒 296度58分46.19秒
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(357, 25, 51.22) - 0.2, angle_to_radian(296, 58, 46.19));//前加减小 后减减小
	   //填充颜色    X=0.282米  Y=0.579米 
	 BoundaryFill(convert(282, 579, x, y).x, convert(282, 579, x, y).y, rgb);
 }
 /// <summary>
/// 填充腮帮颜色
/// </summary>
/// <param name="x">指定坐标X</param>
/// <param name="y">指定坐标Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillCheeks(int x, int y, COLORREF rgb) {
	 //逆时针 弧度1增加线开头变短 弧度2减小 末尾线变短
	 //顺时针 弧度1减小线开头变短 弧度2增加 末尾线变短
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(rgb);
	 //左腮
	 //17   X=0.301米  Y=0.480米   X=0.314米  Y=0.474米  X=0.320米  Y=0.476米 222度52分32.60秒 294度24分49.26秒
	 Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		 angle_to_radian(222, 52, 32.6)+0.8, angle_to_radian(294, 24, 49.26));//前加减小 后减减小
	//18
	//X=0.320米  Y=0.476米 X=0.304米  Y=0.441米   X=0.301米  Y=0.480米  49度25分12.66秒 107度52分9.20秒
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(49, 25, 12.66) + 0.35, angle_to_radian(107, 52, 9.2) + 0.3);//前加减小 后减减小
	   //填充颜色    X=0.303米  Y=0.455米
	 BoundaryFill(convert(303, 455, x, y).x, convert(303, 455, x, y).y,rgb);
	 Sleep(100);

	 //右腮
	//21  X=0.281米  Y=0.594米  X=0.273米  Y=0.588米  X=0.270米  Y=0.576米 110度6分20.99秒 182度51分36.95秒  
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//前加减小 后减减小
	// 25  X=0.281米  Y=0.594米 X=0.242米  Y=0.587米  X=0.270米  Y=0.576米  357度25分51.22秒 296度58分46.19秒
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(357, 25, 51.22) - 0.2, angle_to_radian(296, 58, 46.19));//前加减小 后减减小
		//填充颜色    : X=0.257米  Y=0.586米  
	 BoundaryFill(convert(257, 586, x, y).x, convert(257, 586, x, y).y, rgb);
 }
 /// <summary>
/// 填充鼻子颜色
/// </summary>
/// <param name="x">指定坐标X</param>
/// <param name="y">指定坐标Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillNose(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(rgb);
	 //26 
	//X=0.298米  Y=0.525米  X=0.308米  Y=0.537米  X=0.293米  Y=0.541米  263度22分18.66秒 130度13分16.69秒
	 Cirthree(convert(298, 525, x, y).x, convert(298, 525, x, y).y, convert(308, 537, x, y).x, convert(308, 537, x, y).y, convert(293, 541, x, y).x, convert(293, 541, x, y).y,
		 angle_to_radian(263, 22, 18.66), angle_to_radian(130, 13, 16.69));//前加减小 后减减小
	 //27 
	 //X=0.299米  Y=0.525米  X=0.295米  Y=0.531米  X=0.296米  Y=0.543米 229度4分22.30秒 150度0分22.36秒
	 Cirthree(convert(299, 525, x, y).x, convert(299, 525, x, y).y, convert(295, 531, x, y).x, convert(295, 531, x, y).y, convert(296, 543, x, y).x, convert(293, 543, x, y).y,
		 angle_to_radian(229, 4, 22.3), angle_to_radian(150, 0, 22.36) - 0.5);//前加减小 后减减小
			//填充颜色    X=0.301米  Y=0.533米
	 BoundaryFill(convert(301, 533, x, y).x, convert(301, 533, x, y).y, rgb);
 }
 /// <summary>
/// 填充嘴巴颜色
/// </summary>
/// <param name="x">指定坐标X</param>
/// <param name="y">指定坐标Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillMouth(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(rgb);
	 //28 
	//X=0.294米  Y=0.533米  X=0.284米  Y=0.514米  X=0.290米  Y=0.499米  122度50分28.32秒 223度27分28.35秒
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		 angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//前加减小 后减减小
	 //29 
	 //X=0.294米  Y=0.533米 X=0.280米  Y=0.540米  X=0.273米  Y=0.561米 257度43分39.66秒 174度6分13.43秒
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		 angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//前加减小 后减减小
	 //30 
	 // X=0.285米  Y=0.519米  X=0.270米  Y=0.516米   X=0.259米  Y=0.521米 297度57分10.55秒 235度54分32.11秒
	 Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11) + 0.2);//前加减小 后减减小
	 //31
	 // X=0.280米  Y=0.540米  X=0.268米  Y=0.534米  X=0.259米  Y=0.521米 103度26分12.32秒 162度30分12.91秒
	 Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//前加减小 后减减小
	// X=0.277米  Y=0.526米  
	 BoundaryFill(convert(277, 526, x, y).x, convert(277, 526, x, y).y, rgb);
	 //设置线型
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(RGB(10, 10, 10));
	 //28 
   //X=0.294米  Y=0.533米  X=0.284米  Y=0.514米  X=0.290米  Y=0.499米  122度50分28.32秒 223度27分28.35秒
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		 angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//前加减小 后减减小
	 //29 
	 //X=0.294米  Y=0.533米 X=0.280米  Y=0.540米  X=0.273米  Y=0.561米 257度43分39.66秒 174度6分13.43秒
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		 angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//前加减小 后减减小
	 //30 
	 // X=0.285米  Y=0.519米  X=0.270米  Y=0.516米   X=0.259米  Y=0.521米 297度57分10.55秒 235度54分32.11秒
	 Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11) + 0.2);//前加减小 后减减小
	 //31
	 // X=0.280米  Y=0.540米  X=0.268米  Y=0.534米  X=0.259米  Y=0.521米 103度26分12.32秒 162度30分12.91秒
	 Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//前加减小 后减减小
 }
 /// <summary>
/// 填充脚丫颜色
/// </summary>
/// <param name="x">指定坐标X</param>
/// <param name="y">指定坐标Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillFoots(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //设置线色
	 setlinecolor(rgb);

	 //左脚
		 // X=0.102米  Y=0.353 X=0.095米  Y=0.352米 X=0.090米  Y=0.363米  297度41分28.87秒 161度26分56.78秒
	 Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(95, 352, x, y).x, convert(95, 352, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		 angle_to_radian(297, 41, 28.87), angle_to_radian(161, 26, 56.78));//前加减小 后减减小
	 // X=0.102米  Y=0.353  X=0.098米  Y=0.362米 X=0.090米  Y=0.363米 352度46分12.08秒 106度22分13.57秒
	 Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(98, 362, x, y).x, convert(98, 362, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		 angle_to_radian(352, 46, 12.08), angle_to_radian(106, 22, 13.57) - 0.3);//前加减小 后减减小
	 // X=0.096米  Y=0.358米
	 BoundaryFill(convert(96, 358, x, y).x, convert(96, 358, x, y).y, rgb);
	 Sleep(100);

	 // X=0.116米  Y=0.362米 X=0.108米  Y=0.360米  X=0.101米  Y=0.367米  317度39分8.35秒 187度5分41.70秒
	 Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(108, 360, x, y).x, convert(108, 360, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		 angle_to_radian(317, 39, 8.35), angle_to_radian(187, 5, 41.7) - 0.3);//前加减小 后减减小
	 // X=0.116米  Y=0.362米  X=0.111米  Y=0.369米 X=0.101米  Y=0.367米  X=0.101米  Y=0.367米=8度17分27.46秒  =136度27分22.58秒
	 Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(111, 369, x, y).x, convert(111, 369, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		 angle_to_radian(8, 17, 27.46), angle_to_radian(136, 27, 22.58));//前加减小 后减减小
	 //X=0.108米  Y=0.365米
	 BoundaryFill(convert(108, 365, x, y).x, convert(108, 365, x, y).y, rgb);
	 Sleep(100);

	 //X=0.117米  Y=0.376米   X=0.109米  Y=0.372米  X=0.101米  Y=0.381米 329度10分9.96秒 181度22分7.37秒
	 Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(109, 372, x, y).x, convert(109, 372, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		 angle_to_radian(329, 10, 9.96), angle_to_radian(181, 22, 7.37));//前加减小 后减减小
	 //X=0.117米  Y=0.376米   X=0.111米  Y=0.383米  X=0.101米  Y=0.381米 15度26分31.36秒 135度5分45.98秒
	 Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(111, 383, x, y).x, convert(111, 383, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		 angle_to_radian(15, 26, 31.36), angle_to_radian(135, 5, 45.98));//前加减小 后减减小
	 // X=0.108米  Y=0.378米 
	 BoundaryFill(convert(108, 378, x, y).x, convert(108, 378, x, y).y, rgb);
	 Sleep(100);

	 //X=0.096米  Y=0.372米 X=0.087米  Y=0.370米  X=0.074米  Y=0.386米 299度3分38.35秒 171度38分8.91秒
	 Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(87, 370, x, y).x, convert(87, 370, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		 angle_to_radian(299, 3, 38.35), angle_to_radian(171, 38, 8.91));//前加减小 后减减小
	 //X=0.096米  Y=0.372米 X=0.090米  Y=0.387米   X=0.074米  Y=0.386米  343度40分27.29秒 127度1分19.97秒
	 Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(90, 387, x, y).x, convert(90, 387, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		 angle_to_radian(343, 40, 27.29), angle_to_radian(127, 1, 19.97));//前加减小 后减减小
	 //  X=0.084米  Y=0.379米
	 BoundaryFill(convert(84, 379, x, y).x, convert(84, 379, x, y).y,rgb);
	 Sleep(100);

	 //右脚
	 //  X=0.116米  Y=0.642米   X=0.111米  Y=0.636米   X=0.101米  Y=0.638米 341度40分12.79秒 222度43分32.33秒
	 Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(111, 636, x, y).x, convert(111, 636, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		 angle_to_radian(341, 40, 12.79), angle_to_radian(222, 43, 32.33));//前加减小 后减减小
	 //X=0.116米  Y=0.642米   X=0.105米  Y=0.645米   X=0.101米  Y=0.638米 29度17分54.10秒 175度5分51.02秒
	 Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(105, 645, x, y).x, convert(105, 645, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		 angle_to_radian(29, 17, 54.1), angle_to_radian(175, 5, 51.02));//前加减小 后减减小
	 // X=0.108米  Y=0.639米 
	 BoundaryFill(convert(108, 639, x, y).x, convert(108, 639, x, y).y, rgb);
	 Sleep(100);

	 // X=0.115米  Y=0.659米 X=0.109米  Y=0.649米 X=0.101米  Y=0.651米 11度34分2.18秒 226度10分24.04秒
	 Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(109, 649, x, y).x, convert(109, 649, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		 angle_to_radian(11, 34, 2.18), angle_to_radian(226, 10, 24.04));//前加减小 后减减小
	 //X=0.115米  Y=0.659米  X=0.105米  Y=0.658米 X=0.101米  Y=0.651米 61度48分24.44秒 175度56分1.78秒
	 Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(105, 658, x, y).x, convert(105, 658, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		 angle_to_radian(61, 48, 24.44), angle_to_radian(175, 59, 1.78));//前加减小 后减减小
	 //  X=0.110米  Y=0.653米
	 BoundaryFill(convert(110, 653, x, y).x, convert(110, 653, x, y).y,rgb);
	 Sleep(100);

	 // X=0.103米  Y=0.665米  X=0.096米  Y=0.656米  X=0.091米  Y=0.657米 7度6分59.98秒 242度31分15.10秒
	 Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(96, 656, x, y).x, convert(96, 656, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		 angle_to_radian(7, 6, 59.98), angle_to_radian(242, 31, 15.1));//前加减小 后减减小
	 //X=0.103米  Y=0.665米  X=0.098米  Y=0.667米  X=0.091米  Y=0.657米 57度19分9.55秒 192度19分5.54秒
	 Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(98, 667, x, y).x, convert(98, 667, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		 angle_to_radian(57, 19, 9.55), angle_to_radian(192, 19, 5.54));//前加减小 后减减小
		 //  X=0.095米  Y=0.659米
	 BoundaryFill(convert(95, 659, x, y).x, convert(95, 659, x, y).y,rgb);
	 Sleep(100);

	 //  X=0.096米  Y=0.648米  X=0.085米  Y=0.630米  X=0.074米  Y=0.632米 13度3分12.91秒 239度15分54.89秒
	 Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(85, 630, x, y).x, convert(85, 630, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		 angle_to_radian(13, 3, 12.91), angle_to_radian(239, 15, 54.89));//前加减小 后减减小
	 //X=0.096米  Y=0.648米  X=0.087米  Y=0.650米   X=0.074米  Y=0.632米 59度0分34.03秒 193度18分33.76秒
	 Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(87, 650, x, y).x, convert(87, 650, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		 angle_to_radian(59, 0, 34.03), angle_to_radian(193, 18, 33.76));//前加减小 后减减小
	 //  X=0.090米  Y=0.642米
	 BoundaryFill(convert(90, 642, x, y).x, convert(90, 642, x, y).y, rgb);
 }
 /// <summary>
 /// 设置色卡
 /// </summary>
 /// <param name="x">色卡左上角横坐标</param>
 /// <param name="y">色卡左上角纵坐标</param>
 void SetColorCard(int x, int y) {
	 const int wide = 5;
	 const int height = 23;
	 int x0 = x;
	 int y0 = y;//保留原有信息
	 //设置填充颜色
	//1   DARK SKIN
	 setfillcolor(RGB(94,28,12));
	 POINT pts1[] = { {x, y}, {x+200, y}, {x+200, y+height}, {x, y+height} };
	 fillpolygon(pts1, 4);
	 y += wide;
	 y += height;
	 //2 LIGHT SKIN
	 setfillcolor(RGB(241 ,149 ,108 ));
	 POINT pts2[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts2, 4);
	 y += wide;
	 y += height;
	 //3  腮帮
	 setfillcolor(RGB(254 ,204 ,203 ));
	 POINT pts3[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts3, 4);
	 y += wide;
	 y += height;
	 //4  BLUE SKY
	 setfillcolor(RGB(97 ,117 ,171 ));
	 POINT pts4[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts4, 4);
	 y += wide;
	 y += height;
	 //5   FOLLIAGE
	 setfillcolor(RGB(91 ,103 ,39 ));
	 POINT pts5[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts5, 4);
	 y += wide;
	 y += height;
	 //6   BLUE FLOWER
	 setfillcolor(RGB( 163, 131,196 ));
	 POINT pts6[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts6, 4);
	 y += wide;
	 y += height;
	 //7  BLUISH GREEN
	 setfillcolor(RGB( 141,253 ,153 ));
	 POINT pts7[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts7, 4);
	 y += wide;
	 y += height;
	 //8   ORANGE
	 setfillcolor(RGB(235 ,97 , 0));
	 POINT pts8[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts8, 4);
	 y += wide;
	 y += height;
	 //9  BLUE
	 setfillcolor(RGB(1, 0, 142 ));
	 POINT pts9[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts9, 4);
	 y += wide;
	 y += height;
	 //10  MODERATE RED
	 setfillcolor(RGB(220,30 ,42 ));
	 POINT pts10[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts10, 4);
	 y += wide;
	 y += height;
	 //11 PURPLE
	 setfillcolor(RGB(69 , 0,69 ));
	 POINT pts11[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts11, 4);
	 y += wide;
	 y += height;
	 //12  YELLOW GREEN
	 setfillcolor(RGB(187 , 255,20 ));
	 POINT pts12[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts12, 4);
	 y += wide;
	 y += height;
	 //13  ORANGE YELLOW
	 setfillcolor(RGB(254 ,143 ,1 ));
	 POINT pts13[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts13, 4);
	 y += wide;
	 y += height;
	 //14  GREEN
	 setfillcolor(RGB(65 ,173 ,36 ));
	 POINT pts14[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts14, 4);
	 y += wide;
	 y += height;
	 //height  RED
	 setfillcolor(RGB( 204,0 , 1));
	 POINT ptsheight[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(ptsheight, 4);
	 y += wide;
	 y += height;
	 //16  YELLOW
	 setfillcolor(RGB(255, 217,0 ));
	 POINT pts16[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts16, 4);
	 y += wide;
	 y += height;
	 //17   MAGENTA
	 setfillcolor(RGB(207 ,3 ,124 ));
	 POINT pts17[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts17, 4);
	 y += wide;
	 y += height;
	 //18   CYAN
	 setfillcolor(RGB(0 , 147, 190));
	 POINT pts18[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts18, 4);
	 y += wide;
	 y += height;
	 //19  DARK
	 setfillcolor(RGB(0 ,0 ,0 ));
	 POINT pts19[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts19, 4);
	 y += wide;
	 y += height;
	 //20  耳朵
	 setfillcolor(RGB(255 ,220 ,220 ));
	 POINT pts20[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts20, 4);
	 y += wide;
	 y += height;	


	 //第二列
	 y = y0;
	 x = x0 + 300;
	 //1   鼻子
	 setfillcolor(RGB(62, 5, 14));
	 POINT pts21[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts21, 4);
	 y += wide;
	 y += height;
	 //2 胭脂
	 setfillcolor(RGB(157, 41, 50));
	 POINT pts22[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts22, 4);
	 y += wide;
	 y += height;
	 //3  牙白
	 setfillcolor(RGB(239, 222, 176));
	 POINT pts23[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts23, 4);
	 y += wide;
	 y += height;
	 //4  驼色
	 setfillcolor(RGB(168, 132, 98));
	 POINT pts24[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts24, 4);
	 y += wide;
	 y += height;
	 //5   秋香色
	 setfillcolor(RGB(217, 182, 18));
	 POINT pts25[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts25, 4);
	 y += wide;
	 y += height;
	 //6   竹青
	 setfillcolor(RGB(120, 146, 98));
	 POINT pts26[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts26, 4);
	 y += wide;
	 y += height;
	 //7  黛色
	 setfillcolor(RGB(73, 65, 102));
	 POINT pts27[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts27, 4);
	 y += wide;
	 y += height;
	 //8   鸦青
	 setfillcolor(RGB(66, 75, 80));
	 POINT pts28[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts28, 4);
	 y += wide;
	 y += height;
	 //9  檀
	 setfillcolor(RGB(179, 109, 970));
	 POINT pts29[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts29, 4);
	 y += wide;
	 y += height;
	 //10  黛蓝
	 setfillcolor(RGB(65, 80, 101));
	 POINT pts30[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts30, 4);
	 y += wide;
	 y += height;
	 //11 月白
	 setfillcolor(RGB(215, 236, 241));
	 POINT pts31[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts31, 4);
	 y += wide;
	 y += height;
	 //12  水绿
	 setfillcolor(RGB(212, 242, 232));
	 POINT pts32[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts32, 4);
	 y += wide;
	 y += height;
	 //13  炎
	 setfillcolor(RGB(255, 51, 0));
	 POINT pts33[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts33, 4);
	 y += wide;
	 y += height;
	 //14  靛青
	 setfillcolor(RGB(23, 124, 176));
	 POINT pts34[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts34, 4);
	 y += wide;
	 y += height;
	 //茶白
	 setfillcolor(RGB(243, 248, 241));
	 POINT pt35[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pt35, 4);
	 y += wide;
	 y += height;
	 //16  赤
	 setfillcolor(RGB(195, 39, 43));
	 POINT pts36[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts36, 4);
	 y += wide;
	 y += height;
	 //17   绾
	 setfillcolor(RGB(169, 129, 117));
	 POINT pts37[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts37, 4);
	 y += wide;
	 y += height;
	 //18   嘴巴
	 setfillcolor(RGB(255, 158, 159));
	 POINT pts38[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts38, 4);
	 y += wide;
	 y += height;
	 //19  砖红
	 setfillcolor(RGB(156, 102, 101));
	 POINT pts39[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts39, 4);
	 y += wide;
	 y += height;
	 //20  紫罗兰
	 setfillcolor(RGB(138, 43, 226));
	 POINT pts40[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts40, 4);
	 y += wide;
	 y += height;
 }
 /// <summary>
 /// 游戏开始
 /// </summary>
 /// <param name="x">指定横坐标</param>
 /// <param name="y">指定纵坐标</param>
 void GameStart(int x,int y) {
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 TCHAR s1[] = _T("填色游戏");
	 outtextxy(200, 30, s1);
	 Sleep(2000);
	 DelText();
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 TCHAR s2[] = _T("点击屏幕开始游戏");
	 outtextxy(150, 30, s2);
	 MOUSEMSG m;		// 定义鼠标消息
	 TCHAR s3[] = _T("根据提示选择右方色卡中的颜色");
	 int off = 0;//判断是否左键单击 0为没有 1位有
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 settextcolor(RGB(241, 149, 108));
			 settextstyle(40, 0, _T("楷体"));
			 outtextxy(10, 30, s3);
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off==1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 Sleep(2000);
	 off = 0;
	 DelText();
	 TCHAR s4[] = _T("请选择耳朵的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s4);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillLeftEar(x,y,getpixel(m.x,m.y));			
			Sleep(100);
			FillRightEar(x, y, getpixel(m.x, m.y));
			off = 1;
			break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s5[] = _T("请选择眼睛的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s5);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillEyes(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s6[] = _T("请选择脸颊的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s6);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillCheeks(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s7[] = _T("请选择鼻子的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s7);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillNose(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s8[] = _T("请选择嘴巴的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s8);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillMouth(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s9[] = _T("请选择胡萝卜的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s9);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillCarrot(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s10[] = _T("请选择绿叶的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s10);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillLeaf(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 off = 0;
	 TCHAR s11[] = _T("请选择脚丫的颜色");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s11);
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 FillFoots(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
	 DelText();
	 TCHAR s12[] = _T("点击鼠标继续");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 outtextxy(150, 30, s12);
	 off = 0;
	 TCHAR s13[] = _T("真棒！极乐净土送给你");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("楷体"));
	 FlushMouseMsgBuffer();
	 // 获取一条鼠标消息
	 while (true)
	 {
		 // 获取一条鼠标消息
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();		
			 outtextxy(150, 30, s13);
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// 按鼠标右键退出程序
		 }
		 if (off == 1)
		 {
			 break;//退出获取鼠标事件
		 }
	 }
 }
 void DelText() {
	 //消除字体
	 setfillcolor(RGB(255, 255, 255));
	 setlinecolor(RGB(255, 255, 255));
	 POINT pts[] = { {0, 0}, {590, 0}, {590, 80}, {0, 80} };
	 fillpolygon(pts, 4);
 }



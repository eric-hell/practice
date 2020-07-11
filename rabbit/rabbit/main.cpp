#include<graphics.h>
#include<Windows.h>
#include<math.h>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2);
double HuDu(double x0, double y0, double x1, double y1);
double Cross(double X1, double Y1, double X2, double Y2, double X3, double Y3);
void drawrabbit(double x, double y, double scale);
double angle_to_radian(double degree, double min, double second);
POINT convert(double x, double y, double X, double Y);
int main(void) {
	//初始化图形
	initgraph(800, 600);
	//设置背景为白色
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	//画头部弧  X=0.438米  Y=0.484米  X=0.432米  Y=0.576米  X=0.383米  Y=0.653米 
	int x = convert(247, 366, 400, 225).x;
	int y = convert(351, 388, 400, 225).y;
	//double m = atan((136.0-263.0)/(520.0-385.0));
	//double n = atan((136.0 - 263.0) / (520.0 - 385.0));
	drawrabbit(400, 225, 1.0);



	system("pause");
	return 0;
}
/// <summary>
/// 三点画圆弧
/// </summary>
/// <param name="P1">起始点</param>
/// <param name="P2">第二点</param>
/// <param name="P3">终点</param>
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
/// <param name="rongcha">容差</param>
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
/// 三点顺时针绘制圆弧
/// </summary>
/// <param name="X1">第一个点的X</param>
/// <param name="Y1">第一个点的Y</param>
/// <param name="X2">第二个点的X</param>
/// <param name="Y2">第二个点的Y</param>
/// <param name="X3">第三个点的X</param>
/// <param name="Y3">第三个点的Y</param>
/// <param name="rongcha">容差</param>
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
	const int delay = 500;
	//设置线型
	setlinestyle(PS_SOLID, 5);
	//设置线色
	setlinecolor(RGB(10, 10, 10));

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
		angle_to_radian(227, 7, 42.41), angle_to_radian(175, 45, 26.43));
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
	//X=0.180米  Y=0.456米  X=0.175米  Y=0.461米  X=0.162米  Y=0.458米 33度6分54.28秒  =22度59分33.74秒
	Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
		angle_to_radian(33, 6, 54.28),angle_to_radian(22, 59, 33.74));//前加减小 后减减小
	Sleep(delay);
	// X=0.162米  Y=0.458米   X=0.148米  Y=0.437米 X=0.144米  Y=0.416米 132度54分8.27秒 181度56分3.85秒
	Cirthree(convert(162, 458, x, y).x, convert(162, 458, x, y).y, convert(148, 437, x, y).x, convert(148, 437, x, y).y, convert(144, 416, x, y).x, convert(144, 416, x, y).y,
		angle_to_radian(132, 54, 8.27) , angle_to_radian(181, 56, 3.85) );//前加减小 后减减小
	Sleep(delay);

	//右手


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
	if (((x - x0) > 0 && (y - y0) > 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//第二象限
	if ((x - x0) > 0 && (y - y0) < 0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//第三象限
	if ((x - x0) < 0 && (y - y0) < 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//第四象限
	if ((x - x0) < 0 && (y - y0) > 0)
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


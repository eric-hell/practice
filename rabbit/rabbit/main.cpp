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
	//��ʼ��ͼ��
	initgraph(1200, 700);
	//���ñ���Ϊ��ɫ
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	//setlinecolor(RGB(255, 0, 0));
	////��ͷ����  X=0.438��  Y=0.484��  X=0.432��  Y=0.576��  X=0.383��  Y=0.653�� 
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
/// ���㻭Բ��
/// </summary>
/// <param name="X1">��һ���������</param>
/// <param name="Y1">��һ����������</param>
/// <param name="X2">�ڶ����������</param>
/// <param name="Y2">�ڶ�����������</param>
/// <param name="X3">�������������</param>
/// <param name="Y3">��������������</param>
/// <param name="hudu1">��ʼ����</param>
/// <param name="hudu2">��������</param>
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
	//�жϵ�һ������ڶ������λ�ã�ȷ����˳ʱ�뻭������ʱ�뻭
	//һ������˳ʱ��
	if (Cross(X1, Y1, X2, Y2, X3, Y3) > 0)
	{
		Cirshun(X1, Y1, X2, Y2, X3, Y3, hudu1, hudu2);
	}
	if (Cross(X1, Y1, X2, Y2, X3, Y3) < 0)
	{
		Cirni(X1, Y1, X2, Y2, X3, Y3, hudu1, hudu2);
	}

	//int quadrant1 = 0;//�ڶ�������ڵ�һ���������λ��
	//int quadrant2 = 0;//������������ڵڶ����������λ��
	////ȷ��ǰ�������������λ��
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
	////ȷ�����������������λ��
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
	////����������ʱ��
	//if (quadrant1 == 1 && quadrant2 == 2 || quadrant1 ==1  && quadrant2 == 3
	//	|| quadrant1 == 1 && quadrant2 == 4 || quadrant1 == 2 && quadrant2 == 2
	//	|| quadrant1 == 2 && quadrant2 == 3 || quadrant1 == 3 && quadrant2 == 1
	//	|| quadrant1 == 3 && quadrant2 == 4
	//	|| quadrant1 == 4 && quadrant2 == 1 || quadrant1 == 4 && quadrant2 == 2) {
	//	Cirni(X1, Y1, X2, Y2, X3, Y3,rongcha);
	//}
}
/// <summary>
/// ������ʱ�����Բ��
/// </summary>
/// <param name="X1">��һ�����X</param>
/// <param name="Y1">��һ�����Y</param>
/// <param name="X2">�ڶ������X</param>
/// <param name="Y2">�ڶ������Y</param>
/// <param name="X3">���������X</param>
/// <param name="Y3">���������Y</param>
/// <param name="hudu1">��ʼ����</param>
/// <param name="hudu1">�������Ȼ���</param>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
	//��Բ��
	//��L1  ��бʽ�󽻵�
	double m = (double)(X2 - X1) / (Y1 - Y2);//3.833333333
	double p = (double)(X2 + X1) / 2;//339.5
	double q = (double)(Y2 + Y1) / 2;//84
	double n = (double)(X3 - X2) / (Y2 - Y3);//1.75
	double w = (double)(X3 + X2) / 2;//317.5
	double v = (double)(Y3 + Y2) / 2;//93 ����Ϊ���ɱ�����������Ľ��
	//x��yΪԲ������
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//��뾶
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
	//�󻡶���Ҫ���ĸ����޽����� ��Բ��Ϊԭ�� �жϵ������Բ��ķ���
	//��Բ��  ���ڲ����������ͼ���������᲻ͬ����������/2
	//double hudu1 = HuDu(x, y, X1, Y1)+rongcha;//start hudu
	//double hudu2 = HuDu(x, y, X3, Y3) -rongcha;//end hudu
	//double hudu3 = 0.0;
	if (hudu1 >= hudu2)
	{
		hudu2 += 2 * acos(-1);
	}
	////else//���ȴ�Ҫ��ʱ��ת�Ǿ�С�Ǽ�2���
	////{
	////	hudu3 = hudu1;
	////	hudu1 = hudu2;
	////	hudu2 = hudu3 + 2 * acos(-1);

	////}
	arc(x + r, y + r, x - r, y - r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// ������ʱ�����Բ��
/// </summary>
/// <param name="X1">��һ�����X</param>
/// <param name="Y1">��һ�����Y</param>
/// <param name="X2">�ڶ������X</param>
/// <param name="Y2">�ڶ������Y</param>
/// <param name="X3">���������X</param>
/// <param name="Y3">���������Y</param>
/// <param name="hudu1">��ʼ����</param>
/// <param name="hudu1">�������Ȼ���</param>
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double hudu1, double hudu2) {
	//��Բ��
	//��L1  ��бʽ�󽻵�
	double m = (double)(X2 - X1) / (Y1 - Y2);
	double p = (double)(X2 + X1) / 2;
	double q = (double)(Y2 + Y1) / 2;
	double n = (double)(X3 - X2) / (Y2 - Y3);
	double w = (double)(X3 + X2) / 2;
	double v = (double)(Y3 + Y2) / 2;//����Ϊ���ɱ�����������Ľ��
	//x��yΪԲ������
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//��뾶
	double r = (double)sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//�󻡶���Ҫ���ĸ����޽����� ��Բ��Ϊԭ�� �жϵ������Բ��ķ���
	//��Բ�� 
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
	else//����С��Ҫ˳ʱ��ת�Ǿ�С�Ǽ�2���
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
/// ��λ�ǽǶ�ת����
/// </summary>
/// <param name="degree">����</param>
/// <param name="min">����</param>
/// <param name="second">����</param>
/// <returns></returns>
double angle_to_radian(double degree, double min, double second)
{
	//450�ȼ�ȥx����ʵ�ʶ���
	double Tsecond = degree * 3600 + min * 60 + second;//������
	int Ysecond = 450 * 3600 - Tsecond;//ʣ��������
	second = Ysecond % 60;
	min = ((int)(Ysecond - second) % 3600) / 60;
	degree = (Ysecond - min * 60 - second) / 3600;
	double flag = (degree < 0) ? -1.0 : 1.0;			//�ж�����
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
/// �󻡶�ֵ
/// </summary>
/// <param name="x0">Բ�ĺ�����</param>
/// <param name="y0">Բ��������</param>
/// <param name="x1">�������</param>
/// <param name="y1">��������</param>
/// <returns>����ֵ</returns>
double HuDu(double x0, double y0, double x1, double y1) {
	const double PI = acos(-1);
	x0 = (double)x0;
	y0 = (double)y0;
	x1 = (double)x1;
	y1 = (double)y1;
	if ((x1 > x0) && (y1 == y0))//x+����
	{
		double hudu = 0.0;
		return hudu;
	}
	if ((x1 < x0) && (y1 == y0))//x-����
	{
		double hudu = PI;
		return hudu;
	}
	if ((x1 == x0) && (y1 > y0))//y+����
	{
		double hudu = PI / 2;
		return hudu;
	}
	if ((x1 == x0) && (y1 < y0))//y-����
	{
		double hudu = PI * 3 / 2;
		return hudu;
	}
	if ((x1 > x0) && (y1 < y0))//��һ������
	{
		double hudu = (double)atan((y1 - y0) / (x0 - x1));
		return hudu;
	}
	if ((x1 < x0) && (y1 < y0))//�ڶ�������
	{
		double hudu = PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 > y0)))//����������
	{
		double hudu = (double)3 * (acos(-1)) / 2 - atan(abs((int)((y1 - y0) / (x1 - x0))));
		return hudu;
	}
	if ((x1 > x0) && (y1 > y0))//����������
	{
		double hudu = (double)2 * PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
}
/// <summary>
/// ��������ͼ��
/// </summary>
/// <param name="x">�������ĵĺ�����</param>
/// <param name="y">�������ĵ�������</param>
/// <param name="scale">���Ŵ�С</param>
void drawrabbit(double x, double y, double scale) {
	setaspectratio(scale,scale);
	const int delay = 100;
	setlinestyle(PS_SOLID, 5);
	//������ɫ
	setlinecolor(RGB(10, 10, 10));
	//�Ȼ�����ɫ����
	//��߶���
	//setlinestyle(PS_SOLID, 5);
	////������ɫ
	//setlinecolor(RGB(255, 209, 208));
	////ֱ�� X=0.445��  Y=0.436��    X=0.451��  Y=0.453�� 
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
	////X=0.445��  Y=0.436��  X=0.420��  Y=0.440��
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	////X=0.451��  Y=0.453��   X=0.432��  Y=0.461��
	//line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	////X = 0.432��  Y = 0.461�� X=0.427��  Y=0.451�� X=0.420��  Y=0.440�� 338��16��33.76�� 320��18��27.11��
	//Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
	//	angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
	////�����ɫ X=0.437��  Y=0.447�� 
	//BoundaryFill(convert(437, 447, x, y).x, convert(437, 447, x, y).y,255,209,208);
	////��������
	//setlinestyle(PS_SOLID, 5);
	////������ɫ
	//setlinecolor(RGB(10, 10, 10));
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
	////X=0.445��  Y=0.436��  X=0.420��  Y=0.440��
	//line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	////X=0.451��  Y=0.453��   X=0.432��  Y=0.461��
	//line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	////X = 0.432��  Y = 0.461�� X=0.427��  Y=0.451�� X=0.420��  Y=0.440�� 338��16��33.76�� 320��18��27.11��
	//Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
	//	angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));


	//������߶���    X=0.455��  Y=0.464��  X=0.414��  Y=0.351��
	line((int)convert(455, 464, x, y).x, convert(455, 464, x, y).y, convert(414, 351, x, y).x, convert(414, 351, x, y).y);
	Sleep(delay);
	// X=0.414��  Y=0.351��  X=0.506��  Y=0.454��
	line(convert(414, 351, x, y).x, convert(414, 351, x, y).y, convert(506, 454, x, y).x, convert(506, 454, x, y).y);
	Sleep(delay);
	// X=0.506��  Y=0.454��  X=0.438��  Y=0.484��
	line(convert(506, 454, x, y).x, convert(506, 454, x, y).y, convert(438, 484, x, y).x, convert(438, 484, x, y).y);
	Sleep(delay);
	//X=0.445��  Y=0.436��  X=0.420��  Y=0.440��
	line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
	Sleep(delay);
	//X=0.451��  Y=0.453��   X=0.432��  Y=0.461��
	line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
	Sleep(delay);

	//�����ұ߶��� X=0.386��  Y=0.681�� X=0.283��  Y=0.747��
	line(convert(386, 681, x, y).x, convert(386, 681, x, y).y, convert(283, 747, x, y).x, convert(283, 747, x, y).y);
	Sleep(delay);
	// X=0.283��  Y=0.747��  X=0.419��  Y=0.718��
	line(convert(283, 747, x, y).x, convert(283, 747, x, y).y, convert(419, 718, x, y).x, convert(419, 718, x, y).y);
	Sleep(delay);
	// X=0.419��  Y=0.718�� X=0.383��  Y=0.653��
	line(convert(419, 718, x, y).x, convert(419, 718, x, y).y, convert(383, 653, x, y).x, convert(383, 653, x, y).y);
	Sleep(delay);
	//X=0.378��  Y=0.686�� X=0.365��  Y=0.665�� 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	Sleep(delay);
	// X=0.362��  Y=0.696�� X=0.341��  Y=0.676��
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	Sleep(delay);

	//1��ͷ����  X=0.438��  Y=0.484��  X=0.432��  Y=0.461��  X=0.420��  Y=0.440��                                          ��λ��=354��58��9.06��  320��18��27.11��
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
		angle_to_radian(354, 58, 9.06), angle_to_radian(320, 18, 27.11));
	Sleep(delay);
	// X=0.420��  Y=0.440��  X=0.389��  Y=0.408��   X=0.351��  Y=0.388�� 325��28��32.40�� 288��55��30.64��
	//2
	Cirthree(convert(420, 440, x, y).x, convert(420, 440, x, y).y, convert(389, 408, x, y).x, convert(389, 408, x, y).y, convert(351, 388, x, y).x, convert(351, 388, x, y).y,
		angle_to_radian(325, 28, 32.4), angle_to_radian(288, 55, 30.64));
	Sleep(delay);
	// X=0.438��  Y=0.484��  X=0.432��  Y=0.576��  X=0.381��  Y=0.654�� ��λ��=349��14��56.30�� 47��34��39.20��
	//3
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 576, x, y).x, convert(432, 576, x, y).y, convert(381, 654, x, y).x, convert(381, 654, x, y).y,
		angle_to_radian(349, 14, 56.3), angle_to_radian(47, 34, 39.20));
	Sleep(delay);
	//X=0.381��  Y=0.654��   X=0.341��  Y=0.676��   X=0.253��  Y=0.677��  50��17��43.28�� 108��32��50.81��
	//4
	Cirthree(convert(381, 654, x, y).x, convert(381, 654, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y, convert(253, 677, x, y).x, convert(253, 677, x, y).y,
		angle_to_radian(50, 17, 43.28), angle_to_radian(108, 32, 50.81));
	Sleep(delay);
	//X=0.351��  Y=0.388��  X=0.287��  Y=0.354��   X=0.247��  Y=0.366�� 325��9��39.56�� 238��54��56.29��
	//5
	Cirthree(convert(351, 388, x, y).x, convert(351, 388, x, y).y, convert(287, 354, x, y).x, convert(287, 354, x, y).y, convert(247, 366, x, y).x, convert(247, 366, x, y).y,
		angle_to_radian(325, 9, 39.06), angle_to_radian(238, 54, 56.29));
	Sleep(delay);
	//�ұ�������
	// X=0.253��  Y=0.677��   X=0.195��  Y=0.675��  X=0.165��  Y=0.641�� 66��22��55.43�� 157��51��52.67��
	//6
	Cirthree(convert(253, 677, x, y).x, convert(253, 677, x, y).y, convert(195, 675, x, y).x, convert(195, 675, x, y).y, convert(165, 641, x, y).x, convert(165, 641, x, y).y,
		angle_to_radian(66, 22, 55.43)+0.04, angle_to_radian(157, 51, 52.67));
	Sleep(delay);
	//������������·�
	//X=0.247��  Y=0.366�� X=0.227��  Y=0.394�� X=0.222��  Y=0.431��  227��7��42.41�� 175��45��26.43��
	//7
	Cirthree(convert(247, 366, x, y).x, convert(247, 366, x, y).y, convert(227, 394, x, y).x, convert(227, 394, x, y).y, convert(222, 431, x, y).x, convert(222, 431, x, y).y,
		angle_to_radian(227, 7, 42.41)-0.1, angle_to_radian(175, 45, 26.43));
	Sleep(delay);
	//�����
	//X=0.227��  Y=0.394��   X=0.170��  Y=0.377��  X=0.129��  Y=0.371��   291��29��27.73�� 274��29��11.55��
	//8
	Cirthree(convert(227, 394, x, y).x, convert(227, 394, x, y).y, convert(170, 377, x, y).x, convert(170, 377, x, y).y, convert(129, 371, x, y).x, convert(129, 371, x, y).y,
		angle_to_radian(291, 29, 27.73), angle_to_radian(274, 29, 11.55)-0.02);
	Sleep(delay);
	//�ұ���
	//X=0.165��  Y=0.641�� X=0.146��  Y=0.645��  X=0.127��  Y=0.647��  73��18��18.31�� 89��29��55.92��
	//9
	Cirthree(convert(165, 641, x, y).x, convert(165, 641, x, y).y, convert(146, 645, x, y).x, convert(146, 645, x, y).y, convert(127, 647, x, y).x, convert(127, 647, x, y).y,
		angle_to_radian(73, 18, 18.31)-0.04, angle_to_radian(89, 29, 55.92)+0.04);
	Sleep(delay);
	//��߽�
	// X=0.119��  Y=0.386�� X=0.129��  Y=0.371��  X=0.121��  Y=0.347�� 52��48��1.85�� 311��29��2.75��
	//10
	Cirthree(convert(119, 386, x, y).x, convert(119, 386, x, y).y, convert(129, 371, x, y).x, convert(129, 371, x, y).y, convert(121, 347, x, y).x, convert(121, 347, x, y).y,
		angle_to_radian(52, 48, 1.85), angle_to_radian(311, 29, 2.75));
	Sleep(delay);
	// X=0.121��  Y=0.347�� X=0.101��  Y=0.340��   X=0.078��  Y=0.349�� 311��42��4.98�� ��λ��=222��54��4.49��
	//11
	Cirthree(convert(121, 347, x, y).x, convert(121, 347, x, y).y, convert(101, 340, x, y).x, convert(101, 340, x, y).y, convert(78, 349, x, y).x, convert(78, 349, x, y).y,
		angle_to_radian(311, 42, 4.98)+0.04, angle_to_radian(222, 54, 4.49));
	Sleep(delay);
	//  X=0.078��  Y=0.349��   X=0.065��  Y=0.365��  X=0.057��  Y=0.393�� 229��41��26.93�� 180��56��32.95��
	//12
	Cirthree(convert(78, 349, x, y).x, convert(78, 349, x, y).y, convert(65, 365, x, y).x, convert(65, 365, x, y).y, convert(57, 393, x, y).x, convert(57, 393, x, y).y,
		angle_to_radian(229, 41, 26.93), angle_to_radian(180, 56, 32.95));
	Sleep(delay);
	//X=0.057��  Y=0.393��  X=0.062��  Y=0.402��  X=0.071��  Y=0.405��  173��56��21.50��  89��12��59.74��
	//13
	Cirthree(convert(57, 393, x, y).x, convert(57, 393, x, y).y, convert(62, 402, x, y).x, convert(62, 402, x, y).y, convert(71, 405, x, y).x, convert(71, 405, x, y).y,
		angle_to_radian(173, 56, 21.5), angle_to_radian(89, 12, 59.74));
	Sleep(delay);
	//�ұ߽�
	//  X=0.120��  Y=0.633��  X=0.127��  Y=0.657��   X=0.108��  Y=0.679��  316��53��49.63�� 71��47��24.51��
	//14
	Cirthree(convert(120, 633, x, y).x, convert(120, 633, x, y).y, convert(127, 657, x, y).x, convert(127, 657, x, y).y, convert(108, 679, x, y).x, convert(108, 679, x, y).y,
		angle_to_radian(316, 53, 49.63), angle_to_radian(71, 47, 24.51));
	Sleep(delay);
	// X=0.108��  Y=0.679��   X=0.077��  Y=0.668��  X=0.057��  Y=0.642�� 93��25��41.52�� 157��32��15.72��
	//15
	Cirthree(convert(108, 679, x, y).x, convert(108, 679, x, y).y, convert(77, 668, x, y).x, convert(77, 668, x, y).y, convert(57, 642, x, y).x, convert(57, 642, x, y).y,
		angle_to_radian(93, 25, 41.52), angle_to_radian(157, 32, 15.72));
	Sleep(delay);
	//X=0.057��  Y=0.642��  X=0.059��  Y=0.621�� X=0.071��  Y=0.614�� 150��13��35.04�� 261��36��49.06��
	//16
	Cirthree(convert(57, 642, x, y).x, convert(57, 642, x, y).y, convert(59, 621, x, y).x, convert(59, 621, x, y).y, convert(71, 614, x, y).x, convert(71, 614, x, y).y,
		angle_to_radian(150, 13, 35.04), angle_to_radian(261, 36, 49.06));
	Sleep(delay);
	// X=0.071��  Y=0.405��    X=0.074��  Y=0.439�� X=0.071��  Y=0.614�� 355��0��38.98��  5��6��55.41��
	//17
	Cirthree(convert(71, 405, x, y).x, convert(71, 405, x, y).y, convert(74, 439, x, y).x, convert(74, 439, x, y).y, convert(71, 614, x, y).x, convert(71, 614, x, y).y,
		angle_to_radian(355, 0, 38.98)+0.013, angle_to_radian(5, 6, 55.41)-0.013);
	Sleep(delay);
	//β��
	//  X=0.156��  Y=0.375�� X=0.173��  Y=0.365��  X=0.186��  Y=0.350�� 66��49��20.73�� 33��32��0.09��
	//18
	Cirthree(convert(156, 375, x, y).x, convert(156, 375, x, y).y, convert(173, 365, x, y).x, convert(173, 365, x, y).y, convert(186, 350, x, y).x, convert(186, 350, x, y).y,
		angle_to_radian(66, 49, 20.73) , angle_to_radian(33, 32, 0.09) );
	Sleep(delay);
	//  X=0.186��  Y=0.350��   X=0.187��  Y=0.339��  X=0.173��  Y=0.318�� 15��53��44.36�� 299��55��11.23��
	//19
	Cirthree(convert(186, 350, x, y).x, convert(186, 350, x, y).y, convert(187, 339, x, y).x, convert(187, 339, x, y).y, convert(173, 318, x, y).x, convert(173, 318, x, y).y,
		angle_to_radian(15, 53, 44.36), angle_to_radian(299, 55, 11.23));
	Sleep(delay);
	//  X=0.173��  Y=0.318�� X=0.160��  Y=0.315�� X=0.137��  Y=0.327�� 299��20��26.10�� 213��6��45.52��
	//20
	Cirthree(convert(173, 318, x, y).x, convert(173, 318, x, y).y, convert(160, 315, x, y).x, convert(160, 315, x, y).y, convert(137, 327, x, y).x, convert(137, 327, x, y).y,
		angle_to_radian(299, 20, 26.1), angle_to_radian(213, 6, 45.52));
	Sleep(delay);
	//  X = 0.137��  Y = 0.327�� X=0.132��  Y=0.340��  X=0.127��  Y=0.355�� 208��4��4.71�� 192��11��57.10��
	//21
	Cirthree(convert(137, 327, x, y).x, convert(137, 327, x, y).y, convert(132, 340, x, y).x, convert(132, 340, x, y).y, convert(127, 355, x, y).x, convert(127, 355, x, y).y,
		angle_to_radian(208, 4, 4.71)+0.1, angle_to_radian(192, 11, 57.1)-0.1);//ǰ�Ӽ�С �����С
	Sleep(delay);
	//����
	//X=0.177��  Y=0.415��  X=0.182��  Y=0.435��    X=0.180��  Y=0.457�� 338��9��26.11�� 13��17��49.62��
	Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
		angle_to_radian(338, 9, 26.11) , angle_to_radian(13, 17, 49.62) );//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.180��  Y=0.456��  X=0.175��  Y=0.461��  X=0.162��  Y=0.458�� 22��59��33.74�� 143��0��4.64��
	Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
		angle_to_radian(22, 59, 33.74),angle_to_radian(143, 0, 4.64));//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.162��  Y=0.458��   X=0.148��  Y=0.437�� X=0.144��  Y=0.416�� 132��54��8.27�� 181��56��3.85��
	Cirthree(convert(162, 458, x, y).x, convert(162, 458, x, y).y, convert(148, 437, x, y).x, convert(148, 437, x, y).y, convert(144, 416, x, y).x, convert(144, 416, x, y).y,
		angle_to_radian(132, 54, 8.27) , angle_to_radian(181, 56, 3.85) );//ǰ�Ӽ�С �����С
	Sleep(delay);

	//����
	//X=0.165��  Y=0.641��  X=0.159��  Y=0.617�� X=0.163��  Y=0.592�� 154��17��9.23�� 200��39��3.32��
	Cirthree(convert(165, 641, x, y).x, convert(165, 641, x, y).y, convert(159, 617, x, y).x, convert(159, 617, x, y).y, convert(163, 592, x, y).x, convert(163, 592, x, y).y,
		angle_to_radian(154, 17, 9.23), angle_to_radian(200, 39, 3.32));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.163��  Y=0.592�� X=0.173��  Y=0.576��   X=0.178��  Y=0.557�� 34��40��23.80�� 2��53��37.42��
	Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
		angle_to_radian(34, 40, 23.8)-0.1, angle_to_radian(2, 53, 37.42));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.178��  Y=0.557��  X=0.169��  Y=0.541�� X=0.146��  Y=0.541�� 357��17��30.34�� 235��17��53.72��
	Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
		angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.146��  Y=0.541��  X=0.128��  Y=0.556��   X=0.116��  Y=0.576�� 236��32��55.32�� 204��36��28.89��
	Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
		angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//��ʱ�� ����1�����߿�ͷ��� ����2��С ĩβ�߱��
	//˳ʱ�� ����1��С�߿�ͷ��� ����2���� ĩβ�߱��

	//���ܲ�����������Ϻ���
	//X=0.182��  Y=0.445�� X=0.196��  Y=0.443�� X=0.208��  Y=0.455�� 235��10��22.80�� 347��4��4.18��
	Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
		angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.208��  Y=0.455��  X=0.204��  Y=0.485��    X=0.202��  Y=0.488�� 352��52��48.42�� 27��1��47.81��
	Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
		angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.202��  Y=0.488��   X=0.197��  Y=0.545��    X=0.199��  Y=0.551�� 204��52��26.34�� 160��30��24.25��
	Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
		angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//4  X=0.199��  Y=0.551��  X=0.189��  Y=0.558��  X=0.177��  Y=0.559��  39��26��10.94�� 100��12��16.85��
	Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//7   X=0.139��  Y=0.546��  X=0.152��  Y=0.493��  X=0.170��  Y=0.462�� 184��30��26.61�� 216��49��29.37��
	Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
		angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//��Ҷ
	//11  X=0.195��  Y=0.555�� X=0.204��  Y=0.565�� X=0.206��  Y=0.578�� 304��0��44.27�� 2��14��2.70��
	Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
		angle_to_radian(304, 0, 44.27)+0.2, angle_to_radian(2, 14, 2.7));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//12  X=0.206��  Y=0.578��  X=0.200��  Y=0.586��  X=0.188��  Y=0.580�� 9��59��48.96�� 158��8��5.94��
	Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
		angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//13  X=0.188��  Y=0.580��  X=0.181��  Y=0.593�� X=0.168��  Y=0.586�� 343��34��17.94�� 163��17��6.93��
	Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
		angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//ǰ�Ӽ�С �����С
	Sleep(delay);
	
	//��������
	setlinestyle(PS_SOLID, 3);
	//����
	//14   X=0.320��  Y=0.476�� X=0.333��  Y=0.485��  X=0.336��  Y=0.493�� 285��34��1.95�� 348��7��58.59��
	Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(333, 485, x, y).x, convert(333, 485, x, y).y, convert(336, 493, x, y).x, convert(336, 493, x, y).y,
		angle_to_radian(285, 34, 1.95), angle_to_radian(348, 7, 58.59));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//15   X=0.336��  Y=0.493�� X=0.332��  Y=0.503�� X=0.326��  Y=0.505�� 355��19��23.78�� 90��28��44.97��
	Cirthree(convert(336, 493, x, y).x, convert(336, 493, x, y).y, convert(332, 503, x, y).x, convert(332, 503, x, y).y, convert(326, 505, x, y).x, convert(326, 505, x, y).y,
		angle_to_radian(355, 19, 23.78), angle_to_radian(90, 28, 44.97));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//16   X=0.326��  Y=0.505��  X=0.308��  Y=0.498��  X=0.301��  Y=0.480��  85��38��9.36�� 184��18��40.34��
	Cirthree(convert(326, 505, x, y).x, convert(326, 505, x, y).y, convert(308, 498, x, y).x, convert(308, 498, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		angle_to_radian(85, 38, 9.36), angle_to_radian(184, 18, 40.34));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//17   X=0.301��  Y=0.480��   X=0.314��  Y=0.474��  X=0.320��  Y=0.476�� 222��52��32.60�� 294��24��49.26��
	Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		angle_to_radian(222, 52, 32.6), angle_to_radian(294, 24, 49.26));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//19    X=0.320��  Y=0.491�� X=0.327��  Y=0.488�� X=0.330��  Y=0.492�� 197��24��32.69�� 352��36��56.48��
	Cirthree(convert(320, 491, x, y).x, convert(320, 491, x, y).y, convert(327, 488, x, y).x, convert(327, 488, x, y).y, convert(330, 492, x, y).x, convert(330, 492, x, y).y,
		angle_to_radian(197, 24, 32.69), angle_to_radian(352, 36, 56.48)+1.7);//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.330��  Y=0.492�� X=0.328��  Y=0.496��  X=0.325��  Y=0.497�� 1��22��48.28�� 93��16��57.13��
	Cirthree(convert(330, 492, x, y).x, convert(330, 492, x, y).y, convert(328, 496, x, y).x, convert(328, 496, x, y).y, convert(325, 497, x, y).x, convert(325, 497, x, y).y,
		angle_to_radian(1, 22, 48.28)+1.3, angle_to_radian(93, 16, 57.13));//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.325��  Y=0.497��  X=0.321��  Y=0.494��  X=0.320��  Y=0.491�� 98��35��16.88�� ��λ��=174��23��34.16��
	Cirthree(convert(325, 497, x, y).x, convert(325, 497, x, y).y, convert(321, 494, x, y).x, convert(321, 494, x, y).y, convert(320, 491, x, y).x, convert(320, 491, x, y).y,
		angle_to_radian(98, 35, 16.88), angle_to_radian(174, 23, 34.16));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//18
	//X=0.320��  Y=0.476�� X=0.304��  Y=0.441��   X=0.301��  Y=0.480��  49��25��12.66�� 107��52��9.20��
	Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		angle_to_radian(49, 25, 12.66)+0.3, angle_to_radian(107, 52, 9.2)+0.5);//ǰ�Ӽ�С �����С
	Sleep(delay);
	

	//����
	//23  X=0.297��  Y=0.571��  X=0.305��  Y=0.578�� X=0.307��  Y=0.589��   290��23��17.75�� 8��41��14.46��  
	Cirthree(convert(297, 571, x, y).x, convert(297, 571, x, y).y, convert(305, 578, x, y).x, convert(305, 578, x, y).y, convert(307, 589, x, y).x, convert(307, 589, x, y).y,
		angle_to_radian(290, 23, 17.75), angle_to_radian(8, 41, 14.46));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//20 X=0.307��  Y=0.589��  X=0.295��  Y=0.597��  X=0.281��  Y=0.594�� 33��54��37.10�� 124��46��51.43��   
	Cirthree(convert(307, 589, x, y).x, convert(307, 589, x, y).y, convert(295, 597, x, y).x, convert(295, 597, x, y).y, convert(281, 594, x, y).x, convert(281, 594, x, y).y,
		angle_to_radian(33, 54, 37.1), angle_to_radian(124, 46, 51.43));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//21  X=0.281��  Y=0.594��  X=0.273��  Y=0.588��  X=0.270��  Y=0.576�� 110��6��20.99�� 182��51��36.95��  
	Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//22  X=0.270��  Y=0.576��  X=0.285��  Y=0.568��   X=0.297��  Y=0.571�� 214��33��24.28�� 302��49��44.41��  
	Cirthree(convert(270, 576, x, y).x, convert(270, 576, x, y).y, convert(285, 568, x, y).x, convert(285, 568, x, y).y, convert(297, 571, x, y).x, convert(297, 571, x, y).y,
		angle_to_radian(214, 33, 24.28), angle_to_radian(302, 49, 44.41));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//24  X=0.300��  Y=0.583��  X=0.296��  Y=0.578��   X=0.291��  Y=0.583�� 359��59��60.00�� 182��7��45.49��   
	Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(296, 578, x, y).x, convert(296, 578, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49)-0.5);//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.300��  Y=0.583��  X=0.297��  Y=0.587��   X=0.291��  Y=0.583�� 6��45��29.16�� 175��22��16.34��
	Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(297, 587, x, y).x, convert(297, 587, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49)-0.2);//ǰ�Ӽ�С �����С
	Sleep(delay);
	// 25  X=0.281��  Y=0.594�� X=0.242��  Y=0.587��  X=0.270��  Y=0.576��  357��25��51.22�� 296��58��46.19��
	Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		angle_to_radian(357, 25, 51.22)-0.2, angle_to_radian(296, 58, 46.19));//ǰ�Ӽ�С �����С
	Sleep(delay);
	
	//��ʱ�� ����1�����߿�ͷ��� ����2��С ĩβ�߱��
	//˳ʱ�� ����1��С�߿�ͷ��� ����2���� ĩβ�߱��
	
	//26 
	//X=0.298��  Y=0.525��  X=0.308��  Y=0.537��  X=0.293��  Y=0.541��  263��22��18.66�� 130��13��16.69��
	Cirthree(convert(298, 525, x, y).x, convert(298, 525, x, y).y, convert(308, 537, x, y).x, convert(308, 537, x, y).y, convert(293, 541, x, y).x, convert(293, 541, x, y).y,
		angle_to_radian(263, 22, 18.66) , angle_to_radian(130, 13, 16.69));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//27 
	//X=0.299��  Y=0.525��  X=0.295��  Y=0.531��  X=0.296��  Y=0.543�� 229��4��22.30�� 150��0��22.36��
	Cirthree(convert(299, 525, x, y).x, convert(299, 525, x, y).y, convert(295, 531, x, y).x, convert(295, 531, x, y).y, convert(296, 543, x, y).x, convert(293, 543, x, y).y,
		angle_to_radian(229, 4, 22.3), angle_to_radian(150, 0, 22.36)-0.5);//ǰ�Ӽ�С �����С
	Sleep(delay);

	//��������
	setlinestyle(PS_SOLID, 3);
	//28 
	//X=0.294��  Y=0.533��  X=0.284��  Y=0.514��  X=0.290��  Y=0.499��  122��50��28.32�� 223��27��28.35��
	Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//29 
	//X=0.294��  Y=0.533�� X=0.280��  Y=0.540��  X=0.273��  Y=0.561�� 257��43��39.66�� 174��6��13.43��
	Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//30 
	// X=0.285��  Y=0.519��  X=0.270��  Y=0.516��   X=0.259��  Y=0.521�� 297��57��10.55�� 235��54��32.11��
	Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11)+0.2);//ǰ�Ӽ�С �����С
	Sleep(delay);
	//31
	// X=0.280��  Y=0.540��  X=0.268��  Y=0.534��  X=0.259��  Y=0.521�� 103��26��12.32�� 162��30��12.91��
	Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//��ʱ�� ����1�����߿�ͷ��� ����2��С ĩβ�߱��
	//˳ʱ�� ����1��С�߿�ͷ��� ����2���� ĩβ�߱��
	//���
	// X=0.102��  Y=0.353 X=0.095��  Y=0.352�� X=0.090��  Y=0.363��  297��41��28.87�� 161��26��56.78��
	Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(95, 352, x, y).x, convert(95, 352, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		angle_to_radian(297, 41, 28.87) , angle_to_radian(161, 26, 56.78) );//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.102��  Y=0.353  X=0.098��  Y=0.362�� X=0.090��  Y=0.363�� 352��46��12.08�� 106��22��13.57��
	Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(98, 362, x, y).x, convert(98, 362, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		angle_to_radian(352, 46, 12.08) , angle_to_radian(106, 22, 13.57)-0.3 );//ǰ�Ӽ�С �����С
	Sleep(delay);

	// X=0.116��  Y=0.362�� X=0.108��  Y=0.360��  X=0.101��  Y=0.367��  317��39��8.35�� 187��5��41.70��
	Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(108, 360, x, y).x, convert(108, 360, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		angle_to_radian(317, 39, 8.35) , angle_to_radian(187, 5, 41.7)-0.3 );//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.116��  Y=0.362��  X=0.111��  Y=0.369�� X=0.101��  Y=0.367��  X=0.101��  Y=0.367��=8��17��27.46��  =136��27��22.58��
	Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(111, 369, x, y).x, convert(111, 369, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		angle_to_radian(8, 17, 27.46) , angle_to_radian(136, 27, 22.58) );//ǰ�Ӽ�С �����С
	Sleep(delay);

	//X=0.117��  Y=0.376��   X=0.109��  Y=0.372��  X=0.101��  Y=0.381�� 329��10��9.96�� 181��22��7.37��
	Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(109, 372, x, y).x, convert(109, 372, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		angle_to_radian(329, 10, 9.96) , angle_to_radian(181, 22, 7.37) );//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.117��  Y=0.376��   X=0.111��  Y=0.383��  X=0.101��  Y=0.381�� 15��26��31.36�� 135��5��45.98��
	Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(111, 383, x, y).x, convert(111, 383, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		angle_to_radian(15, 26, 31.36), angle_to_radian(135, 5, 45.98));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//X=0.096��  Y=0.372�� X=0.087��  Y=0.370��  X=0.074��  Y=0.386�� 299��3��38.35�� 171��38��8.91��
	Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(87, 370, x, y).x, convert(87, 370, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		angle_to_radian(299, 3, 38.35) , angle_to_radian(171, 38, 8.91) );//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.096��  Y=0.372�� X=0.090��  Y=0.387��   X=0.074��  Y=0.386��  343��40��27.29�� 127��1��19.97��
	Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(90, 387, x, y).x, convert(90, 387, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		angle_to_radian(343, 40, 27.29), angle_to_radian(127, 1, 19.97));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//�ҽ�
	//  X=0.116��  Y=0.642��   X=0.111��  Y=0.636��   X=0.101��  Y=0.638�� 341��40��12.79�� 222��43��32.33��
	Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(111, 636, x, y).x, convert(111, 636, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		angle_to_radian(341, 40, 12.79), angle_to_radian(222, 43, 32.33));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.116��  Y=0.642��   X=0.105��  Y=0.645��   X=0.101��  Y=0.638�� 29��17��54.10�� 175��5��51.02��
	Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(105, 645, x, y).x, convert(105, 645, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		angle_to_radian(29, 17, 54.1), angle_to_radian(175, 5, 51.02));//ǰ�Ӽ�С �����С
	Sleep(delay);

	// X=0.115��  Y=0.659�� X=0.109��  Y=0.649�� X=0.101��  Y=0.651�� 11��34��2.18�� 226��10��24.04��
	Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(109, 649, x, y).x, convert(109, 649, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		angle_to_radian(11, 34, 2.18), angle_to_radian(226, 10, 24.04));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.115��  Y=0.659��  X=0.105��  Y=0.658�� X=0.101��  Y=0.651�� 61��48��24.44�� 175��56��1.78��
	Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(105, 658, x, y).x, convert(105, 658, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		angle_to_radian(61, 48, 24.44), angle_to_radian(175, 59, 1.78));//ǰ�Ӽ�С �����С
	Sleep(delay);

	// X=0.103��  Y=0.665��  X=0.096��  Y=0.656��  X=0.091��  Y=0.657�� 7��6��59.98�� 242��31��15.10��
	Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(96, 656, x, y).x, convert(96, 656, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		angle_to_radian(7, 6, 59.98), angle_to_radian(242, 31, 15.1));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.103��  Y=0.665��  X=0.098��  Y=0.667��  X=0.091��  Y=0.657�� 57��19��9.55�� 192��19��5.54��
	Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(98, 667, x, y).x, convert(98, 667, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		angle_to_radian(57, 19, 9.55), angle_to_radian(192, 19, 5.54));//ǰ�Ӽ�С �����С
	Sleep(delay);

	//  X=0.096��  Y=0.648��  X=0.085��  Y=0.630��  X=0.074��  Y=0.632�� 13��3��12.91�� 239��15��54.89��
	Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(85, 630, x, y).x, convert(85, 630, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		angle_to_radian(13, 3, 12.91), angle_to_radian(239, 15, 54.89));//ǰ�Ӽ�С �����С
	Sleep(delay);
	//X=0.096��  Y=0.648��  X=0.087��  Y=0.650��   X=0.074��  Y=0.632�� 59��0��34.03�� 193��18��33.76��
	Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(87, 650, x, y).x, convert(87, 650, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		angle_to_radian(59, 0, 34.03), angle_to_radian(193, 18, 33.76));//ǰ�Ӽ�С �����С
	Sleep(delay);


	////��ɫ
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
/// ����ת������cass����תΪ��ͼ����
/// </summary>
/// <param name="x">cass������x</param>
/// <param name="y">cass������y</param>
/// <param name="X">ָ����ͼ����X</param>
/// <param name="Y">ָ����ͼ����Y</param>
/// <returns></returns>
POINT  convert(double x, double y, double X, double Y) {
	//��һ������ˮƽ����ֵ������Ծ���
	//��������ο���
	//X=0.294��  Y=0.533��
	const int x0 = 294;
	const int y0 = 533;
	int xx = 0, yy = 0;
	int distancesz = abs((int)x - x0);//������ֱ�������
	int distancesp = abs((int)y - y0);//����ˮƽ�������
	//�ڶ����ж���Է�λ
	//��һ����
	if (((x - x0) >= 0 && (y - y0) >= 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//�ڶ�����
	if ((x - x0) >= 0 && (y - y0) <= 0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//��������
	if ((x - x0) <= 0 && (y - y0) <= 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//��������
	if ((x - x0) <= 0 && (y - y0) >= 0)
	{
		xx = X + distancesp;
		yy = Y + distancesz;
	}

	//��������ȷ��ת���������ֵ
	POINT pt[1];
	pt[0] = { xx,yy };
	return pt[0];
}
/// <summary>
/// ������������ж���ת���򣬷��ش���0��˳ʱ�룬С��0����ʱ�롣
/// </summary>
/// <param name="X1">��һ����X</param>
/// <param name="Y1">��һ����Y</param>
/// <param name="X2">�ڶ�����X</param>
/// <param name="Y2">�ڶ�����Y</param>
/// <param name="X3">��������X</param>
/// <param name="Y3">��������Y</param>
/// <returns>������ֵ</returns>
double Cross(double X1, double Y1, double X2, double Y2, double X3, double Y3) {
	//������������ж���ת���򣬷��ش���0��˳ʱ�룬С��0����ʱ�롣
	return (X2 - X1) * (Y3 - Y2) - (Y2 - Y1) * (X3 - X2);
}
/// <summary>
/// �������
/// </summary>
/// <param name="x">���ĵĺ�����</param>
/// <param name="y">���ĵ�������</param>
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
 /// ����������ɫ
 /// </summary>
 /// <param name="x">ָ������X</param>
 /// <param name="y">ָ������Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillLeftEar(int x,int y, COLORREF rgb){
	/* �Ȼ�����ɫ����*/
		/*��߶�����ɫ���*/
		setlinestyle(PS_SOLID, 5);
		//������ɫ
		setlinecolor(rgb);
		//ֱ�� X=0.445��  Y=0.436��    X=0.451��  Y=0.453�� 
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
		//X=0.445��  Y=0.436��  X=0.420��  Y=0.440��
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
		//X=0.451��  Y=0.453��   X=0.432��  Y=0.461��
		line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
		//X = 0.432��  Y = 0.461�� X=0.427��  Y=0.451�� X=0.420��  Y=0.440�� 338��16��33.76�� 320��18��27.11��
		Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
			angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
		//�����ɫ X=0.437��  Y=0.447�� 
		BoundaryFill(convert(437, 447, x, y).x, convert(437, 447, x, y).y,rgb);
		//��������
		setlinestyle(PS_SOLID, 5);
		//������ɫ
		setlinecolor(RGB(10, 10, 10));
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(451, 453, x, y).x, convert(451, 453, x, y).y);
		//X=0.445��  Y=0.436��  X=0.420��  Y=0.440��
		line(convert(445, 436, x, y).x, convert(445, 436, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y);
		//X=0.451��  Y=0.453��   X=0.432��  Y=0.461��
		line(convert(451, 453, x, y).x, convert(451, 453, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y);
		//X = 0.432��  Y = 0.461�� X=0.427��  Y=0.451�� X=0.420��  Y=0.440�� 338��16��33.76�� 320��18��27.11��
		Cirthree(convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(427, 451, x, y).x, convert(427, 451, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,
			angle_to_radian(338, 16, 33.76), angle_to_radian(320, 18, 27.11));
 }
 /// <summary>
 /// ����Ҷ�����ɫ
 /// </summary>
 /// <param name="x">ָ������X</param>
 /// <param name="y">ָ������Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillRightEar(int x,int y, COLORREF rgb) {
	/* �ұ߶�����ɫ���*/
	setlinestyle(PS_SOLID, 5);
	//������ɫ
	setlinecolor(rgb);
	//ֱ��  X=0.378��  Y=0.686��  X=0.362��  Y=0.696�� 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(362, 696, x, y).x, convert(362, 696, x, y).y);
	//
	//X=0.378��  Y=0.686�� X=0.365��  Y=0.665�� 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	// X=0.362��  Y=0.696�� X=0.341��  Y=0.676��
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	/*X=0.365��  Y=0.665��  X=0.354��  Y=0.671��   X=0.341��  Y=0.676�� 59��45��41.34�� 70��36��34.68��*/
	Cirthree(convert(365, 665, x, y).x, convert(365, 665, x, y).y, convert(354, 671, x, y).x, convert(354, 671, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y,
		angle_to_radian(59, 45, 41.34), angle_to_radian(70, 36, 34.68));
	//�����ɫ  X=0.363��  Y=0.679��  
	BoundaryFill(convert(363, 679, x, y).x, convert(363, 679, x, y).y,rgb);
	//��������
	setlinestyle(PS_SOLID, 5);
	//������ɫ
	setlinecolor(RGB(10, 10, 10));
	//ֱ��  X=0.378��  Y=0.686��  X=0.362��  Y=0.696�� 
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(362, 696, x, y).x, convert(362, 696, x, y).y);
	//
	/*X=0.378��  Y=0.686�� X=0.365��  Y=0.665�� */
	line(convert(378, 686, x, y).x, convert(378, 686, x, y).y, convert(365, 665, x, y).x, convert(365, 665, x, y).y);
	// X=0.362��  Y=0.696�� X=0.341��  Y=0.676��
	line(convert(362, 696, x, y).x, convert(362, 696, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y);
	//X=0.365��  Y=0.665��  X=0.354��  Y=0.671��   X=0.341��  Y=0.676�� 59��45��41.34�� 70��36��34.68��
	Cirthree(convert(365, 665, x, y).x, convert(365, 665, x, y).y, convert(354, 671, x, y).x, convert(354, 671, x, y).y, convert(341, 676, x, y).x, convert(341, 676, x, y).y,
		angle_to_radian(59, 45, 41.34), angle_to_radian(70, 36, 34.68));
 }
 /// <summary>
 /// �����ܲ���ɫ
 /// </summary>
 /// <param name="x">ָ������X</param>
 /// <param name="y">ָ������Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillCarrot(int x, int y, COLORREF rgb) {
	/* ���ܲ����*/
		setlinestyle(PS_SOLID, 5);
		//������ɫ
		setlinecolor(rgb);
		Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
			angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//ǰ�Ӽ�С �����С
			//X=0.208��  Y=0.455��  X=0.204��  Y=0.485��    X=0.202��  Y=0.488�� 352��52��48.42�� 27��1��47.81��
		Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
			angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//ǰ�Ӽ�С �����С
			// X=0.202��  Y=0.488��   X=0.197��  Y=0.545��    X=0.199��  Y=0.551�� 204��52��26.34�� 160��30��24.25��
		Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
			angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//ǰ�Ӽ�С �����С
		//4  X=0.199��  Y=0.551��  X=0.189��  Y=0.558��  X=0.177��  Y=0.559��  39��26��10.94�� 100��12��16.85��
		Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
			angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//ǰ�Ӽ�С �����С
		//X=0.163��  Y=0.592�� X=0.173��  Y=0.576��   X=0.178��  Y=0.557�� 34��40��23.80�� 2��53��37.42��
		Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
			angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//ǰ�Ӽ�С �����С
		//X=0.178��  Y=0.557��  X=0.169��  Y=0.541�� X=0.146��  Y=0.541�� 357��17��30.34�� 235��17��53.72��
		Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
			angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//ǰ�Ӽ�С �����С
		//X=0.146��  Y=0.541��  X=0.128��  Y=0.556��   X=0.116��  Y=0.576�� 236��32��55.32�� 204��36��28.89��
		Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
			angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//ǰ�Ӽ�С �����С
			//7   X=0.139��  Y=0.546��  X=0.152��  Y=0.493��  X=0.170��  Y=0.462�� 184��30��26.61�� 216��49��29.37��
		Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
			angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//ǰ�Ӽ�С �����С
		//X=0.177��  Y=0.415��  X=0.182��  Y=0.435��    X=0.180��  Y=0.457�� 338��9��26.11�� 13��17��49.62��
		Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
			angle_to_radian(338, 9, 26.11), angle_to_radian(13, 17, 49.62));//ǰ�Ӽ�С �����С
		//X=0.180��  Y=0.456��  X=0.175��  Y=0.461��  X=0.162��  Y=0.458�� 22��59��33.74�� 143��0��4.64��
		Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
			angle_to_radian(22, 59, 33.74), angle_to_radian(143, 0, 4.64));//ǰ�Ӽ�С �����С
		//�����ɫ   X=0.178��  Y=0.497��
			BoundaryFill(convert(178, 497, x, y).x, convert(178, 497, x, y).y,rgb);
			//��������
			setlinestyle(PS_SOLID, 5);
			//������ɫ
			setlinecolor(RGB(10, 10, 10));
	Cirthree(convert(182, 445, x, y).x, convert(182, 445, x, y).y, convert(196, 443, x, y).x, convert(196, 443, x, y).y, convert(208, 455, x, y).x, convert(208, 455, x, y).y,
			angle_to_radian(235, 10, 22.8), angle_to_radian(347, 4, 4.18));//ǰ�Ӽ�С �����С
			//X=0.208��  Y=0.455��  X=0.204��  Y=0.485��    X=0.202��  Y=0.488�� 352��52��48.42�� 27��1��47.81��
		Cirthree(convert(208, 455, x, y).x, convert(208, 455, x, y).y, convert(204, 485, x, y).x, convert(204, 485, x, y).y, convert(202, 488, x, y).x, convert(202, 488, x, y).y,
			angle_to_radian(352, 52, 48.42), angle_to_radian(27, 1, 47.81));//ǰ�Ӽ�С �����С
			// X=0.202��  Y=0.488��   X=0.197��  Y=0.545��    X=0.199��  Y=0.551�� 204��52��26.34�� 160��30��24.25��
		Cirthree(convert(202, 488, x, y).x, convert(202, 488, x, y).y, convert(197, 545, x, y).x, convert(197, 545, x, y).y, convert(199, 551, x, y).x, convert(199, 551, x, y).y,
			angle_to_radian(204, 52, 26.34)-0.1, angle_to_radian(160, 30, 24.25));//ǰ�Ӽ�С �����С
		//4  X=0.199��  Y=0.551��  X=0.189��  Y=0.558��  X=0.177��  Y=0.559��  39��26��10.94�� 100��12��16.85��
		Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
			angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//ǰ�Ӽ�С �����С
		//X=0.163��  Y=0.592�� X=0.173��  Y=0.576��   X=0.178��  Y=0.557�� 34��40��23.80�� 2��53��37.42��
		Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
			angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//ǰ�Ӽ�С �����С
		//X=0.178��  Y=0.557��  X=0.169��  Y=0.541�� X=0.146��  Y=0.541�� 357��17��30.34�� 235��17��53.72��
		Cirthree(convert(178, 557, x, y).x, convert(178, 557, x, y).y, convert(169, 541, x, y).x, convert(169, 541, x, y).y, convert(146, 541, x, y).x, convert(146, 541, x, y).y,
			angle_to_radian(357, 17, 30.34), angle_to_radian(235, 17, 53.72));//ǰ�Ӽ�С �����С
		//X=0.146��  Y=0.541��  X=0.128��  Y=0.556��   X=0.116��  Y=0.576�� 236��32��55.32�� 204��36��28.89��
		Cirthree(convert(146, 541, x, y).x, convert(146, 541, x, y).y, convert(128, 556, x, y).x, convert(128, 556, x, y).y, convert(116, 576, x, y).x, convert(116, 576, x, y).y,
			angle_to_radian(236, 32, 55.32), angle_to_radian(204, 36, 28.89));//ǰ�Ӽ�С �����С
			//7   X=0.139��  Y=0.546��  X=0.152��  Y=0.493��  X=0.170��  Y=0.462�� 184��30��26.61�� 216��49��29.37��
		Cirthree(convert(139, 546, x, y).x, convert(139, 546, x, y).y, convert(152, 493, x, y).x, convert(152, 493, x, y).y, convert(170, 462, x, y).x, convert(170, 462, x, y).y,
			angle_to_radian(184, 30, 26.61), angle_to_radian(216, 49, 29.37));//ǰ�Ӽ�С �����С
		//X=0.177��  Y=0.415��  X=0.182��  Y=0.435��    X=0.180��  Y=0.457�� 338��9��26.11�� 13��17��49.62��
		Cirthree(convert(177, 415, x, y).x, convert(177, 415, x, y).y, convert(182, 435, x, y).x, convert(182, 435, x, y).y, convert(180, 457, x, y).x, convert(180, 457, x, y).y,
			angle_to_radian(338, 9, 26.11), angle_to_radian(13, 17, 49.62));//ǰ�Ӽ�С �����С
		//X=0.180��  Y=0.456��  X=0.175��  Y=0.461��  X=0.162��  Y=0.458�� 22��59��33.74�� 143��0��4.64��
		Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
			angle_to_radian(22, 59, 33.74), angle_to_radian(143, 0, 4.64));//ǰ�Ӽ�С �����С
 }
 /// <summary>
 /// �����Ҷ��ɫ
 /// </summary>
 /// <param name="x">ָ������X</param>
 /// <param name="y">ָ������Y</param>
 /// <param name="r">R</param>
 /// <param name="g">G</param>
 /// <param name="b">B</param>
 void FillLeaf(int x, int y, COLORREF rgb) {
	 //��Ҷ���
	 setlinestyle(PS_SOLID, 5);
	 	//������ɫ
	 	setlinecolor(rgb);
	 //��Ҷ
	 	//11  X=0.195��  Y=0.555�� X=0.204��  Y=0.565�� X=0.206��  Y=0.578�� 304��0��44.27�� 2��14��2.70��
	 Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
	 	angle_to_radian(304, 0, 44.27) + 0.2, angle_to_radian(2, 14, 2.7));//ǰ�Ӽ�С �����С
	 //12  X=0.206��  Y=0.578��  X=0.200��  Y=0.586��  X=0.188��  Y=0.580�� 9��59��48.96�� 158��8��5.94��
	 Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
	 	angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//ǰ�Ӽ�С �����С
	 //13  X=0.188��  Y=0.580��  X=0.181��  Y=0.593�� X=0.168��  Y=0.586�� 343��34��17.94�� 163��17��6.93��
	 Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
	 	angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//ǰ�Ӽ�С �����С
	 //X=0.163��  Y=0.592�� X=0.173��  Y=0.576��   X=0.178��  Y=0.557�� 34��40��23.80�� 2��53��37.42��
	 Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
	 	angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//ǰ�Ӽ�С �����С
	 //4  X=0.199��  Y=0.551��  X=0.189��  Y=0.558��  X=0.177��  Y=0.559��  39��26��10.94�� 100��12��16.85��
		 Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		 	angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//ǰ�Ӽ�С �����С
	 //�����ɫ    X=0.188��  Y=0.571�� 
			 BoundaryFill(convert(188, 571, x, y).x, convert(188, 571, x, y).y,rgb);
			 //��������
			 setlinestyle(PS_SOLID, 5);
			 //������ɫ
			 setlinecolor(RGB(10, 10, 10));
 //��Ҷ
	 	//11  X=0.195��  Y=0.555�� X=0.204��  Y=0.565�� X=0.206��  Y=0.578�� 304��0��44.27�� 2��14��2.70��
	 Cirthree(convert(195, 555, x, y).x, convert(195, 555, x, y).y, convert(204, 565, x, y).x, convert(204, 565, x, y).y, convert(206, 578, x, y).x, convert(206, 578, x, y).y,
	 	angle_to_radian(304, 0, 44.27) + 0.2, angle_to_radian(2, 14, 2.7));//ǰ�Ӽ�С �����С
	 //12  X=0.206��  Y=0.578��  X=0.200��  Y=0.586��  X=0.188��  Y=0.580�� 9��59��48.96�� 158��8��5.94��
	 Cirthree(convert(206, 578, x, y).x, convert(206, 578, x, y).y, convert(200, 586, x, y).x, convert(200, 586, x, y).y, convert(188, 580, x, y).x, convert(188, 580, x, y).y,
	 	angle_to_radian(9, 59, 48.96), angle_to_radian(158, 8, 5.94));//ǰ�Ӽ�С �����С
	 //13  X=0.188��  Y=0.580��  X=0.181��  Y=0.593�� X=0.168��  Y=0.586�� 343��34��17.94�� 163��17��6.93��
	 Cirthree(convert(188, 580, x, y).x, convert(188, 580, x, y).y, convert(181, 593, x, y).x, convert(181, 593, x, y).y, convert(168, 586, x, y).x, convert(168, 586, x, y).y,
	 	angle_to_radian(343, 34, 17.94), angle_to_radian(163, 17, 6.93));//ǰ�Ӽ�С �����С
	 //X=0.163��  Y=0.592�� X=0.173��  Y=0.576��   X=0.178��  Y=0.557�� 34��40��23.80�� 2��53��37.42��
	 Cirthree(convert(163, 592, x, y).x, convert(163, 592, x, y).y, convert(173, 576, x, y).x, convert(173, 576, x, y).y, convert(178, 557, x, y).x, convert(178, 557, x, y).y,
	 	angle_to_radian(34, 40, 23.8) - 0.1, angle_to_radian(2, 53, 37.42));//ǰ�Ӽ�С �����С
	 //4  X=0.199��  Y=0.551��  X=0.189��  Y=0.558��  X=0.177��  Y=0.559��  39��26��10.94�� 100��12��16.85��
		 Cirthree(convert(199, 551, x, y).x, convert(199, 551, x, y).y, convert(189, 558, x, y).x, convert(189, 558, x, y).y, convert(177, 559, x, y).x, convert(177, 559, x, y).y,
		 	angle_to_radian(39, 26, 10.94) , angle_to_radian(100, 12, 16.85));//ǰ�Ӽ�С �����С
 }
 /// <summary>
/// ����۾���ɫ
/// </summary>
/// <param name="x">ָ������X</param>
/// <param name="y">ָ������Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillEyes(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(rgb);
	 //����
	//14   X=0.320��  Y=0.476�� X=0.333��  Y=0.485��  X=0.336��  Y=0.493�� 285��34��1.95�� 348��7��58.59��
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(333, 485, x, y).x, convert(333, 485, x, y).y, convert(336, 493, x, y).x, convert(336, 493, x, y).y,
		 angle_to_radian(285, 34, 1.95), angle_to_radian(348, 7, 58.59));//ǰ�Ӽ�С �����С
	 //15   X=0.336��  Y=0.493�� X=0.332��  Y=0.503�� X=0.326��  Y=0.505�� 355��19��23.78�� 90��28��44.97��
	 Cirthree(convert(336, 493, x, y).x, convert(336, 493, x, y).y, convert(332, 503, x, y).x, convert(332, 503, x, y).y, convert(326, 505, x, y).x, convert(326, 505, x, y).y,
		 angle_to_radian(355, 19, 23.78), angle_to_radian(90, 28, 44.97));//ǰ�Ӽ�С �����С
	 //16   X=0.326��  Y=0.505��  X=0.308��  Y=0.498��  X=0.301��  Y=0.480��  85��38��9.36�� 184��18��40.34��
	 Cirthree(convert(326, 505, x, y).x, convert(326, 505, x, y).y, convert(308, 498, x, y).x, convert(308, 498, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(85, 38, 9.36), angle_to_radian(184, 18, 40.34));//ǰ�Ӽ�С �����С
	 //17   X=0.301��  Y=0.480��   X=0.314��  Y=0.474��  X=0.320��  Y=0.476�� 222��52��32.60�� 294��24��49.26��
	 Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		 angle_to_radian(222, 52, 32.6), angle_to_radian(294, 24, 49.26));//ǰ�Ӽ�С �����С
	 //19    X=0.320��  Y=0.491�� X=0.327��  Y=0.488�� X=0.330��  Y=0.492�� 197��24��32.69�� 352��36��56.48��
	 Cirthree(convert(320, 491, x, y).x, convert(320, 491, x, y).y, convert(327, 488, x, y).x, convert(327, 488, x, y).y, convert(330, 492, x, y).x, convert(330, 492, x, y).y,
		 angle_to_radian(197, 24, 32.69), angle_to_radian(352, 36, 56.48) + 1.7);//ǰ�Ӽ�С �����С
	 // X=0.330��  Y=0.492�� X=0.328��  Y=0.496��  X=0.325��  Y=0.497�� 1��22��48.28�� 93��16��57.13��
	 Cirthree(convert(330, 492, x, y).x, convert(330, 492, x, y).y, convert(328, 496, x, y).x, convert(328, 496, x, y).y, convert(325, 497, x, y).x, convert(325, 497, x, y).y,
		 angle_to_radian(1, 22, 48.28) + 1.3, angle_to_radian(93, 16, 57.13));//ǰ�Ӽ�С �����С
	 // X=0.325��  Y=0.497��  X=0.321��  Y=0.494��  X=0.320��  Y=0.491�� 98��35��16.88�� ��λ��=174��23��34.16��
	 Cirthree(convert(325, 497, x, y).x, convert(325, 497, x, y).y, convert(321, 494, x, y).x, convert(321, 494, x, y).y, convert(320, 491, x, y).x, convert(320, 491, x, y).y,
		 angle_to_radian(98, 35, 16.88), angle_to_radian(174, 23, 34.16));//ǰ�Ӽ�С �����С
	 //18
	 //X=0.320��  Y=0.476�� X=0.304��  Y=0.441��   X=0.301��  Y=0.480��  49��25��12.66�� 107��52��9.20��
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(49, 25, 12.66) + 0.3, angle_to_radian(107, 52, 9.2) + 0.5);//ǰ�Ӽ�С �����С
	  //�����ɫ    X=0.311��  Y=0.488��
	 BoundaryFill(convert(311, 488, x, y).x, convert(311, 488, x, y).y,rgb);
	 Sleep(100);

	 //����
	 //23  X=0.297��  Y=0.571��  X=0.305��  Y=0.578�� X=0.307��  Y=0.589��   290��23��17.75�� 8��41��14.46��  
	 Cirthree(convert(297, 571, x, y).x, convert(297, 571, x, y).y, convert(305, 578, x, y).x, convert(305, 578, x, y).y, convert(307, 589, x, y).x, convert(307, 589, x, y).y,
		 angle_to_radian(290, 23, 17.75), angle_to_radian(8, 41, 14.46));//ǰ�Ӽ�С �����С
	 //20 X=0.307��  Y=0.589��  X=0.295��  Y=0.597��  X=0.281��  Y=0.594�� 33��54��37.10�� 124��46��51.43��   
	 Cirthree(convert(307, 589, x, y).x, convert(307, 589, x, y).y, convert(295, 597, x, y).x, convert(295, 597, x, y).y, convert(281, 594, x, y).x, convert(281, 594, x, y).y,
		 angle_to_radian(33, 54, 37.1), angle_to_radian(124, 46, 51.43));//ǰ�Ӽ�С �����С
	 //21  X=0.281��  Y=0.594��  X=0.273��  Y=0.588��  X=0.270��  Y=0.576�� 110��6��20.99�� 182��51��36.95��  
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//ǰ�Ӽ�С �����С
	 //22  X=0.270��  Y=0.576��  X=0.285��  Y=0.568��   X=0.297��  Y=0.571�� 214��33��24.28�� 302��49��44.41��  
	 Cirthree(convert(270, 576, x, y).x, convert(270, 576, x, y).y, convert(285, 568, x, y).x, convert(285, 568, x, y).y, convert(297, 571, x, y).x, convert(297, 571, x, y).y,
		 angle_to_radian(214, 33, 24.28), angle_to_radian(302, 49, 44.41));//ǰ�Ӽ�С �����С
	 //24  X=0.300��  Y=0.583��  X=0.296��  Y=0.578��   X=0.291��  Y=0.583�� 359��59��60.00�� 182��7��45.49��   
	 Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(296, 578, x, y).x, convert(296, 578, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		 angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49) - 0.5);//ǰ�Ӽ�С �����С
	 //X=0.300��  Y=0.583��  X=0.297��  Y=0.587��   X=0.291��  Y=0.583�� 6��45��29.16�� 175��22��16.34��
	 Cirthree(convert(300, 583, x, y).x, convert(300, 583, x, y).y, convert(297, 587, x, y).x, convert(297, 587, x, y).y, convert(291, 583, x, y).x, convert(291, 583, x, y).y,
		 angle_to_radian(359, 59, 60), angle_to_radian(182, 7, 45.49) - 0.2);//ǰ�Ӽ�С �����С
	 // 25  X=0.281��  Y=0.594�� X=0.242��  Y=0.587��  X=0.270��  Y=0.576��  357��25��51.22�� 296��58��46.19��
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(357, 25, 51.22) - 0.2, angle_to_radian(296, 58, 46.19));//ǰ�Ӽ�С �����С
	   //�����ɫ    X=0.282��  Y=0.579�� 
	 BoundaryFill(convert(282, 579, x, y).x, convert(282, 579, x, y).y, rgb);
 }
 /// <summary>
/// ���������ɫ
/// </summary>
/// <param name="x">ָ������X</param>
/// <param name="y">ָ������Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillCheeks(int x, int y, COLORREF rgb) {
	 //��ʱ�� ����1�����߿�ͷ��� ����2��С ĩβ�߱��
	 //˳ʱ�� ����1��С�߿�ͷ��� ����2���� ĩβ�߱��
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(rgb);
	 //����
	 //17   X=0.301��  Y=0.480��   X=0.314��  Y=0.474��  X=0.320��  Y=0.476�� 222��52��32.60�� 294��24��49.26��
	 Cirthree(convert(301, 480, x, y).x, convert(301, 480, x, y).y, convert(314, 474, x, y).x, convert(314, 474, x, y).y, convert(320, 476, x, y).x, convert(320, 476, x, y).y,
		 angle_to_radian(222, 52, 32.6)+0.8, angle_to_radian(294, 24, 49.26));//ǰ�Ӽ�С �����С
	//18
	//X=0.320��  Y=0.476�� X=0.304��  Y=0.441��   X=0.301��  Y=0.480��  49��25��12.66�� 107��52��9.20��
	 Cirthree(convert(320, 476, x, y).x, convert(320, 476, x, y).y, convert(304, 441, x, y).x, convert(304, 441, x, y).y, convert(301, 480, x, y).x, convert(301, 480, x, y).y,
		 angle_to_radian(49, 25, 12.66) + 0.35, angle_to_radian(107, 52, 9.2) + 0.3);//ǰ�Ӽ�С �����С
	   //�����ɫ    X=0.303��  Y=0.455��
	 BoundaryFill(convert(303, 455, x, y).x, convert(303, 455, x, y).y,rgb);
	 Sleep(100);

	 //����
	//21  X=0.281��  Y=0.594��  X=0.273��  Y=0.588��  X=0.270��  Y=0.576�� 110��6��20.99�� 182��51��36.95��  
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(273, 588, x, y).x, convert(273, 588, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(110, 6, 20.99), angle_to_radian(182, 51, 36.95));//ǰ�Ӽ�С �����С
	// 25  X=0.281��  Y=0.594�� X=0.242��  Y=0.587��  X=0.270��  Y=0.576��  357��25��51.22�� 296��58��46.19��
	 Cirthree(convert(281, 594, x, y).x, convert(281, 594, x, y).y, convert(242, 587, x, y).x, convert(242, 587, x, y).y, convert(270, 576, x, y).x, convert(270, 576, x, y).y,
		 angle_to_radian(357, 25, 51.22) - 0.2, angle_to_radian(296, 58, 46.19));//ǰ�Ӽ�С �����С
		//�����ɫ    : X=0.257��  Y=0.586��  
	 BoundaryFill(convert(257, 586, x, y).x, convert(257, 586, x, y).y, rgb);
 }
 /// <summary>
/// ��������ɫ
/// </summary>
/// <param name="x">ָ������X</param>
/// <param name="y">ָ������Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillNose(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(rgb);
	 //26 
	//X=0.298��  Y=0.525��  X=0.308��  Y=0.537��  X=0.293��  Y=0.541��  263��22��18.66�� 130��13��16.69��
	 Cirthree(convert(298, 525, x, y).x, convert(298, 525, x, y).y, convert(308, 537, x, y).x, convert(308, 537, x, y).y, convert(293, 541, x, y).x, convert(293, 541, x, y).y,
		 angle_to_radian(263, 22, 18.66), angle_to_radian(130, 13, 16.69));//ǰ�Ӽ�С �����С
	 //27 
	 //X=0.299��  Y=0.525��  X=0.295��  Y=0.531��  X=0.296��  Y=0.543�� 229��4��22.30�� 150��0��22.36��
	 Cirthree(convert(299, 525, x, y).x, convert(299, 525, x, y).y, convert(295, 531, x, y).x, convert(295, 531, x, y).y, convert(296, 543, x, y).x, convert(293, 543, x, y).y,
		 angle_to_radian(229, 4, 22.3), angle_to_radian(150, 0, 22.36) - 0.5);//ǰ�Ӽ�С �����С
			//�����ɫ    X=0.301��  Y=0.533��
	 BoundaryFill(convert(301, 533, x, y).x, convert(301, 533, x, y).y, rgb);
 }
 /// <summary>
/// ��������ɫ
/// </summary>
/// <param name="x">ָ������X</param>
/// <param name="y">ָ������Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillMouth(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(rgb);
	 //28 
	//X=0.294��  Y=0.533��  X=0.284��  Y=0.514��  X=0.290��  Y=0.499��  122��50��28.32�� 223��27��28.35��
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		 angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//ǰ�Ӽ�С �����С
	 //29 
	 //X=0.294��  Y=0.533�� X=0.280��  Y=0.540��  X=0.273��  Y=0.561�� 257��43��39.66�� 174��6��13.43��
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		 angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//ǰ�Ӽ�С �����С
	 //30 
	 // X=0.285��  Y=0.519��  X=0.270��  Y=0.516��   X=0.259��  Y=0.521�� 297��57��10.55�� 235��54��32.11��
	 Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11) + 0.2);//ǰ�Ӽ�С �����С
	 //31
	 // X=0.280��  Y=0.540��  X=0.268��  Y=0.534��  X=0.259��  Y=0.521�� 103��26��12.32�� 162��30��12.91��
	 Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//ǰ�Ӽ�С �����С
	// X=0.277��  Y=0.526��  
	 BoundaryFill(convert(277, 526, x, y).x, convert(277, 526, x, y).y, rgb);
	 //��������
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(RGB(10, 10, 10));
	 //28 
   //X=0.294��  Y=0.533��  X=0.284��  Y=0.514��  X=0.290��  Y=0.499��  122��50��28.32�� 223��27��28.35��
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(284, 514, x, y).x, convert(284, 514, x, y).y, convert(290, 499, x, y).x, convert(290, 499, x, y).y,
		 angle_to_radian(122, 50, 28.32), angle_to_radian(223, 27, 28.35));//ǰ�Ӽ�С �����С
	 //29 
	 //X=0.294��  Y=0.533�� X=0.280��  Y=0.540��  X=0.273��  Y=0.561�� 257��43��39.66�� 174��6��13.43��
	 Cirthree(convert(294, 533, x, y).x, convert(294, 533, x, y).y, convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(273, 561, x, y).x, convert(273, 561, x, y).y,
		 angle_to_radian(257, 43, 39.66), angle_to_radian(174, 6, 13.43));//ǰ�Ӽ�С �����С
	 //30 
	 // X=0.285��  Y=0.519��  X=0.270��  Y=0.516��   X=0.259��  Y=0.521�� 297��57��10.55�� 235��54��32.11��
	 Cirthree(convert(285, 519, x, y).x, convert(285, 519, x, y).y, convert(270, 516, x, y).x, convert(270, 516, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(297, 57, 10.55), angle_to_radian(235, 54, 32.11) + 0.2);//ǰ�Ӽ�С �����С
	 //31
	 // X=0.280��  Y=0.540��  X=0.268��  Y=0.534��  X=0.259��  Y=0.521�� 103��26��12.32�� 162��30��12.91��
	 Cirthree(convert(280, 540, x, y).x, convert(280, 540, x, y).y, convert(268, 534, x, y).x, convert(268, 534, x, y).y, convert(259, 521, x, y).x, convert(259, 521, x, y).y,
		 angle_to_radian(103, 26, 12.32), angle_to_radian(162, 30, 12.91));//ǰ�Ӽ�С �����С
 }
 /// <summary>
/// ����Ѿ��ɫ
/// </summary>
/// <param name="x">ָ������X</param>
/// <param name="y">ָ������Y</param>
/// <param name="r">R</param>
/// <param name="g">G</param>
/// <param name="b">B</param>
 void FillFoots(int x, int y, COLORREF rgb) {
	 setlinestyle(PS_SOLID, 3);
	 //������ɫ
	 setlinecolor(rgb);

	 //���
		 // X=0.102��  Y=0.353 X=0.095��  Y=0.352�� X=0.090��  Y=0.363��  297��41��28.87�� 161��26��56.78��
	 Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(95, 352, x, y).x, convert(95, 352, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		 angle_to_radian(297, 41, 28.87), angle_to_radian(161, 26, 56.78));//ǰ�Ӽ�С �����С
	 // X=0.102��  Y=0.353  X=0.098��  Y=0.362�� X=0.090��  Y=0.363�� 352��46��12.08�� 106��22��13.57��
	 Cirthree(convert(102, 353, x, y).x, convert(102, 353, x, y).y, convert(98, 362, x, y).x, convert(98, 362, x, y).y, convert(90, 363, x, y).x, convert(90, 363, x, y).y,
		 angle_to_radian(352, 46, 12.08), angle_to_radian(106, 22, 13.57) - 0.3);//ǰ�Ӽ�С �����С
	 // X=0.096��  Y=0.358��
	 BoundaryFill(convert(96, 358, x, y).x, convert(96, 358, x, y).y, rgb);
	 Sleep(100);

	 // X=0.116��  Y=0.362�� X=0.108��  Y=0.360��  X=0.101��  Y=0.367��  317��39��8.35�� 187��5��41.70��
	 Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(108, 360, x, y).x, convert(108, 360, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		 angle_to_radian(317, 39, 8.35), angle_to_radian(187, 5, 41.7) - 0.3);//ǰ�Ӽ�С �����С
	 // X=0.116��  Y=0.362��  X=0.111��  Y=0.369�� X=0.101��  Y=0.367��  X=0.101��  Y=0.367��=8��17��27.46��  =136��27��22.58��
	 Cirthree(convert(116, 362, x, y).x, convert(116, 362, x, y).y, convert(111, 369, x, y).x, convert(111, 369, x, y).y, convert(101, 367, x, y).x, convert(101, 367, x, y).y,
		 angle_to_radian(8, 17, 27.46), angle_to_radian(136, 27, 22.58));//ǰ�Ӽ�С �����С
	 //X=0.108��  Y=0.365��
	 BoundaryFill(convert(108, 365, x, y).x, convert(108, 365, x, y).y, rgb);
	 Sleep(100);

	 //X=0.117��  Y=0.376��   X=0.109��  Y=0.372��  X=0.101��  Y=0.381�� 329��10��9.96�� 181��22��7.37��
	 Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(109, 372, x, y).x, convert(109, 372, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		 angle_to_radian(329, 10, 9.96), angle_to_radian(181, 22, 7.37));//ǰ�Ӽ�С �����С
	 //X=0.117��  Y=0.376��   X=0.111��  Y=0.383��  X=0.101��  Y=0.381�� 15��26��31.36�� 135��5��45.98��
	 Cirthree(convert(117, 376, x, y).x, convert(117, 376, x, y).y, convert(111, 383, x, y).x, convert(111, 383, x, y).y, convert(101, 381, x, y).x, convert(101, 381, x, y).y,
		 angle_to_radian(15, 26, 31.36), angle_to_radian(135, 5, 45.98));//ǰ�Ӽ�С �����С
	 // X=0.108��  Y=0.378�� 
	 BoundaryFill(convert(108, 378, x, y).x, convert(108, 378, x, y).y, rgb);
	 Sleep(100);

	 //X=0.096��  Y=0.372�� X=0.087��  Y=0.370��  X=0.074��  Y=0.386�� 299��3��38.35�� 171��38��8.91��
	 Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(87, 370, x, y).x, convert(87, 370, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		 angle_to_radian(299, 3, 38.35), angle_to_radian(171, 38, 8.91));//ǰ�Ӽ�С �����С
	 //X=0.096��  Y=0.372�� X=0.090��  Y=0.387��   X=0.074��  Y=0.386��  343��40��27.29�� 127��1��19.97��
	 Cirthree(convert(96, 372, x, y).x, convert(96, 372, x, y).y, convert(90, 387, x, y).x, convert(90, 387, x, y).y, convert(74, 386, x, y).x, convert(74, 386, x, y).y,
		 angle_to_radian(343, 40, 27.29), angle_to_radian(127, 1, 19.97));//ǰ�Ӽ�С �����С
	 //  X=0.084��  Y=0.379��
	 BoundaryFill(convert(84, 379, x, y).x, convert(84, 379, x, y).y,rgb);
	 Sleep(100);

	 //�ҽ�
	 //  X=0.116��  Y=0.642��   X=0.111��  Y=0.636��   X=0.101��  Y=0.638�� 341��40��12.79�� 222��43��32.33��
	 Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(111, 636, x, y).x, convert(111, 636, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		 angle_to_radian(341, 40, 12.79), angle_to_radian(222, 43, 32.33));//ǰ�Ӽ�С �����С
	 //X=0.116��  Y=0.642��   X=0.105��  Y=0.645��   X=0.101��  Y=0.638�� 29��17��54.10�� 175��5��51.02��
	 Cirthree(convert(116, 642, x, y).x, convert(116, 642, x, y).y, convert(105, 645, x, y).x, convert(105, 645, x, y).y, convert(101, 638, x, y).x, convert(101, 638, x, y).y,
		 angle_to_radian(29, 17, 54.1), angle_to_radian(175, 5, 51.02));//ǰ�Ӽ�С �����С
	 // X=0.108��  Y=0.639�� 
	 BoundaryFill(convert(108, 639, x, y).x, convert(108, 639, x, y).y, rgb);
	 Sleep(100);

	 // X=0.115��  Y=0.659�� X=0.109��  Y=0.649�� X=0.101��  Y=0.651�� 11��34��2.18�� 226��10��24.04��
	 Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(109, 649, x, y).x, convert(109, 649, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		 angle_to_radian(11, 34, 2.18), angle_to_radian(226, 10, 24.04));//ǰ�Ӽ�С �����С
	 //X=0.115��  Y=0.659��  X=0.105��  Y=0.658�� X=0.101��  Y=0.651�� 61��48��24.44�� 175��56��1.78��
	 Cirthree(convert(115, 659, x, y).x, convert(115, 659, x, y).y, convert(105, 658, x, y).x, convert(105, 658, x, y).y, convert(101, 651, x, y).x, convert(101, 651, x, y).y,
		 angle_to_radian(61, 48, 24.44), angle_to_radian(175, 59, 1.78));//ǰ�Ӽ�С �����С
	 //  X=0.110��  Y=0.653��
	 BoundaryFill(convert(110, 653, x, y).x, convert(110, 653, x, y).y,rgb);
	 Sleep(100);

	 // X=0.103��  Y=0.665��  X=0.096��  Y=0.656��  X=0.091��  Y=0.657�� 7��6��59.98�� 242��31��15.10��
	 Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(96, 656, x, y).x, convert(96, 656, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		 angle_to_radian(7, 6, 59.98), angle_to_radian(242, 31, 15.1));//ǰ�Ӽ�С �����С
	 //X=0.103��  Y=0.665��  X=0.098��  Y=0.667��  X=0.091��  Y=0.657�� 57��19��9.55�� 192��19��5.54��
	 Cirthree(convert(103, 665, x, y).x, convert(103, 665, x, y).y, convert(98, 667, x, y).x, convert(98, 667, x, y).y, convert(91, 657, x, y).x, convert(91, 657, x, y).y,
		 angle_to_radian(57, 19, 9.55), angle_to_radian(192, 19, 5.54));//ǰ�Ӽ�С �����С
		 //  X=0.095��  Y=0.659��
	 BoundaryFill(convert(95, 659, x, y).x, convert(95, 659, x, y).y,rgb);
	 Sleep(100);

	 //  X=0.096��  Y=0.648��  X=0.085��  Y=0.630��  X=0.074��  Y=0.632�� 13��3��12.91�� 239��15��54.89��
	 Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(85, 630, x, y).x, convert(85, 630, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		 angle_to_radian(13, 3, 12.91), angle_to_radian(239, 15, 54.89));//ǰ�Ӽ�С �����С
	 //X=0.096��  Y=0.648��  X=0.087��  Y=0.650��   X=0.074��  Y=0.632�� 59��0��34.03�� 193��18��33.76��
	 Cirthree(convert(96, 648, x, y).x, convert(96, 648, x, y).y, convert(87, 650, x, y).x, convert(87, 650, x, y).y, convert(74, 632, x, y).x, convert(74, 632, x, y).y,
		 angle_to_radian(59, 0, 34.03), angle_to_radian(193, 18, 33.76));//ǰ�Ӽ�С �����С
	 //  X=0.090��  Y=0.642��
	 BoundaryFill(convert(90, 642, x, y).x, convert(90, 642, x, y).y, rgb);
 }
 /// <summary>
 /// ����ɫ��
 /// </summary>
 /// <param name="x">ɫ�����ϽǺ�����</param>
 /// <param name="y">ɫ�����Ͻ�������</param>
 void SetColorCard(int x, int y) {
	 const int wide = 5;
	 const int height = 23;
	 int x0 = x;
	 int y0 = y;//����ԭ����Ϣ
	 //���������ɫ
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
	 //3  ����
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
	 //20  ����
	 setfillcolor(RGB(255 ,220 ,220 ));
	 POINT pts20[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts20, 4);
	 y += wide;
	 y += height;	


	 //�ڶ���
	 y = y0;
	 x = x0 + 300;
	 //1   ����
	 setfillcolor(RGB(62, 5, 14));
	 POINT pts21[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts21, 4);
	 y += wide;
	 y += height;
	 //2 ��֬
	 setfillcolor(RGB(157, 41, 50));
	 POINT pts22[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts22, 4);
	 y += wide;
	 y += height;
	 //3  ����
	 setfillcolor(RGB(239, 222, 176));
	 POINT pts23[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts23, 4);
	 y += wide;
	 y += height;
	 //4  ��ɫ
	 setfillcolor(RGB(168, 132, 98));
	 POINT pts24[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts24, 4);
	 y += wide;
	 y += height;
	 //5   ����ɫ
	 setfillcolor(RGB(217, 182, 18));
	 POINT pts25[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts25, 4);
	 y += wide;
	 y += height;
	 //6   ����
	 setfillcolor(RGB(120, 146, 98));
	 POINT pts26[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts26, 4);
	 y += wide;
	 y += height;
	 //7  ��ɫ
	 setfillcolor(RGB(73, 65, 102));
	 POINT pts27[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts27, 4);
	 y += wide;
	 y += height;
	 //8   ѻ��
	 setfillcolor(RGB(66, 75, 80));
	 POINT pts28[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts28, 4);
	 y += wide;
	 y += height;
	 //9  ̴
	 setfillcolor(RGB(179, 109, 970));
	 POINT pts29[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts29, 4);
	 y += wide;
	 y += height;
	 //10  ����
	 setfillcolor(RGB(65, 80, 101));
	 POINT pts30[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts30, 4);
	 y += wide;
	 y += height;
	 //11 �°�
	 setfillcolor(RGB(215, 236, 241));
	 POINT pts31[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts31, 4);
	 y += wide;
	 y += height;
	 //12  ˮ��
	 setfillcolor(RGB(212, 242, 232));
	 POINT pts32[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts32, 4);
	 y += wide;
	 y += height;
	 //13  ��
	 setfillcolor(RGB(255, 51, 0));
	 POINT pts33[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts33, 4);
	 y += wide;
	 y += height;
	 //14  ����
	 setfillcolor(RGB(23, 124, 176));
	 POINT pts34[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts34, 4);
	 y += wide;
	 y += height;
	 //���
	 setfillcolor(RGB(243, 248, 241));
	 POINT pt35[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pt35, 4);
	 y += wide;
	 y += height;
	 //16  ��
	 setfillcolor(RGB(195, 39, 43));
	 POINT pts36[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts36, 4);
	 y += wide;
	 y += height;
	 //17   �
	 setfillcolor(RGB(169, 129, 117));
	 POINT pts37[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts37, 4);
	 y += wide;
	 y += height;
	 //18   ���
	 setfillcolor(RGB(255, 158, 159));
	 POINT pts38[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts38, 4);
	 y += wide;
	 y += height;
	 //19  ש��
	 setfillcolor(RGB(156, 102, 101));
	 POINT pts39[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts39, 4);
	 y += wide;
	 y += height;
	 //20  ������
	 setfillcolor(RGB(138, 43, 226));
	 POINT pts40[] = { {x, y}, {x + 200, y}, {x + 200, y + height}, {x, y + height} };
	 fillpolygon(pts40, 4);
	 y += wide;
	 y += height;
 }
 /// <summary>
 /// ��Ϸ��ʼ
 /// </summary>
 /// <param name="x">ָ��������</param>
 /// <param name="y">ָ��������</param>
 void GameStart(int x,int y) {
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 TCHAR s1[] = _T("��ɫ��Ϸ");
	 outtextxy(200, 30, s1);
	 Sleep(2000);
	 DelText();
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 TCHAR s2[] = _T("�����Ļ��ʼ��Ϸ");
	 outtextxy(150, 30, s2);
	 MOUSEMSG m;		// ���������Ϣ
	 TCHAR s3[] = _T("������ʾѡ���ҷ�ɫ���е���ɫ");
	 int off = 0;//�ж��Ƿ�������� 0Ϊû�� 1λ��
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 settextcolor(RGB(241, 149, 108));
			 settextstyle(40, 0, _T("����"));
			 outtextxy(10, 30, s3);
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off==1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 Sleep(2000);
	 off = 0;
	 DelText();
	 TCHAR s4[] = _T("��ѡ��������ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s4);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
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
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s5[] = _T("��ѡ���۾�����ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s5);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillEyes(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s6[] = _T("��ѡ�����յ���ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s6);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillCheeks(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s7[] = _T("��ѡ����ӵ���ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s7);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillNose(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s8[] = _T("��ѡ����͵���ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s8);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillMouth(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s9[] = _T("��ѡ����ܲ�����ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s9);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillCarrot(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s10[] = _T("��ѡ����Ҷ����ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s10);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();
			 FillLeaf(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 off = 0;
	 TCHAR s11[] = _T("��ѡ���Ѿ����ɫ");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s11);
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 FillFoots(x, y, getpixel(m.x, m.y));
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
	 DelText();
	 TCHAR s12[] = _T("���������");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 outtextxy(150, 30, s12);
	 off = 0;
	 TCHAR s13[] = _T("��������־����͸���");
	 settextcolor(RGB(241, 149, 108));
	 settextstyle(40, 0, _T("����"));
	 FlushMouseMsgBuffer();
	 // ��ȡһ�������Ϣ
	 while (true)
	 {
		 // ��ȡһ�������Ϣ
		 m = GetMouseMsg();
		 switch (m.uMsg)
		 {
		 case WM_LBUTTONDOWN:
			 DelText();		
			 outtextxy(150, 30, s13);
			 off = 1;
			 break;
		 case WM_RBUTTONUP:
			 ;	// ������Ҽ��˳�����
		 }
		 if (off == 1)
		 {
			 break;//�˳���ȡ����¼�
		 }
	 }
 }
 void DelText() {
	 //��������
	 setfillcolor(RGB(255, 255, 255));
	 setlinecolor(RGB(255, 255, 255));
	 POINT pts[] = { {0, 0}, {590, 0}, {590, 80}, {0, 80} };
	 fillpolygon(pts, 4);
 }



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
	//��ʼ��ͼ��
	initgraph(800, 600);
	//���ñ���Ϊ��ɫ
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	//��ͷ����  X=0.438��  Y=0.484��  X=0.432��  Y=0.576��  X=0.383��  Y=0.653�� 
	int x = convert(247, 366, 400, 225).x;
	int y = convert(351, 388, 400, 225).y;
	//double m = atan((136.0-263.0)/(520.0-385.0));
	//double n = atan((136.0 - 263.0) / (520.0 - 385.0));
	drawrabbit(400, 225, 1.0);



	system("pause");
	return 0;
}
/// <summary>
/// ���㻭Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
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
/// <param name="rongcha">�ݲ�</param>
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
/// ����˳ʱ�����Բ��
/// </summary>
/// <param name="X1">��һ�����X</param>
/// <param name="Y1">��һ�����Y</param>
/// <param name="X2">�ڶ������X</param>
/// <param name="Y2">�ڶ������Y</param>
/// <param name="X3">���������X</param>
/// <param name="Y3">���������Y</param>
/// <param name="rongcha">�ݲ�</param>
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
	const int delay = 500;
	//��������
	setlinestyle(PS_SOLID, 5);
	//������ɫ
	setlinecolor(RGB(10, 10, 10));

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
		angle_to_radian(227, 7, 42.41), angle_to_radian(175, 45, 26.43));
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
	//X=0.180��  Y=0.456��  X=0.175��  Y=0.461��  X=0.162��  Y=0.458�� 33��6��54.28��  =22��59��33.74��
	Cirthree(convert(180, 456, x, y).x, convert(180, 456, x, y).y, convert(175, 461, x, y).x, convert(175, 461, x, y).y, convert(162, 458, x, y).x, convert(162, 458, x, y).y,
		angle_to_radian(33, 6, 54.28),angle_to_radian(22, 59, 33.74));//ǰ�Ӽ�С �����С
	Sleep(delay);
	// X=0.162��  Y=0.458��   X=0.148��  Y=0.437�� X=0.144��  Y=0.416�� 132��54��8.27�� 181��56��3.85��
	Cirthree(convert(162, 458, x, y).x, convert(162, 458, x, y).y, convert(148, 437, x, y).x, convert(148, 437, x, y).y, convert(144, 416, x, y).x, convert(144, 416, x, y).y,
		angle_to_radian(132, 54, 8.27) , angle_to_radian(181, 56, 3.85) );//ǰ�Ӽ�С �����С
	Sleep(delay);

	//����


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
	if (((x - x0) > 0 && (y - y0) > 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//�ڶ�����
	if ((x - x0) > 0 && (y - y0) < 0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//��������
	if ((x - x0) < 0 && (y - y0) < 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//��������
	if ((x - x0) < 0 && (y - y0) > 0)
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


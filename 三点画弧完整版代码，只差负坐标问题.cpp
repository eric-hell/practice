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
	//��ʼ��ͼ��
	initgraph(800, 450);
	//���ñ���Ϊ��ɫ
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	//��ͷ����  X=0.438��  Y=0.484��  X=0.432��  Y=0.576��  X=0.383��  Y=0.653�� 
	int x=  convert(258, 519, 400, 225).x;
	int y = convert(258, 519, 400, 225).y;
	double m = atan((136.0-263.0)/(520.0-385.0));
	double n = atan((136.0 - 263.0) / (520.0 - 385.0));
	drawrabbit(400,225,1.0);



	system("pause");
	return 0;
}
/// <summary>
/// ���㻭Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirthree(double X1, double Y1, double X2, double Y2, double X3, double Y3,double rongcha) {
	//�жϵ�һ������ڶ������λ�ã�ȷ����˳ʱ�뻭������ʱ�뻭
	//һ������˳ʱ��
	if (((X2 - X1) > 0 && (Y2 - Y1) > 0) || ((X2 - X1) < 0 && (Y2 - Y1) < 0)) {
		Cirshun(X1, Y1, X2, Y2, X3, Y3,rongcha);
	}
	//����������ʱ��
	if (((X2 - X1) > 0 && (Y2 - Y1) < 0) || ((X2 - X1) < 0 && (Y2 - Y1) > 0)) {
		Cirni(X1, Y1, X2, Y2, X3, Y3,rongcha);
	}
}
/// <summary>
/// ���㻭��ʱ��Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirni(double X1, double Y1, double X2, double Y2, double X3, double Y3,double rongcha) {
	//��Բ��
	//��L1  ��бʽ�󽻵�
	double m =(double)(X2-X1) / (Y1-Y2);//3.833333333
	double p =(double)(X2 + X1) / 2;//339.5
	double q =(double)(Y2 + Y1) / 2;//84
	double n =(double)(X3-X2) / (Y2-Y3);//1.75
	double w =(double)(X3 + X2) / 2;//317.5
	double v =(double)(Y3 + Y2) / 2;//93 ����Ϊ���ɱ�����������Ľ��
	//x��yΪԲ������
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//��뾶
	double r =(double)sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//�󻡶���Ҫ���ĸ����޽����� ��Բ��Ϊԭ�� �жϵ������Բ��ķ���
	//��Բ��  ���ڲ����������ͼ���������᲻ͬ����������/2
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
/// ���㻭˳ʱ��Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirshun(double X1, double Y1, double X2, double Y2, double X3, double Y3, double rongcha) {
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
	//��Բ��  ���ڲ����������ͼ���������᲻ͬ����������/2
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
	if ((x1 > x0) && (y1 <y0))//��һ������
	{
		double hudu =(double)atan((y1 - y0) / (x0 - x1));
		return hudu;
	}
	if ((x1 < x0) && (y1 < y0))//�ڶ�������
	{
		double hudu =PI-atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 > y0)));//����������
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
	line((int)convert(455,464,x,y).x, convert(455, 464, x, y).y, convert(414, 351, x, y).x, convert(414, 351, x, y).y);
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
	line(convert(283, 747, x, y).x, convert(283,747, x, y).y, convert(419, 718, x, y).x, convert(419, 718, x, y).y);
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

	//��ͷ����  X=0.438��  Y=0.484��  X=0.432��  Y=0.461��  X=0.420��  Y=0.440�� 
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 461, x, y).x, convert(432, 461, x, y).y, convert(420, 440, x, y).x, convert(420, 440, x, y).y,0.0);
	Sleep(delay);
	// X=0.420��  Y=0.440��  X=0.389��  Y=0.408��   X=0.351��  Y=0.388�� 
	Cirthree(convert(420, 440, x, y).x, convert(420, 440, x, y).y, convert(389, 408, x, y).x, convert(389, 408, x, y).y, convert(351, 388, x, y).x, convert(351, 388, x, y).y,0.1);
	Sleep(delay);
	// X=0.438��  Y=0.484��  X=0.432��  Y=0.576��  X=0.383��  Y=0.653��
	Cirthree(convert(438, 484, x, y).x, convert(438, 484, x, y).y, convert(432, 576, x, y).x, convert(432, 576, x, y).y, convert(383, 653, x, y).x, convert(383, 653, x, y).y, 0.0);
	Sleep(delay);
	//

}
POINT  convert(double x, double y, double X, double Y) {
	//��һ������ˮƽ����ֵ������Ծ���
	//��������ο���
	//X=0.294��  Y=0.533��
	const int x0 = 294;
	const int y0 = 533;
	int xx=0, yy=0;
	int distancesz = abs((int)x-x0);//������ֱ�������
	int distancesp = abs((int)y-y0);//����ˮƽ�������
	//�ڶ����ж���Է�λ
	//��һ����
	if (((x-x0 ) > 0 && (y-y0) > 0))
	{
		xx = X + distancesp;
		yy = Y - distancesz;
	}
	//�ڶ�����
	if ((x-x0)>0 && (y-y0)<0)
	{
		xx = X - distancesp;
		yy = Y - distancesz;
	}
	//��������
	if ((x-x0) < 0 && (y-y0) < 0)
	{
		xx = X - distancesp;
		yy = Y + distancesz;
	}
	//��������
	if ((x-x0) < 0 && (y-y0) > 0)
	{
		xx = X + distancesp;
		yy = Y + distancesz;
	}
	//��������ȷ��ת���������ֵ
		POINT pt[1];
		pt[0] = { xx,yy };
		return pt[0];
}

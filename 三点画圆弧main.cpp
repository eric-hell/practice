#include<graphics.h>
#include<Windows.h>
#include<math.h>
void Cirni(int X1, int Y1, int X2, int Y2, int X3, int Y3);
void Cirshun(int X1, int Y1, int X2, int Y2, int X3, int Y3);
void Cirthree(int X1, int Y1, int X2, int Y2, int X3, int Y3);
double HuDu(int x0, int y0, int x1, int y1);
int main(void) {
	//��ʼ��ͼ��
	initgraph(800,450);
	//���ñ���Ϊ��ɫ
	setbkcolor(RGB(255,255,255));
	cleardevice();
	setlinecolor(RGB(255, 0, 0));
	





	system("pause");
	return 0;
}
/// <summary>
/// ���㻭Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirthree(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	//�жϵ�һ������ڶ������λ�ã�ȷ����˳ʱ�뻭������ʱ�뻭
	//һ��������ʱ��
	if (((X2-X1)>0&&(Y2-Y1)>0)||((X2 - X1) < 0 && (Y2 - Y1) < 0)) {
		Cirni( X1,  Y1,  X2,  Y2,  X3,  Y3);
	}
	//��������˳ʱ��
	if (((X2 - X1) < 0 && (Y2 - Y1) > 0) || ((X2 - X1) > 0 && (Y2 - Y1) < 0)) {
		Cirshun(X1, Y1, X2, Y2, X3, Y3);
	}
}
/// <summary>
/// ���㻭��ʱ��Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirni(int X1,int Y1, int X2, int Y2, int X3, int Y3) {
	//��Բ��
	//��L1  ��бʽ�󽻵�
	int m = (X2-X1) / (Y1-Y2);
	int p = (X2+X1) / 2;
	int q = (Y2+Y1) / 2;
	int n = (X3-X2) / (Y2-Y3);
	int w = (X3+X2) / 2;
	int v = (Y3+Y2) / 2;//����Ϊ���ɱ�����������Ľ��
	//x��yΪԲ������
	int x = (-m*p+q-v+n*w) / (n-m);
	int y = n * (x - w) + v;
	//��뾶
	double r =sqrt(pow((X1-x),2)+ pow((Y1 - y), 2)) ;
	//�󻡶���Ҫ���ĸ����޽����� ��Բ��Ϊԭ�� �жϵ������Բ��ķ���
	//��Բ��
	double hudu1 = HuDu(x, y, X1, Y1);//start hudu
	double hudu2 = HuDu(x, y, X3, Y3);//end hudu

	arc(x-r,y-r,x+r,y+r, hudu1, hudu2);
	//line(X1,Y1,X2,Y2);
}
/// <summary>
/// ���㻭˳ʱ��Բ��
/// </summary>
/// <param name="P1">��ʼ��</param>
/// <param name="P2">�ڶ���</param>
/// <param name="P3">�յ�</param>
void Cirshun(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	//��Բ��
	//��L1  ��бʽ�󽻵�
	int m = (X2 - X1) / (Y1 - Y2);
	int p = (X2 + X1) / 2;
	int q = (Y2 + Y1) / 2;
	int n = (X3 - X2) / (Y2 - Y3);
	int w = (X3 + X2) / 2;
	int v = (Y3 + Y2) / 2;//����Ϊ���ɱ�����������Ľ��
	//x��yΪԲ������
	int x = (-m * p + q - v + n * w) / (n - m);
	int y = n * (x - w) + v;
	//��뾶
	double r = sqrt(pow((X1 - x), 2) + pow((Y1 - y), 2));
	//�󻡶���Ҫ���ĸ����޽����� ��Բ��Ϊԭ�� �жϵ������Բ��ķ���
	//��Բ��
	double hudu1 = -HuDu(x, y, X1, Y1);//start hudu
	double hudu2 = -HuDu(x, y, X3, Y3);//end hudu

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
double HuDu(int x0,int y0,int x1,int y1) {
	const double PI = acos(-1);
	if ((x1 > x0) && (y1==y0))//x+����
	{
		double hudu = 0.0;
		return hudu;
	}
	if ((x1 <x0) && (y1==y0))//x-����
	{
		double hudu =  PI;
		return hudu;
	}
	if ((x1==x0) && (y1 >y0))//y+����
	{
		double hudu =PI / 2;
		return hudu;
	}
	if ((x1==x0) &&(y1< y0))//y-����
	{
		double hudu =PI * 3 / 2;
		return hudu;
	}
	if ((x1 > x0 )&& (y1 > y0 ))//��һ������
	{
		double hudu= atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if ((x1 < x0) && (y1 > y0))//�ڶ�������
	{
		double hudu =PI-atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if (((x1 < x0) && (y1 < y0)));//����������
	{
		double hudu = 3*(acos(-1))/2 - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
	if ((x1 > x0) && (y1 < y0))//����������
	{
		double hudu =2*PI - atan((y1 - y0) / (x1 - x0));
		return hudu;
	}
}
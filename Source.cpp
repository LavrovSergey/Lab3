#include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;
int l5()
{
	setlocale(LC_ALL, "Russian");
	double xp, xn, a, b, eps, f, f1;
	cout << "������ ��������� f(x)=x^3+x-5=0 �� ������� � ����� ���������" << endl;
	cout << "f`(x)=3x^2+1" << endl;
	cout << "f``(x)=6x" << endl;
	cout << "������� ��������" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "������� �������";
	cin >> eps;
	if ((a * a * a + a - 5) * 6 * a > 0) { xp = a; }
	else if ((b * b * b + b - 5) * 6 * b > 0) { xp = b; }
	else if ((a * a * a + a - 5) * 6 * a < 0 && (b * b * b + b - 5) * 6 * b < 0) { cout << "�� ���������, ������ ��� ������"; return 0; }
	for (int i = 0; i < 100000; i++)
	{
		f = xp * xp * xp + xp - 5;
		f1 = 3 * xp * xp + 1;
		xn = xp - f / f1;
		if (abs(xn - xp) < eps) { cout << "x= " << xp<<endl; break; }
		xp = xn;
		xn = 0;
	}
	int code;
	cout << "���� ������ � ����, ������� ������";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
double f(double x, double y, int k)
{
	if (k == 1) { return x * sin(y); }
	if (k == 2) { return x * cos(y); }
	if (k == 3) { return x * tan(y); }
	if (k == 4) { return x * 1 / tan(y); }
}

int l19()
{
	setlocale(LC_ALL, "Russian");
	int i, k;
	double Integral, x;
	cout << "������� ������� ��������������" << endl;
	double a, b;
	cin >> a >> b;
	cout << "������� �=";
	cin >> x;
	double step = 0.1;
	double n;
	n = (b - a) / step;
	cout << "�������� ������� " << endl;
	cout << "1.y*sinx, 2.y*cosx, 3.y*tgx, 4.y*ctgx, ";
	do { cin >> k; } while (k < 0 && k>4);
	// ��������� �������� �� ������� ����������� ��������������
	Integral = 0.0;
	for (i = 1; i <= n; i++)
		Integral = Integral + step * f(x, a + step * (i - 0.5), k);
	cout << "g(x) = " << Integral<<endl;
	int code;
	cout << "���� ������ � ���� ������� ������";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
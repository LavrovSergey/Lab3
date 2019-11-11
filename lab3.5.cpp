#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double xp, xn, a, b, eps, f, f1;
	cout << "Решаем уравнение f(x)=x^3+x-5=0 на отрезке с вашей точностью" << endl;
	cout << "f`(x)=3x^2+1" << endl;
	cout << "f``(x)=6x" << endl;
	cout << "Введите интервал" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "Введите эпсилон";
	cin >> eps;
	if ((a * a * a + a - 5) * 6 * a > 0) { xp = a; }
	else if ((b * b * b + b - 5) * 6 * b > 0) { xp = b; }
	else if((a * a * a + a - 5) * 6 * a < 0 && (b * b * b + b - 5) * 6 * b < 0){cout << "Не сходиться, значит нет ответа"; return 0; }
	for (int i = 0; i < 100000; i++)
	{
		f = xp * xp * xp + xp - 5;
		f1 = 3 * xp * xp + 1;
		xn = xp - f / f1;
		if (abs(xn - xp) < eps) { cout << "x= " << xp; break; }
		xp = xn;
		xn = 0;
	}
	return 0;
}
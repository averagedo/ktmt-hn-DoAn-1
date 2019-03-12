#include"Function.h"

void main()
{
	QInt I, E, V;
	string a = "15";
	string m = "15";
	int b[128] = { 0 };
	int c[128] = { 0 };
	b[126] = 1; b[124] = 1; b[123] = 1, b[0] = 1;
	c[127] = 1;
	int* f;
	string z, x, v;
	I.ScanQInt(a, 10);
	E.ScanQInt(m, 10);
	if (E == I)cout << "dung" << endl;

	//I.ScanQInt(a,10);
	//I.PrintQInt();

	//I.ChiaBinary(a);
	

	
	system("pause");
}
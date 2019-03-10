#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class QInt
{
private:
	int qInt[4];
public:
	QInt();
	string ChiaBinary(string a);
	void DecToBin(string a, int* &b, int n);	//chuyen tu string sang mang int vs n ptu
	void ScanQInt();
	string NhanHai(string a);
	string MuHai(int a);
	string CongStr(string a, string b);
	string BinToDec(int *a, int n);	//chuyen tu mang intvs n ptu sang string
	void PrintQInt();
};
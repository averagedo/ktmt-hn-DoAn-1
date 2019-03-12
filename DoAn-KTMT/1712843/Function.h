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
	void setQInt(int* a, int n);
	int* getQInt();

	string ChiaBinary(string a);
	void DecToBin(string a, int* &b);	//chuyen tu string sang mang int vs n ptu
	int* BuHai(int *a);
	string NhanHai(string a);
	string MuHai(int a);
	string CongHaiChuoi(string Src1, string Src2);
	string BinToDec(int a[], int n);	//chuyen tu mang int vs n ptu sang string
	void PrintQInt();
	string BinToHex(int *a, int n);
	string DecToHex(string a);
	int* HexToBin(string a);
	void ScanQInt(string a,int n);	//n la kieu so (n=10 hay n=16)
	void ScanQInt(int* a);

	const QInt operator+(QInt& a);
	const QInt operator-(QInt& a);
	const QInt operator*(QInt& a);

	bool operator<(QInt& a);
	bool operator>(QInt& a);
	bool operator==(QInt& a);
	bool operator<=(QInt& a);
	bool operator>=(QInt& a);
	//QInt operator=(QInt& a);

	/*QInt operator&(const QInt& a);
	QInt operator|(const QInt& a);
	QInt operator^(const QInt& a);
	friend QInt operator~(const QInt& a);*/

	QInt operator>>(int a);
};
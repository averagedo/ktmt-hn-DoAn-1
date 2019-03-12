#include"Function.h"

QInt::QInt()
{
	for (int i = 0; i < 4; i++)
	{
		qInt[i] = 0;
	}
}

void QInt::setQInt(int * a, int n)
{
	for (int i = 0; i < 4; i++)
	{
		qInt[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
		{
			if (i < 32)
				qInt[0] = (1 << (31 - i)) | qInt[0];
			else if (i < 64)
				qInt[1] = (1 << (63 - i)) | qInt[1];
			else if (i < 96)
				qInt[2] = (1 << (95 - i)) | qInt[2];
			else if (i < 128)
				qInt[3] = (1 << (127 - i)) | qInt[3];
		}
	}
}

int* QInt::getQInt()
{
	int n = 128;
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (i < 32)
			a[i] = (qInt[0] >> (31 - i)) & 1;
		else if (i < 64)
			a[i] = (qInt[1] >> (63 - i)) & 1;
		else if (i < 96)
			a[i] = (qInt[2] >> (95 - i)) & 1;
		else if (i < 128)
			a[i] = (qInt[3] >> (127 - i)) & 1;
	}
	return a;
}

string QInt::ChiaBinary(string a)
{
	string b;
	int du = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (du == 0)
		{
			b.push_back((char)((((int)a[i] - 48) / 2) + 48));
			if ((((int)a[i] - 48) % 2) != 0)
				du = ((int)a[i] - 48) % 2;
		}
		else {
			du = du * 10 + ((int)a[i] - 48);
			b.push_back((char)((du / 2) + 48));
			du = du % 2;
		}
	}
	if (b[0] == '0')
		b.erase(b.begin());
	return b;
}

void QInt::DecToBin(string a, int* &b)
{
	b = new int[128];
	for (int i = 0; i < 128; i++)
	{
		b[i] = 0;
	}
	int i = 0;
	while (a != "")
	{
		if (a[a.length() - 1] % 2 == 0)
			b[128 - i - 1] = 0;
		else
			b[128 - i - 1] = 1;
		i++;
		a = ChiaBinary(a);
	}
}

int * QInt::BuHai(int * a)
{
	for (int i = 0; i < 128; i++)
	{
		a[i] = (a[i] == 1) ?  0 : 1 ;
	}
	QInt trai, phai;
	int c[128]; c[127] = 1;
	trai.ScanQInt(a);
	phai.ScanQInt(c);
	phai = phai + trai;
	return phai.getQInt();
}

string QInt::NhanHai(string a)
{
	int v, nho = 0;
	string b;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		v = ((char)a[i] - 48) * 2;
		if (nho == 0)
		{
			if (v >= 10)
			{
				nho = 1;
				v = v % 10;
				b.insert(0, 1, char(v + 48));
				if (i == 0)
					b.insert(0, 1, char(1 + 48));
			}
			else
				b.insert(0, 1, char(v + 48));
		}
		else
		{
			if (v >= 9)// lo bang 9 nho 1 =10
			{
				nho = 1;
				v = (v + 1) % 10;
				b.insert(0, 1, char(v + 48));
				if (i == 0)
					b.insert(0, 1, char(1 + 48));
			}
			else {
				nho = 0;
				b.insert(0, 1, char(v + 48 + 1));
			}
		}
	}
	return b;
}

string QInt::MuHai(int a)
{
	string b = "2";
	if (a == 0)
		b = '1';
	for (int i = 1; i < a; i++)
	{
		b = NhanHai(b);
	}
	return b;
}

string QInt::CongHaiChuoi(string Src1, string Src2)
{
	string Ketqua = "";
	if (Src1.size() < Src2.size())
		Src1.swap(Src2); // chuỗi Src1 có độ dai>= chuỗi Src2
	int SoNho = 0; // mặc định số nhớ ban đầu là 0
	int Size1 = Src1.size(), Size2 = Src2.size();
	int SoTong = 0; // Tổng sau khi chia mỗi cơ số cũng bằng
	for (int i = 0; i < Src2.size(); i++)
	{
		int a1 = Src1[Size1 - 1 - i] - 48;
		int a2 = Src2[Size2 - 1 - i] - 48;
		SoTong = a1 + a2 + SoNho;
		SoNho = SoTong / 10;
		char c = SoTong % 10 + 48;
		Ketqua.insert(0, 1, c);
	}
	for (int i = Size1 - Size2 - 1; i >= 0; i--)
	{
		int a = Src1[i] - 48;
		SoTong = Src1[i] - 48 + SoNho;
		SoNho = SoTong / 10;
		char c = SoTong % 10 + 48;
		Ketqua.insert(0, 1, c);
	}
	// Trường hợp nếu cộng vào số cuối cùng vẫn còn số nhớ bị dư
	if (SoTong > 9)
	{
		char c = SoNho + 48;
		Ketqua.insert(0, 1, c);
	}
	return Ketqua;
}

string QInt::BinToDec(int a[],int n)
{
	string b = "0",c;
	int am = 0;
	if (a[0] == 1)
	{
		a = BuHai(a);
		am = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 1)
		{
			c = MuHai(n - 1 - i);
			b = CongHaiChuoi(c, b);
		}
	}
	if (am==1)
		b.insert(0, 1, '-');
	return b;
}


void QInt::PrintQInt()
{
	int b[128] = { 0 };
	string c = "0";
	for (int i = 0; i < 128; i++)
	{
		if (i < 32)
			b[i] = (qInt[0] >> (31 - i)) & 1;
		else if (i < 64)
			b[i] = (qInt[1] >> (63 - i)) & 1;
		else if (i < 96)
			b[i] = (qInt[2] >> (95 - i)) & 1;
		else if (i < 128)
			b[i] = (qInt[3] >> (127 - i)) & 1;
	}
	c = BinToDec(b,128);
	cout << c << endl;
}

string QInt::BinToHex(int * a, int n)
{
	int b[4], d = 0, e = 0;
	string c, f;
	int i = 0;
	while (1)
	{
		if (i > n - 1)
			break;
		for (int i = 0; i < 4; i++)
			b[i] = 0;
		while (d < 4 && i != n)
		{
			b[3-d] = a[n - 1 - i];
			d++;
			i++;
		}
		d = 0;
		if (i == n - 1)
			f = BinToDec(b, n % 4);
		else
			f = BinToDec(b, 4);
		if (f.length() == 1)
			c.insert(0, f);
		else
		{
			for (int i = 0; i < f.length(); i++)
			{
				e = e * 10 + ((int)f[i] - 48);
			}
			c.insert(0, 1, (char)(e + 48 + 7));
		}
	}
	return c;
}

string QInt::DecToHex(string a)
{
	int*b;
	DecToBin(a, b);
	return BinToHex(b, 128);
}

int * QInt::HexToBin(string a)
{
	int* b = new int[128];
	string c;
	int j;
	for (int i = 0; i < 128; i++)
	{
		b[i] = 0;
	}
	for (int i = a.length()-1; i >= 0; i--)
	{

		if (a[i] > 57)
		{
			c.push_back('1');
			c.push_back(a[i] - 17);
		}
		else
			c.push_back(a[i]);
		j = (a.length() - 1 - i) * 4;
		while (c != "" )
		{
			if (c[c.length() - 1] % 2 == 0)
				b[128 - j - 1] = 0;
			else
				b[128 - j - 1] = 1;
			j++;
			c = ChiaBinary(c);
		}
		c.clear();
	}
	return b;
}

void QInt::ScanQInt(string a, int n)
{
	int* b;
	if (n == 10)
	{
		int tru = 0;
		if (a[0] == '-')
		{
			a.erase(a.begin());
			tru = 1;

		}
		DecToBin(a, b);
		if (tru == 1)
			b = BuHai(b);
		setQInt(b, 128);
	}
	else if (n == 16)
	{
		b = HexToBin(a);
		setQInt(b, 128);
	}
}

void QInt::ScanQInt(int * a)
{
	setQInt(a, 128);
}

const QInt QInt::operator+(QInt & a)
{
	int* phai = getQInt();
	int* trai = a.getQInt();
	int kq[128], tong;
	QInt b;
	int nho = 0;
	for (int i = 127; i >= 0; i--)
	{
		if (nho == 1)
			trai[i]++;
		nho = 0;
		tong = trai[i] + phai[i];
		if (tong == 2)
		{
			nho = 1;
			kq[i] = 0;
		}
		else if (tong == 3)
		{
			nho = 1;
			kq[i] = 1;
		}
		else
			kq[i] = tong;
	}
	b.ScanQInt(kq);
	return b;
}

const QInt QInt::operator-(QInt & a)
{
	int* the = a.getQInt();
	the = a.BuHai(the);
	a.setQInt(the, 128);
	QInt b;
	b.setQInt(this->getQInt(), 128); 
	return  b + a;
}

const QInt QInt::operator*(QInt & a)
{
	int* M = a.getQInt();
	int* Q = this->getQInt();
	int mang[128 * 2 + 1] = { 0 };
	for (int i= 128; i < 128 * 2; i++)
	{
		mang[i] = Q[i - 128];
	}
	int *A;
	A = mang;
	M = &mang[128];
	Q = &mang[256];
	QInt TA, TM;
	TA.setQInt(A, 128);
	TM.setQInt(M, 128);
	for (int k = 128; k > 0; k--)
	{
		if (mang[255] == 1 && mang[256] == 0)
			TA = TA - TM;
		else if (mang[255] == 0 && mang[256] == 1)
			TA = TA + TM;
		for (int i = 256; i >= 1; i--)
		{
			mang[i] = mang[i - 1];
		}
		mang[1] = (mang[0] == 0) ? 0 : 1;

		TA.setQInt(A, 128);
	}
}

bool QInt::operator<(QInt & a)
{
	int *b, *c;
	b = this->getQInt();
	c = a.getQInt();
	if (b[0] > c[0])
		return true;
	if (b[0] < c[0])
		return false;
	for (int i = 1 ; i < 128; i++)
	{
		if (b[i] > c[i])
			return false;
		if (b[i] < c[i])
			return true;
	}
}

bool QInt::operator>(QInt & a)
{
	int *b, *c;
	b = this->getQInt();
	c = a.getQInt();
	if (b[0] > c[0])
		return false;
	if (b[0] < c[0])
		return true;
	for (int i = 1; i < 128; i++)
	{
		if (b[i] > c[i])
			return true;
		if (b[i] < c[i])
			return false;
	}
}

bool QInt::operator==(QInt & a)
{
	int *b, *c;
	b = this->getQInt();
	c = a.getQInt();
	int temp = 1;
	for (int i = 0; i < 128; i++)
	{
		if (b[i] != c[i])
			temp = 0;
	}
	return (temp == 1) ? true : false;
}

bool QInt::operator<=(QInt & a)
{
	return (*this < a || *this == a) ? true : false;
}

bool QInt::operator>=(QInt & a)
{
	return (*this > a || *this == a) ? true : false;
}

/*QInt QInt::operator=(QInt & a)
{
	
}*/


QInt QInt::operator>>(int a)
{
	int *b = this->getQInt();
	for (int i = 127; i >=1; i--)
	{
		 b[i] = b[i - 1];
	}
	b[1] = (b[0] == 0) ? 0 : 1;
	this->setQInt(b, 128);
	return *this;
}




#include"Function.h"

QInt::QInt()
{
	for (int i = 0; i < 4; i++)
	{
		qInt[i] = 0;
	}
}

string QInt::ChiaBinary(string a)
{
	string b;
	int du = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (du == 0)
		{
			if (i != 0)
			{
				b.push_back((char)(((int)a[i] - 48) / 2 + 48));
				du = ((int)a[i] - 48) % 2;
			}
			else {
				if ((((int)a[i] - 48) / 2) == 0)
					du = ((int)a[i] - 48) % 2;
				else
				{
					b.push_back((char)(((int)a[i] - 48) / 2 + 48));
					du = ((int)a[i] - 48) % 2;
				}
			}
		}
		else {
			du = du * 10 + ((int)a[i] - 48);
			b.push_back((char)((du / 2) + 48));
			du = du % 2;
		}
		if (a == "1")
			b = "0";
	}
	return b;
}

void QInt::DecToBin(string a, int* &b, int n)
{
	b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	int i = 0;
	while (a != "0")
	{
		if (a[a.length() - 1] % 2 == 0)
			b[128 - i - 1] = 0;
		else
			b[128 - i - 1] = 1;
		i++;
		a = ChiaBinary(a);
	}
	/*for (int n = 0; n < 128; n++)
	{
		if (b[n] == 1)
		{
			if (n < 32)
				qInt[0] = (1 << (31 - n)) | qInt[0];
			else if (n < 64)
				qInt[1] = (1 << (63 - n)) | qInt[1];
			else if (n < 96)
				qInt[2] = (1 << (95 - n)) | qInt[2];
			else if (n < 128)
				qInt[3] = (1 << (127 - n)) | qInt[3];
		}
	}*/
}

void QInt::ScanQInt()
{
	string a;
	cout << "Nhap so: ";
	cin >> a;
	int* b;
	/*int b[128] = { 0 }, i = 0;
	while (a != "0")
	{
		if (a[a.length() - 1] % 2 == 0)
			b[128 - i - 1] = 0;
		else
			b[128 - i - 1] = 1;
		i++;
		a = ChiaBinary(a);
	}
	for (int j = 0; j < 128; j++)
	{
		cout << b[j] << " ";
	}
	cout << endl;*/
	DecToBin(a, b, 128);
	for (int n = 0; n < 128; n++)
	{
		if (b[n] == 1)
		{
			if (n < 32)
				qInt[0] = (1 << (31 - n)) | qInt[0];
			else if (n < 64)
				qInt[1] = (1 << (63 - n)) | qInt[1];
			else if (n < 96)
				qInt[2] = (1 << (95 - n)) | qInt[2];
			else if (n < 128)
				qInt[3] = (1 << (127 - n)) | qInt[3];
		}
	}
	/*for (int j = 0; j < 4; j++)
	{
		cout << qInt[j] << " ";
	}*/
	delete b;
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

string QInt::CongStr(string a, string b)
{
	int i = 0, nho = 0, tong;
	string c;
	while (1)
	{
		if (int(a.length() - 1 - i) < 0 || int(b.length() - 1 - i) < 0)
		{
			if (nho == 1)
			{
				if (a.length() > b.length())
				{
					c.insert(0, 1, char(a[a.length() - i - 1] + 1));
					for (int j = abs(int(a.length() - b.length())) - 2; j >= 0; j--)
					{
						c.insert(0, 1, a[j]);
					}
				}
				else if (a.length() == b.length())
					c.insert(0, 1, '1');
				else
				{
					c.insert(0, 1, char(b[b.length() - i - 1] + 1));
					for (int j = abs(int(a.length() - b.length())) - 2; j >= 0; j--)
					{
						c.insert(0, 1, b[j]);
					}
				}
			}
			else
			{
				if (a.length() > b.length())
				{
					for (int j = abs(int(a.length() - b.length())) - 1; j >= 0; j--)
					{
						c.insert(0, 1, a[j]);
					}
				}
				else
				{
					for (int j = abs(int(a.length() - b.length())) - 1; j >= 0; j--)
					{
						c.insert(0, 1, b[j]);
					}
				}
			}
			break;
		}
		tong = int(a[a.length() - 1 - i] - 48) + int(b[b.length() - 1 - i] - 48);
		if (nho == 0)
		{
			if (tong >= 10)
			{
				nho = 1;
				tong = tong % 10;
				c.insert(0, 1, char(tong + 48));
			}
			else
				c.insert(0, 1, char(tong + 48));
		}
		else
		{
			if (tong >= 9)// lo bang 9 nho 1 =10
			{
				nho = 1;
				tong = (tong + 1) % 10;
				c.insert(0, 1, char(tong + 48));
			}
			else
			{
				nho = 0;
				c.insert(0, 1, char(tong + 1 + 48));
			}
		}
		i++;
	}
	return c;
}

string QInt::BinToDec(int a[], int n)
{
	string b = "0";
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
		{
			b = CongStr(MuHai(n - 1 - i), b);
		}
	}			
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
	/*for (int i = 0; i < 128; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 128; i++)
	{
		if (b[i] == 1)
		{
			c = CongStr(MuHai(127 - i), c);

		}
	}*/
	c = BinToDec(b, 128);
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
	DecToBin(a, b, 128);
	return BinToHex(b, 128);
}

QInt QInt::operator+(const QInt & a)
{
	
}

#include "DaThuc.h"


DaThuc::DaThuc()
{
	n = 0;
	HeSo = new float[1];
	HeSo[0] = 0;
}

//void DaThuc::Tang()
//{
//
//}

//DaThuc::~DaThuc() 
//{
//	delete[] HeSo;
//}

//void DaThuc::Input() {
//	cout << "Nhap bac da thuc: ";
//	cin >> n;
//	HeSo = new float[n + 1];
//	cout << "Nhap vao cac he so: ";
//	for (int i = n; i >= 0; i--)
//		cin >> HeSo[i];
//}

//void DaThuc::Output() {
//	//cout << "P[x] = ";
//	if (n > 1)
//	{
//		float S = 0;
//		for (int i = n; i >= 0; i--) S += HeSo[i];
//		if (S == 0.0) cout << 0;
//		for (int i = n; i >= 0; i--)
//		{
//			if (i > 1)
//			{
//				if (i != n)
//				{
//					if (HeSo[i] > 0)
//					{
//						if (HeSo[i] != 1) cout << " +" << HeSo[i] << "x^" << i;
//						else cout << " +x^" << i;
//					}
//					else if (HeSo[i] < 0)
//					{
//						if (HeSo[i] != -1) cout << " " << HeSo[i] << "x^" << i;
//						else cout << " -x^" << i;
//					}
//				}
//				else
//				{
//					if (HeSo[i] > 0)
//					{
//						if (HeSo[i] != 1) cout << HeSo[i] << "x^" << i;
//						else cout << "x^" << i;
//					}
//					else if (HeSo[i] < 0)
//					{
//						if (HeSo[i] != -1) cout << HeSo[i] << "x^" << i;
//						else cout << " -x^" << i;
//					}
//				}
//			}
//			else if (i == 1)
//			{
//				if (HeSo[i] > 0)
//				{
//					if (HeSo[i] == 1) cout << " +x";
//					else cout << " +" << HeSo[i] << "x";
//				}
//				else if (HeSo[i] < 0)
//				{
//					if (HeSo[i] == -1) cout << " -x";
//					else cout << " " << HeSo[i] << "x";
//				}
//			}
//			else
//			{
//				if (HeSo[i] != 0)
//					if (HeSo[i] > 0) cout << " +" << HeSo[i];
//					else cout << " " << HeSo[i];
//			}
//		}
//	}
//	else
//	{
//		if (n == 0) {
//			cout << HeSo[0];
//		}
//		else
//		{
//			if (HeSo[1] != 0)
//			{
//				if (HeSo[1] > 0)
//					if (HeSo[1] == 1) cout << "x";
//					else cout << HeSo[1] << "x";
//				if (HeSo[1] < 0)
//					if (HeSo[1] == -1) cout << "-x";
//					else cout << HeSo[1] << "x";
//				if (HeSo[0] > 0) cout << " +" << HeSo[0];
//				if (HeSo[0] < 0) cout << " " << HeSo[0];
//			}
//			else cout << HeSo[0];
//		}
//	}
//	cout << "\n";
//}

DaThuc operator+(const DaThuc dt1, const DaThuc dt2)
{
	DaThuc dt;
	dt.n = max(dt1.n, dt2.n);
	dt.HeSo = new float[dt.n];

	for (int i = dt.n; i >= 0; i--)
	{
		if (i > dt1.n) dt.HeSo[i] = dt2.HeSo[i];
		else if (i > dt2.n) dt.HeSo[i] = dt1.HeSo[i];
		else dt.HeSo[i] = dt1.HeSo[i] + dt2.HeSo[i];
	}
	return dt;
}
DaThuc operator-(const DaThuc dt1, const DaThuc dt2)
{
	DaThuc dt;
	dt.n = max(dt1.n, dt2.n);
	dt.HeSo = new float[dt.n];

	for (int i = dt.n; i >= 0; i--)
	{
		if (i > dt1.n) dt.HeSo[i] = -dt2.HeSo[i];
		else if (i > dt2.n) dt.HeSo[i] = dt1.HeSo[i];
		else dt.HeSo[i] = dt1.HeSo[i] - dt2.HeSo[i];
	}
	return dt;
}
DaThuc operator*(const DaThuc dt1, const DaThuc dt2)
{
	DaThuc dt;
	dt.n = dt1.n + dt2.n;
	dt.HeSo = new float[dt.n + 1];
	for (int i = dt.n; i >= 0; i--) {
		dt.HeSo[i] = 0;
	}

	for (int i = 0; i <= dt1.n; i++)
		for (int j = 0; j <= dt2.n; j++)
			dt.HeSo[i + j] += dt1.HeSo[i] * dt2.HeSo[j];
	return dt;
}

DaThuc operator/(const DaThuc dt1, const DaThuc dt2)
{
	DaThuc dt;
	dt.n = dt1.n - dt2.n;
	if (dt.n >= 0) {
		dt.HeSo = new float[dt.n + 1];
		for (int i = dt.n; i >= 0; i--) {
			dt.HeSo[i] = 0;
		}

		DaThuc du = dt1, sc = dt2;
		for (int i = dt.n; i >= 0; i--) {
			DaThuc kqc, tam;
			kqc.n = i;
			kqc.HeSo = new float[kqc.n + 1];
			for (int i = kqc.n; i >= 0; i--) {
				kqc.HeSo[i] = 0;
			}
			tam.n = i + dt2.n;
			tam.HeSo = new float[tam.n + 1];
			for (int i = tam.n; i >= 0; i--) {
				tam.HeSo[i] = 0;
			}

			kqc.HeSo[i] = du.HeSo[i + sc.n] / sc.HeSo[sc.n];
			kqc.n = i;
			dt.HeSo[i] = kqc.HeSo[i];
			tam.n = i + sc.n;
			tam = (kqc * sc);
			du = (du - tam);
		}
		return dt;
	}
}

istream& operator>>(istream& is, DaThuc& p)
{
	cout << "Nhap bac da thuc: ";
	cin >> p.n;
	p.HeSo = new float[p.n + 1];
	cout << "Nhap vao cac he so: ";
	for (int i = p.n; i >= 0; i--)
		cin >> p.HeSo[i];
	return is;
}

ostream& operator<<(ostream& os, DaThuc p)
{
	if (p.n > 1)
	{
		float S = 0;
		for (int i = p.n; i >= 0; i--) S += p.HeSo[i];
		if (S == 0.0) cout << 0;
		for (int i = p.n; i >= 0; i--)
		{
			if (i > 1)
			{
				if (i != p.n)
				{
					if (p.HeSo[i] > 0)
					{
						if (p.HeSo[i] != 1) cout << " +" << p.HeSo[i] << "x^" << i;
						else cout << " +x^" << i;
					}
					else if (p.HeSo[i] < 0)
					{
						if (p.HeSo[i] != -1) cout << " " << p.HeSo[i] << "x^" << i;
						else cout << " -x^" << i;
					}
				}
				else
				{
					if (p.HeSo[i] > 0)
					{
						if (p.HeSo[i] != 1) cout << p.HeSo[i] << "x^" << i;
						else cout << "x^" << i;
					}
					else if (p.HeSo[i] < 0)
					{
						if (p.HeSo[i] != -1) cout << p.HeSo[i] << "x^" << i;
						else cout << " -x^" << i;
					}
				}
			}
			else if (i == 1)
			{
				if (p.HeSo[i] > 0)
				{
					if (p.HeSo[i] == 1) cout << " +x";
					else cout << " +" << p.HeSo[i] << "x";
				}
				else if (p.HeSo[i] < 0)
				{
					if (p.HeSo[i] == -1) cout << " -x";
					else cout << " " << p.HeSo[i] << "x";
				}
			}
			else
			{
				if (p.HeSo[i] != 0)
					if (p.HeSo[i] > 0) cout << " +" << p.HeSo[i];
					else cout << " " << p.HeSo[i];
			}
		}
	}
	else
	{
		if (p.n == 0) {
			cout << p.HeSo[0];
		}
		else
		{
			if (p.HeSo[1] != 0)
			{
				if (p.HeSo[1] > 0)
					if (p.HeSo[1] == 1) cout << "x";
					else cout << p.HeSo[1] << "x";
				if (p.HeSo[1] < 0)
					if (p.HeSo[1] == -1) cout << "-x";
					else cout << p.HeSo[1] << "x";
				if (p.HeSo[0] > 0) cout << " +" << p.HeSo[0];
				if (p.HeSo[0] < 0) cout << " " << p.HeSo[0];
			}
			else cout << p.HeSo[0];
		}
	}
	cout << "\n";
	return os;
}

DaThuc& DaThuc::operator=(const DaThuc& dt)
{
	if (this != &dt)
	{
		delete[] HeSo;
		n = dt.n;
		HeSo = new float[n + 1];
		for (int i = n; i >= 0; i--)
			HeSo[i] = dt.HeSo[i];
	}
	return *this;
}




float DaThuc::Value(float x)
{
	float Val = 0;
	for (int i = n; i >= 0; i--)
		Val = Val + HeSo[i] * pow(x, i);
	return Val;
}

float& DaThuc::operator[](int i)
{
	return HeSo[i];
}

DaThuc& DaThuc::operator++()
{
	for (int i = n; i >= 0; i--)
		++HeSo[i];
	return *this;
}
DaThuc DaThuc::operator++(int)
{
	DaThuc dt = *this;
	for (int i = n; i >= 0; i--)
		++HeSo[i];
	return dt;
}
DaThuc& DaThuc::operator--()
{
	for (int i = n; i >= 0; i--)
		--HeSo[i];
	return *this;
}
DaThuc DaThuc::operator--(int)
{
	DaThuc dt = *this;
	for (int i = n; i >= 0; i--)
		--HeSo[i];
	return dt;
}
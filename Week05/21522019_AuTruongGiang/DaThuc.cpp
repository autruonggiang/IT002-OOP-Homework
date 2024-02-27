#include "DaThuc.h"

void DaThuc::Input() {

	cout << "Bac cua da thuc: ";
	cin >> this->bac;

	heSo = new int[bac + 1];
	for (int i = 0; i <= bac; ++i) {
		cout << "He so cua bac " << i << " : ";
		cin >> heSo[i];
	}
}

void DaThuc::Output() {

	int num;

	for (int i = this->bac; i >= 0; --i) {

		if (this->heSo[i] != 0) {

			if (this->heSo[i] >= 0) {
				if (i != this->bac)
					cout << " + ";
			}
			else {
				cout << " - ";
			}

			if (this->heSo[i] >= 0) {
				num = this->heSo[i];
			}
			else {
				num = -1 * this->heSo[i];
			}

			if (i == 0) {
				cout << num << endl;
			}
			else {
				if (num != 1) {
					if (i == 1) {
						cout << num << "x";
					}
					else {
						cout << num << "x^" << i;
					}
				}
				else {
					if (i == 1) {
						cout << "x";
					}
					else {
						cout << "x^" << i;
					}
				}
			}
		}
	}
}

int DaThuc::calcDT(int num) {
	int sum = 0;

	for (int i = bac; i >= 0; --i) {
		sum += pow(num, i) * heSo[i];
	}

	return sum;
}

DaThuc sumDT(DaThuc a, DaThuc b) {
	int num = (a.bac > b.getBac()) ? a.bac : b.getBac();

	DaThuc c;

	c.setBac(num);
	c.setHeSo(num + 1);

	for (int i = num; i >= 0; --i) {
		if (i <= a.bac && i <= b.getBac())
			c.getHeSo()[i] = a.heSo[i] + b.getHeSo()[i];
		else if (i > a.bac)
			c.getHeSo()[i] = b.getHeSo()[i];
		else
			c.getHeSo()[i] = a.heSo[i];
	}

	return c;
}

DaThuc subDT(DaThuc a, DaThuc b) {
	int num = (a.bac > b.bac) ? a.bac : b.bac;

	DaThuc c;

	c.setBac(num);
	c.setHeSo(num + 1);

	for (int i = num; i >= 0; --i) {
		if (i <= a.bac && i <= b.bac)
			c.getHeSo()[i] = a.heSo[i] - b.heSo[i];
		else if (i > a.bac)
			c.getHeSo()[i] = -1 * b.heSo[i];
		else
			c.getHeSo()[i] = a.heSo[i];
	}

	return c;
}

DaThuc multiDT(DaThuc a, DaThuc b) {

	DaThuc c;
	c.setBac(a.bac + b.bac);
	c.setHeSo(a.bac + b.bac + 1);
	createEmpty(c);



	for (int i = 0; i <= a.bac; ++i) {

		DaThuc temp;

		temp.setBac(i + b.bac);
		temp.setHeSo(i + b.bac + 1);
		createEmpty(temp);

		for (int j = 0; j <= b.bac; ++j) {
			temp.getHeSo()[i + j] = a.heSo[i] * b.heSo[j];
		}

		c = sumDT(c, temp);
	}

	return c;
}

ostream& operator << (ostream& os, DaThuc& a) {
	a.Output();
	return os;
}

istream& operator >> (istream& is, DaThuc& a) {
	a.Input();
	return is;
}
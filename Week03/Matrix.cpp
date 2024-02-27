#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

using namespace std;

#define MAX 100
#define PI 3.1415926535898

inline bool IsInt (float Num) {
    int test = Num;
    bool check = test == Num;
    
    return check;
}

void InputInt(int &Num, string Text) {
    float test;
    
    do {
        cout << Text;
        cin >> test;
        
        if (!IsInt(test))
            cout << "So phai nguyen !" << endl;
        else if (test < 0)
    cout << "So nguyen phai lon hon 0 !" << endl;
        
    } while (!IsInt(test) || test < 0);
    
    Num = test;
}

typedef class Matrix {
	
   int row, col;
   int Board[MAX][MAX];
    
public:
    
    Matrix () {};
    Matrix (int row, int col): 
        row(row),
        col(col)
    {};
    
    Matrix (const Matrix&);
    
    void Input(bool);
    void Print();
    Matrix Cong (Matrix&);
    Matrix Tru (Matrix&);
    Matrix Nhan (Matrix&);
    
    inline int GetRow() {return this->row;}
    inline int GetCol() {return this->col;}
    
} MT;

MT::Matrix (const Matrix &Old_Matrix) {
    row = Old_Matrix.row;
    col= Old_Matrix.col;
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            Board[i][j] = Old_Matrix.Board[i][j];
        }
    }
}

void MT::Input (bool random = false) {
    InputInt(row, "Nhap so dong: ");
    InputInt(col, "Nhap so cot: ");
    
    if (!random) {
        cout << endl;
        for (int i = 0; i < row; ++i) {
            cout << "Nhap hang so "  << i << ": ";
            for (int j = 0; j < col; ++j) {
                cin >> Board[i][j];
            }
        }
    } else {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                Board[i][j] = rand() % 100;
            }
        }
    }
}

void MT::Print () {
    
    cout << "[Ma tran thu duoc]" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
}

MT MT::Cong (Matrix &b) {
    MT c;
    
    if (row == b.row && col == b.col) {
        
        c.row = row;
        c.col = col;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                c.Board[i][j] = Board[i][j] + b.Board[i][j];
            }
        }
        
    } else {
        cout << "Hang, cot cua A phai khac B !" << endl;
    }
    
    return c;
}

MT MT::Tru (Matrix &b) {
    
    MT c;
    
    if (row == b.row && col == b.col) {
        
        c.row = row;
        c.col = col;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                c.Board[i][j] = Board[i][j] - b.Board[i][j];
            }
        }
        
    } else {
        cout << "Hang, cot cua A phai khac B !" << endl;
    }
    
    return c;
}

MT MT::Nhan (Matrix &b) {
    MT c;
    
    if (col == b.row) {
        c.row = row;
        c.col = b.col;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < b.col; ++j) {
                c.Board[i][j] = 0;
                for (int k = 0; k < col; ++k) {
                    c.Board[i][j]=c.Board[i][j]+(Board[i][k] * b.Board[k][j]);                    
                }
            }
        }
    } else {
        cout << "Cot A va hang B phai bang nhau !" << endl;
    }
    
    return c;
}

void SolveMT() {
   
    bool random = false;
    
    MT a, b;
    
    string select;
    do {
        cout << "Ban co muon ma tran ngau nhien khong ? (Y hoac N)\n";
        cin >> select;

        if ((select == "Y" || select == "y") || (select == "N" || select == "n")) {
            if (select == "Y" || select == "y") {
                random = true;
        	}
            else
                random = false;
        } else {
            cout << "Y or N (Yes hoac No) !" << endl;
            random = false;
        }
    } while ((select != "Y" && select != "y") && (select != "N" && select != "n"));
    
    cout << endl;
    if (!random) {
        cout << "Nhap ma tran A" << endl;
        a.Input();
        cout << endl;
        a.Print();
        
        cout << "\nNhap ma tran B" << endl;
        b.Input();
        cout << endl;
        b.Print();
    } else {
        cout << "Ma tran A" << endl;
        a.Input(random);
        a.Print();
        
        cout << "\nMa tran B" << endl;
        b.Input(random);
        b.Print();
    }
        
    cout << "\nTong hai ma tran: A + B =" << endl;
    a.Cong(b).Print();
    
    cout << "\nHieu hai ma tran: A - B =" << endl;
    a.Tru(b).Print();
    
    cout << "\nTich hai ma tran: A * B =" << endl;
    a.Nhan(b).Print();
}

void swap(float &a, float &b) {
	float temp;

	temp = a;
	a = b;
	b = temp;
}

void sort(float num[], float heso[], int len) {

	bool stop = true;
	for (int i = 0; i < len-1; ++i) {
		if (num[i] < num[i+1]) {
			stop = false;
			swap(num[i], num[i+1]);
			swap(heso[i], heso[i+1]);
		}
	}

	if (!stop)
		sort(num, heso, len);
}

class DATHUC {
    
public:

	float heso[MAX];
	float mu[MAX];
	int len;

	void rutgon(DATHUC &a) {
		sort(a.mu, a.heso, a.len);

		int black[a.len];
		for (int i = 0; i < a.len; ++i) {
			black[i] = 1;
		}

		DATHUC b;
		for (int i = 0; i < a.len; ++i) {
			b.heso[i] = a.heso[i];
			b.mu[i] = a.mu[i];
		}
		b.len = a.len;

		for (int i = 0; i < a.len; ++i) {
			for (int j = 1 + i; j < a.len; ++j) {
				if (b.mu[i] == b.mu[j] && black[j] == 1) {
					black[j] = 0;
					b.heso[i] += b.heso[j];
				}
			}
			if (b.heso[i] == 0) {
				black[i] = 0;
			}
		}


		for (int i = 0; i < a.len; ++i) {
			if (black[i] == 1 && b.heso[i] == 0) {
				black[i] = 0;
			}
		}

		int ptr = 0;
		for (int i = 0; i < a.len; ++i) {
			if (black[i] == 1) {
				a.heso[ptr] = b.heso[i];
				a.mu[ptr] = b.mu[i];
				ptr++;
			}
		}

		a.len = ptr;
	}

	float rank(DATHUC a) {
		rutgon(a);
		return a.mu[0];
	}

    void xuat(DATHUC a) {
        for (int i = 0; i < a.len; ++i) {
            cout << " ";
            if (a.heso[i] != 0) {
                if(a.mu[i] != 0 && a.mu[i] != 1) {
                    if (a.heso[i] < 0)
                        cout << "- " << a.heso[i]*-1 << "*x^" << a.mu[i];
                    else if (a.heso[i] > 0 && i != 0)
                        if (a.heso[i] != 1)
                            cout << "+ " << a.heso[i] << "*x^" << a.mu[i];
                        else
                            cout << "+ x^" << a.mu[i];
                    else
                        cout << a.heso[i] << "*x^" << a.mu[i];
                } else if (a.mu[i] == 1){
                    if (a.heso[i] < 0)
                        cout << "- " << a.heso[i]*-1 << "*x";
                    else if (a.heso[i] > 0 && i != 0)
                        if (a.heso[i] != 1)
                            cout << "+ " << a.heso[i] << "*x";
                        else
                            cout << "+ x";
                    else
                        cout << a.heso[i] << "*x";
                } else {
                    if (a.heso[i] < 0)
                        cout << "- " << a.heso[i]*-1;
                    else if (a.heso[i] > 0)
                        cout << "+ " << a.heso[i];
                }
            }
        }

        cout << endl;
    }

	DATHUC operator + (DATHUC a) {

		DATHUC c;
		c.len = len + a.len;

		for (int i = 0; i < c.len; ++i) {
			if (i < len) {
				c.heso[i] = heso[i];
				c.mu[i] = mu[i];
			} else {
				c.heso[i] = a.heso[i-len];
				c.mu[i] = a.mu[i-len];
			}

		}

		rutgon(c);
		return c;
	}

	DATHUC operator - (DATHUC a) {

		DATHUC c;
		c.len = len + a.len;

		for (int i = 0; i < c.len; ++i) {
			if (i < len) {
				c.heso[i] = heso[i];
				c.mu[i] = mu[i];
			} else {
				c.heso[i] = a.heso[i-len]*-1;
				c.mu[i] = a.mu[i-len];
			}

		}

		rutgon(c);
		return c;
	}

	DATHUC operator * (DATHUC a) {

		DATHUC c;
		c.len = len * a.len;

		int ptrNum = 0;
		for (int i = 0; i < a.len; ++i) {
			for (int j = 0; j < len; ++j) {
				if (a.mu[i] < 1) {
					c.heso[ptrNum] = heso[j] * a.heso[i];
					c.mu[ptrNum] = mu[j];
				} else {
					c.heso[ptrNum] = heso[j] * a.heso[i];
					c.mu[ptrNum] = mu[j] + a.mu[i];
				}

				ptrNum++;
			}
		}

		rutgon(c);
		return c;
	}

	DATHUC operator / (DATHUC a) {

		DATHUC thuong, du, temp;

		thuong.len = 1;
		thuong.heso[0] = 0;
		thuong.mu[0] = 0;

		for (int i = 0; i < len; ++i) {
			du.heso[i] = heso[i];
			du.mu[i] = mu[i];
		}
		du.len = len;

		int ptrThuong = 0;
        float tHeso, tMu;
		while(rank(du) >= rank(a)) {
			tHeso = du.heso[0]/a.heso[0];
			tMu = du.mu[0] - a.mu[0];

			thuong.heso[ptrThuong] = tHeso;
			thuong.mu[ptrThuong] = tMu;
			ptrThuong++;
			thuong.len = ptrThuong;


			temp.heso[0] = tHeso;
			temp.mu[0] = tMu;
			temp.len = 1;

			temp = temp * a;
			du = du - temp;
			rutgon(du);
            
            if (tMu == 0)
                break;
            
		}

		rutgon(thuong);
		return thuong;
	}

	DATHUC operator % (DATHUC a) {

		DATHUC thuong, du, temp;

		for (int i = 0; i < len; ++i) {
			du.heso[i] = heso[i];
			du.mu[i] = mu[i];
		}
		du.len = len;

		int ptrThuong = 0;
		while(rank(du) >= rank(a)) {
			float tHeso, tMu;
			tHeso = du.heso[0]/a.heso[0];
			tMu = du.mu[0] - a.mu[0];

			thuong.heso[ptrThuong] = tHeso;
			thuong.mu[ptrThuong] = tMu;
			ptrThuong++;
			thuong.len = ptrThuong;


			temp.heso[0] = tHeso;
			temp.mu[0] = tMu;
			temp.len = 1;

			temp = temp * a;
			du = du - temp;
			rutgon(du);
            
            if (tMu == 0)
                break;
            
		}
        
		rutgon(du);
		return du;
	}

};

DATHUC copy(DATHUC a) {
	return a;
}

void xuat(DATHUC a) {
    
	if ((a.len <= 1 && a.heso[0] == 0) || a.len == 0) {
		cout << " 0";
	}

	for (int i = 0; i < a.len; ++i) {
		cout << " ";
		if (a.heso[i] != 0) {
			if (a.mu[i] != 0 && a.mu[i] != 1) {
				if (a.heso[i] < 0)
					cout << "- " << a.heso[i]*-1 << "*x^" << a.mu[i];
				else if (a.heso[i] > 0 && i != 0) {
					if (a.heso[i] != 1)
						cout << "+ " << a.heso[i] << "*x^" << a.mu[i];
					else
						cout << "+ x^" << a.mu[i];
				} else {
					if (a.heso[i] != 1)
						cout << a.heso[i] << "*x^" << a.mu[i];
					else
						cout << "x^" << a.mu[i];
				}
			} else if (a.mu[i] == 1) {
				if (a.heso[i] < 0)
					cout << "- " << a.heso[i]*-1 << "*x";
				else if (a.heso[i] > 0 && i != 0) {
					if (a.heso[i] != 1)
						cout << "+ " << a.heso[i] << "*x";
					else
						cout << "+ x";
				} else
					cout << a.heso[i] << "*x";
			} else {
				if (a.heso[i] < 0)
					cout << "- " << a.heso[i]*-1;
				else if (a.heso[i] > 0 && i != 0)
					cout << "+ " << a.heso[i];
				else
					cout << a.heso[i];
			}
		}
	}
    
	cout << endl;
}

void clean(string &a) {

	string temp;
	for (int i = 0; i <= a.length()-3; ++i) {
		temp = "";
		temp = temp + a[i] + a[i+1] + a[i+2];
		if (temp == "*x+" || temp == "*x-") {
			a.insert(i+2, "^1");
		}
	}
}

void rutgon(DATHUC &a) {
	sort(a.mu, a.heso, a.len);

	int black[a.len];
	for (int i = 0; i < a.len; ++i) {
		black[i] = 1;
	}

	DATHUC b;
	for (int i = 0; i < a.len; ++i) {
		b.heso[i] = a.heso[i];
		b.mu[i] = a.mu[i];
	}
	b.len = a.len;

	for (int i = 0; i < a.len; ++i) {
		for (int j = 1 + i; j < a.len; ++j) {
			if (b.mu[i] == b.mu[j] && black[j] == 1) {
				black[j] = 0;
				b.heso[i] += b.heso[j];
			}
		}
		if (b.heso[i] == 0) {
			black[i] = 0;
		}
	}

	int ptr = 0;
	for (int i = 0; i < a.len; ++i) {
		if (black[i] == 1) {
			a.heso[ptr] = b.heso[i];
			a.mu[ptr] = b.mu[i];
			ptr++;
		}
	}

	a.len = ptr;
}

void nhap(DATHUC &a) {
	cout << "Nhap da thuc (VD: 2.3*x^5+6*x+14): ";
	string bien;
	cin >> bien;

	if (bien[0] != '-')
		bien = "+" + bien;

	bien = bien + "+";
	clean(bien);

	int state = 0; // 0: nothing | 1: heso | 2: mu
	string temp = "";
	int ptrNum= 0, ptrMu = 0;

	//cout << bien << endl;

	for (int i = 0; i < bien.length(); ++i) {
		if (bien[i] == '+' || bien[i] == '-') {
			if (temp != "+" && temp != "-" && temp != "") {
				if (state == 2) {
					a.mu[ptrMu] = stof(temp);
					temp = "";
					ptrMu++;
				} else if (state == 1) {
					a.heso[ptrNum] = stof(temp);
					ptrNum++;
					a.mu[ptrMu] = 0;
					ptrMu++;
					temp = "";
				}
			}
			state = 1;
            temp += bien[i];
		} else if (bien[i] == '^')
			state = 2;
		else if (bien[i] == '*') {
			state = 0;
			a.heso[ptrNum] = stof(temp);
			temp = "";
			ptrNum++;
			if (i == bien.length() - 1) {
				a.mu[ptrMu] = 0;
			}

		} else if (state == 1 || state == 2) {
			temp += bien[i];
		}
	}

	a.len = max(ptrNum, ptrMu);

	rutgon(a);

	// for (int i = 0; i < a.len; ++i) {
		// cout << a.heso[i] << " " << a.mu[i] << endl;
	// }
}

DATHUC daoham(DATHUC a) {

	DATHUC b;

	for (int i = 0; i < a.len; ++i) {
		if (a.mu[i] != 0) {
			b.heso[i] = a.heso[i]*a.mu[i];
			b.mu[i] = a.mu[i] - 1;
		} else {
			b.heso[i] = 0;
			b.mu[i] = 0;
		}
	}
	b.len = a.len;

	rutgon(b);
	return b;
}

DATHUC daoham(DATHUC a, int k) {

	DATHUC b = copy(a);
	for (int i = 0; i < k; ++i) {
		b = daoham(b);
		rutgon(b);
	}

	rutgon(b);
	return b;
}

float tinhf(DATHUC a, float x) {

	float f = 0;
	for (int i = 0; i < a.len; ++i) {
		f += a.heso[i]*pow(x, a.mu[i]);
	}

	return f;
}

int PT2(float a, float b, float c, float nghiem[]){
    float delta = b*b - 4*a*c;

	float	&x1 = nghiem[0],
			&x2 = nghiem[1];

    if(delta<0){
        x1=x2=0.0;
        return 0;
    }
    else if(delta==0){
        x1 = x2 = -b/(2*a);
        return 1;
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta) / (2*a);
        x2 = (-b - delta) / (2*a);
        return 2;
    }
}

int PT3(float a, float b, float c, float d, float nghiem[]) {
	float dt,k;

	float 	&x1 = nghiem[0],
			&x2 = nghiem[1],
			&x3 = nghiem[2];

	if (a==0) {
		cout << "Phuong trinh vo nghiem !" << endl;
		x1 = x2 = x3 = 0;
		return 0;
	}

	dt = pow(b,2)-3*a*c;
	k = (9*a*b*c-2*pow(b,3)-27*pow(a,2)*d)/(2*sqrt(pow(fabs(dt),3)));

	if (dt>0) {
		if(fabs(k)<=1) {
			x1 = (2*sqrt(dt)*cos(acos(k)/3)-b)/(3*a);
			x2 = (2*sqrt(dt)*cos(acos(k)/3-(2*PI/3))-b)/(3*a);
			x3 = (2*sqrt(dt)*cos(acos(k)/3+(2*PI/3))-b)/(3*a);
			return 3;
		}
		if(fabs(k)>1) {
			x1 = ((sqrt(dt)*fabs(k))/(3*a*k))*(pow((fabs(k)+sqrt(pow(k,2)-1)),1.0/3)+pow((fabs(k)-sqrt(pow(k,2)-1)),1.0/3))-(b/(3*a));
			x2 = 0;
			x3 = 0;
			return 1;
		}
	} else if (dt==0) {
		x1 = (-b-pow(-(pow(b,3)-27*a*a*d),1.0/3))/(3*a);
		x2 = 0;
		x3 = 0;
		return 1;
	} else {
		x1 = (sqrt(fabs(dt))/(3*a))*(pow((k+sqrt(k*k+1)),1.0/3)-pow(-(k-sqrt(k*k+1)),1.0/3))-(b/(3*a));
		x2 = 0;
		x3 = 0;
		return 1;
	}
}

int PT4(float a, float b, float c, float d, float nghiem[]) {
	float a3 = -b;
	float b3 =  a*c -4.*d;
	float c3 = -a*a*d - c*c + 4.*b*d;

	float x3[3];
	int iZeroes = PT3(1, a3, b3, c3, x3);

	float q1, q2, p1, p2, D, sqD, y;
	float eps = 1e-12;

	y = x3[0];
	if (iZeroes != 1) {
		if(fabs(x3[1]) > fabs(y)) y = x3[1];
		if(fabs(x3[2]) > fabs(y)) y = x3[2];
	}

	D = y*y - 4*d;
	if (fabs(D) < eps) {
		q1 = q2 = y * 0.5;

		D = a*a - 4*(b-y);
		if(fabs(D) < eps)
			p1 = p2 = a * 0.5;

		else
		{
			sqD = sqrt(D);
			p1 = (a + sqD) * 0.5;
			p2 = (a - sqD) * 0.5;
		}
	} else {
		sqD = sqrt(D);
		q1 = (y + sqD) * 0.5;
		q2 = (y - sqD) * 0.5;

		p1 = (a*q1-c)/(q1-q2);
		p2 = (c-a*q2)/(q1-q2);
	}

	float temp;
	int num = 0;
	D = p1*p1 - 4*q1;
	if (D < 0.0) {
		temp = sqrt(-D) * 0.5;
		if (temp == 0) {
			nghiem[num] = -p1 * 0.5;
			nghiem[num+1] = -1*nghiem[num+1];
			num += 2;
		}
	} else {
		sqD = sqrt(D);
		nghiem[num] = (-p1 + sqD) * 0.5;
		nghiem[num+1] = (-p1 - sqD) * 0.5;
		num += 2;
	}

	D = p2*p2 - 4*q2;
	if (D < 0.0) {
		temp = sqrt(-D) * 0.5;
		if (temp == 0) {
			nghiem[num] = -p2 * 0.5;
			nghiem[num+1] = -1*nghiem[num];
			num += 2;
		}
	} else {
		sqD = sqrt(D);
		nghiem[num] = (-p2 + sqD) * 0.5;
		nghiem[num+1] = (-p2 - sqD) * 0.5;
		num += 2;
	}

    return num;
}

void inHeso(float heso[], int start, DATHUC f) {

	int ptr = 0, ptrHeso = 0, mu;
	while (mu > 0) {
		mu = ptrHeso + start;


		if (f.mu[ptr] == mu) {
			heso[ptrHeso] = f.heso[ptr];
			ptr++;
		} else {
			heso[ptrHeso] = 0;
		}

		ptrHeso++;
		start -= 2;
	}
}

void check(DATHUC f, float a, float b) {

	float nghiem[MAX];
	float heso[MAX];
	int ptrNghiem = 0;

	rutgon(f);
	if (f.mu[0] == 1) {
		if (f.len > 1) {
			if(f.heso[0] == 0) {
				if (f.heso[1] == 0) {
					cout << "Phuong trinh vo so nghiem !" << endl;
				} else {
					cout << "Phuong trinh vo nghiem !" << endl;
				}
			} else {
				nghiem[ptrNghiem] = -f.heso[1]/f.heso[0];
				ptrNghiem++;
			}
		} else {
			nghiem[ptrNghiem] = 0;
			ptrNghiem++;
		}
	} else if (f.mu[0] == 2) {
		inHeso(heso, 2, f);

		ptrNghiem = PT2(heso[0], heso[1], heso[2], nghiem);
		if (ptrNghiem == 0)
			cout << "Phuong trinh vo nghiem !";

	} else if (f.mu[0] == 3) {

		inHeso(heso, 3, f);

		ptrNghiem = PT3(heso[0], heso[1], heso[2], heso[3], nghiem);
		if (ptrNghiem == 0)
			cout << "Phuong trinh vo nghiem !";
	} else if (f.mu[0] == 4 && f.heso[0] == 1) {
		inHeso(heso, 4, f);

		ptrNghiem = PT4(heso[1], heso[2], heso[3], heso[4], nghiem);
		if (ptrNghiem == 0)
			cout << "Phuong trinh vo nghiem !";
	} else {
		cout << "Chua co phuong phap giai cho PT bac 4 co he so khac 1 va bac cao hon 4.";
	}
	
	bool state = true;
	if (f.mu[0] >= 1) {
		for (int i = 0; i < ptrNghiem; ++i) {
			if (a <= nghiem[i] && nghiem[i] <= b ) {
				if (state) {
					cout << "So nghiem f(x) thoa man khoang (" << a << ", " << b << " la: ";
					cout << "[" << nghiem[i];
					state = false;
				} else {
					cout << ", " << nghiem[i];
				}
			}
		}
		if (!state)
			cout << "]" << endl;
	} else {
		cout << "\nKhong ton tai !" << endl;
	}
}

void SolveDT() {
    
    DATHUC a, b;
	nhap(a);
	nhap(b);
    
	rutgon(a);
	rutgon(b);

	cout << "____________________________" << endl;

	cout << "f(x) =";
	xuat(a);
	cout << "g(x) =";
	xuat(b);
	cout << endl;

	cout << "f(x) + g(x) =";
	xuat(a+b);
	cout << "f(x) - g(x) =";
	xuat(a-b);
	cout << "f(x) * g(x) =";
	xuat(a*b);
	cout << "f(x) / g(x) =";
	xuat(a/b);
	cout << "         Du  =";
	xuat(a%b);
    
	cout << "\nDao ham bac 1 cua f(x):";
	xuat(daoham(a));
    
	cout << "\nSo bac muon dao ham: ";
	int k;
	cin >> k;
	cout << "Dao ham bac " << k << " cua f(x):";
	xuat(daoham(a, k));
	int x;
	cout << "\nGia tri x: ";
	cin >> x;
	cout << "f(" << x << "): " << tinhf(a, x) << endl;

	int y, z;
	cout << "\nNhap khoang (a, b): ";
	cin >> y >> z;
	check(a, y, z); 
}

int main() {
    
    srand(time(NULL));
    
    cout << "_______________________________" << endl;
    SolveMT();
    
    cout << "\n_______________________________" << endl;
    SolveDT();
	
	return 0;
}

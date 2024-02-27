
#include <iostream>
#include "OfficeList.h"
#include "ProductList.h"

using namespace std;

int main()
{
    ProductList arrProduct;
    OfficeList arrOffice;

    arrProduct.Input();
    arrOffice.Input();

    cout << "Producion employee" << endl;
    arrProduct.Output();

    cout << "Office employee" << endl;
    arrOffice.Output();

    int numEmp;
    numEmp = arrProduct.getSize() + arrOffice.getSize();
    cout << "Nhap so luong nhan vien: " << numEmp << endl;

    cout << "\nNhan vien san xuat co muc luong cao nhat" << endl;
    arrProduct.getMaxSalary()->Output();
    cout << "\nNhan vien van phong co muc luong cao nhat" << endl;
    arrOffice.getMaxSalary()->Output();

    cout << "\nNhan vien san xuat co ho Le" << endl;
    for (int i = 0; i < arrProduct.getSize(); ++i) {
        if (arrProduct.getList()[i].getFName() == "Le") {
            arrProduct.getList()[i].Output();
            cout << endl;
        }
    }

    cout << "\nNhan vien van phong co ho Le" << endl;
    for (int i = 0; i < arrOffice.getSize(); ++i) {
        if (arrOffice.getList()[i].getFName() == "Le") {
            arrOffice.getList()[i].Output();
            cout << endl;
        }
    }

    cout << endl;
    cout << "Tuoi trung binh cua nhan vien san xuat: " << arrProduct.getArgAge() << endl;
    cout << "Tuoi trung binh cua nhan vien van phong: " << arrOffice.getArgAge() << endl;

    float argAge = (arrProduct.getTotalAge() + arrOffice.getTotalAge()) / (arrProduct.getSize() + arrOffice.getSize());
    cout << "Tuoi trung binh cua nhan vien ca cong ty: " << argAge << endl;

    Employee* temp;
    temp = (arrProduct.getMaxAge()->getAge() > arrOffice.getMaxAge()->getAge()) ? arrProduct.getMaxAge() : arrOffice.getMaxAge();

    cout << "\nNhan vien lon tuoi nhat cong ty" << endl;
    temp->Output();

    int total = 0;

    cout << "\nTong luong cua nhan vien san xuat: " << arrProduct.getTotalSalary() << endl;
    cout << "Tong luong cua nhan vien van phong: " << arrOffice.getTotalSalary() << endl;

    total = arrProduct.getTotalSalary() + arrOffice.getTotalSalary();
    cout << "Tong luong cua nhan vien ca cong ty: " << total << endl;

}

// BaiKiemTra01_Dao_Le_Anh.cpp : This file contains the 'main' function. Program execution begins and ends there.
// day la mot du an nho nho cua em
// do la nhung thao tac debug cua em, em cam on co da xem a
#include <iostream>
using namespace std;
int main()
{
	// tao va gan gia tri cho mang
	const int MAX = 20;
	int n = 0;
	int sumeven = 0;
	int count = 0;
	int max = 0;
	int min = 0;
redo:
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	if (n > MAX || n <= 0) {
		cout << "So phan tu khong hop le. Vui long nhap lai!" << endl;
		goto redo;
	}
	int a[MAX];
	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i + 1 << "] = ";
		cin >> a[i];
	}
	//hien thi vi tri cua so lon nhat va nho nhat trong mang

	min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			cout << "So lon nhat trong mang: " << max << endl;
			cout << "Vi tri cua so lon nhat trong mang: " << i + 1 << endl;
		}
		if (a[i] == min) {
			cout << "So nho nhat trong mang: " << min << endl;
			cout << "Vi tri cua so nho nhat trong mang: " << i + 1 << endl;
		}
	}
	// sap xep mang theo thu tu giam dan

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "Mang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	// tinh tong cac so chan trong mang

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			sumeven += a[i];
		}
	}
	cout << "Tong cac so chan trong mang: " << sumeven << endl;

	// hien thi 3 gia tri cao nhat trong mang

	cout << "Top 3 thong tin gia tri cao nhat trong mang: ";
	for (int i = 0; i < 3 && i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	// dem so lan xuat hien cua so 5 trong mang

	for (int i = 0; i < n; i++) {
		if (a[i] % 10 == 5) {
			count++;
		}
		if (a[i] == 55) {
			count++;
		}
	}
	cout << "So lan xuat hien 5 trong mang: " << count << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

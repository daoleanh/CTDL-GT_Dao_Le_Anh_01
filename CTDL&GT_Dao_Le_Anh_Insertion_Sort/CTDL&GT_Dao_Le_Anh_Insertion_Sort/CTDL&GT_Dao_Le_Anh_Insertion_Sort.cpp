// CTDL&GT_Dao_Le_Anh_Insertion_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void insertionsort(int arr[], int n) {
    for (int i =1;i<n;i++){
		// lay phan tu can chen
        int temp = arr[i];
        int j = i ;
		//dich chuyen phan tu ve dung vi tri
        while (j >= 0 && arr[j-1] > temp) {
            arr[j ] = arr[j-1];
            j--;
        }
		arr[j] = temp;
		// in mang sau moi lan lap
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
	}
}

















int main()
{
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
    int* p = new int[n];
	cout << "Nhap cac phan tu: " << endl;
    for (int i = 0; i < n; i++) {
		cout << "p[" << i << "] = ";
        cin >> p[i];
    }
    insertionsort(p, n);
	delete[] p;
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

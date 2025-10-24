// CTDL&GT_Dao_Le_Anh_SelectionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void selectionsort(int arr[],int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        for (int i = 0; i <n; i++){
            cout << arr[i] << "\t";
		}
		cout << endl;
	}
}

int main()
{
    int n;
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	int* p = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "p[" << i + 1 << "] =  ";
        cin >> p[i];
	}
	selectionsort(p, n);
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

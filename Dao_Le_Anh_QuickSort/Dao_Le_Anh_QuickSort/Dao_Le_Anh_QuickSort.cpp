// Dao_Le_Anh_QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
/// <summary>
/// do phuc tap thuat toan cua quicksort
/// worst case (pivot o phan tu lon nhat hoac nho nhat): T(n) = O(n^2) (do luon phai chay n phan tu moi lan lap)
/// best case (chia ra 2 mang deu): T(n) = O(n*logn)
/// decent case (chia ra 2 mang khong qua lech): T(n) = O(n*logn)
/// </summary>
/// <param name="arr"></param>
/// <param name="first"></param>
/// <param name="last"></param>
void partitionfunc(int arr[], int first, int last) {
    if (first >= last) return;

    int pivot = arr[first];
    int i = first + 1, j = last;

    cout << "pivot = " << pivot << ", first = " << first << ", last = " << last << endl;

    while (i <= j) {
        while (arr[i] <= pivot && i <= j) i++;
        while (arr[j] > pivot && i <= j) j--;
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        
        cout << "Trang thai hien tai (pivot = " << pivot << "): ";
        for (int k = first; k < last + 1; k++) cout << arr[k] << "\t";
        cout << "  (i=" << i << ", j=" << j << ")" << endl;
    }

    swap(arr[first], arr[j]);
    cout << "Sau khi dua pivot ve dung vi tri: ";
    for (int k = 0; k < last + 1; k++) cout << arr[k] << "\t";
    cout << "  (pivot o vi tri " << j << ")\n" << endl;

    
    partitionfunc(arr, first, j - 1);
    partitionfunc(arr, j + 1, last);
}

void quicksort(int arr[], int n) {
    partitionfunc(arr, 0, n - 1);
}





int main()
{
    int n = 0;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int* test = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "nhap phan tu thu " << i + 1 << ":";
        cin >> test[i];
    }
    quicksort(test, n);
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

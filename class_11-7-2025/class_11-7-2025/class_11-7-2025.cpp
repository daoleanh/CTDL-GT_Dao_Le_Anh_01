// class_11-7-2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T>
class stack {
    T* data;
    int capacity;
    int top{ -1 };
public:
    stack(int size = 100)
    : capacity(size)
    , data(new T[size]) {}
    ~stack() { delete[] data;}
public:
    void push(const T& value) {
        data[++top] = value;
    }
    T pop() { return data[top--]; }
    T& peek() const { return data[top]; }
    bool IsEmpty() const { return top < 0; }
    bool IsFull() const { return count() == capacity; }
    int count() const { return top + 1; }
};



/*
int indexof(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i+1;
        }
    }
}
int indexofx(int a[], int n, int x) {
    int f =0, l =n-1;
    while (f<=l) {
        int i = 0;
        while (i > 0) {
            int f = 0;
            int l = n - 1;
            int m = (f+l) / 2;
            if (a[m] < a[i]) {
                m++;
                f = m;
            }
            if (a[m] > a[i]) {
                m--;
                l = m;
            }
        }
        if (f == l && a[i] != x) return -1;

    }
}
int lastindexof(int a[], int n, int x) {
    for (int i = n-1; i >=0; i--) {
        if (a[i] == x) {
            return i+1;
        }
    }
}
int count(int a[], int n, int x) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x ) time++;
    }
    return time;
}

int search(int a[], int n, int x) {
    int first = 0, last = n - 1;
    while (first <= last) {
        int m = (first + last) / 2;
        int c = a[m] - x;
        if (c == 0) return m;
        if (c < 0) first = m + 1;
        else last = m - 1;
    } return -1;
}*/







int main()
{
    int x = 25;
    cout << x << "(10) = ";
    stack <int> s(8 * sizeof(int));
    do {
        s.push(x % 2);
        x /= 2;
    } while (x);
    while (!s.IsEmpty()) cout << s.pop();
    cout << "(2)\n";
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

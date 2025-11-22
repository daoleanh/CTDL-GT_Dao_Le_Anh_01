// class_21_11_2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;
struct SinhVien {
    string hoTen;
    string MSSV;
    int namsinh;
    double gpa;
};
struct node {
    SinhVien info;
    node* next;
};
struct List {
    node* firstnode;
};
int ds_dai(List* ds) {
    node* p = ds->firstnode;
    int a = 0;
    while (p != nullptr) {
        a++;
        p = p->next;
    }
    return a;
}
void list_init(List* ds) {
    ds->firstnode = nullptr;
}
void nhapSinhVien(SinhVien& sv) {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);

    cout << "Nhap MSSV: ";
    getline(cin, sv.MSSV);

    cout << "Nhap nam sinh: ";
    cin >> sv.namsinh;
    while (sv.namsinh <= 0 || cin.fail() ) {
        cout << "Thong tin khong hop le! Vui long nhap lai nam sinh: ";
        cin >> sv.namsinh;
    }

    cout << "Nhap GPA: ";
    cin >> sv.gpa;
    while (sv.gpa <= 0 || cin.fail() || sv.gpa >4) {
        cout << "Thong tin khong hop le! Vui long nhap lai GPA: ";
        cin >> sv.gpa;
    }
}
void inthongtinlist(List* ds) {
    node* node = ds->firstnode;
    int a = ds_dai(ds);
    cout << endl << "Do dai cua danh sach: \t" << a;
    if (ds->firstnode == 0) cout << endl << "Danh sach rong \r\n";
    else {
        while (node != nullptr) {
            cout << endl << "Dia chi cua node " << a << "\t" << &node->info;
            cout << endl << "node->next: \t\t" << node->next << endl;
            node = node->next;
            a--;
        }
        cout << endl;
    }
}
void add_first(List* ds, SinhVien sv) {
    node* p = new node;
    p->info = sv;
    p->next = ds->firstnode;
    ds->firstnode = p;
}
void add_last(List* ds, SinhVien sv) {
    node* p = new node;
    p->info = sv;
    p->next = nullptr;

    if (ds->firstnode == nullptr) {
        ds->firstnode = p;
        return;
    }

    node* q = ds->firstnode;
    while (q->next != nullptr) {
        q = q->next;
    }
    q->next = p;
}
int count_svtren32(List* ds) {
    int count = 0;
    node* p = ds->firstnode;
    while (p != nullptr) {
        if (p->info.gpa > 3.2)
            count++;
        p = p->next;
    }
    return count;
}
void sapxeptangdan(List* ds) {
    for (node* i = ds->firstnode; i != nullptr; i = i->next) {
        for (node* j = i->next; j != nullptr; j = j->next) {
            if (i->info.gpa > j->info.gpa) {
                double temp = 0;
                temp = i->info.gpa;
                i->info.gpa = j->info.gpa;
                j->info.gpa = temp;
            }
        }
    }
}
void intieude() {
    cout << left << setw(10) << "Ho Ten"
        << setw(20) << "Nam sinh""MSSV"
        << setw(15) << "Nam sinh"
        << setw(15) << "gpa"
        << endl;
}
void inbangthongtinlist(List* ds) {
    intieude();
    for (node* i = ds->firstnode; i != nullptr; i = i->next) {
        cout << left << setw(10) << i->info.hoTen
            << setw(20) << i->info.MSSV
            << setw(15) << i->info.namsinh
            << setw(15) << i->info.gpa
            << endl;
    }
}








int main()
{
    //nhap so luong sinh vien
    int n = 0;
    while (n <= 0) {
        cout << "Nhap so luong sinh vien muon nhap: ";
        cin >> n;
    }
    //nhap danh sach sinh vien
    List ds;
    list_init(& ds);
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien " << i + 1 << " :" << endl;
        nhapSinhVien(sv);
        add_first(&ds, sv);
    }
    cout << "Danh sach da nhap la: " << endl;
    inbangthongtinlist(&ds);
    //chon tac dung can lam
    int a = 0;
    while ( a != 4 ) {
        cout << "1. In ra chieu dai danh sach sinh vien. " << endl;
        cout << "2. In ra so luong sinh vien co gpa > 3.2." << endl;
        cout << "3. Sap xep danh sach sinh vien theo thu tu tang dan cua diem gpa, sau do them vao danh sach 1 sinh vien co gpa 2.4 va bo sung vao danh sach. " << endl;
        cout << "4. Thoat." << endl;
        cout << "Chon chuc nang can thuc hien (1-4): ";
        cin >> a;
        while (a < 1 || a > 4 || cin.fail()) {
            cout << "Lua chon khong hop le. Vui long nhap lai (1-6): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> a;
        }
        cout << "Ban da chon option " << a << endl;
        switch (a) 
        {
        case 1: {
            cout << "Danh sach dai " << ds_dai(&ds) << endl;
            break;
            }
        case 2: {
            cout << "So sinh vien co gpa > 3.2 la: " << count_svtren32(&ds) <<endl;
            break;
            }
        case 3: {
            sapxeptangdan(&ds);
            inbangthongtinlist(&ds);
            cout << " Sau khi them 1 sinh vien vao danh sach: " << endl;
            SinhVien a;
            a.gpa = 2.5;
            a.hoTen = 'A';
            a.MSSV = "202413222";
            a.namsinh = 2006;
            add_first(&ds, a);
            sapxeptangdan(&ds);
            inbangthongtinlist(&ds);
            break;
            }
        case 4: cout << "Thoat " << endl; break;
        }
    }

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

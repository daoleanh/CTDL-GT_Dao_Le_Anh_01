// Tree_ARRAY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define MAX 100
#define Nil -1
typedef int Node;
typedef int DataType;
struct Tree {
    DataType Data[MAX];
    int level;
	int Maxnode;
};
void initTree(Tree& T) { 
    T.level = 0; 
    T.Maxnode = 0;
} 

int emptyTree(Tree T) {
    return T.Maxnode == 0;
}
Node Root(Tree T) {
    if (!emptyTree(T))
        return 0;
    else
        return Nil;
}
Node leftChild(Tree T, Node p) {
	return 2 * (p + 1) - 1;
}
Node rightChild(Tree T, Node p) {
    return 2 * (p + 1);
}
void updateMaxnode(Tree& T, int idx) {
    if (idx < 0 || idx >= MAX) {
        cout << "idx vuot ngoai mang!\n";
        return;
    }

   
    if (T.level <= 0) T.level = 1;
    while (idx > ((1 << T.level) - 2) && ((1 << T.level) - 1) < MAX) {
        T.level++;
    }

    T.Maxnode = (1 << T.level) - 1;
    if (T.Maxnode > MAX) T.Maxnode = MAX;
}

void nhapGiatriNode(Tree& T, int idx) {
    if (idx < 0 || idx >= MAX) {
        cout << "idx vuot ngoai mang!\n";
        return;
    }

    if (emptyTree(T)) {
        
        T.level = 1;
        updateMaxnode(T, 0);                
        cout << "Cay rong! Khoi tao cay moi!\nNhap gia tri nut goc (idx=0): ";
        cin >> T.Data[0];
        return;
    }

    
    updateMaxnode(T, idx);


    if (idx >= T.Maxnode) {
        cout << "Khong the mo rong cay de chua idx nay!\n";
        return;
    }

    cout << "Nhap gia tri nut thu idx=" << idx << ": ";
    cin >> T.Data[idx];
}

void addLeftChild(Tree& T, Node p, DataType v) {
    if (emptyTree(T)) {
        cout << "Cay rong! Hay tao nut goc truoc.\n";
        return;
    }
    if (p < 0 || p >= T.Maxnode) {
        cout << "Vi tri nut cha khong hop le!\n";
        return;
    }

    Node lc = 2 * p + 1;           // index con trai (0-based)
    if (lc < 0 || lc >= MAX) {
        cout << "Khong the them nut con trai (vuot MAX).\n";
        return;
    }

    updateMaxnode(T, lc);          // mo rong cay neu can
    if (lc >= T.Maxnode) {         // truong hop bi chan boi MAX
        cout << "Khong the them nut con trai!\n";
        return;
    }

    T.Data[lc] = v;
}

void addRightChild(Tree& T, Node p, DataType v) {
    if (emptyTree(T)) {
        cout << "Cay rong! Hay tao nut goc truoc.\n";
        return;
    }
    if (p < 0 || p >= T.Maxnode) {
        cout << "Vi tri nut cha khong hop le!\n";
        return;
    }

    Node rc = 2 * p + 2;           // index con phai (0-based)
    if (rc < 0 || rc >= MAX) {
        cout << "Khong the them nut con phai (vuot MAX).\n";
        return;
    }

    updateMaxnode(T, rc);
    if (rc >= T.Maxnode) {
        cout << "Khong the them nut con phai!\n";
        return;
    }

    T.Data[rc] = v;
}

void preOrder(Tree T, Node p) { // NLR
    if (p == Nil || p >= T.Maxnode) return;
    cout << T.Data[p] << " ";
    preOrder(T, 2 * p + 1);
    preOrder(T, 2 * p + 2);
}

void inOrder(Tree T, Node p) {  // LNR
    if (p == Nil || p >= T.Maxnode) return;
    inOrder(T, 2 * p + 1);
    cout << T.Data[p] << " ";
    inOrder(T, 2 * p + 2);
}

void postOrder(Tree T, Node p) { // LRN
    if (p == Nil || p >= T.Maxnode) return;
    postOrder(T, 2 * p + 1);
    postOrder(T, 2 * p + 2);
    cout << T.Data[p] << " ";
}

















void printLabel(Node p) {
    if (p < 0) { cout << "Nil"; return; }
    if (p == 0) { cout << "T"; return; }

    int steps[64];
    int k = 0;

    while (p > 0) {
		if (p % 2 == 1) steps[k++] = 1;// con trai  
		else            steps[k++] = 2;// con phai  
		p = (p - 1) / 2;               // ve nut cha
    }

    cout << "T";
    for (int i = k - 1; i >= 0; --i) {
        cout << "." << steps[i];
    }
}








int main() {
    Tree cay;
    initTree(cay);

    cout << "Nhap muc cho cay (vd: muc = 3 => 7 nut): ";
    cin >> cay.level;
    cay.Maxnode = (1 << cay.level) - 1;
    if (cay.Maxnode > MAX) cay.Maxnode = MAX;

    cout << "Nhap gia tri cho " << cay.Maxnode << " nut:\n";
    for (int i = 0; i < cay.Maxnode; i++) {
        cout << "Nhap nut ";
        printLabel(i);
        cout << ": ";
        cin >> cay.Data[i];
    }

    cout << "Cay vua nhap co " << cay.Maxnode << " nut.\n";
    for (int i = 0; i < cay.Maxnode; i++) {
        cout << "Nut ";
        printLabel(i);
        cout << " co gia tri la: " << cay.Data[i] << "\n";
    }
    int n = 0;
    do {
        cout << "Chon kieu duyet cay (1: NLR, 2: LNR, 3: LRN), nhan 0 de thoat: ";
        cin >> n;
        switch (n)
        {
        default:{
            cout << "Lua chon khong hop le! Hay nhap 0-3.\n";
            break;
        }
        case 0: {
            break;
        }
        case 1: {
            cout << "Duyet tien tu (NLR): ";
            preOrder(cay, Root(cay));
            cout << "\n";
            break;
        }
        case 2: {
            cout << "Duyet trung tu (LNR): ";
            inOrder(cay, Root(cay));
            cout << "\n";
            break;
        }
        case 3: {
            cout << "Duyet hau tu (LRN): ";
            postOrder(cay, Root(cay));
            cout << "\n";
            break;
        }
       }
    } while (n != 0);
 
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

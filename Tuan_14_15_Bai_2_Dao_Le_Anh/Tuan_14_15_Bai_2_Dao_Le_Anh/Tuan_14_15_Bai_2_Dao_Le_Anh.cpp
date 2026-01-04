// Tuan_14_15_Bai_2_Dao_Le_Anh.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    Node lc = 2 * p + 1;           // index con trai 
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

    Node rc = 2 * p + 2;           // index con phai 
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

void preOrder(Tree T, Node p) { // NLR duyet truoc
    if (p == Nil || p >= T.Maxnode) return;
    cout << T.Data[p] << " ";
    preOrder(T, 2 * p + 1);
    preOrder(T, 2 * p + 2);
}




void printLabel(Node p) { // in chi muc cho nut p
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
bool sameTreeRec(const Tree& A, const Tree& B, int pA, int pB) {
    // cả hai đều "Nil"
    if (pA >= A.Maxnode && pB >= B.Maxnode) return true;

    // một nil, một không
    if (pA >= A.Maxnode || pB >= B.Maxnode) return false;

    // khác giá trị
    if (A.Data[pA] != B.Data[pB]) return false;

    // so sánh 2 cây con
    return sameTreeRec(A, B, 2 * pA + 1, 2 * pB + 1) &&
        sameTreeRec(A, B, 2 * pA + 2, 2 * pB + 2);
}

bool sameTree(const Tree& A, const Tree& B) {
    return sameTreeRec(A, B, 0, 0);
}











int main() {
    Tree A, B;
    initTree(A);
    initTree(B);

   
    cout << "Nhap muc cho cay A (vd: muc=3 => 7 nut): ";
    cin >> A.level;
    A.Maxnode = (1 << A.level) - 1;
    if (A.Maxnode > MAX) A.Maxnode = MAX;

    cout << "Nhap gia tri cho " << A.Maxnode << " nut cua cay A:\n";
    for (int i = 0; i < A.Maxnode; i++) {
        cout << "A - Nhap nut ";
        printLabel(i);
        cout << ": ";
        cin >> A.Data[i];
    }

    
    cout << "\nNhap muc cho cay B (vd: muc=3 => 7 nut): ";
    cin >> B.level;
    B.Maxnode = (1 << B.level) - 1;
    if (B.Maxnode > MAX) B.Maxnode = MAX;

    cout << "Nhap gia tri cho " << B.Maxnode << " nut cua cay B:\n";
    for (int i = 0; i < B.Maxnode; i++) {
        cout << "B - Nhap nut ";
        printLabel(i);
        cout << ": ";
        cin >> B.Data[i];
    }

   
    cout << "\nin duyet truoc (NLR) cay A: ";
    preOrder(A, Root(A));
    cout << "\nin duyet truoc (NLR) cay B: ";
    preOrder(B, Root(B));
    cout << "\n";

	// so sanh 2 cay
    if (sameTree(A, B)) cout << "\n=> HAI CAY GIONG HET NHAU.\n";
    else                cout << "\n=> HAI CAY KHAC NHAU.\n";

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

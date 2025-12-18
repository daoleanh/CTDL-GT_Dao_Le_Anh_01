// Tree_linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

typedef int DataType;

struct Node {
    DataType data;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
};


void initTree(Tree& T) { T.root = nullptr; }
int emptyTree(Tree T) { return T.root == nullptr; }
Node* Root(Tree T) { return T.root; }


Node* makeNode(DataType x) {
    Node* p = new Node;
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

Node* findNode(Node* r, DataType key) {
    if (r == nullptr) return nullptr;
    if (r->data == key) return r;
    Node* L = findNode(r->left, key);
    if (L != nullptr) return L;
    return findNode(r->right, key);
}


void createRoot(Tree& T, DataType x) {
    if (!emptyTree(T)) {
        cout << "Cay da co goc!\n";
        return;
    }
    T.root = makeNode(x);
}


void addLeftChild(Tree& T, DataType parentValue, DataType v) {
    if (emptyTree(T)) { cout << "Cay rong! Tao goc truoc.\n"; return; }

    Node* p = findNode(T.root, parentValue);
    if (p == nullptr) { cout << "Khong tim thay nut cha!\n"; return; }

    if (p->left != nullptr) { cout << "Nut cha da co con trai!\n"; return; }
    p->left = makeNode(v);
}

void addRightChild(Tree& T, DataType parentValue, DataType v) {
    if (emptyTree(T)) { cout << "Cay rong! Tao goc truoc.\n"; return; }

    Node* p = findNode(T.root, parentValue);
    if (p == nullptr) { cout << "Khong tim thay nut cha!\n"; return; }

    if (p->right != nullptr) { cout << "Nut cha da co con phai!\n"; return; }
    p->right = makeNode(v);
}


void preOrder(Node* r) { // NLR
    if (!r) return;
    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(Node* r) { // LNR
    if (!r) return;
    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

void postOrder(Node* r) { // LRN
    if (!r) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}

void clearTree(Node*& r) {
    if (!r) return;
    clearTree(r->left);
    clearTree(r->right);
    delete r;
    r = nullptr;
}


int main() {
    Tree T; initTree(T);

    int cmd;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1) Tao goc\n";
        cout << "2) Them con trai\n";
        cout << "3) Them con phai\n";
        cout << "4) Duyet NLR\n";
        cout << "5) Duyet LNR\n";
        cout << "6) Duyet LRN\n";
        cout << "0) Thoat\n";
        cout << "Chon: ";
        cin >> cmd;

        if (cmd == 1) {
            DataType x;
            cout << "Nhap gia tri goc: ";
            cin >> x;
            createRoot(T, x);
        }
        else if (cmd == 2) {
            DataType par, v;
            cout << "Nhap gia tri nut cha: ";
            cin >> par;
            cout << "Nhap gia tri con trai: ";
            cin >> v;
            addLeftChild(T, par, v);
        }
        else if (cmd == 3) {
            DataType par, v;
            cout << "Nhap gia tri nut cha: ";
            cin >> par;
            cout << "Nhap gia tri con phai: ";
            cin >> v;
            addRightChild(T, par, v);
        }
        else if (cmd == 4) {
            cout << "NLR: ";
            preOrder(Root(T));
            cout << "\n";
        }
        else if (cmd == 5) {
            cout << "LNR: ";
            inOrder(Root(T));
            cout << "\n";
        }
        else if (cmd == 6) {
            cout << "LRN: ";
            postOrder(Root(T));
            cout << "\n";
        }
        else if (cmd == 0) {
            cout << "Thoat!\n";
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }

    } while (cmd != 0);

    clearTree(T.root);
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

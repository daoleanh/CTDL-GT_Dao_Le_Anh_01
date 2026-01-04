#include <iostream>
using namespace std;

struct Node {
    int value;      // gia tri nut
    Node* left;     // con tro toi con trai
    Node* right;    // con tro toi con phai

    Node(int v, Node* l = NULL, Node* r = NULL) {
        value = v;
        left = l;
        right = r;
    }
};

class BSTree {
private:
    Node* root;

    // de quy
    void makeEmpty(Node*& t) {
        if (t == NULL) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }

    void insert(int val1, Node*& t) {
        if (t == NULL) {
            t = new Node(val1);
            return;
        }
        if (val1 < t->value) insert(val1, t->left);
        else if (val1 > t->value) insert(val1, t->right);
        // neu bang nhau: bo qua (khong chen trung)
    }

    Node* search(int val2, Node* t) {
        if (t == NULL) return NULL;
        if (val2 == t->value) return t;
        if (val2 < t->value) return search(val2, t->left);
        return search(val2, t->right);
    }

public:
    BSTree() { root = NULL; }

    ~BSTree() { makeEmpty(root); }

    bool isEmpty() { return root == NULL; }

    void makeEmpty() { makeEmpty(root); }

    void insert(int val1) { insert(val1, root); }

    Node* search(int val2) { return search(val2, root); }

    Node* getRoot() { return root; } // tiện để duyệt
};

// ===== Duyet cay =====
void PREORDER_travl(Node* t) {        // NLR
    if (t == NULL) return;
    cout << t->value << " ";
    PREORDER_travl(t->left);
    PREORDER_travl(t->right);
}

void INORDER_travl(Node* t) {         // LNR
    if (t == NULL) return;
    INORDER_travl(t->left);
    cout << t->value << " ";
    INORDER_travl(t->right);
}

void POSTORDER_travl(Node* t) {       // LRN
    if (t == NULL) return;
    POSTORDER_travl(t->left);
    POSTORDER_travl(t->right);
    cout << t->value << " ";
}

int main() {
    BSTree bst;

    // Chen cac node
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node* root = bst.search(5);

    cout << "Duyet truoc (Preorder - NLR): ";
    PREORDER_travl(root);
    cout << "\n";

    cout << "Duyet giua (Inorder - LNR): ";
    INORDER_travl(root);
    cout << "\n";

    cout << "Duyet sau (Postorder - LRN): ";
    POSTORDER_travl(root);
    cout << "\n\n";

    // Tim hai node 4 va 9
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;
    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;

    // Lam rong cay
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}

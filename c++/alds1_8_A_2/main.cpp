#include <iostream>

using namespace std;


struct Node {
    int key;
    Node *right, *left;
};

// NILの表現方法面白いな、俺もこれ使う
Node *root, *NIL;

void insert(int  key) {
    Node *current = root;
    Node *target = NIL;
    Node *z;

    z = new Node;
    z->key = key;
    z->left = NIL;
    z->right = NIL;

    cout << "root != NIL " << (root != NIL) << endl;
    cout << "current != NIL " << (current != NIL) << endl;
    while (current != NIL) {
        target = current;
        if (z->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (target == NIL) {
        root = z;
    } else if (z->key < target->key) {
        target->left = z;
    } else {
        target->right = z;
    }
}

void inorder(Node *x) {
    if (x != NIL) {
        inorder(x->left);
        cout << x->key << " ";
        inorder(x->right);
    }
}

void preorder(Node *x) {
    if (x != NIL) {
        cout << x->key << " ";
        inorder(x->left);
        inorder(x->right);
    }
}


int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n, i, x;
    string com;

    cin >> n;

    for (i = 0; i < n; i ++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            insert(x);
        } else if (com == "print") {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }

    return 0;
}

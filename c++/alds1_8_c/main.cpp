#include <iostream>

using namespace std;


struct Node {
    int key;
    Node *right, *left, *parent;
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

    while (current != NIL) {
        target = current;
        if (z->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    z->parent = target;
    if (target == NIL) {
        root = z;
    } else if (z->key < target->key) {
        target->left = z;
    } else {
        target->right = z;
    }
}

bool find(int x) {
    Node *current = root;
    while (current != NIL) {
        if (current->key == x) {
            return true;
        } else if (current->key < x) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return false;
}

void deleteByKey(int key) {
    Node *current = root;
    while (current != NIL) {
        if (current->key == key) {
            break;
        } else if (current->key < key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current->left != NIL && current->right != NIL) {
    }
}

void inorder(Node *x, string &result) {
    if (x != NIL) {
        inorder(x->left, result);
        result +=  " " + to_string(x->key);
        inorder(x->right, result);
    }
}

void preorder(Node *x, string &result) {
    if (x != NIL) {
        result +=  " " + to_string(x->key);
        preorder(x->left, result);
        preorder(x->right, result);
    }
}


int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n, i, x;
    string com;

    cin >> n;

    string result = "";

    for (i = 0; i < n; i ++) {
        cin >> com;
        if (com == "insert") {
            cin >> x;
            insert(x);
        } else if (com == "find") {
            cin >> x;
            bool isFind = find(x);
            result += (isFind ? "yes\n" : "no\n");
        } else if (com == "print") {
            inorder(root, result);
            result += "\n";
            preorder(root, result);
            result += "\n";
        }
    }

    cout << result;

    return 0;
}

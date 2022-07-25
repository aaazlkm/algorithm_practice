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

Node* findNextNodeWhenInOrder(Node* current) {
    if (current->left != NIL) {
        return findNextNodeWhenInOrder(current->left);
    }
    return current;
}

void deleteByKey(Node *root, Node* parent, int key) {
    Node *current = root;
    while (current != NIL) {
        if (current->key == key) {
            break;
        } else if (current->key < key) {
            parent = current;
            current = current->right;
        } else {
            parent = current;
            current = current->left;
        }
    }

    if (parent == NIL) {
        root = NIL;
        return;
    }

    if (current->left == NIL && current->right == NIL) {
        if (parent->left == current) {
            parent->left = NIL;
        } else {
            parent->right = NIL;
        }
    } else if (current->left != NIL && current->right != NIL) {
        Node* nextNode = findNextNodeWhenInOrder(current->right);
        current->key = nextNode->key;
        deleteByKey(current->right, current, nextNode->key);
    } else {
        if (current->left != NIL) {
            if (parent->left == current) {
                parent->left = current->left;
                current->left->parent = parent;
                delete current;
            } else {
                parent->right = current->left;
                current->left->parent = parent;
                delete current;
            }
        } else if (current->right != NIL) {
            if (parent->left == current) {
                parent->left = current->right;
                current->right->parent = parent;
                delete current;
            } else {
                parent->right = current->right;
                current->right->parent = parent;
                delete current;
            }
        }
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
        } else if (com == "delete") {
            cin >> x;
//            result += "========= delete start";
//            result += x;
//            result += "\n";
////            preorder(root, result);
//            result += "\n";
            deleteByKey(root, NIL, x);
//            preorder(root, result);
//            result += "\n";
//            result += "=========\n";
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

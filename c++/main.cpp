#include <iostream>
#include <vector>

using namespace std;

const int NIL = -1;
const int MAX = 100005;
void printVector(vector<int> A) {
    for (int i: A) {
        cout << i << " ";
    }
    cout << endl;
}

struct Node {
    int value = NIL;
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
};

struct Node root;

void printTreeInfoByPreorder(Node node) {
    cout << node.value << endl;
    if (node.left != nullptr) {
        printTreeInfoByPreorder(*node.left);
    }
    if (node.right != nullptr) {
        printTreeInfoByPreorder(*node.right);
    }
}

void printTreeInfoByInorder(Node node) {
    if (node.left != nullptr) {
        printTreeInfoByPreorder(*node.left);
    }
    cout << node.value << endl;
    if (node.right != nullptr) {
        printTreeInfoByPreorder(*node.right);
    }
}

void insert(Node nodeToInsert) {
    cout << "===== insert " << nodeToInsert.value << " =====" << endl;
    Node *current = &root;

    if (root.value == NIL) {
        cout << "parent is null" << endl;
        root.value = nodeToInsert.value;
        return;
    }

    while (current->value != NIL && (current->left != nullptr || current->right != nullptr)) {
        cout << "current: " << current->value << " nodeToInsert" << nodeToInsert.value << endl;
        cout << "left: " << ((current->left != nullptr) ? current->left->value : -1)  << endl;
        cout << "right: " << ((current->right != nullptr) ? current->right->value : -1)  << endl;
        cout << (nodeToInsert.value < current->value) << endl;
        cout << (current->value <= nodeToInsert.value) << endl;

        if (nodeToInsert.value < current->value) {
            if (current->left != nullptr) {
                cout << "left swap current: " << current->left->value <<  endl;
                current = current->left;
                continue;
            } else {
                cout << "left break" << endl;
                break;
            }
        } else {
            if (current->right != nullptr) {
                current = current->right;
                cout << "right swap current: " << current->right->value << endl;
                continue;
            } else {
                cout << "right break" << endl;
                break;
            }
        }
    }
    cout << "insert "<< endl;
    nodeToInsert.parent = current;
    if (nodeToInsert.value < current->value) {
        current->left = &nodeToInsert;
    } else {
        current->right = &nodeToInsert;
    }
    cout << "current: " << current->value << endl;
    cout << "left: " << ((current->left != nullptr) ? current->left->value : -1)  << endl;
    cout << "right: " << ((current->right != nullptr) ? current->right->value : -1)  << endl;
    cout << (current->left != nullptr) << endl;
    cout << (current->right != nullptr) << endl;
}

int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        int value;
        cin >> operation;
        if (operation == "insert") {
            cin >> value;
            Node node = {
                value,
                nullptr,
                nullptr,
                nullptr
            };
            node.value = value;
            cout << "node: " << &node << endl;
            insert(node);
        } else if (operation == "print") {
            cout << "preorder" << endl;
            printTreeInfoByPreorder(root);
            printTreeInfoByInorder(root);
        }
    }
    return 0;
}

// node instance is reused for each insert operation.
// so we need to reset it before each insert operation.
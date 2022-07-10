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
    Node *parent = nullptr;
    Node *current = &root;


    if (root.value == NIL) {
        cout << "parent is null" << endl;
        root.value = nodeToInsert.value;
        return;
    }

    while (current->value != NIL && (current->left != nullptr || current->right != nullptr)) {
        cout << "current: " << current->value << endl;
        cout << (current->left != nullptr) << endl;
        cout << (current->right != nullptr) << endl;
        cout << (nodeToInsert.value < current->value) << endl;
        cout << (current->value <= nodeToInsert.value) << endl;

        cout << "current: " << current->value << " nodeToInsert" << nodeToInsert.value << endl;

        parent = current;
        if (nodeToInsert.value < current->value) {
            if (current->left != nullptr) {
                current = current->left;
            } else {
                break;
            }
        }


        if (current->value <= nodeToInsert.value){
            if (current->right != nullptr) {
                current = current->right;
            } else {
                break;
            }
        }
    }
    cout << "insert "<< endl;
    nodeToInsert.parent = parent;
    if (nodeToInsert.value < current->value) {
        current->left = &nodeToInsert;
    } else {
        current->right = &nodeToInsert;
    }
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
            struct Node node;
            node.value = value;
            insert(node);
        } else if (operation == "print") {
            cout << "preorder" << endl;
            printTreeInfoByPreorder(root);
            printTreeInfoByInorder(root);
        }
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int NIL = -1;

struct Node {
    int id = NIL;
    int value = NIL;
    int parentId = NIL;
    int leftId = NIL;
    int rightId = NIL;
};

Node nodes[500000];

void printTreeInfoByInorder(Node node) {
    if (node.leftId != NIL) {
        printTreeInfoByInorder(nodes[node.leftId]);
    }
    cout << " " << node.value;
    if (node.rightId != NIL) {
        printTreeInfoByInorder(nodes[node.rightId]);
    }
}

void printTreeInfoByPreorder(Node node) {
    cout << " " << node.value;
    if (node.leftId != NIL) {
        printTreeInfoByPreorder(nodes[node.leftId]);
    }
    if (node.rightId != NIL) {
        printTreeInfoByPreorder(nodes[node.rightId]);
    }
}

void insert(Node root, Node nodeToInsert) {
    Node current = root;

    while (current.leftId != NIL || current.rightId != NIL) {
        int leftValue = nodes[current.leftId].value;
        int rightValue = nodes[current.rightId].value;

        if (nodeToInsert.value < current.value) {
            if (current.leftId != NIL) {
//                cout << "left swap current: " << leftValue << endl;
                current = nodes[current.leftId];
                continue;
            } else {
//                cout << "left break" << endl;
                break;
            }
        } else {
            if (current.rightId != NIL) {
                current = nodes[current.rightId];
//                cout << "right swap current: " << rightValue << endl;
                continue;
            } else {
//                cout << "right break" << endl;
                break;
            }
        }
    }
    nodes[nodeToInsert.id] = nodeToInsert;
    nodes[nodeToInsert.id].parentId = current.parentId;
    if (nodeToInsert.value < current.value) {
        nodes[current.id].leftId = nodeToInsert.id;
    } else {
        nodes[current.id].rightId = nodeToInsert.id;
    }
//    cout << "current: " << current.value << endl;
//    cout << "leftId: " << nodes[current.id].leftId << endl;
//    cout << "rightId: " << nodes[current.id].rightId << endl;
//    cout << "leftValue: " << nodes[nodes[current.id].leftId].value << endl;
//    cout << "rightValue: " << nodes[nodes[current.id].rightId].value << endl;
//    cout << (current.leftId != NIL) << endl;
//    cout << (current.rightId != NIL) << endl;
}

int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Node root;
    bool isRootInitialized = false;

    for (int i = 0; i < n; i++) {
        string operation;
        int value;
        cin >> operation;
        if (operation == "insert") {
            cin >> value;
//            cout << "===== insert " << value << " =====" << endl;
            struct Node nodeToInsert;
            nodeToInsert.id = i;
            nodeToInsert.value = value;
            nodes[nodeToInsert.id] = nodeToInsert;
            if (isRootInitialized) {
                insert(nodes[root.id], nodeToInsert);
            } else {
                root = nodeToInsert;
                isRootInitialized = true;
            }
//            cout << "====== end insert ======" << endl;
        } else if (operation == "print") {
//            cout << "preorder" << endl;
            printTreeInfoByInorder(nodes[root.id]);
            cout << endl;
            printTreeInfoByPreorder(nodes[root.id]);
            cout << endl;
        }
    }

    return 0;
}

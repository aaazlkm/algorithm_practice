#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using namespace std;

//int BAN = -2;
int NIL = -1;
int MAX = 32500001;

int S[35000001];

int maxI = 0;

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

//void insert(int i, int value) {
//    if (MAX < i) {
//        return;
//    }
//
//    if (S[i] == NIL) {
//        S[i] = value;
//        return;
//    }
//
//    if (S[i] == BAN) {
//        insert(left(i), value);
//        return;
//    }
//
//    if (value < S[i]) {
//        insert(left(i), value);
//    } else {
//        insert(right(i), value);
//    }
//}
//
//int extract() {
//    if (S[1] == NIL) {
//        return NIL;
//    }
//    int i = 1;
//    while (true) {
//        if (right(i) < MAX && S[right(i)] != NIL && S[right(i)] != BAN) {
//            i = right(i);
//        } else if (S[i] == BAN && (left(i) < MAX  && S[left(i)] != NIL)) {
//            i = left(i);
//        } else {
//            int result = S[i];
//            if (left(i) < MAX  && S[left(i)] != NIL) {
//                S[i] = BAN;
//            } else {
//                S[i] = NIL;
//            }
//            return result;
//        }
//    }
//}

void maxHeapify(int i) {
    int leftI = left(i);
    int rightI = right(i);

//    cout << "maxHeapify: " << i << endl;
//
//    if (i == 1) {
//        cout << "i: " << i << " rightI: " << rightI << " leftI: " << leftI << endl;
//    }

    int largest;
    if (leftI < MAX && S[leftI] > S[i]) {
        largest = leftI;
    } else {
        largest = i;
    }

    if (rightI < MAX && S[rightI] > S[largest]) {
        largest = rightI;
    }

    if (largest != i) {
        swap(S[i], S[largest]);
        maxHeapify(largest);
    }
}

void buildMaxHeap() {
    for (int i = maxI / 2; i > 0; i--) {
        maxHeapify(i);
    }
}

void insert(int i, int value) {
    if (MAX < i) {
        return;
    }

    if (maxI < i) {
        maxI = i;
    }

    if (S[i] == NIL) {
        S[i] = value;
        return;
    }

    if (value > S[i]) {
        int temp = S[i];
        S[i] = value;
        insert(left(i), temp);
    } else {
        insert(right(i), value);
    }
}

void renewKey(int i) {
    int temp = S[i];
    S[i] = NIL;
    insert(1, temp);
    if (left(i) < MAX && S[left(i)] != NIL) {
        renewKey(left(i));
    }
    if (right(i) < MAX && S[right(i)] != NIL) {
        renewKey(right(i));
    }
}

int extract() {
    int result = S[1];
    S[1] = NIL;
    buildMaxHeap();
    return result;
}

void printNode(int i) {
    cout << S[i] << " ";
    if (left(i) < MAX && S[left(i)] != NIL) {
        cout << "l: " << S[left(i)]<< " ";
    }
    if (right(i) < MAX && S[right(i)] != NIL) {
        cout << "r: " << S[right(i)]<< " ";
    }
    cout << endl;
    if (left(i) < MAX && S[left(i)] != NIL) {
        printNode(left(i));
    }
    if (right(i) < MAX && S[right(i)] != NIL) {
        printNode(right(i));
    }
}

vector<string> readFile(string fileName) {
    vector<string> result;
    ifstream outputFile;
    outputFile.open(fileName);
    if(!outputFile) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    int i =0;
    while ( !outputFile.eof() ) { // keep reading until end-of-file
        cout << "The next number is " << i << endl;
        string line;
        outputFile >> line; // sets EOF flag if no value found
        result.push_back(line);
    }
    outputFile.close();
    cout << "End-of-file reached.." << endl;
    return result;
}

void compare() {
    vector<string> result = readFile("result.txt");
    vector<string> answer = readFile("answer.txt");
    for (int i = 0; i< result.size(); i++) {
        if (result[i] != answer[i]) {
            cout << "Error: "  << "i=" << i + 1 << " " << result[i] << " != " << answer[i] << endl;
        }
    }
}


int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

//    ofstream out("out.txt");
//    streambuf *coutbuf = cout.rdbuf(); //save old buf
//    cout.rdbuf(out.rdbuf());

    fill_n(S, MAX, NIL);

    while (true) {
        string command;
        cin >> command;
        if (command == "insert") {
            int value;
            cin >> value;
            insert(1, value);
        } else if (command == "extract") {
            int value = extract();
            cout << value << endl;
        } else if (command == "end") {
            break;
        }
//        cout << "======= tree ======" << endl;
//        printNode(1);
//        cout << "======= tree end ======" << endl;

    }
//    compare();
    return 0;
}


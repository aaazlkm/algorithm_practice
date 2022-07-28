#include <iostream>
#include <cmath>

using namespace std;

int NIL = -1;
int MAX = 2000001;

int S[2000001];

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void insert(int i, int value) {
    if (MAX < i) {
        return;
    }

    if (S[i] == NIL) {
        S[i] = value;
        return;
    }

    if (value < S[i]) {
        insert(left(i), value);
    } else {
        insert(right(i), value);
    }
}

void renewKey(int i) {
    int temp = S[i];
    S[i] == NIL;
    insert(1, temp);
    if (left(i) < MAX && S[left(i)] != NIL) {
        renewKey(left(i));
    }
    if (right(i) < MAX && S[right(i)] != NIL) {
        renewKey(right(i));
    }
}

int extract() {
    if (S[1] == NIL) {
        return NIL;
    }
    int i = 1;
    while (true) {
        if (right(i) < MAX && S[right(i)] != NIL) {
            i = right(i);
        } else {
            int result = S[i];
            S[i] = NIL;
            if (left(i) < MAX && S[left(i)] != NIL) {
                renewKey(left(i));
            }
            return result;
        }
    }
}

int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    fill_n(S, 2000001, NIL);

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
    }
    return 0;
}

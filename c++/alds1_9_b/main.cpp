#include <iostream>
#include <cmath>

using namespace std;

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void maxHeapify(int A[], int i) {
    int leftI = left(i);
    int rightI = right(i);

    int largest;
    if (leftI <= A[0] && A[leftI] > A[i]) {
        largest = leftI;
    } else {
        largest = i;
    }

    if (rightI <= A[0] && A[rightI] > A[largest]) {
        largest = rightI;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest);
    }
}

int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int nodes[n + 1];
    nodes[0] = n;

    for (int i = 1; i <= n; i++) {
        cin >> nodes[i];
    }

    for (int i = n / 2; i > 0; i--) {
        maxHeapify(nodes, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << " " << nodes[i];
    }
    cout << endl;
    return 0;
}

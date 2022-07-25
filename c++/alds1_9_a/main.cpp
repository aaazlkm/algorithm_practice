#include <iostream>
#include <cmath>

using namespace std;

int main() {
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int nodes[n];

    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    for (int i = 0; i < n; i++) {
        int nodeI = i + 1;
        int parentI = floor(nodeI / 2);
        int leftI  = 2 * nodeI;
        int rightI = 2 * nodeI + 1;
        string result = "";
        result += "node ";
        result += to_string(nodeI);
        result += ": key = ";
        result += to_string(nodes[i]);
        result += ", ";
        if (parentI != 0) {
            result += "parent key = ";
            result += to_string(nodes[parentI - 1]);
            result += ", ";
        }
        if (leftI <= n) {
            result += "left key = ";
            result += to_string(nodes[leftI - 1]);
            result += ", ";
        }
        if (rightI <= n) {
            result += "right key = ";
            result += to_string(nodes[rightI - 1]);
            result += ", ";
        }

        cout <<  result << endl;
    }
    return 0;
}

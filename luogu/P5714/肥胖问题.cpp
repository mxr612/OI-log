#include <iostream>

using namespace std;

double w, h, x;

int main() {
    freopen("P5714.in", "r", stdin);
    cin >> w >> h;
    x = w / (h * h);
    if (x < 18.5) {
        cout << "Underweight";
    }
    if (x >= 18.5 && x < 24) {
        cout << "Normal";
    }
    if (x >= 24) {
        cout << x << endl;
        cout << "Overweight";
    }
    // cout << x;
    return 0;
}
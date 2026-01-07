#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b >= 45) {
        int b_2 = b - 45;
        cout << a << " " << b_2;
    }
    else {
        int a_2;
        if (a <= 0) {
            a_2 = 23;
        }
        else {
            a_2 = a - 1;
        }
        int b_3 = 60 - 45 + b;
        cout << a_2 << " " << b_3;
    }

    return 0;
}

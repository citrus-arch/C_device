#include <iostream>
using namespace std;

void func(int &a, int b = 10) {
    a += b;
}

int main() {
    int x = 5;
    func(x);
    cout << x << endl;
    return 0;
}
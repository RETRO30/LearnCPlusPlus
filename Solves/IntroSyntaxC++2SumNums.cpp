#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; n > 0; n--) {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << a + b;
        cout << "\n";
    }
    return 0;
}
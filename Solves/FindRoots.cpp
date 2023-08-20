#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    double d = (b * b) - (4 * a * c);
    if (d >= 0) {
        double x1, x2;
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << x1 << ' ' << x2;
        cout << '\n';
    }
    else {
        cout << "No real roots\n";
    } 

    return 0;
}
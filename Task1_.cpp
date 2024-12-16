#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    float x, y, R, S, C;
    cin >> x >> y;
    R = cos(2 * x) * sin(y);
    S = pow(M_E, 1 / x) * log(y);
    cout << R << endl << S << endl;
    C = max(R, S);
    cout << C << endl;
    system("PAUSE>nul");
    return 0;
}
#include <stdio.h>
#define size_m 10
using namespace std;
#include <iostream>
void chet(const int* arrA) {
    int j = 0, i = 0;
    int b[size_m] = { 0 };
    for (i = 0, j = 0; i < size_m; i++) {
        if (!(arrA[i] % 2)) {
            b[j++] = arrA[i];
        }
    }

    for (i = 0; i < j; i++) {
        printf("%d ", b[i]);
    }
}
int main()
{
    int k, m[10];

    for (k = 0; k < 10; k++)
    {
        cin >> m[k];

    }
    chet(m);

    system("pause");
    return 0;
}
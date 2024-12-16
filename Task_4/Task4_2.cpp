#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
void AAA(std::set<int> setA, std::set<int> setB) {
    std::vector<int> setC;
    std::vector<int> setC1;

    int j = 0, i = 0;
    set_intersection(setA.begin(), setA.end(),
        setB.begin(), setB.end(),
        inserter(setC, setC.begin()));
    setC1.reserve(setC.size());
    for (auto it = setC.cbegin(); it != setC.cend(); ++it) {
        int value = *it;
        if (value % 3 != 0) {
            setC1.push_back(value);
        }
    }
    for (int i = 0; i != setC1.size(); ++i) {
        std::cout << setC[i] << std::endl;
    }
    }

int main()
{
    int N_A, N_B, insertnum;
    std::set<int> A, B;

    std::wcout << L"Elements of A: ";
    std::cin >> N_A;

    std::wcout << L"Set A: " << std::endl;
    for (int i = 0; i < N_A; i++) {
        std::cin >> insertnum;
        A.insert(insertnum);
    }

    std::wcout << L"Elements of B: ";
    std::cin >> N_B;

    std::wcout << L"Set B: " << std::endl;
    for (int i = 0; i < N_B; i++) {
        std::cin >> insertnum;
        B.insert(insertnum);
    }
    AAA(A, B);
    system("PAUSE>nul");
    return 0;
 }
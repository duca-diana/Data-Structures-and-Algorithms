#include <iostream>
#include "Matrix.h"
#include "ShortTest.h"
#include "ExtendedTests.h"
using namespace std;

int main() {
    testAll();
    testAllExtended();
    cout << "Test End" << endl;
    system("pause");
}
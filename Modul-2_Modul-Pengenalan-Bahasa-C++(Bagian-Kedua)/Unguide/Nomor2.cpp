#include <iostream>
using namespace std;


void kuadratkan(int &x) {
    x = x * x;
}

int main() {
    int nilai = 5;
    cout << "Nilai awal: " << nilai << endl;


    kuadratkan(nilai);

    cout << "Nilai setelah dikuadratkan: " << nilai << endl;

    return 0;
}
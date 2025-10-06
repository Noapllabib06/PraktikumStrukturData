#include <iostream>
using namespace std;

// Prosedur dengan parameter referensi
void kuadratkan(int &x) {
    x = x * x;  // Nilai asli x diubah menjadi kuadratnya
}

int main() {
    int nilai;

    cout << "Masukkan sebuah nilai: ";
    cin >> nilai;
    cout << "Nilai awal: " << nilai << endl;

    // Memanggil prosedur dengan parameter referensi
    kuadratkan(nilai);

    cout << "Nilai setelah dikuadratkan: " << nilai << endl;

    return 0;
}
#include <iostream>
using namespace std;


void tampilkanMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}


void transposeMatriks(int asal[3][3], int hasil[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[j][i] = asal[i][j];
        }
    }
}

int main() {
    int matriksAwal[3][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int matriksTranspose[3][3];

    cout << "Matriks Awal:" << endl;
    tampilkanMatriks(matriksAwal);
    transposeMatriks(matriksAwal, matriksTranspose);

    cout << "\nMatriks Hasil Transpose:" << endl;
    tampilkanMatriks(matriksTranspose);

    return 0;
}
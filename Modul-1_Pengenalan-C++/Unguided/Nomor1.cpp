#include<iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "Masukan Angka1 : ";
    cin >> angka1;
    cout << "Masukan Angka2 : ";
    cin >> angka2;

    //Penjumlahan
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    //Pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    //Perkalian
    cout << "Perkalian : " << angka1 * angka2 << endl;
    //Pembagian
    if ( angka2 != 0) {
        cout << "Pembagian : " << angka1 / angka2 << endl;
    } else {
        cout << "Pembagian : Tidak Bisa Karena Pembagi Adalah 0";
    }
    return 0;
}
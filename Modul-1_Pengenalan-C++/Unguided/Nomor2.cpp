#include <iostream>
#include <string>
using namespace std;

string stringsatuan(int n) {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan"};

    if (n == 0) return "nol";
    if (n == 100) return "seratus";

    int puluh = n / 10;
    int sisa  = n % 10;

    //kasus untuk satua
    if (puluh == 0) {
        return satuan[sisa];
    }

    // kasus buat belasan
    if (puluh == 1) {
        if (sisa == 0) {
            return "sepuluh";
        } else if (sisa == 1) {
            return "sebelas"; 
        } else { 
            return satuan[sisa] + " belas";
        }
    }

    if (puluh > 1) {
        if (sisa == 0) {
            return satuan[puluh] + " puluh";
        } else { 
            return satuan[puluh] + " puluh " + satuan[sisa];
        }
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Input harus 0 - 100" << endl;
    } else {
        cout << angka << " : " << stringsatuan(angka) << endl;
    }

    return 0;
}
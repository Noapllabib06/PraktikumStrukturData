#include <iostream>
#include <string>
using namespace std;

struct Pembeli {
    string nama;
    string pesanan;
    Pembeli* next;
};

Pembeli* front = nullptr;
Pembeli* rear = nullptr;

void tambahAntrian(string nama, string pesanan) {
    Pembeli* baru = new Pembeli{nama, pesanan, nullptr};
    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Antrian berhasil ditambahkan.\n";
}

void layaniAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    Pembeli* hapus = front;
    cout << "Melayani: " << hapus->nama << " - " << hapus->pesanan << endl;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete hapus;
}

void tampilkanAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }
    Pembeli* temp = front;
    cout << "Daftar Antrian:\n";
    while (temp != nullptr) {
        cout << temp->nama << " - " << temp->pesanan << endl;
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string nama, pesanan;
    do {
        cout << "\nMenu Antrian Pembeli\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                cout << "Nama pembeli: ";
                getline(cin, nama);
                cout << "Pesanan: ";
                getline(cin, pesanan);
                tambahAntrian(nama, pesanan);
                break;
            case 2:
                layaniAntrian();
                break;
            case 3:
                tampilkanAntrian();
                break;
            case 4:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Menu tidak valid.\n";
        }
    } while (pilihan != 4);
    return 0;
}
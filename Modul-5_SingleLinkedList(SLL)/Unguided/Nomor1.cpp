#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string pesanan;
    Node* next;
};

Node* depan = nullptr;
Node* belakang = nullptr;

void tambahAntrian() {
    Node* baru = new Node();
    cout << "Nama: ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "Pesanan: ";
    getline(cin, baru->pesanan);
    baru->next = nullptr;
    
    if (belakang == nullptr) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }
    cout << "Antrian ditambahkan\n";
}

void layaniAntrian() {
    if (depan == nullptr) {
        cout << "Antrian kosong\n";
        return;
    }
    
    Node* temp = depan;
    cout << "Melayani: " << temp->nama << " - " << temp->pesanan << endl;
    depan = depan->next;
    
    if (depan == nullptr) {
        belakang = nullptr;
    }
    
    delete temp;
}

void tampilkanAntrian() {
    if (depan == nullptr) {
        cout << "Antrian kosong\n";
        return;
    }
    
    Node* temp = depan;
    int no = 1;
    cout << "\nDaftar Antrian:\n";
    while (temp != nullptr) {
        cout << no << ". " << temp->nama << " - " << temp->pesanan << endl;
        temp = temp->next;
        no++;
    }
}

void cariPembeli() {
    if (depan == nullptr) {
        cout << "Antrian kosong\n";
        return;
    }
    
    string namaCari;
    cout << "Masukkan nama pembeli yang dicari: ";
    cin.ignore();
    getline(cin, namaCari);
    
    Node* temp = depan;
    int posisi = 1;
    bool ditemukan = false;
    
    cout << "\nHasil Pencarian:\n";
    while (temp != nullptr) {
        if (temp->nama == namaCari) {
            cout << "Ditemukan di posisi " << posisi << endl;
            cout << "Nama: " << temp->nama << endl;
            cout << "Pesanan: " << temp->pesanan << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
        posisi++;
    }
    
    if (!ditemukan) {
        cout << "Pembeli dengan nama \"" << namaCari << "\" tidak ditemukan.\n";
    }
}

int main() {
    int pilih;
    
    do {
        cout << "\n1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Cari Pembeli\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        
        if (pilih == 1) {
            tambahAntrian();
        } else if (pilih == 2) {
            layaniAntrian();
        } else if (pilih == 3) {
            tampilkanAntrian();
        } else if (pilih == 4) {
            cariPembeli();
        } else if (pilih == 0) {
            cout << "Terima kasih!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
        
    } while (pilih != 0);
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int ISBN;
    string Judul;
    string Penulis;
    Buku* next;
};

Buku* front = nullptr;
Buku* rear = nullptr;

void tambahBuku(int ISBN, string Judul, string Penulis) {
    Buku* baru = new Buku{ISBN, Judul, Penulis, nullptr};
    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Buku Baru Berhasil Ditambahkan.\n";
}

void hapusbuku(int ISBN) {
    if (front == nullptr) {
        cout << "Rak Buku Kosong.\n";
        return;
    }

    if (front->ISBN == ISBN) {
        Buku* temp = front;
        front = front->next;
        delete temp;
        cout << "Buku dengan ISBN " << ISBN << " telah dihapus dari rak.\n";
        return;
    }
}

void memperbaruiBuku(int ISBN, string JudulBaru, string PenulisBaru) {
    Buku* temp = front;
    while (temp != nullptr) {
        if (temp->ISBN == ISBN) {
            temp->Judul = JudulBaru;
            temp->Penulis = PenulisBaru;
            cout << "Buku dengan ISBN " << ISBN << " telah diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Buku dengan ISBN " << ISBN << " tidak ditemukan.\n";
}

//void susunanBuku() {
    //if (front == nullptr) {
        //cout << "Rak Buku Kosong.\n";
        //return;
    //}
//    Buku* hapus = front;
//    cout << "Melayani: " << hapus->nama << " - " << hapus->pesanan << endl;
//   front = front->next;
//   if (front == nullptr) rear = nullptr;
//    delete hapus;
//}

void tampilkanBuku() {
    if (front == nullptr) {
        cout << "Rak Buku Kosong.\n";
        return;
    }
    Buku* temp = front;
    cout << "Susunan Buku:\n";
    while (temp != nullptr) {
        cout << temp->ISBN << " - " << temp->Judul << " - " << temp->Penulis << endl;
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string Judul, Penulis;
    do {
        cout << "\nMenu Antrian Pembeli\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku Berdasarkan ISBN\n";
        cout << "3. Tampilkan Buku\n";
        cout << "4. Memperbarui Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                cout << "ISBN Buku: ";
                int ISBN;
                cin >> ISBN;
                cin.ignore();
                cout << "Nama/Judul Buku: ";
                getline(cin, Judul);
                cout << "Penulis: ";
                getline(cin, Penulis);
                tambahBuku(ISBN, Judul, Penulis);
                break;
            case 2:
                cout << "Masukkan ISBN Buku yang akan dihapus: ";
                cin >> ISBN;
                cin.ignore();
                hapusbuku(ISBN);
                break;
            case 3:
                tampilkanBuku();
                break;
            case 4:
                cout << "Memperbarui Buku\n";
                cout << "Masukkan ISBN Buku yang akan diperbarui: ";
                cin >> ISBN;
                cin.ignore();
                cout << "Nama/Judul Buku Baru: ";
                getline(cin, Judul);
                cout << "Penulis Baru: ";
                getline(cin, Penulis);
                memperbaruiBuku(ISBN, Judul, Penulis);
                break;
            case 5:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Menu tidak valid.\n";
        }
    } while (pilihan != 5);
    return 0;
}
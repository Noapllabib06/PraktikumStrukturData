#include <iostream>
#include <string>

using namespace std;

struct infotype {
    string isbn;
    string judul;
    string penulis;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype data) {
    address P = new elmlist;
    P->info.isbn = data.isbn;
    P->info.judul = data.judul;
    P->info.penulis = data.penulis;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

address cariBukuByISBN(List L, string isbn) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.isbn == isbn) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}


void cariDanTampilkanBuku(List L) {
    if (L.first == NULL) {
        cout << "\n[INFO] Daftar buku masih kosong, tidak ada yang bisa dicari." << endl;
        return;
    }

    int pilihanCari;
    cout << "\n--- Cari Buku Berdasarkan ---" << endl;
    cout << "1. Judul" << endl;
    cout << "2. Penulis" << endl;
    cout << "3. ISBN" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihanCari;

    if (cin.fail() || pilihanCari < 1 || pilihanCari > 3) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "\n[ERROR] Pilihan tidak valid." << endl;
        return;
    }

    string keyword;
    cout << "Masukkan kata kunci pencarian: ";
    cin.ignore(); 
    getline(cin, keyword);

    address P = L.first;
    bool ditemukan = false;
    int i = 1;

    while (P != NULL) {
        bool cocok = false;
        if (pilihanCari == 1 && P->info.judul.find(keyword) != string::npos) {
            cocok = true;
        } else if (pilihanCari == 2 && P->info.penulis.find(keyword) != string::npos) {
            cocok = true;
        } else if (pilihanCari == 3 && P->info.isbn == keyword) {
            cocok = true;
        }

        if (cocok) {
            cout << i << ". ISBN    : " << P->info.isbn << endl;
            cout << "   Judul   : " << P->info.judul << endl;
            cout << "   Penulis : " << P->info.penulis << endl;
            ditemukan = true;
            i++;
        }
        P = P->next;
    }

    if (!ditemukan) {
        cout << "   (Buku dengan kata kunci '" << keyword << "' tidak ditemukan)" << endl;
    }

}


void tambahBuku(List &L, infotype data) {
    address P = alokasi(data);
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    cout << "\n[INFO] Buku '" << data.judul << "' berhasil ditambahkan." << endl;
}

void hapusBuku(List &L, string isbn) {
    address P = cariBukuByISBN(L, isbn);

    if (P == NULL) {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        L.first = P->next;
    } else {
        address prev = L.first;
        while (prev->next != P) {
            prev = prev->next;
        }
        prev->next = P->next;
    }

    cout << "\n[INFO] Buku '" << P->info.judul << "' berhasil dihapus." << endl;
    dealokasi(P);
}

void updateBuku(List &L, string isbn) {
    address P = cariBukuByISBN(L, isbn);
    if (P != NULL) {
        cout << "\nData Buku Ditemukan:" << endl;
        cout << "Judul Lama: " << P->info.judul << endl;
        cout << "Penulis Lama: " << P->info.penulis << endl;

        cout << "\nMasukkan Judul Baru: ";
        cin.ignore();
        getline(cin, P->info.judul);

        cout << "Masukkan Penulis Baru: ";
        getline(cin, P->info.penulis);

        cout << "\n[INFO] Data buku berhasil diperbarui." << endl;
    } else {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
    }
}

void lihatBuku(List L) {
    if (L.first == NULL) {
        cout << "               (Tidak ada buku di daftar)" << endl;
    } else {
        address P = L.first;
        int i = 1;
        while (P != NULL) {
            cout << i << ". ISBN    : " << P->info.isbn << endl;
            cout << "   Judul   : " << P->info.judul << endl;
            cout << "   Penulis : " << P->info.penulis << endl;
            P = P->next;
            i++;
        }
    }
}

int main() {
    List daftar_buku;
    createList(daftar_buku);
    int pilihan;
    string isbn;
    infotype dataBuku;

    do {
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Perbarui Buku" << endl;
        cout << "4. Lihat Semua Buku" << endl;
        cout << "5. Cari Buku" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        

        if (cin.fail()) {
            cout << "\n[ERROR] Input harus berupa angka." << endl;
            cin.clear();
            cin.ignore(10000, '\n'); 
            pilihan = 0; 
            continue; 
        }


        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Buku Baru ---" << endl;
                cout << "Masukkan ISBN: ";
                cin >> dataBuku.isbn;
                cout << "Masukkan Judul: ";
                cin.ignore();
                getline(cin, dataBuku.judul);
                cout << "Masukkan Penulis: ";
                getline(cin, dataBuku.penulis);
                tambahBuku(daftar_buku, dataBuku);
                break;
            case 2:
                cout << "\n--- Hapus Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                cin >> isbn;
                hapusBuku(daftar_buku, isbn);
                break;
            case 3:
                cout << "\n--- Perbarui Data Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan diperbarui: ";
                cin >> isbn;
                updateBuku(daftar_buku, isbn);
                break;
            case 4:
                lihatBuku(daftar_buku);
                break;
            case 5:
                cariDanTampilkanBuku(daftar_buku);
                break;
            case 6:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    listinduk L;
    address P;
    address_anak PA;
    
    CreateList(L);
    
    cout << "=== TEST MULTI LINKED LIST ===" << endl;
    
    cout << "\n1. Insert Pegawai" << endl;
    P = alokasi(1);
    insertLast(L, P);
    
    P = alokasi(2);
    insertLast(L, P);
    
    P = alokasi(3);
    insertLast(L, P);
    
    cout << "Pegawai berhasil ditambahkan" << endl;
    
    cout << "\n2. Insert Anak untuk Pegawai 1" << endl;
    P = findElm(L, 1);
    if (P != Nil) {
        PA = alokasiAnak(101);
        insertLastAnak(P->lanak, PA);
        
        PA = alokasiAnak(102);
        insertLastAnak(P->lanak, PA);
        
        PA = alokasiAnak(103);
        insertLastAnak(P->lanak, PA);
        
        cout << "Anak berhasil ditambahkan" << endl;
    }
    
    cout << "\n3. Insert Anak untuk Pegawai 2" << endl;
    P = findElm(L, 2);
    if (P != Nil) {
        PA = alokasiAnak(201);
        insertLastAnak(P->lanak, PA);
        
        PA = alokasiAnak(202);
        insertLastAnak(P->lanak, PA);
        
        cout << "Anak berhasil ditambahkan (ID: 201, 202)" << endl;
    }
    
    cout << "\n4. Tampilkan Semua Data" << endl;
    printInfo(L);
    
    cout << "\n5. Hapus Anak 102 dari Pegawai 1" << endl;
    P = findElm(L, 1);
    if (P != Nil) {
        delPAnak(P->lanak, 102);
        cout << "Anak 102 berhasil dihapus" << endl;
    }
    
    printInfo(L);
    
    cout << "\n6. Hapus Pegawai 1 beserta semua anaknya" << endl;
    delP(L, 1);
    cout << "Pegawai 1 dan semua anaknya berhasil dihapus" << endl;
    
    printInfo(L);
    
    cout << "\n7. Jumlah Data" << endl;
    cout << "Jumlah Pegawai: " << nbList(L) << endl;
    
    P = findElm(L, 2);
    if (P != Nil) {
        cout << "Jumlah Anak Pegawai 2: " << nbListAnak(P->lanak) << endl;
    }
    
    cout << "\n8. Hapus Semua Data" << endl;
    delAll(L);
    cout << "Semua data berhasil dihapus" << endl;
    
    printInfo(L);
    
    return 0;
}
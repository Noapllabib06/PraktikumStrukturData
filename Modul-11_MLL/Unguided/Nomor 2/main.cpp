#include "multilist.h"

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    address P;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    P = alokasi(x);
    return P;
}

int main() {
    List L;
    address P1 = Nil;
    address P2 = Nil;
    infotype x;
    
    createList(L);
    
    cout << "=== Operasi Circular List ===" << endl;
    cout << "Insert First, Last, dan After" << endl << endl;
    
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);
    cout << "Danu (04) ditambahkan di depan" << endl;
    
    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);
    cout << "Fahmi (06) ditambahkan di belakang" << endl;
    
    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);
    cout << "Bobi (02) ditambahkan di depan" << endl;
    
    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);
    cout << "Ali (01) ditambahkan di depan" << endl;
    
    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);
    cout << "Gita (07) ditambahkan di belakang" << endl;
    
    x.nim = "07";
    P1 = findElm(L, x);
    if (P1 != Nil) {
        P2 = createData("Cindi", "03", 'p', 3.5);
        insertAfter(L, P1, P2);
        cout << "Cindi (03) ditambahkan setelah Gita (07)" << endl;
    }
    
    x.nim = "02";
    P1 = findElm(L, x);
    if (P1 != Nil) {
        P2 = createData("Hilmi", "08", 'l', 3.3);
        insertAfter(L, P1, P2);
        cout << "Hilmi (08) ditambahkan setelah Bobi (02)" << endl;
    }
    
    x.nim = "04";
    P1 = findElm(L, x);
    if (P1 != Nil) {
        P2 = createData("Eli", "05", 'p', 3.4);
        insertAfter(L, P1, P2);
        cout << "Eli (05) ditambahkan setelah Danu (04)" << endl;
    }
    
    printInfo(L);
    
    return 0;
}
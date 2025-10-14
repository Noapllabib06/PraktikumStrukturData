# <h1 align="center">Laporan Praktikum Modul 4 <br> Linked List</h1>
<p align="center">Naufal Labib Asyidiq - 103112400108</p>

## Dasar Teori

Dalam pemrograman C++, modularitas digunakan untuk memecah program besar menjadi beberapa bagian agar lebih terstruktur dan mudah dikelola. Konsep ini diwujudkan melalui pemisahan kode ke dalam tiga jenis file, yaitu header file (.h) yang berisi deklarasi struktur dan fungsi, implementation file (.cpp) yang berisi isi fungsi, serta main file (main.cpp) yang menjadi titik awal eksekusi program. Dengan cara ini, program lebih mudah dipahami, diperbarui, dan digunakan kembali tanpa perlu menulis ulang seluruh kode.

## Guided

### soal 1 

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Pointer awal dan akhir
Node* head = nullptr;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk insert di depan
void insertDepan(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Data " << data << " berhasil ditambahkan di depan.\n";
}


void insertBelakang(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data " << data << " berhasil ditambahkan di belakang.\n";
}

void insertSetelah(int target, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << target << " tidak ditemukan!\n";
    } else {
        Node* newNode = createNode(dataBaru);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data " << dataBaru << " berhasil disisipkan setelah " << target << ".\n";
    }
}

// ========== DELETE FUNCTION ==========
void hapusNode(int data) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Jika data di node pertama
    if (temp != nullptr && temp->data == data) {
        head = temp->next;
        delete temp;
        cout << "Data " << data << " berhasil dihapus.\n";
        return;
    }

    // Cari node yang akan dihapus
    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Jika data tidak ditemukan
    if (temp == nullptr) {
        cout << "Data " << data << " tidak ditemukan!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Data " << data << " berhasil dihapus.\n";
}

// ========== UPDATE FUNCTION ==========
void updateNode(int dataLama, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != dataLama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << dataLama << " tidak ditemukan!\n";
    } else {
        temp->data = dataBaru;
        cout << "Data " << dataLama << " berhasil diupdate menjadi " << dataBaru << ".\n";
    }
}

// ========== DISPLAY FUNCTION ==========
void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ========== MAIN PROGRAM ==========
int main() {
    int pilihan, data, target, dataBaru;

    do {
        cout << "\n=== MENU SINGLE LINKED LIST ===\n";
        cout << "1. Insert Depan\n";
        cout << "2. Insert Belakang\n";
        cout << "3. Insert Setelah\n";
        cout << "4. Hapus Data\n";
        cout << "5. Update Data\n";
        cout << "6. Tampilkan List\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data);
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 3:
                cout << "Masukkan data target: ";
                cin >> target;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                insertSetelah(target, dataBaru);
                break;
            case 4:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                hapusNode(data);
                break;
            case 5:
                cout << "Masukkan data lama: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                updateNode(data, dataBaru);
                break;
            case 6:
                tampilkanList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}

```
### OUTPUT UNTUK MASING-MASING CABANG

untuk opsi 1
> Output
> ![Screenshot Guided Nomor 1 poin 1](P4output/Guided4Nomor1Poin1.PNG)

Pilihan ini menjalankan fungsi insertDepan(), yaitu untuk menambahkan node baru di awal linked list. Program meminta pengguna memasukkan data integer, kemudian membuat node baru dengan nilai tersebut, dan mengatur agar node baru menjadi head (elemen pertama). Jika sebelumnya sudah ada data, maka node baru akan menunjuk ke node lama sebagai next.

untuk opsi 2
> Output
> ![Screenshot Guided Nomor 1 poin 2](P4output/Guided4Nomor1Poin2.PNG)

Case ini menjalankan fungsi insertBelakang(), yang menambahkan node baru di akhir linked list. Program akan mencari node terakhir dengan cara menelusuri list hingga menemukan node yang next-nya bernilai nullptr, kemudian menambahkan node baru di situ. Jika list masih kosong, node baru langsung menjadi head.

untuk opsi 3
> Output
> ![Screenshot Guided Nomor 1 poin 3](P4output/Guided4Nomor1Poin3.PNG)

Pada case ini dipanggil fungsi insertSetelah(). Program meminta dua input: data target dan data baru. Fungsi akan mencari node yang berisi data target, lalu menyisipkan node baru setelah node tersebut. Jika data target tidak ditemukan, akan muncul pesan bahwa data tidak ditemukan.

untuk opsi 4
> Output
> ![Screenshot Guided Nomor 1 poin 4](P4output/Guided4Nomor1Poin4.PNG)

Case ini menggunakan fungsi hapusNode() untuk menghapus node berdasarkan nilai datanya. Program mencari node yang berisi data yang ingin dihapus. Jika data tersebut berada di head, maka head diganti dengan node berikutnya. Jika berada di tengah atau akhir, maka pointer next dari node sebelumnya diubah agar melewati node yang dihapus.

untuk opsi 5
> Output
> ![Screenshot Guided Nomor 1 poin 5](P4output/Guided4Nomor1Poin5.PNG)

Case ini menjalankan fungsi updateNode(), yang digunakan untuk mengubah nilai data dari node tertentu. Program meminta dua input: data lama dan data baru. Kemudian fungsi mencari node yang berisi data lama dan menggantinya dengan data baru. Jika tidak ditemukan, akan ditampilkan pesan kesalahan.

Opsi 6 Tidak perlu menggunakan Screenshoot mandiri karena sudah digunakan pada opsi opsi diatas


## Unguided
## Nomor 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.


```cpp
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;

    if (jumlah > 10) {
        jumlah = 10;
        cout << "Jumlah dibatasi hanya 10 mahasiswa.\n";
    }
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Nama   : ";
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    //Pake "===" biar rapih :)
    cout << "\n==========================================\n";
    cout << "           DATA NILAI MAHASISWA           \n";
    cout << "==========================================\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "------------------------------------------\n";
    }

    return 0;
}
```

Output
> ![Screenshot Unguided Nomor 1](P3output/Unguided3Nomor1.PNG)

Program ini dibuat untuk menyimpan dan menampilkan data mahasiswa menggunakan bahasa C++. Data setiap mahasiswa disimpan dalam struct Mahasiswa yang berisi nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Data beberapa mahasiswa disimpan dalam array dengan jumlah maksimal sepuluh orang. Nilai akhir dihitung menggunakan fungsi hitungNilaiAkhir() dengan rumus 0.3 * UTS + 0.4 * UAS + 0.3 * tugas. Melalui fungsi utama (main()), pengguna dapat memasukkan data mahasiswa, kemudian program akan menghitung dan menampilkan hasilnya secara otomatis. Program ini menggambarkan penerapan konsep struct, array, dan fungsi untuk pengelolaan data secara terstruktur dan efisien.

### soal 2
### Code 1 pelajaran.cpp

```cpp
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

//Heheeh pake " === " Biar Rapih Aja :)"
void tampil_pelajaran(pelajaran pel) {
    cout << "==============================" << endl;
    cout << "        DATA PELAJARAN       " << endl;
    cout << "==============================" << endl;
    cout << "Nama Mata Kuliah : " << pel.namaMapel << endl;
    cout << "Kode Mata Kuliah : " << pel.kodeMapel << endl;
    cout << "==============================" << endl;
}
```

### Code 2 pelajaran.h

```cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

// ======== ADT Pelajaran ========
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

### Code 3 main.cpp

```cpp
#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

> Output
> ![Screenshot Guided Nomor 2](P3output/Unguided3Nomor2.PNG)


Program ini merupakan contoh penerapan Abstract Data Type (ADT) sederhana dalam bahasa C++ yang berfungsi untuk menyimpan serta menampilkan informasi mengenai mata kuliah. Program dibagi menjadi tiga bagian utama, yaitu pelajaran.h, pelajaran.cpp, dan main.cpp, yang saling terhubung membentuk satu sistem yang terstruktur.
Pada file pelajaran.h, terdapat deklarasi struktur pelajaran dengan dua atribut, yaitu namaMapel untuk nama mata kuliah dan kodeMapel untuk kode mata kuliah. File ini juga berisi deklarasi dua fungsi, yaitu create_pelajaran() untuk membuat data pelajaran baru dan tampil_pelajaran() untuk menampilkan data tersebut ke layar. File header ini berperan sebagai penghubung agar struktur dan fungsi dapat digunakan oleh file lain.
Kemudian, pada pelajaran.cpp, kedua fungsi tersebut diimplementasikan. Fungsi create_pelajaran() digunakan untuk membuat objek bertipe pelajaran berdasarkan parameter nama dan kode mata kuliah yang diberikan, lalu mengembalikannya. Sedangkan tampil_pelajaran() bertugas menampilkan data mata kuliah dengan tampilan yang rapi menggunakan garis pembatas.
Bagian utama program terdapat pada main.cpp, di mana dua variabel string digunakan untuk menyimpan nama dan kode mata kuliah. Nilai tersebut kemudian dikirim ke fungsi create_pelajaran() untuk membuat objek pelajaran, dan hasilnya ditampilkan melalui tampil_pelajaran(). Secara keseluruhan, program ini menunjukkan konsep pemrograman modular serta penerapan ADT yang memisahkan antara data dan fungsinya, sehingga program menjadi lebih terstruktur dan mudah dikelola.

## Nomor 3
Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer


```cpp
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarPosisi(A, B, 1, 1);

    cout << "\nSetelah menukar elemen di posisi [1][1]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nNilai sebelum ditukar melalui pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "Nilai setelah ditukar melalui pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
```

Output
> ![Screenshot Unguided Nomor 3](P3output/Unguided3Nomor3.PNG)

Program ini dibuat untuk menunjukkan penggunaan array dua dimensi (2D) dan pointer dalam bahasa C++. Di dalamnya terdapat dua buah array 2D berukuran 3x3 yang menyimpan bilangan integer, serta dua pointer yang menunjuk ke variabel bertipe integer. Program juga menggunakan beberapa fungsi untuk menampilkan isi array, menukar isi antar array pada posisi tertentu, serta menukar nilai variabel melalui pointer.
Fungsi tampilArray() digunakan untuk menampilkan elemen-elemen array dalam bentuk tabel menggunakan dua perulangan bersarang. Fungsi tukarPosisi() berfungsi menukar nilai pada posisi tertentu antara dua array 2D, misalnya antara elemen A[1][1] dan B[1][1], dengan bantuan variabel sementara agar data tidak hilang saat penukaran. Selanjutnya, fungsi tukarPointer() digunakan untuk menukar nilai dua variabel integer melalui pointer dengan cara menukar nilai yang ditunjuk oleh kedua pointer tersebut.
Dalam fungsi main(), program menampilkan isi array sebelum dan sesudah penukaran agar terlihat perubahan datanya. Selain itu, program juga menampilkan hasil pertukaran nilai antara dua variabel x dan y menggunakan pointer. Dengan demikian, program ini memperlihatkan penerapan konsep dasar manipulasi array 2D dan pointer dalam C++, serta cara penggunaan fungsi untuk memecah tugas program menjadi bagian-bagian yang lebih terstruktur dan mudah dipahami.


## Referensi

1. Huda, A., Ardi, N., & Muabi, A. (2021). Pengantar coding berbasis C/C++. UNP PRESS. https://books.google.com/books?hl=id&lr=&id=G9dbEAAAQBAJ&oi=fnd&pg=PA129&dq=pemrograman+modular+c%2B%2B&ots=6eIIaNft7h&sig=ZKo25TGEsn8RMaSwHkno8LZHCZQ

2. Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146. https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4

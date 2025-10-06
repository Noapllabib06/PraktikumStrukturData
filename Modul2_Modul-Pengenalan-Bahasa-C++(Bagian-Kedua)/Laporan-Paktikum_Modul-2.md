# <h1 align="center">Laporan Praktikum Modul 2 <br>Pengenalan Bahasa C++ Bagian 2</h1>

<p align="center">Naufal Labib Asyidiq 103112400108</p>

## Dasar Teori

Dalam pemrograman C++, terdapat beberapa konsep dasar yang sering digunakan seperti array, pointer, dan fungsi. Array digunakan untuk menyimpan sekumpulan data dengan tipe yang sama, baik satu dimensi maupun dua dimensi (matriks). Dengan array, program bisa mengelola banyak data secara lebih efisien. Misalnya, pada matriks 3x3, data disusun dalam bentuk baris dan kolom, dan bisa dilakukan operasi seperti transpose untuk menukar posisi baris menjadi kolom. Selain itu, ada juga fungsi dan prosedur yang digunakan agar program lebih terstruktur. Fungsi mengembalikan nilai hasil proses, sedangkan prosedur hanya menjalankan perintah tanpa mengembalikan nilai.
Sementara itu, pointer dan call by reference digunakan untuk mengakses dan memodifikasi data langsung dari alamat memorinya. Pointer menyimpan alamat suatu variabel dan memungkinkan program mengubah nilai aslinya tanpa perlu menyalin data. Konsep ini juga digunakan saat menukar nilai dua variabel menggunakan alamat memori atau referensi. Dengan call by reference, variabel dikirim langsung ke fungsi menggunakan tanda &, sehingga perubahan yang terjadi di dalam fungsi akan memengaruhi nilai asli di luar fungsi. Konsep-konsep ini penting untuk memahami cara kerja memori, efisiensi program, dan komunikasi antar bagian dalam program C++.


## Guided

### Soal 1 Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int nilai[5] = {1,2,3,4,5};
    
    for (int i = 0; i < 5; ++i) {
        cout << "Element ke-"<< i << " = " << nilai[i] << endl;
    }

    return 0;
}
```

> ![Screenshot guided 1](P2output/Guided2Nomor1.png)

Penjelasan
Program ini merupakan contoh penggunaan array dan perulangan for di C++. Di dalam program, sebuah array bernama nilai berisi lima elemen yaitu 1 sampai 5. Melalui perulangan for, program menampilkan setiap elemen array satu per satu ke layar. Variabel i digunakan sebagai indeks untuk mengakses elemen ke-0 hingga ke-4 pada array. Setiap iterasi akan mencetak posisi elemen (Element ke-i) beserta nilainya. Setelah semua elemen ditampilkan, program selesai dijalankan.

### Soal 2 Array 2D

```cpp
#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

> ![Screenshot guided 2](P2output/Guided2Nomor2.png)

Penjelasan
Program ini merupakan contoh penggunaan array dua dimensi (matriks) di C++. Di dalam program, dibuat sebuah matriks berukuran 3x3 yang berisi angka 1 sampai 9. Dua perulangan bersarang (for) digunakan untuk menampilkan elemen-elemen matriks ke layar. Perulangan luar (i) mengatur baris, sedangkan perulangan dalam (j) mengatur kolom. Setiap elemen ditampilkan dengan spasi, dan setelah satu baris selesai dicetak, program menambahkan endl untuk pindah ke baris berikutnya. Hasilnya, matriks akan ditampilkan dalam bentuk tabel 3x3 di layar.

### Soal 3 Pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    int umur = 25;
    int *p_umur;
    
    p_umur = &umur;
    
    cout << "Nilai 'umur': " << umur << endl;
    cout << "Alamat memori 'umur': " << &umur << endl;
    cout << "Nilai 'p_umur' (alamat):" << p_umur << endl;
    cout << "Nilai yang diakses 'p_umur': " << *p_umur << endl;
    cout << "Alamat memori dari pointer 'p_umur' itu sendiri: " << &p_umur << endl;
    
    return 0;
}
```

> ![Screenshot guided 3](P2output/Guided2Nomor3.png)

Penjelasan
Program ini merupakan contoh penggunaan pointer di C++. Variabel umur diset dengan nilai 25, lalu dibuat pointer p_umur yang menyimpan alamat memori dari variabel umur menggunakan operator &. Ketika program dijalankan, ia menampilkan beberapa informasi: nilai asli umur, alamat memorinya, nilai yang disimpan di pointer (p_umur), serta nilai yang diakses melalui pointer menggunakan operator dereference (*p_umur). Selain itu, program juga menampilkan alamat memori tempat pointer p_umur itu sendiri disimpan. Program ini membantu memahami bagaimana pointer bekerja dalam mengakses dan mereferensikan data di memori.

### Soal 4 Array Pointer

```cpp
#include <iostream>
using namespace std;

int main(){
    int data[5] = {10,20,30,40,50};
    int *p_data = data;

    cout << "Mengakses elemen array cara normal: " << endl;

    for (int i = 0; i < 5; ++i){
        cout << "Nilai elemen ke-" << i << ": " << data[i] << endl;
    }

    cout << "Mengakses elemen array menggunakan pointer: " << endl;

    for (int i = 0; i < 5; ++i){
        cout << "Nilai elemen ke-" << i << ": " << *(p_data + i) << endl;
    }

    return 0;
}
```

> ![Screenshot guided 4](P2output/Guided2Nomor4.png)

Penjelasan
Program ini menunjukkan cara mengakses elemen array menggunakan pointer di C++. Pertama, array data berisi lima nilai yaitu 10, 20, 30, 40, dan 50. Pointer p_data kemudian diinisialisasi untuk menunjuk ke elemen pertama array tersebut. Program menampilkan dua cara mengakses isi array: yang pertama dengan cara biasa menggunakan indeks data[i], dan yang kedua menggunakan pointer dengan ekspresi *(p_data + i). Pada ekspresi ini, pointer bergerak ke elemen berikutnya dengan menambah nilai i, lalu operator * digunakan untuk mengambil nilai dari alamat tersebut. Hasilnya, kedua cara menghasilkan output yang sama, namun cara kedua memperlihatkan bagaimana pointer dapat digunakan untuk menjelajahi elemen-elemen array.

### Soal 5 String Pointer

```cpp
#include <iostream>
using namespace std;

int main() {
    char pesan_array[] = "Nasi Padang";
    char *pesan_pointer = "Ayam Bakar 23";

    cout << "String Array: " << pesan_array << endl;
    cout << "String Pointer: " << pesan_pointer << endl;

    // Mengubah karakter dalam array diperbolehkan
    pesan_array[0] = 'h';
    cout << "String Array setelah diubah: " << pesan_array << endl;

    // Pointer dapat diubah untuk menunjuk ke string lain
    pesan_pointer = "Sarinah";
    cout << "String Pointer setelah menunjuk ke string lain: " << pesan_pointer << endl;

    return 0;
}
```

> ![Screenshot guided 5](P2output/Guided2Nomor5.png)

Penjelasan
Program ini menunjukkan perbedaan antara string array dan string pointer di C++. Variabel pesan_array menyimpan string "Nasi Padang" sebagai array karakter yang dapat diubah isinya, sedangkan pesan_pointer menunjuk ke string literal "Ayam Bakar 23" yang hanya bisa dibaca. Program menampilkan kedua string tersebut, lalu mengubah karakter pertama pada pesan_array menjadi huruf kecil ‘h’, yang diperbolehkan karena array bersifat mutable. Selanjutnya, pointer pesan_pointer diarahkan untuk menunjuk ke string lain yaitu "Sarinah". Hasilnya menunjukkan bahwa isi array dapat diubah langsung, sedangkan pointer tidak bisa mengubah isi string literal, tetapi bisa diarahkan ke string lain.

### Soal 6 Function

```cpp
#include <iostream>
using namespace std;

int tambah(int a, int b)
{
    return a + b;
}

void tampilkanHasil(int a, int b, int hasil) {
    cout << "Hasil penjumlahan " << a << " + " << b << " adalah: " << hasil << endl;
}

int main() {
    int angka1 = 10;
    int angka2 = 5;

    int hasilJumlah = tambah(angka1, angka2);

    tampilkanHasil(angka1, angka2, hasilJumlah);

    return 0;
}
```

> ![Screenshot guided 6](P2output/Guided2Nomor6.png)

Penjelasan
Program ini merupakan contoh penggunaan fungsi dan prosedur di C++. Fungsi tambah(int a, int b) digunakan untuk menghitung hasil penjumlahan dua bilangan dan mengembalikan nilainya menggunakan return. Sementara itu, prosedur tampilkanHasil(int a, int b, int hasil) hanya menampilkan hasil penjumlahan tanpa mengembalikan nilai apa pun. Di dalam fungsi main(), dua variabel angka1 dan angka2 masing-masing bernilai 10 dan 5. Keduanya dikirim ke fungsi tambah() untuk dihitung, lalu hasilnya disimpan dalam variabel hasilJumlah. Setelah itu, prosedur tampilkanHasil() dipanggil untuk menampilkan hasil penjumlahan tersebut ke layar.

### Soal 7 Call By Pointer

```cpp
#include <iostream>
using namespace std;

void tukar(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukar(&a, &b);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;
    return 0;
}
```

> ![Screenshot guided 7](P2output/Guided2Nomor7.png)

Penjelasan
Program ini menunjukkan penggunaan pointer untuk menukar nilai dua variabel di C++. Prosedur tukar(int *px, int *py) menerima dua parameter berupa alamat memori dari variabel a dan b. Di dalam prosedur, nilai yang ditunjuk oleh pointer px dan py ditukar menggunakan variabel sementara temp. Pada fungsi main(), variabel a bernilai 10 dan b bernilai 20. Sebelum pertukaran, program menampilkan nilai awal keduanya. Setelah memanggil tukar(&a, &b), nilai a dan b tertukar karena prosedur bekerja langsung pada alamat memorinya. Hasil akhirnya menunjukkan a = 20 dan b = 10.

### Soal 8 Call By Reference

```cpp
#include <iostream>
using namespace std;

void tukar(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukar(a, b);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;
    return 0;
}
```

> ![Screenshot guided 8](P2output/Guided2Nomor8.png)

Penjelasan
Program ini merupakan contoh penggunaan call by reference untuk menukar nilai dua variabel di C++. Prosedur tukar(int &x, int &y) menggunakan parameter referensi (&), sehingga perubahan pada x dan y langsung memengaruhi variabel asli yang dikirim dari fungsi main(). Di dalam prosedur, nilai x disimpan sementara di variabel temp, kemudian x diisi dengan nilai y, dan y diisi dengan nilai temp, sehingga keduanya saling bertukar. Dalam fungsi main(), variabel a bernilai 10 dan b bernilai 20. Setelah memanggil tukar(a, b), nilai a dan b tertukar menjadi a = 20 dan b = 10.

## Unguided

### Soal 1

1. Buatlah sebuah program untuk melakukan transpose pada sebuah matriks persegi berukuran 3x3. Operasi transpose adalah mengubah baris menjadi kolom dan sebaliknya. Inisialisasi matriks awal di dalam kode, kemudian buat logika untuk melakukan transpose dan simpan hasilnya ke dalam matriks baru. Terakhir, tampilkan matriks awal dan matriks hasil transpose.

Contoh Output:

Matriks Awal:
1 2 3
4 5 6
7 8 9

Matriks Hasil Transpose:
1 4 7
2 5 8
3 6 9

```cpp
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriksTranspose[3][3];

    cout << "Matriks Awal:" << endl;
    tampilkanMatriks(matriksAwal);
    transposeMatriks(matriksAwal, matriksTranspose);

    cout << "\nMatriks Hasil Transpose:" << endl;
    tampilkanMatriks(matriksTranspose);

    return 0;
}
```

> Output
> ![Screenshot unguided Nomor 1](P2output/Laprak2Nomor1.png)

Penjelasan code
Program ini berfungsi untuk melakukan transpose matriks 3x3 menggunakan bahasa C++. Di dalamnya terdapat dua prosedur: tampilkanMatriks() untuk menampilkan isi matriks, dan transposeMatriks() untuk menukar posisi baris dan kolom. Di fungsi main(), matriks awal berisi nilai 1–9 diinisialisasi, lalu hasil transpose disimpan pada matriks baru bernama matriksTranspose. Proses transpose dilakukan dengan menukar indeks menggunakan hasil[j][i] = asal[i][j], sehingga baris berubah menjadi kolom dan sebaliknya. Terakhir, hasilnya ditampilkan untuk menunjukkan perbedaan antara matriks awal dan matriks hasil transpose.

### Soal 2

2. Buatlah program yang menunjukkan penggunaan call by reference. Buat sebuah prosedur bernama kuadratkan yang menerima satu parameter integer secara referensi (&). Prosedur ini akan mengubah nilai asli variabel yang dilewatkan dengan nilai kuadratnya. Tampilkan nilai variabel di main() sebelum dan sesudah memanggil prosedur untuk membuktikan perubahannya. 

Contoh Output:

Nilai awal: 5
Nilai setelah dikuadratkan: 25

```cpp
#include <iostream>
using namespace std;


void kuadratkan(int &x) {
    x = x * x;
}

int main() {
    int nilai = 5;
    cout << "Nilai awal: " << nilai << endl;


    kuadratkan(nilai);

    cout << "Nilai setelah dikuadratkan: " << nilai << endl;

    return 0;
}
```

> Output
> ![Screenshot unguided Nomor 2](P2output/Laprak2Nomor2.png)

Penjelasan code
Program ini merupakan contoh penggunaan call by reference di C++ untuk mengubah nilai variabel secara langsung melalui prosedur. Variabel nilai diinisialisasi dengan angka 5, lalu ditampilkan sebagai nilai awal. Prosedur kuadratkan(int &x) menggunakan parameter referensi (&), sehingga ketika dipanggil dengan kuadratkan(nilai), perubahan pada x juga memengaruhi variabel asli nilai. Di dalam prosedur, nilai dikalikan dengan dirinya sendiri (x = x * x), menghasilkan nilai kuadratnya. Setelah prosedur dijalankan, program menampilkan hasilnya, yaitu nilai 25 sebagai hasil kuadrat dari 5.

## Referensi

1.
2.
3.

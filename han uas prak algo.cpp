#include <iostream>
#include <string>

// Inisialisasi koleksi buku
int jumlahBuku = 5;
using namespace std;

const int Max_Buku = 50;

// Array
string judul[Max_Buku];
string penulis[Max_Buku];
string kodeBuku[Max_Buku];
bool tersedia[Max_Buku];
int tahunTerbit[Max_Buku];

// Fungsi untuk menambahkan buku ke koleksi
void tambahBuku(string judul, string penulis, int tahun, string kode) {
    if (jumlahBuku < Max_Buku) {
        ::judul[jumlahBuku] = judul;
        ::penulis[jumlahBuku] = penulis;
        ::tahunTerbit[jumlahBuku] = tahun;
        ::kodeBuku[jumlahBuku] = kode;
        ::tersedia[jumlahBuku] = true;
        jumlahBuku++;
        cout << "Buku berhasil ditambahkan ke koleksi." << endl;
    } else {
        cout << "Koleksi buku penuh." << endl;
    }
}

// Fungsi untuk mencari buku berdasarkan kode buku
int cariBuku(string kode) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (::kodeBuku[i] == kode) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk meminjamkan buku
void pinjamBuku(string kode, string peminjam) {
    int index = cariBuku(kode);
    if (index != -1) {
        if (::tersedia[index]) {
            ::tersedia[index] = false;
            cout << "Buku dipinjamkan kepada " << peminjam << endl;
        } else {
            cout << "Buku sudah dipinjam." << endl;
        }
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku(string kode) {
    int index = cariBuku(kode);
    if (index != -1) {
        if (!::tersedia[index]) {
            ::tersedia[index] = true;
            cout << "Buku berhasil dikembalikan." << endl;
        } else {
            cout << "Buku sudah tersedia." << endl;
        }
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;

    do {
    	cout << "\t\t\t\t\t\t =========================================" << endl;
        cout << "\t\t\t\t\t\t =========== Jatukrama Library ===========" << endl;
        cout << "\t\t\t\t\t\t =========================================" << endl;
        cout << "1. Menambah Buku" << endl;
        cout << "2. Mencari Buku" << endl;
        cout << "3. Meminjam Buku" << endl;
        cout << "4. Mengembalikan Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string j, p, k;
                int t;
                cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, j);
                cout << "Penulis: ";
                getline(cin, p);
                cout << "Tahun Terbit: ";
                cin >> t;
                cout << "Kode Buku: ";
                cin >> k;
                tambahBuku(j, p, t, k);
                break;
            }
            case 2: {
                string k;
                cout << "Kode Buku: ";
                cin >> k;
                int index = cariBuku(k);
                if (index != -1) {
                    cout << "Buku ditemukan:" << endl;
                    cout << "Judul: " << ::judul[index] << endl;
                    cout << "Penulis: " << ::penulis[index] << endl;
                    cout << "Tahun Terbit: " << ::tahunTerbit[index] << endl;
                    cout << "Kode: " << ::kodeBuku[index] << endl;
                    if (::tersedia[index]) {
                        cout << "Status: Tersedia" << endl;
                    } else {
                        cout << "Status: Dipinjam" << endl;
                    }
                } else {
                    cout << "Buku tidak ditemukan." << endl;
                }
                break;
            }
            case 3: {
                string k, p;
                cout << "Kode Buku: ";
                cin >> k;
                cout << "Nama Peminjam: ";
                cin.ignore();
                getline(cin, p);
                pinjamBuku(k, p);
                break;
            }
            case 4: {
                string k;
                cout << "Kode Buku: ";
                cin >> k;
                kembalikanBuku(k);
                break;
            }
            case 5:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}


#include <iostream>
#include <thread>  // Untuk fungsi sleep
#include <chrono>  // Untuk durasi sleep

using namespace std;

const char *daftar[5] = {
    "Borland C++", "Algoritma", "Matematika Diskrit", "Kalkulus", "Komputer Aplikasi"
};

void menu_utama();
void pemilihan_berulang();
void anggota();
void pinjam_buku();
void pengembalian_buku();
void keluar_program();

// Fungsi untuk menampilkan loading sementara
void loading() {
    cout << "\n\t\tPlease wait:\n\n";
    cout << "\t\tLoading:";
    for (int i = 0; i < 20; i++) {
        cout << "*";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl;
    system("cls || clear");
}

// Fungsi untuk menampilkan menu utama
void menu_utama() {
    system("cls || clear");
    loading();
    cout << "==================================================" << endl;
    cout << "|\tPROGRAM PERPUSTAKAAN C++\t\t|" << endl;
    cout << "==================================================" << endl;
    cout << "Selamat datang di perpustakaan kami!" << endl;
    cout << "\nPilihan Menu:\n";
    cout << "\t1. Anggota\n";
    cout << "\t2. Pinjam Buku\n";
    cout << "\t3. Pengembalian Buku\n";
    cout << "\t4. Tutup Program\n\n";
    int pilihan;
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
    cout << endl;

    switch (pilihan) {
        case 1:
            anggota();
            break;
        case 2:
            pinjam_buku();
            break;
        case 3:
            pengembalian_buku();
            break;
        case 4:
            keluar_program();
            break;
        default:
            cout << "\tTolong Pilih Salah Satu dan Ulangi Kembali!" << endl;
            loading();
            menu_utama();
            break;
    }
}

// Fungsi untuk menampilkan data anggota
void anggota() {
    system("cls || clear");
    cout << "======================================================" << endl;
    cout << "\t\t\t ANGGOTA \t\t" << endl;
    cout << "======================================================" << endl;
    cout << "\tNAMA:\t\t\tNIM:" << endl;
    cout << "\t1. Aulia\t\t11111***" << endl;
    cout << "\t2. Prayoga\t\t11111***" << endl;
    cout << "\t3. Dewa\t\t11111***" << endl;
    cout << "\t4. Mayang\t\t11111***" << endl;
    cout << "\t5. Damar\t\t11111***" << endl;
    pemilihan_berulang();
}

// Fungsi untuk meminjam buku
void pinjam_buku() {
    system("cls || clear");
    cout << "======================================================" << endl;
    cout << "\t\t\t PINJAM BUKU \t\t" << endl;
    cout << "======================================================" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\t" << (i + 1) << "\t" << daftar[i] << endl;
    }

    cout << "\nNama : ";
    string nama;
    cin >> nama;

    unsigned int tanggal;
    cout << "Masukkan tanggal peminjaman (1-31): ";
    cin >> tanggal;

    if (tanggal < 1 || tanggal > 31) {
        cout << "Tanggal tidak valid!" << endl;
        return;
    }

    int jumlah;
    cout << "Jumlah buku yang ingin dipinjam: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        int kode;
        cout << "Inputkan kode buku: ";
        cin >> kode;

        if (kode >= 1 && kode <= 5) {
            cout << "Anda telah meminjam buku: " << daftar[kode - 1] << endl;
        } else {
            cout << "Kode buku tidak valid!" << endl;
        }
    }

    pemilihan_berulang();
}

// Fungsi untuk pengembalian buku
void pengembalian_buku() {
    system("cls || clear");
    cout << "==========================================================" << endl;
    cout << "\t\tPENGEMBALIAN BUKU\t\t" << endl;
    cout << "==========================================================" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\t" << (i + 1) << "\t" << daftar[i] << endl;
    }

    cout << "\nNama : ";
    string nama;
    cin >> nama;

    int jumlah;
    cout << "Jumlah buku yang ingin dikembalikan: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        int kode;
        cout << "Inputkan kode buku: ";
        cin >> kode;

        if (kode >= 1 && kode <= 5) {
            cout << "Anda telah mengembalikan buku: " << daftar[kode - 1] << endl;
        } else {
            cout << "Kode buku tidak valid!" << endl;
        }
    }

    pemilihan_berulang();
}

// Fungsi pemilihan berulang
void pemilihan_berulang() {
    char pilih;
    cout << "\nInputkan [Y] untuk kembali ke menu utama atau [N] untuk keluar: ";
    cin >> pilih;

    if (pilih == 'Y' || pilih == 'y') {
        menu_utama();
    } else if (pilih == 'N' || pilih == 'n') {
        keluar_program();
    } else {
        cout << "Input tidak valid! Silahkan ulangi.\n";
        pemilihan_berulang();
    }
}

// Fungsi untuk keluar program
void keluar_program() {
    system("cls || clear");
    cout << "===========================================================" << endl;
    cout << "\t\tPROGRAM PERPUSTAKAAN C++\t\t" << endl;
    cout << "===========================================================" << endl;
    cout << "\tTerima Kasih Atas Kunjungan Anda!" << endl;
    cout << "===========================================================" << endl;
    exit(0);
}

// Fungsi utama
int main() {
    menu_utama();
    return 0;
}

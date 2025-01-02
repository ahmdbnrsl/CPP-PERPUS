#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// Array daftar buku
string daftar[5] = {"Borland C++", "Algoritma", "Matematika Diskrit", "Kalkulus", "Komputer Aplikasi"};

// Fungsi deklarasi
void menu_utama();
void anggota();
void pinjam_buku();
void pengembalian_buku();
void keluar_program();
void pemilihan_berulang();

// Fungsi untuk menampilkan loading
void loading()
{
    cout << "\n\tPlease wait...\n\n";
    for (int i = 0; i < 20; i++)
    {
        cout << ".";
        Sleep(100);
    }
    cout << endl;
}

// Fungsi menu utama
void menu_utama()
{
    system("cls");
    loading();

    cout << "\t============================|\n";
    cout << "\t|   PROGRAM PERPUSTAKAAN C++   |\n";
    cout << "\t============================|\n";
    cout << "\n\tPilihan Menu: \n";
    cout << "\t1. Anggota\n";
    cout << "\t2. Pinjam Buku\n";
    cout << "\t3. Pengembalian Buku\n";
    cout << "\t4. Tutup Program\n";

    int pilihan;
    cout << "\n\tMasukkan Pilihan: ";
    cin >> pilihan;

    switch (pilihan)
    {
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
        cout << "\n\tPilihan tidak valid! Ulangi kembali.\n";
        menu_utama();
        break;
    }
}

// Fungsi anggota
void anggota()
{
    system("cls");
    cout << "\t============================\n";
    cout << "\t\tANGGOTA\n";
    cout << "\t============================\n";
    cout << "\t1. Aulia     (111111***)\n";
    cout << "\t2. Prayoga   (111111***)\n";
    cout << "\t3. Dewa      (111111***)\n";
    cout << "\t4. Mayang    (111111***)\n";
    cout << "\t5. Damar     (111111***)\n";

    pemilihan_berulang();
}

// Fungsi pinjam buku
void pinjam_buku()
{
    system("cls");
    cout << "\t====================\n";
    cout << "\t\tPINJAM BUKU\n";
    cout << "\t====================\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << (i + 1) << ". " << daftar[i] << "\n";
    }

    string nama;
    int tanggal, jumlah, kode;

    cout << "\n\tNama: ";
    cin >> nama;
    cout << "\tMasukkan tanggal pinjam (1-31): ";
    cin >> tanggal;

    if (tanggal < 1 || tanggal > 31)
    {
        cout << "\tTanggal salah!\n";
        pemilihan_berulang();
        return;
    }

    cout << "\tJumlah buku yang ingin dipinjam: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        cout << "\n\tInputkan kode buku: ";
        cin >> kode;
        if (kode >= 1 && kode <= 5)
        {
            cout << "\tAnda meminjam buku: " << daftar[kode - 1] << "\n";
        }
        else
        {
            cout << "\tKode buku tidak valid.\n";
        }
    }

    cout << "\tTanggal kembali: " << ((tanggal + 7) % 31) << "\n";
    pemilihan_berulang();
}

// Fungsi pengembalian buku
void pengembalian_buku()
{
    system("cls");
    cout << "\t====================\n";
    cout << "\t\tPENGEMBALIAN BUKU\n";
    cout << "\t====================\n";

    string nama;
    int jumlah, kode;

    cout << "\n\tNama: ";
    cin >> nama;
    cout << "\tJumlah buku yang ingin dikembalikan: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        cout << "\n\tInputkan kode buku: ";
        cin >> kode;
        if (kode >= 1 && kode <= 5)
        {
            cout << "\tAnda mengembalikan buku: " << daftar[kode - 1] << "\n";
        }
        else
        {
            cout << "\tKode buku tidak valid.\n";
        }
    }

    pemilihan_berulang();
}

// Fungsi untuk keluar program
void keluar_program()
{
    system("cls");
    cout << "\n\tTerima kasih atas kunjungan Anda!\n";
    exit(0);
}

// Fungsi untuk memilih kembali
void pemilihan_berulang()
{
    char pilih;
    cout << "\n\tKembali ke menu utama? (Y/N): ";
    cin >> pilih;

    if (pilih == 'Y' || pilih == 'y')
    {
        menu_utama();
    }
    else
    {
        keluar_program();
    }
}

// Fungsi utama
int main()
{
    menu_utama();
    return 0;
}

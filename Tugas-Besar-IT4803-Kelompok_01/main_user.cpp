#include "main_user.h"
#include "list_menu_relasi.h"
#include "list_pelanggan.h"

#include <iostream>

using namespace std;

void main_user(ListMenu &menuList, ListPelanggan &pelangganList){
    int pilihan;
    do {
        cout << "\n===== MENU STUDI KASUS =====\n";
        cout << "1. Tambah Pesanan (Relasi Menu - Pelanggan)\n";
        cout << "2. Tampilkan Menu dan Pelanggan\n";
        cout << "3. Tampilkan Menu berdasarkan Pelanggan\n";
        cout << "4. Tampilkan Hasil Komputasi\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int idMenu, idPelanggan;
            cout << "ID Menu       : ";
            cin >> idMenu;
            cout << "ID Pelanggan  : ";
            cin >> idPelanggan;

            tambahRelasiMenuPelanggan(menuList, pelangganList, idMenu, idPelanggan);
        }
        else if (pilihan == 2) {
            address_menu M = menuList.first;
            if (M == nullptr) {
                cout << "Belum ada menu." << endl;
            }
            while (M != nullptr) {
                cout << "\nMenu: " << M->info.nama_menu
                     << " (ID: " << M->info.id_menu << ")\n";
                showAllRelasi(M->first_relasi);
                M = M->next;
            }
        }
        else if (pilihan == 3) {
            int id;
            cout << "ID Pelanggan: ";
            cin >> id;

            address_menu M = menuList.first;
            bool found = false;

            while (M != nullptr) {
                address_relasi R = M->first_relasi;
                while (R != nullptr) {
                    if (R->info.id_pelanggan == id) {
                        cout << "Pelanggan memesan menu: "
                             << M->info.nama_menu << endl;
                        found = true;
                        break;
                    }
                    R = R->next;
                }
                M = M->next;
            }

            if (!found) {
                cout << "Pelanggan belum memiliki pesanan." << endl;
            }
        }
        else if (pilihan == 4) {
            cout << "\n--- Jumlah Pelanggan per Menu ---\n";
            tampilkanJumlahPelangganPerMenu(menuList);

            int tanpaRelasi = hitungPelangganTanpaRelasi(pelangganList, menuList);
            cout << "\nJumlah pelanggan tanpa relasi: "
                 << tanpaRelasi << endl;
        }

    } while (pilihan != 0);
}

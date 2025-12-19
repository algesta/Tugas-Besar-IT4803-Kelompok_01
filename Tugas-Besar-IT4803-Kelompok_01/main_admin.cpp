#include "main_admin.h"
#include "list_menu_relasi.h"
#include "list_pelanggan.h"

#include <iostream>

using namespace std;

void main_admin(ListMenu &menuList, ListPelanggan &pelangganList){
    int pilihan;
    do {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Insert Menu\n";
        cout << "2. Delete Menu\n";
        cout << "3. Insert Pelanggan\n";
        cout << "4. Delete Pelanggan\n";
        cout << "5. Tampilkan Semua Menu\n";
        cout << "6. Tampilkan Semua Pelanggan\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            InfoTypeMenu info;
            cout << "\nID Menu   : ";
            cin >> info.id_menu;
            cin.ignore();
            cout << "Nama Menu : ";
            getline(cin, info.nama_menu);
            cout << "Harga     : ";
            cin >> info.harga_menu;

            insertMenuIfUnique(menuList, info);
        }
        else if (pilihan == 2) {
            int id;
            cout << "ID Menu yang akan dihapus: ";
            cin >> id;

            deleteMenuIfNoRelation(menuList, id);
        }
        else if (pilihan == 3) {
            InfoTypePelanggan info;
            cout << "ID Pelanggan   : ";
            cin >> info.id_pelanggan;
            cin.ignore();
            cout << "Nama Pelanggan : ";
            getline(cin, info.nama_pelanggan);
            cout << "Jenis Member   : ";
            getline(cin, info.jenis_member);
            cout << "Diskon         : ";
            cin >> info.potongan_member;

            insertPelangganIfUnique(pelangganList, info);
        }
        else if (pilihan == 4) {
            int id;
            cout << "ID Pelanggan yang akan dihapus: ";
            cin >> id;

            deletePelangganIfNoRelation(pelangganList, menuList, id);
        }
        else if (pilihan == 5) {
            showAllMenu(menuList);
        }
        else if (pilihan == 6) {
            showAllPelanggan(pelangganList);
        }

    } while (pilihan != 0);
}

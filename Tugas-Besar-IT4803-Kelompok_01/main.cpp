#include "main_admin.h"
#include "main_user.h"
#include <iostream>
using namespace std;

int main(){
    ListMenu menuList;
    ListPelanggan pelangganList;

    menuList.first = nullptr;
    pelangganList.first = nullptr;
    pelangganList.last = nullptr;

    int pilihan;
    do {
        cout << "\n===== PROGRAM UTAMA =====\n";
        cout << "1. Menu Admin\n";
        cout << "2. Menu Studi Kasus\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            main_admin(menuList, pelangganList);
        }
        else if (pilihan == 2) {
            main_user(menuList, pelangganList);
        }
    } while (pilihan != 0);

    cout << "Program selesai.\n";
    return 0;
}

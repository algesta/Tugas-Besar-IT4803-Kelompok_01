#include "list_menu_relasi.h"
#include "list_pesanan.h"

address_menu findMenu(ListMenu L, string id_menu){
    address_menu P= L.first;
    while (P != nullptr){
        if (P->info.id_menu == id_menu){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllMenu(ListMenu L){
    if (L.first == nullptr){
        cout << "--- List Menu Kosong ---" << endl;
        return;
    }
    address_menu P = L.first;
    int i = 1;
    cout << "===== DAFTAR MENU =====" << endl;
    while (P != nullptr){
        cout << i << ". ID: " << P->info.id_menu << " | Nama: " << P->info.nama_menu << " | Harga: Rp " << P->info.harga << endl;
        P = P->next;
        i++;
    }
    cout << "=======================" << endl;
}

void insertLastMenu(ListMenu &L, address_menu P){
    if (L.first == nullptr) {
        L.first = P;
        cout << "SUCCESS: Menu " << P->info.nama_menu << " ditambahkan di akhir list (sebagai elemen pertama)." << endl;
        return;
    }

    address_menu last = L.first;
    while (last->next != nullptr){
        last = last->next;
    }
    last->next = P;
    cout << "SUCCESS: Menu " << P->info.nama_menu << " ditambahkan di akhir list." << endl;
}

void deleteFirstMenu(ListMenu &L, address_menu &P){
    P = L.first;
    if (L.first != nullptr){
        L.first = P->next;
        P->next = nullptr;
        cout << "SUCCESS: Menu ID " << P->info.id_menu << " dihapus dari awal list." << endl;
    } else {
        cout << "ERROR: List Menu kosong. Delete First gagal." << endl;
        P = nullptr;
    }
}

void deleteAfterMenu(ListMenu &L, address_menu prec, address_menu &P) {
    if (prec != nullptr && prec->next != nullptr){
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
        cout << "SUCCESS: Menu ID " << P->info.id_menu << " dihapus setelah " << prec->info.id_menu << "." << endl;
    } else {
        P = nullptr;
        cout << "ERROR: Predecessor tidak valid atau tidak ada elemen setelahnya. Delete After gagal." << endl;
    }
}

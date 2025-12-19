#include "list_pelanggan.h"
#include "list_menu_relasi.h"

#include <iostream>

using namespace std;

bool isEmptyPelanggan(ListPelanggan L){ return L.first == nullptr; }

address_pelanggan findPelangganById(ListPelanggan L, int id_pelanggan){
    address_pelanggan P = L.first;
    while (P != nullptr){
        if (P->info.id_pelanggan == id_pelanggan){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

address_pelanggan findPelangganByName(ListPelanggan L, string nama_pelanggan){
    address_pelanggan P = L.first;
    while (P != nullptr){
        if( P->info.nama_pelanggan == nama_pelanggan){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllPelanggan(ListPelanggan L){
    if (L.first == nullptr){
        cout << "\nList pelanggan kosong.\n";
        return;
    }
    address_pelanggan P = L.first;
    while (P != nullptr){
        cout << "ID         : " << P->info.id_pelanggan << endl;
        cout << "Nama       : " << P->info.nama_pelanggan << endl;
        cout << "Member     : " << P->info.jenis_member << endl;
        cout << "Diskon     : " << P->info.potongan_member << endl;
        cout << "----------------------------------------" << endl;
        P = P->next;
    }
}

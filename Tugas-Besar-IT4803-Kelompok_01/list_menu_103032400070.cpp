#include "list_menu_relasi.h"

#include <iostream>

using namespace std;

address_menu findMenuById(ListMenu L, int id_menu){
    address_menu P = L.first;
    while (P){
        if(P->info.id_menu == id_menu) return P;
        P = P->next;
    }
    return nullptr;
}

address_menu findMenuByName(ListMenu L, string nama_menu){
    address_menu P = L.first;
    while (P != nullptr){
        if (P->info.nama_menu == nama_menu){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

address_relasi findRelationById(address_relasi first_relasi, int id_pelanggan, int id_menu){
    address_relasi R = first_relasi;
    while (R != nullptr){
        if (R->info.id_pelanggan == id_pelanggan && R->info.id_menu == id_menu){
            return R;
        }
        R = R->next;
    }
    return nullptr;
}


void showAllMenu(ListMenu L){
    address_menu M = L.first;
    if (M == nullptr){
        cout << "\nMenu kosong.\n";
        return;
    }
    while (M != nullptr){
        cout << "ID: " << M->info.id_menu
             << ", Nama: " << M->info.nama_menu
             << ", Harga: " << M->info.harga_menu << endl;
        M = M->next;
    }
}

void showAllRelasi(address_relasi first_relasi){
    if (first_relasi == nullptr){
        cout << "  Tidak ada pelanggan.\n";
        return;
    }
    address_relasi R = first_relasi;

    while (R){
        cout << "  - " << R->info.nama_pelanggan << " (ID: " << R->info.id_pelanggan << ")\n";
        R = R->next;
    }
}

bool tambahRelasiMenuPelanggan(ListMenu &menuList, ListPelanggan &pelangganList, int id_menu, int id_pelanggan){
    address_menu M = findMenuById(menuList, id_menu);
    address_pelanggan P = findPelangganById(pelangganList, id_pelanggan);
    if (M == nullptr || P == nullptr){
        cout << "Menu atau pelanggan tidak ditemukan.\n";
        return false;
    }
    address_relasi R = M->first_relasi;

    while (R != nullptr){
        if (R->info.id_pelanggan == id_pelanggan){
            cout << "Relasi sudah ada.\n";
            return false;
        }
        R = R->next;
    }

    InfoTypeRelasi info;
    info.id_menu = id_menu;
    info.id_pelanggan = id_pelanggan;
    info.nama_pelanggan = P->info.nama_pelanggan;

    address_relasi newRelasi = allocateRelasi(info);
    insertLastRelasi(M->first_relasi, newRelasi);
    return true;
}

void tampilkanJumlahPelangganPerMenu(const ListMenu &L){
    address_menu M = L.first;
    while   (M != nullptr){
        int jumlah = 0;
        address_relasi R = M->first_relasi;
        while (R != nullptr){
            jumlah++;
            R = R->next;
        }
        cout << "Menu " << M->info.nama_menu << " memiliki " << jumlah << " pelanggan.\n";
        M = M->next;
    }
}

int hitungPelangganTanpaRelasi(const ListPelanggan &LP, const ListMenu &LM){
    int count = 0;
    address_pelanggan P = LP.first;
    while (P != nullptr){
        bool punyaRelasi = false;
        address_menu M = LM.first;
        while (M != nullptr && !punyaRelasi){
            address_relasi R = M->first_relasi;
            while (R != nullptr){
                if (R->info.id_pelanggan == P->info.id_pelanggan){
                    punyaRelasi = true;
                    break;
                }
                R = R->next;
            }
            M = M->next;
        }
        if (!punyaRelasi){
            count++;
        }
        P = P->next;
    }
    return count;
}

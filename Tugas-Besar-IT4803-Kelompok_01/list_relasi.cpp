#include "list_relasi.h"
#include "list_menu.h"
#include "list_pesanan.h"

address_relasi allocateRelasi(address_pesanan child){
    address_relasi R = new ElementRelasi;

    R->child = child;

    R->next = nullptr;
    R->prev = nullptr;

    return R;
}

void insertRelasi(address_menu &p_menu, address_relasi R){
    if (p_menu == nullptr){
        cout << "Error: Parent Menu tidak valid." << endl;
        return;
    }
    if (p_menu->first_relasi == nullptr){
        p_menu->first_relasi = R;
    }else{
        R->next = p_menu->first_relasi;
        p_menu->first_relasi->prev = R;
        p_menu->first_relasi = R;
    }
}

address_relasi findRelasi(address_menu p_menu, string id_pesanan){
    if (p_menu == nullptr){
        return nullptr;
    }
    address_relasi R = p_menu->first_relasi;

    while (R != nullptr){
        if (R->child->info.id_pesanan == id_pesanan){
            return R;
        }
        R = R->next;
    }

    return nullptr;
}

void deleteRelasi(address_menu &p_menu, address_relasi &p_relasi){
    if (p_menu == nullptr || p_relasi == nullptr){
        return;
    }
    if (p_relasi == p_menu->first_relasi){
        if (p_relasi->next != nullptr){
            p_menu->first_relasi = p_relasi->next;
            p_relasi->next->prev = nullptr;
        }else{
            p_menu->first_relasi = nullptr;
        }
    }else if (p_relasi->next == nullptr){
        p_relasi->prev->next = nullptr;
    }else{
        p_relasi->prev->next = p_relasi->next;
        p_relasi->next->prev = p_relasi->prev;
    }
    p_relasi->next = nullptr;
    p_relasi->prev = nullptr;
}

int countRelasiDiMenu(address_menu p_menu){
    if (p_menu == nullptr){
        return 0;
    }
    int count = 0;

    address_relasi R = p_menu->first_relasi;

    while (R != nullptr){
        count++;
        R = R->next;
    }

    return count;
}


void showRelasiMenu(address_menu p_menu){
    if (p_menu == nullptr || p_menu->first_relasi == nullptr){
        cout << " (Tidak terhubung ke Pesanan mana pun)" << endl;
        return;
    }
    cout << " ->Dipilih dalam Pesanan {" << countRelasiDiMenu(p_menu) << " total relasi):"  << endl;

    address_relasi R = p_menu->first_relasi;

    while (R != nullptr){
        address_pesanan p_pesanan = R->child;

        cout << "   - ID Pesanan: " << p_pesanan->info.id_pesanan << " | Pelanggan: " << p_pesanan->info.nama_pelanggan << " | Status: " << p_pesanan->info.status_pesanan << endl;

        R = R->next;
    }
}

void editRelasiTotal(ListMenu &L_menu, ListPesanan &L_pesanan, string id_menu, string id_pesanan_lama, string id_pesanan_baru){
    address_menu p_menu = findMenu(L_menu, id_menu);

    if (p_menu == nullptr){
        cout << "Error: Menu dengan ID " << id_menu << " tidak ditemukan." << endl;
        return;
    }
    address_pesanan p_baru = findPesanan(L_pesanan, id_pesanan_lama);

    if (p_baru == nullptr){
        cout << "Error: pesanan baru (ID " << id_pesanan_baru << ") tidak ditemukan." << endl;
        return;
    }
    address_relasi R_edit = findRelasi(p_menu, id_pesanan_lama);

    if (R_edit != nullptr){
        R_edit->child = p_baru;

        cout << "SUCCESS: Relasi Menu " << id_menu << " di-update. Pesanan lama (" << id_pesanan_lama << ") diganti menjadi Pesanan baru (" << id_pesanan_baru << ")." << endl;
    }else{
        cout << "WARNING: Relasi antara Menu " << id_menu << " dan Pesanan " << id_pesanan_lama << " tidak ditemukan." << endl;
    }
}

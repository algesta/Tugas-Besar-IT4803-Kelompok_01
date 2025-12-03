#include "list_pesanan.h"

void insertLastPesanan(ListPesanan &L, address_pesanan p) {
    if (isEmptyPesanan(L)) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        p->prev = L.tail;
        L.tail = p;
    }
}

void deleteLastPesanan(ListPesanan &L, address_pesanan &p) {
    if (isEmptyPesanan(L)) {
        p = nullptr;
        return;
    }

    p = L.tail;

    if (L.head == L.tail) {
        L.head = nullptr;
        L.tail = nullptr;
    } else {
        L.tail = p->prev;
        L.tail->next = nullptr;
        p->prev = nullptr;
    }
}

address_pesanan findPesanan(ListPesanan L, string id_pesanan) {
    address_pesanan p = L.head;

    while (p != nullptr) {
        if (p->info.id_pesanan == id_pesanan) {
            return p;
        }
        p = p->next;
    }

    return nullptr;
}

void showAllPesanan(ListPesanan L) {
    if (isEmptyPesanan(L)) {
        cout << "List Pesanan kosong." << endl;
        return;
    }

    address_pesanan p = L.head;
    int count = 1;

    cout << "===== DAFTAR SEMUA PESANAN =====" << endl;
    while (p != nullptr) {
        cout << count << ". ID Pesanan: " << p->info.id_pesanan << endl;
        cout << "   Nama Pelanggan: " << p->info.nama_pelanggan << endl;
        cout << "   Total Harga: Rp " << p->info.total_harga << endl;
        p = p->next;
        count++;
    }
    cout << "================================" << endl;
}

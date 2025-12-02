#ifndef LIST_RELASI_103032400065_H_INCLUDED
#define LIST_RELASI_103032400065_H_INCLUDED

// Wajib meng-include header List Pesanan Anda, karena Relasi akan menunjuk ke Node Pesanan
#include "list_pesanan_103032400065.h"

// --- 1. Deklarasi Tipe Data Pointer dan Node Relasi ---
typedef struct ElementRelasi *address_relasi;

// ElementRelasi adalah node SLL yang menyimpan pointer ke List Child (Pesanan)
struct ElementRelasi {
    // PENTING: Pointer ke List Child (DLL Pesanan)
    address_pesanan child;

    // Pointer next untuk SLL Relasi
    address_relasi next;
};

// --- 2. Deklarasi Fungsi Dasar Relasi ---
address_relasi allocateRelasi_103032400065(address_pesanan P);
// Fungsi ini membuat node relasi baru yang menunjuk ke node Pesanan (P)

// Fungsi untuk menghubungkan Relasi ke List Parent (akan diimplementasikan di list_menu.cpp nanti)
// address_relasi findRelasi_103032400065(ListMenu L, address_pesanan P);
// ... dan seterusnya

#endif // LIST_RELASI_103032400065_H_INCLUDED

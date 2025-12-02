#include "list_relasi_103032400065.h"
// Wajib menyertakan file header Relasi Anda.

// Implementasi fungsi dasar Relasi (PIC Bersama)

// --- 1. Fungsi allocateRelasi (Alokasi Node Relasi Baru) ---
// Tujuan: Membuat node baru yang akan disimpan di List Parent (Menu).
// Node ini menyimpan pointer ke List Child (Pesanan).

address_relasi allocateRelasi_103032400065(address_pesanan P) {
    // P adalah address_pesanan (node Pesanan/Child) yang akan dihubungkan.

    // Alokasikan memori untuk elemen Relasi baru
    address_relasi R = new ElementRelasi;

    // Set pointer child Relasi agar menunjuk ke node Pesanan (P)
    R->child = P;

    // Inisialisasi pointer next (karena Relasi ini adalah SLL di dalam node Parent)
    R->next = NULL;

    return R;
}

/* Setelah ini, Anda dan rekan Anda akan menulis fungsi lain di file ini,
   terutama fungsi untuk INSERT dan DELETE Relasi, contoh:

// Fungsi Insert:
// void insertRelasiFirst_103032400065(address_relasi &first_relasi_parent, address_relasi R);
// Fungsi Delete:
// void deleteRelasi_103032400065(address_relasi &first_relasi_parent, address_relasi &R);

*/

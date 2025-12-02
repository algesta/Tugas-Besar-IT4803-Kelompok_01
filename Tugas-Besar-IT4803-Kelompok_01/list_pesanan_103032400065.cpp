#include "list_pesanan_103032400065.h"
// Wajib menyertakan file header yang berisi deklarasi struct dan prototype fungsi.

// --- 1. Fungsi createListPesanan (Inisialisasi List Kosong) ---
// Tujuan: Membuat list baru dengan menginisialisasi head dan tail menjadi NULL.
void createListPesanan_103032400065(ListPesanan &L) {
    // List kosong jika head dan tail menunjuk ke NULL
    L.head = NULL;
    L.tail = NULL;
}

// --- 2. Fungsi isEmptyPesanan (Cek List Kosong) ---
// Tujuan: Mengembalikan TRUE jika list belum memiliki elemen (node).
bool isEmptyPesanan_103032400065(ListPesanan L) {
    // Dalam DLL, cukup cek pointer head.
    return L.head == NULL;
}

// --- 3. Fungsi allocatePesanan (Alokasi Node Baru) ---
// Tujuan: Membuat node baru di memori (heap) dan mengisi datanya.
address_pesanan allocatePesanan_103032400065(InfoPesanan info) {
    // Alokasikan memori untuk elemen baru (node)
    address_pesanan P = new ElementPesanan;

    // Isi data (info) dengan data yang diberikan
    P->info = info;

    // Inisialisasi pointer next dan prev untuk node baru
    P->next = NULL;
    P->prev = NULL; // PENTING: Node baru pada DLL selalu memiliki prev NULL

    return P;
}

/* Setelah ini, Anda akan melanjutkan dengan fungsi-fungsi utama DLL lainnya, seperti:

// Fungsi Insert:
// void insertFirstPesanan_103032400065(ListPesanan &L, address_pesanan P);
// void insertLastPesanan_103032400065(ListPesanan &L, address_pesanan P);
// void insertAfterPesanan_103032400065(ListPesanan &L, address_pesanan Prec, address_pesanan P);

// Fungsi Delete:
// void deleteFirstPesanan_103032400065(ListPesanan &L, address_pesanan &P);
// ... dan seterusnya
*/

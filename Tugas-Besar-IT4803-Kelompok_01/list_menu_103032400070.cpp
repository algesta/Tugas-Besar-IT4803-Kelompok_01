#include "list_menu.h"
// Wajib menyertakan file header yang berisi deklarasi struct dan prototype fungsi.

// --- 1. Fungsi createListMenu (Inisialisasi List Kosong) ---
// Tujuan: Membuat list baru dengan menginisialisasi head menjadi NULL.
void createListMenu(ListMenu &L) {
    // List kosong jika head menunjuk ke NULL
    L.head = NULL;
}

// --- 2. Fungsi isEmptyMenu (Cek List Kosong) ---
// Tujuan: Mengembalikan TRUE jika list belum memiliki elemen (node).
bool isEmptyMenu(ListMenu L) {
    // Dalam SLL, cukup cek pointer head.
    return L.head == NULL;
}

// --- 3. Fungsi allocateMenu (Alokasi Node Baru) ---
// Tujuan: Membuat node baru di memori (heap) dan mengisi datanya.
address_menu allocateMenu(InfoMenu info) {
    // Alokasikan memori untuk elemen baru (node)
    address_menu P = new ElementMenu;

    // Isi data (info) dengan data yang diberikan
    P->info = info;

    // Inisialisasi pointer next untuk node baru
    P->next = NULL;

    // Inisialisasi head List Relasi di node Menu (akan diaktifkan nanti)
    // P->first_relasi = NULL;

    return P;
}

/* Setelah ini, rekan Anda akan melanjutkan dengan fungsi-fungsi SLL lainnya, seperti:

// Fungsi Insert:
// void insertFirstMenu(ListMenu &L, address_menu P);
// void insertLastMenu(ListMenu &L, address_menu P);
// void insertAfterMenu(ListMenu &L, address_menu Prec, address_menu P);

// Fungsi Delete:
// void deleteFirstMenu(ListMenu &L, address_menu &P);
// ... dan seterusnya
*/

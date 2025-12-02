#ifndef LIST_PESANAN_103032400065_H_INCLUDED
#define LIST_PESANAN_103032400065_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// --- 1. Definisi Info Element (DLL Pesanan) ---
// Minimal 3 atribut wajib:
struct InfoPesanan {
    string id_pesanan;
    string nama_pelanggan;
    int total_harga; // Atribut tipe int/real
};

// --- 2. Deklarasi Tipe Data Pointer dan Node (DLL) ---
typedef struct ElementPesanan *address_pesanan;

struct ElementPesanan {
    InfoPesanan info;
    address_pesanan next;
    address_pesanan prev; // Penanda Doubly Linked List
};

// --- 3. Deklarasi List Header ---
struct ListPesanan {
    address_pesanan head;
    address_pesanan tail; // DLL membutuhkan pointer tail
};

// --- 4. Deklarasi Fungsi Dasar (Prototype) ---
void createListPesanan_103032400065(ListPesanan &L);
bool isEmptyPesanan_103032400065(ListPesanan L);
address_pesanan allocatePesanan_103032400065(InfoPesanan info);

#endif // LIST_PESANAN_103032400065_H_INCLUDED

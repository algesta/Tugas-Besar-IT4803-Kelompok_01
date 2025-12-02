#ifndef LIST_MENU_H_INCLUDED
#define LIST_MENU_H_INCLUDED

#include <iostream>
#include <string>

// Header Relasi (akan dibuat bersama) perlu di-include di sini
// #include "list_relasi_103032400065.h" // Nanti setelah file relasi jadi

using namespace std;

// --- 1. Definisi Info Element (Menu Restoran) ---
// Memenuhi syarat: Minimal 3 atribut wajib
struct InfoMenu {
    string id_menu;
    string nama_menu;
    int harga; // Atribut tipe int/real
};

// --- 2. Deklarasi Tipe Data Pointer dan Node ---
typedef struct ElementMenu *address_menu;
// address_relasi didefinisikan di list_relasi.h

// ElementMenu adalah node dalam Singly Linked List (SLL)
struct ElementMenu {
    InfoMenu info;
    address_menu next; // PENTING: Penanda Singly Linked List (hanya next)

    // PENTING: Pointer ke List Relasi (Sesuai MLL Tipe A)
    // List Relasi akan tersimpan di setiap node Menu (Parent)
    // address_relasi first_relasi; // Nanti diisi setelah file relasi dibuat
};

// --- 3. Deklarasi List Header ---
struct ListMenu {
    address_menu head; // SLL hanya membutuhkan pointer head
};

// --- 4. Deklarasi Fungsi Dasar (Prototype) ---
void createListMenu(ListMenu &L);
bool isEmptyMenu(ListMenu L);
address_menu allocateMenu(InfoMenu info);
// void insertFirstMenu(ListMenu &L, address_menu P);
// ... dan seterusnya

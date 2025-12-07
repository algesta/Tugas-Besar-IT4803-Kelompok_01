#ifndef LIST_MENU_RELASI_H
#define LIST_MENU_RELASI_H

#include <iostream>
#include <string>

using namespace std;

typedef struct ElementPesanan *address_pesanan;
typedef struct ElementRelasi *address_relasi;

struct InfoTypeMenu{
    string id_menu;
    string nama_menu;
    int harga;
};

typedef struct ElementMenu *address_menu;

struct ElementMenu{
    InfoTypeMenu info;
    address_menu next;
    address_relasi first_relasi;
};

struct ListMenu{
    address_menu first;
};

struct ElementRelasi{
    address_relasi next;
    address_pesanan child;
    address_menu parent;
};

void createListMenu(ListMenu &L);
bool isEmptyMenu(ListMenu L);
address_menu allocateMenu(InfoTypeMenu info);

void insertFirstMenu(ListMenu &L, address_menu P);
void insertLastMenu(ListMenu &L, address_menu P);
void insertAfterMenu(ListMenu &L, address_menu prec, address_menu P);

void deleteFirstMenu(ListMenu &L, address_menu &P);
void deleteAfterMenu(ListMenu &L, address_menu prec, address_menu &P);
void deleteLastMenu(ListMenu &L, address_menu &P);

address_menu findMenu(ListMenu L, string id_menu);
void showAllMenu(ListMenu L);

address_relasi allocateRelasi(address_pesanan P_pesanan, address_menu P_menu);
void insertRelasi(address_menu &P_menu, address_pesanan P_pesanan, address_relasi R_utama, address_relasi R_balik);

address_relasi findRelasi(address_menu P_menu, string id_pesanan);
void deleteRelasi(address_menu &P_menu, address_relasi &P_relasi_utama, address_relasi &P_relasi_balik);

void deleteMenuTotal(ListMenu &L_menu, ListPesanan_ptr L_pesanan, string id_menu);
void deletePesananTotal(ListPesanan &L_pesanan, address_pesanan &P_pesanan);

void showPesananFromMenu(address_menu P_menu);
void showMenuRelasi(ListMenu L_menu);
void showMenuOfPesanan(address_pesanan P_pesanan);
void showPesananRelasi(ListPesanan L_pesanan);

int countRelasiDiMenu(addess_menu P_menu);
int countRelasiDiPesanan(address_pesanan P_pesanan);
int countPesananTanpaRelasi(ListPesanan L_pesanan);

void editRelasiTotal(ListMenu &L_menu, ListPesanan_ptr L_pesanan, string id_menu, string id_pesanan_lama, string id_pesanan_baru);

#endif // LIST_PARENT_RELASI_H

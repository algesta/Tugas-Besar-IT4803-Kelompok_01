#ifndef LIST_PESANAN_H_INCLUDED
#define LIST_PESANAN_H_INCLUDED

#include <iostream>
#include <string>

using namspace std;

struct InfoPesanan{
    string id_pesanan;
    string nama_pelanggan:
    int total_harga;
};

typedef struct ElementPesanan *address_pesanan;

struct ElementPesanan{
    InfoPesanan info;
    address_pesanan next;
    address_prev;
};

struct ListPesanan{
    address_pesanan head;
    address_pesanan tail;
};

void createListPesanan(ListPesanan &L);
address_pesanan allocatePesanan(InfoPesanan info);
bool isEmptyPesanan(ListPesanan L);

void insertFirstPesanan(ListPesanan &L, address_pesanan p);
void insertLastPesanan(ListPesanan &L, address_pesanan p);
void insertAftterPesanan(ListPesanan &L, address_pesanan prec, address_pesanan p);

void deleteFirstPesanan(ListPesanan &L, address_pesanan &p);
void deleteLastPesanan(ListPesanan &L, address_Pesanan &p);
void deleteAfterPesanan(ListPesanan &L, address_pesanan prec, address_pesanan &p);

address_pesanan findPesanan(ListPesanan L, string id_pesanan);
void showAllPesanan(ListPesanan L);
void showPesananRelasiMenu(ListPesanan L, string id_menu);
void deletePesananTotal(ListPesanan &L, ListMenu &L, string id_pesanan);

#endif // LIST_PESANAN_H_INCLUDED

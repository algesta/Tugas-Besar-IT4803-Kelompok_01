#ifndef LIST_PESANAN_H
#define LIST_PESANAN_H

#include <iostream>
#include <string>
#include "list_menu_relasi.h"

using namespace std;

struct InfoTypePesanan{
    string id_pesanan;
    string nama_pelanggan;
    int total_harga;
    string status_pesanan;
};

typedef struct ElementPesanan* address_pesanan;

struct ElementPesanan{
    InfoTypePesanan info;
    address_pesanan next;
    address_pesanan prev;
    address_relasi first_relasi_menu;
};

struct ListPesanan{
    address_pesanan first;
    address_pesanan last;
};

void createListPesanan(ListPesanan &L);
bool isEmptyPesanan(ListPesanan L);
address_pesanan allocatePesanan(InfoTypePesanan info);

void insertFirstPesanan(ListPesanan &L, address_pesanan P);
void insertAfterPesanan(Listpesanan &L, address_pesanan prec, address_pesanan P);
void insertLastPesanan(ListPesanan &L, address_pesanan P);

void deleteFirstPesanan(ListPesanan &L, address_pesanan &P);
void deleteAfterPesanan(ListPesanan &L, address_pesanan prec, address_pesanan &P);
void deleteLastPesanan(ListPesanan &L, address_pesanan &P);

address_pesanan findPesanan(ListPesanan L, string id_pesanan);
void showAllPesanan(ListPesanan L);

#endif // LIST_CHILD_H

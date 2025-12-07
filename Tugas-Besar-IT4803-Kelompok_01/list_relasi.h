#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include <string>

typedef struct ElementMenu *address_menu;
typedef struct ElementPesanan *address_pesanan;

using namespace std;

typedef struct ElementRelasi *addres_relasi;

struct ElementRelasi{
    address_pesanan child;
    address_relasi next;
    address_relasi prev;
};

address_relasi allocateRelasi(address_pesanan p_pesanan);

void insertRelasi(address_menu p_menu, assress_relasi R);
address_relasi findRelasi(address_menu p_menu, string id_pesanan);

void deleteRelasi(address_menu p_menu, address_relasi &p_relasi);

void showRelasiMenu(address_menu p_menu);
int countRelasiDiMenu(address_menu p_menu);
void editRelasiTotal(ListMenu &L_menu, ListPesanan &L_pesanan, string id_menu, string id_pesanan_lama, string id_pesanan_baru);

#endif // LIST_RELASI_H_INCLUDED

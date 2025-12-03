#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_menu.h"
#include "list_pesanan.h"

using namespace std;

typedef struct ElementRelasi *addres_relasi;

struct ElementRelasi{
    address_pesanan child;
    address_relasi next;
    address_relasi prev;
};

address_relasi allocateRelasi(address_pesanan p_pesanan);

void insertRelasi(ListMenu &L_menu, List_Pesanan L_pesanan, string id_menu, string id_pesanan);
address_relasi findRelasi(ListMenu L_menu, string id_menu, string id_pesanan);

#endif // LIST_RELASI_H_INCLUDED

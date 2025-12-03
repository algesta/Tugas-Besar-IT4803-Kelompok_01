#ifndef LIST_MENU_H_INCLUDED
#define LIST_MENU_H_INCLUDED

#include <iostream>
#include <string>
#include "list_relasi.h"

using namespace std;

struct InfoMenu{
    string id_menu;
    string nama_menu;
    int harga;
};

typedef struct ElementMenu *address_menu;

struct ElementMenu{
    InfoMenu info;
    address_menu next;
    address_relasi first_relasi;
};

struct ListMenu{
    address_menu head;
};

void createListtMenu(ListMenu &L);
address_menu allocateMenu(ListMenu info);
bool isEmptyMenu(ListMenu L);

void insertFirstMenu(ListMenu &L, address_menu p);
void insertLastMenu(ListMenu &L, addresss_menu p);
void insertAfterMenu(ListMenu &L, address_menu prec, address_menu p);

void deleteFirstMenu(ListMenu &L, address_menu &p);
void deleteLastMenu(ListMenu &L, address_menu &p);
void deleteAfterMenu(ListMenu &L, address_menu prec, address_menu &p);

address_menu findMenu(ListMenu L, string id_menu);
void showAllMenu(ListMenu L);

void showMenuRelasi(ListMenu L);
void showMenuRelasiChildTertentu(ListMenu L, string id_pesanan);
int countRelasiMenu(address_menu p_menu);
void deleteMenuTotal(ListMenu &L, string id_menu);

#endif // LIST_MENU_H_INCLUDED

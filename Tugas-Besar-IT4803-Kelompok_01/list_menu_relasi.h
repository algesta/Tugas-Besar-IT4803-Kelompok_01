#ifndef LIST_MENU_RELASI_H
#define LIST_MENU_RELASI_H

#include "list_pelanggan.h"
#include <iostream>
#include <string>

using namespace std;

struct ElementMenu;
struct ElementRelasi;

typedef struct ElementMenu* address_menu;
typedef struct ElementRelasi* address_relasi;

struct InfoTypeMenu{
    string nama_menu;
    int id_menu;
    double harga_menu;
};

struct InfoTypeRelasi{
    string nama_pelanggan;
    int id_pelanggan;
    int id_menu;
};

struct ElementRelasi{
    InfoTypeRelasi info;
    address_relasi next;
};

struct ElementMenu{
    InfoTypeMenu info;
    address_menu next;
    address_relasi first_relasi;
};

struct ListMenu{
    address_menu first;
};

//======PARENTTTTTTTTTNIHBROOO
void createListMenu(ListMenu &L);
bool isEmptyMenu(ListMenu L);
address_menu allocateMenu(InfoTypeMenu info);

void insertFirstMenu(ListMenu &L, address_menu P);
void insertLastMenu(ListMenu &L, address_menu P);
void insertAfterMenu(ListMenu &L, address_menu prec, address_menu P);

void deleteFirstMenu(ListMenu &L, address_menu &P);
void deleteLastMenu(ListMenu &L, address_menu &P);
void deleteAfterMenu(ListMenu &L, address_menu prec, address_menu &P);

void showAllMenu(ListMenu L);
address_menu findMenuById(ListMenu L, int id_menu);
address_menu findMenuByName(ListMenu L, string nama_menu);

//======RELASIIIIIIINIHBROOOO
address_relasi allocateRelasi(InfoTypeRelasi info);

void insertFirstRelasi(address_relasi &first_relasi, address_relasi P);
void insertLastRelasi(address_relasi &first_relasi, address_relasi P);
void insertAfterRelasi(address_relasi &first_relasi, address_relasi prec, address_relasi P);

void deleteFirstRelasi(address_relasi &first_relasi, address_relasi &P);
void deleteLastRelasi(address_relasi &first_relasi, address_relasi &P);
void deleteAfterRelasi(address_relasi &first_relasi, address_relasi prec, address_relasi &P);

void showAllRelasi(address_relasi first_relasi);

//======PENGKONDISIANNN
bool insertMenuIfUnique(ListMenu &L, InfoTypeMenu info);
bool deleteMenuIfNoRelation(ListMenu &L, int id_menu);

bool insertPelangganIfUnique(ListPelanggan &L, InfoTypePelanggan info);
bool deletePelangganIfNoRelation(ListPelanggan &LP, ListMenu &LM, int id_pelanggan);

//======RELASI UNTUK STUDI KASUS
bool relasiSudahAda(address_menu menu, int id_pelanggan);
bool tambahRelasiMenuPelanggan(ListMenu &menuList, ListPelanggan &pelangganList, int id_menu, int id_pelanggan);

//======KOMPUTASI MIN 2
bool pelangganMemilikiRelasi(const ListMenu &menuList, int id_pelanggan);
int hitungPelangganTanpaRelasi(const ListPelanggan &LP, const ListMenu &LM);

int hitungRelasiMenu(address_menu menu);
void tampilkanJumlahPelangganPerMenu(const ListMenu &L);

//======OPSIIIWW
address_relasi findRelationById(address_relasi first_relasi, int id_pelanggan, int id_menu);

#endif // LIST_MENU_RELASI_H

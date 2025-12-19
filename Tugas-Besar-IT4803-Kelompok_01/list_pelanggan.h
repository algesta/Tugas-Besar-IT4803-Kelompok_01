#ifndef LIST_PELANGGAN_H
#define LIST_PELANGGAN_H

#include <iostream>
#include <string>

using namespace std;

struct ElementRelasi;

typedef struct ElementPelanggan* address_pelanggan;
typedef struct ElementRelasi* address_relasi;

struct InfoTypePelanggan{
    string nama_pelanggan;
    int id_pelanggan;
    string jenis_member;
    double potongan_member;
};

struct ElementPelanggan{
    InfoTypePelanggan info;
    address_pelanggan next;
    address_pelanggan prev;
    address_relasi first_relasi;
};

struct ListPelanggan{
    address_pelanggan first;
    address_pelanggan last;
};

void createListPelanggan(ListPelanggan &L);
bool isEmptyPelanggan(ListPelanggan L);
address_pelanggan allocatePelanggan(InfoTypePelanggan info);

void insertFirstPelanggan(ListPelanggan &L, address_pelanggan P);
void insertLastPelanggan(ListPelanggan &L, address_pelanggan P);
void insertAfterPelanggan(ListPelanggan &L, address_pelanggan prec, address_pelanggan P);

void deleteFirstPelanggan(ListPelanggan &L, address_pelanggan &P);
void deleteLastPelanggan(ListPelanggan &L, address_pelanggan &P);
void deleteAfterPelanggan(ListPelanggan &L, address_pelanggan prec, address_pelanggan &P);

void showAllPelanggan(ListPelanggan L);
address_pelanggan findPelangganById(ListPelanggan L, int id_pelanggan);
address_pelanggan findPelangganByName(ListPelanggan L, string nama_pelanggan);

#endif // LIST_PELANGGGAN_H

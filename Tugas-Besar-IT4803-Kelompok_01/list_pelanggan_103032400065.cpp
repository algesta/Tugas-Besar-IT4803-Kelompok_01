#include "list_pelanggan.h"
#include "list_menu_relasi.h"

#include <iostream>

using namespace std;

void createListPelanggan(ListPelanggan &L){
    L.first = nullptr;
    L.last = nullptr;
}

address_pelanggan allocatePelanggan(InfoTypePelanggan info){
    address_pelanggan P = new ElementPelanggan;
    P->info = info;
    P->next = nullptr;
    P->prev = nullptr;
    P->first_relasi = nullptr;
    return P;
}

void insertFirstPelanggan(ListPelanggan &L, address_pelanggan P){
    if (L.first == nullptr){
        L.first = L.last = P;
        return;
    }
    P->next = L.first;
    L.first->prev = P;
    L.first = P;
}

void insertLastPelanggan(ListPelanggan &L, address_pelanggan P){
    if (L.first == nullptr){
        L.first = L.last = P;
        return;
    }
    L.last->next = P;
    P->prev = L.last;
    L.last = P;
}

void insertAfterPelanggan(ListPelanggan &L, address_pelanggan prec, address_pelanggan P){
    if (prec != nullptr){
        P->next = prec->next;
        P->prev = prec;
        if (prec->next){
            prec->next->prev = P;
        }else{
            L.last = P;
        }
        prec->next = P;
    }
}

void deleteFirstPelanggan(ListPelanggan &L, address_pelanggan &P){
    if (L.first != nullptr){
        P = L.first;
        L.first = P->next;
        if (L.first != nullptr){
            L.first->prev = nullptr;
        }else{
            L.last = nullptr;
        } L.last = nullptr;
        P->next = P->prev = nullptr;
    }
}

void deleteLastPelanggan(ListPelanggan &L, address_pelanggan &P){
    if (L.last != nullptr){
        P = L.last;
        L.last = P->prev;
        if (L.last != nullptr){
            L.last->next = nullptr;
        }else{
            L.first = nullptr;
        }
        P->next = P->prev = nullptr;
    }
}

void deleteAfterPelanggan(ListPelanggan &L, address_pelanggan prec, address_pelanggan &P){
    if (prec != nullptr && prec->next != nullptr){
        P = prec->next;
        prec->next = P->next;
        if (P->next != nullptr){
            P->next->prev = prec;
        }else{
            L.last = prec;
        }
        P->next = P->prev = nullptr;
    }
}

bool insertPelangganIfUnique(ListPelanggan &L, InfoTypePelanggan info){
    if (findPelangganById(L, info.id_pelanggan)){
        cout << "Pelanggan sudah ada.\n";
        return false;
    }
    address_pelanggan P = allocatePelanggan(info);
    insertLastPelanggan(L, P);
    return true;
}

bool deletePelangganIfNoRelation(ListPelanggan &LP, ListMenu &LM, int id_pelanggan){
    address_pelanggan P = LP.first;
    address_pelanggan prec = nullptr;

    while (P != nullptr && P->info.id_pelanggan != id_pelanggan){
        prec = P;
        P = P->next;
    }

    if (P == nullptr){
        cout << "Pelanggan tidak ditemukan.\n";
        return false;
    }

    address_menu M = LM.first;
    while (M != nullptr){
        address_relasi R = M->first_relasi;
        while (R != nullptr){
            if (R->info.id_pelanggan == id_pelanggan){
                cout << "Pelanggan masih memiliki relasi.\n";
                return false;
            }
            R = R->next;
        }
        M = M->next;
    }

    if (prec == nullptr){
        deleteFirstPelanggan(LP, P);
    }else{
        deleteAfterPelanggan(LP, prec, P);
    }

    delete P;
    return true;
}

int countPelangganRelation(const ListMenu &LM, int id_pelanggan){
    int count = 0;
    address_menu M = LM.first;
    while(M){
        address_relasi R = M->first_relasi;
        while(R){
            if(R->info.id_pelanggan == id_pelanggan) count++;
            R = R->next;
        }
        M = M->next;
    }
    return count;
}


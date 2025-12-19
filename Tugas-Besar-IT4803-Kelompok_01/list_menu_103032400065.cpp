#include "list_menu_relasi.h"

#include <iostream>

using namespace std;

void createListMenu(ListMenu &L){
    L.first = nullptr;
}

address_menu allocateMenu(InfoTypeMenu info){
    address_menu P = new ElementMenu;
    P->info = info;
    P->next = nullptr;
    P->first_relasi = nullptr;
    return P;
}

address_relasi allocateRelasi(InfoTypeRelasi info){
    address_relasi R = new ElementRelasi;
    R->info = info;
    R->next = nullptr;
    return R;
}

void insertFirstMenu(ListMenu &L, address_menu P){
    P->next = L.first;
    L.first = P;
}

void insertLastMenu(ListMenu &L, address_menu P){
    if (L.first == nullptr){
        L.first = P;
    }else{
        address_menu Q = L.first;
        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterMenu(ListMenu &L, address_menu prec, address_menu P){
    if (prec != nullptr){
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteFirstMenu(ListMenu &L, address_menu &P){
    if (L.first != nullptr){
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastMenu(ListMenu &L, address_menu &P){
    if (L.first == nullptr){
        return;
    }
    if (L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
    } else {
        address_menu Q = L.first;
        while (Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfterMenu(ListMenu &L, address_menu prec, address_menu &P){
    if (prec != nullptr && prec->next != nullptr){
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

void insertFirstRelasi(address_relasi &first_relasi, address_relasi P){
    P->next = first_relasi;
    first_relasi = P;
}

void insertLastRelasi(address_relasi &first_relasi, address_relasi P){
    if (first_relasi == nullptr){
        first_relasi = P;
    }else{
        address_relasi Q = first_relasi;
        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterRelasi(address_relasi &first_relasi, address_relasi prec, address_relasi P){
    if (prec != nullptr){
        P->next = prec->next;
        prec->next = P;
    }
}

bool insertMenuIfUnique(ListMenu &L, InfoTypeMenu info){
    if (findMenuById(L, info.id_menu) != nullptr) {
        cout << "Menu sudah ada.\n";
        return false;
    }
    address_menu P = allocateMenu(info);
    insertLastMenu(L, P);
    return true;
}

bool deleteMenuIfNoRelation(ListMenu &L, int id_menu){
    address_menu P = L.first;
    address_menu prec = nullptr;
    while (P != nullptr && P->info.id_menu != id_menu){
        prec = P;
        P = P->next;
    }
    if (P == nullptr){
        cout << "Menu tidak ditemukan.\n";
        return false;
    }
    if (P->first_relasi != nullptr){
        cout << "Menu masih memiliki relasi.\n";
        return false;
    }
    if (prec == nullptr){
        deleteFirstMenu(L, P);
    }else{
        deleteAfterMenu(L, prec, P);
    }
    delete P;
    return true;
}

int countMenuRelation(address_relasi first_relasi){
    int count = 0;
    address_relasi R = first_relasi;
    while(R){
        count++;
        R = R->next;
    }
    return count;
}

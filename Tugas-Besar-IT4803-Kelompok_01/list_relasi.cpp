#include "list_menu_relasi.h"

#include <iostream>

using namespace std;

void deleteFirstRelasi(address_relasi &first_relasi, address_relasi &P){
    if (first_relasi != nullptr){
        P = first_relasi; first_relasi = P->next;
        P->next = nullptr;
    }
}

void deleteLastRelasi(address_relasi &first_relasi, address_relasi &P){
    if (first_relasi != nullptr){
        if (first_relasi->next == nullptr){
            P = first_relasi;
            first_relasi = nullptr;
        }else{
            address_relasi Q = first_relasi;
            while (Q->next->next != nullptr){
                Q = Q->next;
            }
            P = Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfterRelasi(address_relasi &first_relasi, address_relasi prec, address_relasi &P){
    if (prec != nullptr && prec->next != nullptr){
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr; }
}


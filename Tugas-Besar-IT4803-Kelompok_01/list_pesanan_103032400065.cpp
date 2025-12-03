#include "list_pesanan.h"

void createListPesanan(ListPesanan &L){
    L.head = nullptr;
    L.tail = nullptr;
}

address_pesanan allocatePesanan(InfoPesanan info){
    address_pesanan p = new ElementPesanan;
    p->info = info;
    p->next = nullptr;
    p->prev = nullptr;

    return p
}

bool isEmptyPesanan(ListPesanan L){
    return L.head == nullptr;
}

void insertFirstPesanan(ListPesanan &L, address_pesanan p){
    if (isEmptyPesanan(L)){
        L.head = p;
        L.tail = p;
    }else{
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
    }
}

Void insertAferPesanan(ListPesanan &L, address_pesanan prec, address_pesanan p){
    if (prec = nullptr){
        cout << "Error: Node predecessor tidak boleh ditemukan." << endl;
        return;
    }
    if (prec == L.tail){
        insertLastPesanan(L, p);
        return;
    }
    p->next = prec->next;
    p->prev = prec;

    prec->next->prev = p;
    prec->next = p;
}

void deleteFirstPesanan(ListPesanan &L, address_pesanan &p){
    p = L.head;

    if (isEmptyPesanan(L)){
        p = nullptr;
        return;
    }
    if (L.head == L.tail){
        L.head = nullptr;
        L.tail = nullptr;
    } else{
        L.head = p->next;
        L.head->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteAfterPesanan(ListPesanan &L, address_pesanan prec, address_pesanan &p){
    if (prec == nullptr || prec->next == null){
        p = nullptr;
        return;
    }
    p = prec->next;

    if (p == L.tail) {
        L.tail = prec;
        L.tail->next = nullptr;
        p->prev = nullptr;
        return;
    }
    prec->next = p->next;
    p->next->prev = prec;

    p->next = nullptr;
    p->prev = nullptr;
}

#include "list_menu_relasi.h"
#include "list_pesanan.h"

void createListMenu(ListMenu &L){
    L.first = nullptr;
    cout << "INFO: List Menu berhasil dibuat." << endl;
}

bool isEmptyMenu(ListMenu L){
    return L.first == nullptr;
}

address_menu allocateMenu(InfoTypeMenu info){
    address_menu P = new ElementMenu;

    P->info = info;
    P->next = nullptr;
    P->first_relasi = nullptr;

    return P;
}

void insertFirstMenu(ListMenu &L, address_menu P){
        P->next = L.first;
        L.first = P;
        cout << "SUCCESS: Menu " << P->info.nama_menu << " ditambahkan di awal list." << endl;
}

void insertAfterMenu(ListMenu &L, address_menu prec, address_menu P){
    if (prec != nullptr){
        P->next = prec->next;
        prec->next = P;
        cout << "SUCCESS: Menu " << P->info.nama_menu << " ditambahkan setelah " << prec->info.nama_menu << "." << endl;
    } else{
        cout << "ERROR: Predecessor tidak valid. Insert After gagal." << endl;
    }
}

void deleteLastMenu(ListMenu &L, address_menu &P){
    if (L.first == nullptr){
        P = nullptr;
        cout << "ERROR: List Menu kosong. Delete Last gagal." << endl;
        return
    }
    if (L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
        cout << "SUCCESS: Menu ID " << P->info.id_menu << " dihapus (elemen terakhir)." << endl;
        P->next = nullptr;
        return;
    }
    address_menu prec = L.first;

    while (prec->next->next != nullptr){
        prec = prec->next;
    }
    P =  prec->next ;
    prec->next = nullptr;
    P->next = nullptr;
    cout << "SUCCESS: Menu ID " << P->info.id_menu << " dihapus dari akhir list." << endl;
}

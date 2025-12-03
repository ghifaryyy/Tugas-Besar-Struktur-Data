#include "tubes.h"
#include <iostream>
using namespace std;

void createUser_keongracun(list_User &U){
    U.first = nullptr;
    U.last = nullptr;
}

void createParent_keongracun(list_playlist &P){
    P.first = nullptr;
    P.last = nullptr;
}

void createChild_keongracun(list_lagu &L){
    L.first = nullptr;
    L.last = nullptr;
}

void createRelasi__keongracun(list_relasi &R){
    R.first = nullptr;
    R.last = nullptr;
}

bool isUserEmpty_keongracun(adr_User U){
    if (U.first == nullptr && U.last == nullptr){
        return true;
    } else {
        return false;
    }
}

bool isParentEmpty_keongracun(adr_playlist P){
    if (P.first == nullptr && P.last == nullptr){
        return true;
    } else {
        return false;
    }
}

bool isChildEmpty_keongracun(adr_lagu L){
    if (L.first == nullptr && L.last == nullptr){
        return true;
    } else {
        return false;
    }
}

bool isRelasiEmpty_keongracun(adr_relasi R){
    if (R.first == nullptr && R.last == nullptr){
        return true;
    } else {
        return false;
    }
}

adr_User createNodeUser_keongracun(int id, string usn, string peran){
    adr_User U = new elmlist_user;
    U->info.id = id;
    U->info.username = usn;
    U->info.peran = peran;
    U->next = nullptr;
    return U;
}

adr_playlist createNodeParent_keongracun(int id, string nama){
    adr_playlist P = new elmlist_playlist;
    P->info.id = id;
    P->info.nama = nama;
    P->next = nullptr;
    return P;
}

adr_lagu createNodeChild_keongracun(string judul, string album, string genre, int idlagu, int tahun, int durasi){
    adr_lagu L = new elmlist_lagu;
    L->info.judul = judul;
    L->info.album = album;
    L->info.genre = genre;
    L->info.idlagu = idlagu;
    L->info.tahun = tahun;
    L->info.durasi = durasi;
    L->next = nullptr;
    L->prev = nullptr;
    return L;
}

adr_relasi createNodeRelasi_keongracun(adr_playlist P, adr_lagu L){
    adr_relasi R = new elmlist_relasi;
    R->playlist = P;
    R->lagu = L;
    R->next = nullptr;
    return R;
}

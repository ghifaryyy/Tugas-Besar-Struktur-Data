#include "MLL.h"
#include <iostream>
using namespace std;

// ===== LOGIN & MENU =====
// ===== CREATE LIST =====
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
void createRelasi_keongracun(list_relasi &R){
    R.first = nullptr;
    R.last = nullptr;
}

// ===== CEK KOSONG =====
bool isUserEmpty_keongracun(list_User U){
    return U.first == nullptr && U.last == nullptr;
}
bool isParentEmpty_keongracun(list_playlist P){
    return P.first == nullptr && P.last == nullptr;
}
bool isChildEmpty_keongracun(list_lagu L){
    return L.first == nullptr && L.last == nullptr;
}
bool isRelasiEmpty_keongracun(list_relasi R){
    return R.first == nullptr && R.last == nullptr;
}

// ===== CREATE NODE =====
adr_User createNodeUser_keongracun(int id, string usn, string peran){
    adr_User U = new elmlist_user;
    U->info.id = id;
    U->info.username = usn;
    U->info.role = peran;
    U->next = nullptr;
    U->Playlist.first = nullptr;
    U->Playlist.last = nullptr;

    return U;
}
adr_playlist createNodeParent_keongracun(int id, string nama){
    adr_playlist P = new elmlist_playlist;
    P->info.id = id;
    P->info.nama = nama;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}
adr_lagu createNodeChild_keongracun(string judul, string album, string genre, int idlagu, int tahun, int durasi){
    adr_lagu L = new elmlist_lagu;
    L->info.judul = judul;
    L->info.album = album;
    L->info.genre = genre;
    L->info.id_lagu = idlagu;
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
    R->prev = nullptr;
    return R;
}

void adminAddLagu_keongracun(list_lagu &L, adr_lagu song){
    if (isChildEmpty_keongracun(L)){
        L.first = song;
        L.last = song;
    }else{
        song->prev = L.last;
        L.last->next = song;
        L.last = song;
    }
}
void displayAllLagu_keongracun(list_lagu L){
    adr_lagu p = L.first;
    while (p!= nullptr){
        cout << "-----------------------------" << endl;
        cout << p->info.judul << endl;
        cout << p->info.album << endl;
        cout << p->info.genre << endl;
        cout << p->info.id_lagu << endl;
        cout << p->info.tahun << endl;
        cout << p->info.durasi << " menit" << endl;
        cout << "-----------------------------" << endl;

        cout << endl;
        p = p->next;
    }
}

adr_lagu searchIdLagu_keongracun(list_lagu L, int idLagu){
    adr_lagu p = L.first;
    while (p != nullptr){
        if (p->info.id_lagu == idLagu){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
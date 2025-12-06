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


// ===== ADMIN FUNCTION =====
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

void updateLagu_keongracun(adr_lagu &L, string new_judul, string new_album, string new_genre, int new_tahun, int new_durasi){
    L->info.judul = new_judul;
    L->info.album = new_album;
    L->info.genre = new_genre;
    L->info.tahun = new_tahun;
    L->info.durasi = new_durasi;
}

void deleteLagu_keongracun(list_lagu &L, adr_lagu &song){
    if (song == L.first && song == L.last){
        L.first = nullptr;
        L.last = nullptr;
    }else if (song == L.first){
        L.first = song->next;
        L.first->prev = nullptr;
    }else if (song == L.last){
        L.last = song->prev;
        L.last->next = nullptr;
    }else{
        song->prev->next = song->next;
        song->next->prev = song->prev;
    }
    song->next = nullptr;
    song->prev = nullptr;
    delete song;
    song = nullptr;
}


// ===== USER FUNCTION =====
void addUser_keongracun(list_User &U, adr_User user){
    if (isUserEmpty_keongracun(U)){
        U.first = user;
        U.last = user;
    }else{
        U.last->next = user;
        U.last = user;
    }
}

adr_User findUserById_keongracun(list_User U, int id){
    adr_User p = U.first;
    while (p != nullptr){
        if (p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void CreatePlaylistForUser_keongracun(list_User &U, adr_User user, adr_playlist P){
    if (user->Playlist.first == nullptr && user->Playlist.last == nullptr){
        user->Playlist.first = P;
        user->Playlist.last = P;
    }else{
        P->prev = user->Playlist.last;
        user->Playlist.last->next = P;
        user->Playlist.last = P;
    }
}


// ===== PLAYLIST FUNCTION =====
void addPlaylist_keongracun(list_playlist &P, adr_playlist playlist){
    if (isParentEmpty_keongracun(P)){
        P.first = playlist;
        P.last = playlist;
    }else{
        playlist->prev = P.last;
        P.last->next = playlist;
        P.last = playlist;
    }
}

void displayAllPlaylist_keongracun(list_playlist P){
    adr_playlist p = P.first;
    while (p!= nullptr){
        cout << "-----------------------------" << endl;
        cout << "ID Playlist: " << p->info.id << endl;
        cout << "Nama Playlist: " << p->info.nama << endl;
        cout << "-----------------------------" << endl;

        cout << endl;
        p = p->next;
    }
}



// ===== RELATIONSHIP FUNCTION =====
void addSongToPlaylist_keongracun(adr_playlist P, adr_lagu L){
    adr_relasi R = createNodeRelasi_keongracun(P, L);
    if (P->relasi.first == nullptr && P->relasi.last == nullptr){
        P->relasi.first = R;
        P->relasi.last = R;
    }else{
        R->prev = P->relasi.last;
        P->relasi.last->next = R;
        P->relasi.last = R;
    }
}

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "tubes.h"
using namespace std;

// fungsi clearscreen
void clearScreen() {
    system("cls"); // Windows
}

// ===== MENU =====
void menuAdmin_keongracun(list_User &U, list_lagu &L){
    int pilih;
    do{
        cout << "========================================" << endl;
        cout << "   Selamat Datang di Aplikasi MUSIKKUY  " << endl;
        cout << "========================================" << endl <<endl;
        cout << "======= Menu Admin =======" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Update Lagu" << endl;
        cout << "3. Delete Lagu" << endl;
        cout << "4. Tampilkan Lagu" << endl;
        cout << "0. Menu Login" << endl;
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch(pilih){
            case 1:{
                clearScreen();
                cout << "======= Tambah Lagu =======" << endl;
                string nama, judul, album, genre;
                int id, tahun, durasi;
                cout << "Id Lagu: ";
                cin >> id;
                cout << "Nama Artis: ";
                cin >> nama;
                cout << "Judul Lagu: ";
                cin >> judul;
                cout << "Album: ";
                cin >> album;
                cout << "Genre: ";
                cin >> genre;
                cout << "Tahun: ";
                cin >> tahun;
                cout << "Durasi: ";
                cin >> durasi;

                adr_lagu LaguBaru = createNodeChild_keongracun(id, nama, judul, album, genre, tahun, durasi);
                adminAddLagu_keongracun(L, LaguBaru);
                cout << "Lagu berhasil ditambahkan!\n" << endl;
                clearScreen();
                break;
            }
            case 2:{
                clearScreen();
                string newArtis, newJudul, newGenre, newAlbum;
                int id, newTahun, newDurasi;
                displayAllLagu_keongracun(L);
                cout << "\n======= Update Lagu =======" << endl;
                cout << "ID Lagu: ";
                cin >> id;
                adr_lagu song = searchIdLagu_keongracun(L, id);
                if (song != nullptr){
                cout << "Nama Artis: ";
                cin >> newArtis;
                cout << "Judul Lagu: ";
                cin >> newJudul;
                cout << "Album: ";
                cin >> newAlbum;
                cout << "Genre: ";
                cin >> newGenre;
                cout << "Tahun: ";
                cin >> newTahun;
                cout << "Durasi: ";
                cin >> newDurasi;
                updateLagu_keongracun(song, newArtis, newJudul, newAlbum, newGenre, newTahun, newDurasi);
                cout << "Update Berhasil!" << endl;
                }else{
                    cout << "Lagu tidak ditemukan!" << endl;
                }
                break;
            }
            case 3:{
                clearScreen();
                int id;
                displayAllLagu_keongracun(L);
                cout << "======= Hapus Lagu =======" << endl;
                cout << "ID Lagu: ";
                cin >> id;
                adminDeleteLagu_keongracun(U, L, id);
            }
                break;
            case 4:
                clearScreen();
                displayAllLagu_keongracun(L);
                break;
            case 0:
                cout << "Logout ... " << endl;
                 break;

            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }
    while (pilih != 0);
}
void menuUser_keongracun(adr_User user, list_lagu &L){
    int pilihan;
    do{
        cout << "========================================" << endl;
        cout << "   Selamat Datang di Aplikasi MUSIKKUY  " << endl;
        cout << "========================================" << endl << endl;
        cout << "======= Menu User =======" << endl;
        cout << "1. Tambah Playlist" << endl;
        cout << "2. Tambah Lagu ke playlist" << endl;
        cout << "3. Hapus Lagu dari playlist" << endl;
        cout << "4. Lihat Playlist" << endl;
        cout << "5. Lihat Lagu dalam Playlist" << endl;
        cout << "0. Menu Login" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:{
                int id;
                string nama;
                cout << "ID Playlist: ";
                cin >> id;
                cout << "Nama Playlist: ";
                cin >> nama;

                userAddPlaylist_keongracun(user, id, nama);
                break;
            }
            case 2:{
                int id, pilih;
                adr_playlist p;
                adr_lagu q;
                displayAllLagu_keongracun(L);
                cout << "Masukkan id lagu: ";
                cin >> id;

                q = searchIdLagu_keongracun(L, id);
                displayAllPlaylist(user);
                if (q != nullptr){
                    cout << "Pilih id playlist: ";
                    cin >> pilih;
                    p = searchIdPlaylist(user->Playlist, pilih);
                    if (p != nullptr){
                        addSongToPlaylist_keongracun(p, q);
                        cout << "Lagu berhasil ditambahkan ke playlist!" << endl;
                    }else{
                        cout << "Tidak ada playlist tersebut!" << endl;
                    }
                }else{
                    cout << "Lagu tidak ditemukan!" << endl;
                }
                break;
            }
            case 3:{
                int id;
                break;
            }
            case 4:
                displayAllPlaylist(user);
                break;
            case 5:{
                displayAllPlaylist(user);
                int pilih;
                cout << "Masukkan ID playlist yang ingin dilihat: ";
                cin >> pilih;

                adr_playlist P = searchIdPlaylist(user->Playlist, pilih);
                if (P != nullptr) {
                    displaySongsInPlaylist_keongracun(P);
                } else {
                    cout << "Playlist tidak ditemukan!" << endl;
                }
                break;
            }
            case 0:
                cout << "Logout ..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    while (pilihan != 0);
}

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
adr_lagu createNodeChild_keongracun(int idlagu, string nama, string judul, string album, string genre, int tahun, int durasi){
    adr_lagu L = new elmlist_lagu;
    L->info.id_lagu = idlagu;
    L->info.nama = nama;
    L->info.judul = judul;
    L->info.album = album;
    L->info.genre = genre;
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

// ==== fitur admin ===== //
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
void displayAllLagu_keongracun(list_lagu L) {
    adr_lagu p = L.first;

    if (p == nullptr) {
        cout << "Tidak ada lagu dalam library!\n";
        return;
    }

    cout << left;
    cout << setw(10) << "ID";
    cout << setw(20) << "Artis";
    cout << setw(25) << "Judul";
    cout << setw(20) << "Album";
    cout << setw(20) << "Genre";
    cout << setw(8)  << "Tahun";
    cout << setw(15) << "Durasi (menit)";
    cout << endl;

    cout << string(113, '-') << endl;

    while (p != nullptr) {
        cout << left;
        cout << setw(10) << p->info.id_lagu;
        cout << setw(20) << p->info.nama;
        cout << setw(25) << p->info.judul;
        cout << setw(20) << p->info.album;
        cout << setw(20) << p->info.genre;
        cout << setw(8)  << p->info.tahun;
        cout << setw(15) << p->info.durasi;
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
void updateLagu_keongracun(adr_lagu L, string new_nama, string new_judul, string new_album, string new_genre, int new_tahun,
                           int new_durasi){
    L->info.nama = new_nama;
    L->info.judul = new_judul;
    L->info.album = new_album;
    L->info.genre = new_genre;
    L->info.tahun = new_tahun;
    L->info.durasi = new_durasi;
}
void adminDeleteLagu_keongracun(list_User &U, list_lagu &L, int id){
    adr_lagu song = searchIdLagu_keongracun(L, id);
    if (song != nullptr){
        deleteRelasiLagu_keongracun(U, song);
        deleteLagu_keongracun(L, song);
        cout << "Lagu berhasil dihapus!" << endl;
    }else{
        cout << "ID Lagu tidak ditemukan!" << endl;
    }
}
// ===== fitur user ===== //
adr_User searchUser_keongracun(list_User U, string username){
    adr_User P = U.first;
    while (P != nullptr){
        if (P->info.username == username){
            return P;
        }
    P = P->next;
    }
    return nullptr;
}
adr_playlist searchIdPlaylist(list_playlist P, int id){
    adr_playlist Q = P.first;
    while (Q != nullptr){
        if (Q->info.id == id){
            return Q;
        }
    Q = Q->next;
    }
    return nullptr;
}
void addUser_keongracun(list_User &U, adr_User userBaru) {
    if (U.first == nullptr) {
        U.first = userBaru;
        U.last = userBaru;
    } else {
        U.last->next = userBaru;
        U.last = userBaru;
    }
}
void userAddPlaylist_keongracun(adr_User user, int id, string nama){
    adr_playlist P = createNodeParent_keongracun(id, nama);
    if (user->Playlist.first == nullptr && user->Playlist.last == nullptr){
        user->Playlist.first = P;
        user->Playlist.last = P;
    }else{
        P->prev = user->Playlist.last;
        user->Playlist.last->next = P;
        user->Playlist.last = P;
    }
}
void displaySongsInPlaylist_keongracun(adr_playlist P) {
    if (P == nullptr) {
        cout << "Playlist tidak ditemukan!" << endl;
    } else {
        cout << "===== Lagu dalam Playlist: " << P->info.nama << " =====" << endl;

        adr_relasi R = P->relasi.first;
        if (R == nullptr) {
            cout << "Playlist ini masih kosong." << endl;
        } else {
            while (R != nullptr) {
                if (R->lagu == nullptr){
                    cout << "Lagu telah dihapus dari sistem" << endl;
                }else{
                adr_lagu L = R->lagu;
                cout << "ID: " << L->info.id_lagu;
                cout << " | Artis: " << L->info.nama;
                cout << " | Judul: " << L->info.judul;
                cout << " | Album: " << L->info.album;
                cout << " | Genre: " << L->info.genre;
                cout << " | Tahun: " << L->info.tahun;
                cout << " | Durasi: " << L->info.durasi << " menit";
                cout << endl;
                }
                R = R->next;
            }
        }
    }
}
void displayAllPlaylist(adr_User user){
    adr_playlist Q = user->Playlist.first;
    if (Q == nullptr){
    cout << "Tidak ada playlist" << endl;
    }else{
        cout << "===== Playlist Anda =====" << endl;
        while (Q != nullptr){
            cout << Q->info.id << " - " << Q->info.nama << endl;
            Q = Q->next;
        }
    }
}

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
void deleteSongFromPlaylist_keongracun(adr_playlist P, int idLagu) {
    adr_relasi R = P->relasi.first;

    while (R != nullptr) {
        if (R->lagu->info.id_lagu == idLagu) {
            if (R == P->relasi.first) {
                P->relasi.first = R->next;
                if (P->relasi.first != nullptr) {
                    P->relasi.first->prev = nullptr;
                }
            }else if (R == P->relasi.last) {
                P->relasi.last = R->prev;
                if (P->relasi.last != nullptr) {
                    P->relasi.last->next = nullptr;
                }
            }else {
                R->prev->next = R->next;
                if (R->next != nullptr) {
                    R->next->prev = R->prev;
                }
            }
            cout << "Lagu dengan ID " << idLagu << " berhasil dihapus dari playlist!" << endl;
            break;
        }
        R = R->next;
    }
    if (R == nullptr) {
        cout << "Lagu dengan ID " << idLagu << " tidak ditemukan di playlist ini." << endl;
    }
}

// RELASI
void deleteRelasiLagu_keongracun(list_User &U, adr_lagu song){
    adr_User P = U.first;

    while (P != nullptr){
        adr_playlist Q = P->Playlist.first;
        while (Q != nullptr){
            adr_relasi R = Q->relasi.first;
            while (R != nullptr){
                if (R->lagu == song){
                    R->lagu = nullptr;
                }
                R = R->next;
            }
            Q = Q->next;
        }
        P = P->next;
    }
}
void deleteLagu_keongracun(list_lagu &L, adr_lagu &song){
    if (isChildEmpty_keongracun(L)){
        cout << "List kosong" << endl;
    }else if(song == nullptr){
        cout << "Lagu tidak ditemukan" << endl;
    }else{
        if (song == L.first && song == L.last){
            L.first = nullptr;
            L.last = nullptr;
        }else if (song == L.first){
            L.first = song->next;
            if (L.first != nullptr){
                L.first->prev = nullptr;
            }
        }else if(song == L.last){
            L.last = song->prev;
            if (L.last != nullptr){
                L.last->next = nullptr;
            }
        }else{
            song->prev->next = song->next;
            song->next->prev = song->prev;
        }
        song->next = nullptr;
        song->prev = nullptr;
    }
}

// DATA DUMMY //
void DummyLagu_keongracun(list_lagu &L) {
    adminAddLagu_keongracun(L, createNodeChild_keongracun(101, "Taylor_Swift", "Love_Story", "FLR", "Pop", 2008, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(102, "Sheila_On_7", "Dan", "KLSK", "Pop", 2000, 5));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(103, "Fiersa_Besari", "Celengan_Rindu", "PLG", "Indie", 2017, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(104, "Coldplay", "Fix_You", "XY", "Alt", 2005, 5));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(105, "Tulus", "Hati_Hati_di_Jalan", "MNS", "Pop", 2022, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(106, "The_Weeknd", "Blinding_Lights", "HRS", "Synth", 2019, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(107, "RADWIMPS", "Nandemonaiya", "KNW", "Jpop", 2016, 5));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(108, "Ikimonogakari", "Bluebird", "NSO", "Jpop", 2008, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(109, "Ed_Sheeran", "Shape_of_You", "DVD", "Pop", 2017, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(110, "Queen", "Bohemian_Rhapsody", "OPR", "Rock", 1975, 6));
}

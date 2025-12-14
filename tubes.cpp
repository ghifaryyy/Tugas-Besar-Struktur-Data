#include <iostream>
#include <cstdlib>
#include <algorithm>
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
                adr_lagu p;
                bool validID = false;
                cout << "======= Tambah Lagu =======" << endl;
                string nama, judul, album, genre;
                int id, tahun, durasi;
                while(!validID){
                    cout << "Id Lagu: ";
                    cin >> id;
                    p = searchIdLagu_keongracun(L, id);
                    if (p == nullptr){
                        validID = true;
                    }else{
                      cout << "ID tersebut sudah ada! Masukkan ID lain." << endl;                    }
                }
                cout << "Nama Artis: ";
                cin >> nama;
                cout << "Judul Lagu: ";
                cin >> judul;

                adr_lagu q = searchNamaJudulLagu_keongracun(L, nama, judul);
                if (q != nullptr){
                    cout << "Lagu dengan nama artis " << q->info.nama <<" dan judul " << q->info.judul << " sudah ada!" << endl;

                }else{
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
                }
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
        cout << "========================================" << endl;

        // Display Now Playing status
        if (user->currentSong != nullptr){
            if (user->activePlaylist != nullptr){
                cout << "Now Playing: " << user->currentSong->info.judul
                     << " - " << user->currentSong->info.nama
                     << " [PLAYLIST: " << user->activePlaylist->info.nama << "]" << endl;
            } else {
                cout << "Now Playing: " << user->currentSong->info.judul
                     << " - " << user->currentSong->info.nama
                     << " [LIBRARY]" << endl;
            }
        }

        cout << endl << "======= Menu User =======" << endl;
        cout << "1. Tambah Playlist" << endl;
        cout << "2. Hapus Playlist" << endl;
        cout << "3. Tambah Lagu ke playlist" << endl;
        cout << "4. Hapus Lagu dari playlist" << endl;
        cout << "5. Lihat Playlist" << endl;
        cout << "6. Lihat Lagu dalam Playlist" << endl;
        cout << "7. Cari lagu" << endl;
        cout << "8. Music Player" << endl;
        cout << "0. Menu Login" << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:{
                clearScreen();
                int id;
                bool validID = false;
                adr_playlist pl;
                string nama;
                while(!validID){
                    cout << "ID Playlist: ";
                    cin >> id;
                    pl = searchIdPlaylist(user->Playlist, id);
                    if (pl == nullptr){
                        validID = true;
                    }else{
                      cout << "ID tersebut sudah ada! Masukkan ID lain." << endl;                    }
                }
                cout << "Nama Playlist: ";
                cin >> nama;

                userAddPlaylist_keongracun(user, id, nama);
                cout << "Playlist berhasil dibuat!" << endl;
                break;
            }
            case 2:{
                clearScreen();
                displayAllPlaylist(user);
                if (user->Playlist.first != nullptr){
                    int idPlaylist;
                    cout << "Masukkan ID Playlist yang ingin dihapus: ";
                    cin >> idPlaylist;
                    deletePlaylist_keongracun(user, idPlaylist);
                }
                break;
            }
            case 3:{
                clearScreen();
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
            case 4:{
                clearScreen();
                int idPlaylist, idLagu;
                adr_playlist P;
                displayAllPlaylist(user);

                P = searchIdPlaylist(user->Playlist, idPlaylist);
                if (user->Playlist.first != nullptr){
                    cout << "Pilih id Playlist: ";
                    cin >> idPlaylist;

                    P = searchIdPlaylist(user->Playlist, idPlaylist);
                    if (P != nullptr){
                        displaySongsInPlaylist_keongracun(P);

                        if (P->relasi.first != nullptr){
                            cout << "Masukkan id lagu yang ingin dihapus: ";
                            cin >> idLagu;
                            deleteSongFromPlaylist_keongracun(P, idLagu);
                        }
                    }else{
                        cout << "Playlist tidak ditemukan!" << endl;
                    }
                }
                break;
            }
            case 5:
                clearScreen();
                displayAllPlaylist(user);
                break;
            case 6:{
                clearScreen();
                displayAllPlaylist(user);
                int pilih;
                cout << "Masukkan ID playlist yang ingin dilihat: ";
                cin >> pilih;

                adr_playlist P = searchIdPlaylist(user->Playlist, pilih);
                if (P != nullptr) {
                    displaySongsInPlaylist_keongracun(P);
                    cout << endl;
                } else {
                    cout << "Playlist tidak ditemukan!" << endl;
                }
                break;
            }
            case 7:{
                clearScreen();
                string artisName, judulLagu;
                adr_lagu p;
                
                cout << "Masukkan nama artis: ";
                cin >> artisName;
                cout << "Masukkan judul lagu: ";
                cin >> judulLagu;

                p = searchNamaJudulLagu_keongracun(L, artisName, judulLagu);
                if (p != nullptr){
                    cout << endl;
                    cout << "=============================================" << endl;
                    cout << "Artis     : " << p->info.nama << endl;
                    cout << "Judul     : " << p->info.judul << endl;
                    cout << "Album     : " << p->info.album << endl;
                    cout << "Genre     : " << p->info.genre << endl;
                    cout << "Tahun     : " << p->info.tahun << endl;
                    cout << "Durasi    : " << p->info.durasi << " menit" << endl;
                    cout << "=============================================" << endl;

                }else{
                    cout << "Lagu tidak ditemukan!" << endl;
                }
                break;
            }
            case 8:
                clearScreen();
                menuMusicPlayer_keongracun(user, L);
                break;
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
    U->currentSong = nullptr;
    U->activePlaylist = nullptr;

    return U;
}
adr_playlist createNodeParent_keongracun(int id, string nama){
    adr_playlist P = new elmlist_playlist;
    P->info.id = id;
    P->info.nama = nama;
    P->next = nullptr;
    P->prev = nullptr;
    P->relasi.first = nullptr;
    P->relasi.last = nullptr;
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
adr_lagu searchNamaJudulLagu_keongracun(list_lagu L, string nama, string judul){
    transform(nama.begin(), nama.end(), nama.begin(), ::tolower);
    transform(judul.begin(), judul.end(), judul.begin(), ::tolower);

    adr_lagu p = L.first;
    while (p != nullptr){
        string namaLower = p->info.nama;
        string judulLower = p->info.judul;

        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        transform(judulLower.begin(), judulLower.end(), judulLower.begin(), ::tolower);

        if (namaLower == nama && judulLower == judul){
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
        cout << "Total Lagu: " << jumlahLaguPlaylist(P) << endl << endl;
        adr_relasi R = P->relasi.first;
        if (R == nullptr) {
            cout << "Playlist ini masih kosong." << endl;
        } else {
            // Header tabel
            cout << left;
            cout << setw(10) << "ID";
            cout << setw(20) << "Artis";
            cout << setw(25) << "Judul";
            cout << setw(20) << "Album";
            cout << setw(20) << "Genre";
            cout << setw(8)  << "Tahun";
            cout << setw(15) << "Durasi";
            cout<< endl;
            cout << string(118, '-') << endl;

            // Isi tabel
            while (R != nullptr) {
                if (R->lagu == nullptr) {
                    cout << "Lagu telah dihapus dari sistem!" << endl;
                } else {
                    adr_lagu L = R->lagu;
                    cout << left;
                    cout << setw(10) << L->info.id_lagu;
                    cout << setw(20) << L->info.nama;
                    cout << setw(25) << L->info.judul;
                    cout << setw(20) << L->info.album;
                    cout << setw(20) << L->info.genre;
                    cout << setw(8)  << L->info.tahun;
                    cout << setw(15) << L->info.durasi;
                    cout<< endl;
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

void deletePlaylist_keongracun(adr_User user, int idPlaylist){
    adr_playlist P = searchIdPlaylist(user->Playlist, idPlaylist);

    if (P == nullptr){
        cout << "Playlist tidak ditemukan!" << endl;
    } else {
        // Hapus playlist dari DLL
        if (P == user->Playlist.first && P == user->Playlist.last){
            // Satu-satunya playlist
            user->Playlist.first = nullptr;
            user->Playlist.last = nullptr;
        }
        else if (P == user->Playlist.first){
            // Playlist pertama
            user->Playlist.first = P->next;
            if (user->Playlist.first != nullptr){
                user->Playlist.first->prev = nullptr;
            }
        }
        else if (P == user->Playlist.last){
            // Playlist terakhir
            user->Playlist.last = P->prev;
            if (user->Playlist.last != nullptr){
                user->Playlist.last->next = nullptr;
            }
        }
        else{
            // Playlist di tengah
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }

        // Lepaskan pointer playlist
        P->next = nullptr;
        P->prev = nullptr;

        cout << "Playlist \"" << P->info.nama << "\" berhasil dihapus!" << endl;
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
int jumlahLaguPlaylist(adr_playlist P){
    int count = 0;
    adr_relasi R = P->relasi.first;
    while (R != nullptr){
        count++;
        R = R->next;
    }
    return count;
}
// RELASI
void deleteRelasiLagu_keongracun(list_User &U, adr_lagu song){
    adr_User P = U.first;

    while (P != nullptr){
        // Cek jika lagu yang dihapus adalah currentSong user
        if (P->currentSong == song){
            P->currentSong = nullptr;
            P->activePlaylist = nullptr;
            cout << "Lagu yang sedang diputar oleh user \"" << P->info.username << "\" telah dihapus dari sistem." << endl;
        }

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
    adminAddLagu_keongracun(L, createNodeChild_keongracun(111, "LANY", "ILYSB", "ILYSB_EP", "Pop", 2015, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(112, "LANY", "Malibu_Nights", "Malibu_Nights", "Pop", 2018, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(113, "Juicy_Luicy", "Malapetaka", "Malapetaka_EP", "Rock", 2023, 4));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(114, "Sinta_Jojo", "Keong_Racun", "Viral", "Dangdut", 2010, 3));
    adminAddLagu_keongracun(L, createNodeChild_keongracun(115, "Rio_Flappy", "Bunga_Abadi", "Single", "Pop", 2020, 4));

}

// ===== MUSIC PLAYER FEATURES =====
void playSong_keongracun(adr_User user, adr_lagu song, adr_playlist playlist){
    if (song != nullptr){
        user->currentSong = song;
        user->activePlaylist = playlist;

        cout << "\n============================================" << endl;
        cout << "                  MEMUTAR LAGU                " << endl;
        cout << "==============================================" << endl;
        cout << "Artis     : " << song->info.nama << endl;
        cout << "Judul     : " << song->info.judul << endl;
        cout << "Album     : " << song->info.album << endl;
        cout << "Genre     : " << song->info.genre << endl;
        cout << "Tahun     : " << song->info.tahun << endl;
        cout << "Durasi    : " << song->info.durasi << " menit" << endl;
        cout << "Playlist  : " << playlist->info.nama << endl;
        cout << "============================================" << endl;
        cout << "Lagu sedang diputar" << endl;
    } else {
        cout << "Lagu tidak ditemukan!" << endl;
    }
}

void playSongFromLibrary_keongracun(adr_User user, adr_lagu song){
    if (song != nullptr){
        user->currentSong = song;
        user->activePlaylist = nullptr; // Library mode

        cout << "\n============================================" << endl;
        cout << "                  MEMUTAR LAGU               " << endl;
        cout << "=============================================" << endl;
        cout << "Artis     : " << song->info.nama << endl;
        cout << "Judul     : " << song->info.judul << endl;
        cout << "Album     : " << song->info.album << endl;
        cout << "Genre     : " << song->info.genre << endl;
        cout << "Tahun     : " << song->info.tahun << endl;
        cout << "Durasi    : " << song->info.durasi << " menit" << endl;
        cout << "Mode      : LIBRARY MODE" << endl;
        cout << "============================================" << endl;
        cout << "Lagu sedang diputar" << endl;
    } else {
        cout << "Lagu tidak ditemukan!" << endl;
    }
}

void stopSong_keongracun(adr_User user){
    if (user->currentSong != nullptr){
        cout << "\n============================================" << endl;
        cout << "               MENGHENTIKAN LAGU             " << endl;
        cout << "=============================================" << endl;
        cout << "Lagu      : " << user->currentSong->info.judul << endl;
        cout << "Artis     : " << user->currentSong->info.nama << endl;
        cout << "============================================" << endl;
        cout << "Lagu telah dihentikan." << endl;

        user->currentSong = nullptr;
        user->activePlaylist = nullptr;
    } else {
        cout << "Tidak ada lagu yang sedang diputar!" << endl;
    }
}

void showNowPlaying_keongracun(adr_User user){
    if (user->currentSong != nullptr){
        cout << "\n============================================" << endl;
        cout << "NOW PLAYING" << endl;
        cout << "============================================" << endl;
        cout << "Artis     : " << user->currentSong->info.nama << endl;
        cout << "Judul     : " << user->currentSong->info.judul << endl;
        cout << "Album     : " << user->currentSong->info.album << endl;
        cout << "Genre     : " << user->currentSong->info.genre << endl;
        cout << "Tahun     : " << user->currentSong->info.tahun << endl;
        cout << "Durasi    : " << user->currentSong->info.durasi << " menit" << endl;

        if (user->activePlaylist != nullptr){
            cout << "Playlist  : " << user->activePlaylist->info.nama << endl;
        } else {
            cout << "Mode      : LIBRARY MODE" << endl;
        }
        cout << "============================================" << endl;
    } else {
        cout << "Tidak ada lagu yang sedang diputar!" << endl;
    }
}

void nextSong_keongracun(adr_User user, list_lagu L){
    if (user->currentSong == nullptr){
        cout << "Tidak ada lagu yang sedang diputar!" << endl;
    } else {
        adr_lagu nextSong = nullptr;

        // Mode Playlist: ikuti urutan relasi di playlist
        if (user->activePlaylist != nullptr){
            adr_relasi R = user->activePlaylist->relasi.first;
            while (R != nullptr){
                if (R->lagu == user->currentSong){
                    if (R->next != nullptr && R->next->lagu != nullptr){
                        nextSong = R->next->lagu;
                    }
                    break;
                }
                R = R->next;
            }

            if (nextSong != nullptr){
                user->currentSong = nextSong;
                cout << "\n============================================" << endl;
                cout << "            NEXT SONG (PLAYLIST)            " << endl;
                cout << "============================================" << endl;
                cout << "Artis     : " << nextSong->info.nama << endl;
                cout << "Judul     : " << nextSong->info.judul << endl;
                cout << "Playlist  : " << user->activePlaylist->info.nama << endl;
                cout << "============================================" << endl;
                cout << "Lagu sedang diputar" << endl;
            } else {
                cout << "Sudah di lagu terakhir dalam playlist!" << endl;
            }
        }
        // Mode Library: cari lagu mirip (genre atau tahun ±3)
        else {
            string currentGenre = user->currentSong->info.genre;
            int currentYear = user->currentSong->info.tahun;

            // Prioritas 1: Cari genre yang sama
            adr_lagu p = L.first;
            while (p != nullptr && nextSong == nullptr){
                if (p != user->currentSong && p->info.genre == currentGenre){
                    nextSong = p;
                }
                p = p->next;
            }

            // Prioritas 2: Cari tahun ±3
            if (nextSong == nullptr){
                p = L.first;
                while (p != nullptr && nextSong == nullptr){
                    if (p != user->currentSong){
                        int rangeTahun = p->info.tahun - currentYear;
                        if (rangeTahun >= -3 && rangeTahun <= 3){
                            nextSong = p;
                        }
                    }
                    p = p->next;
                }
            }

            if (nextSong != nullptr){
                user->currentSong = nextSong;
                cout << "\n============================================" << endl;
                cout << "        NEXT SONG (REKOMENDASI)             " << endl;
                cout << "============================================" << endl;
                cout << "Artis     : " << nextSong->info.nama << endl;
                cout << "Judul     : " << nextSong->info.judul << endl;
                cout << "Genre     : " << nextSong->info.genre << endl;
                cout << "Tahun     : " << nextSong->info.tahun << endl;
                cout << "============================================" << endl;
                cout << "Lagu sedang diputar" << endl;
            } else {
                cout << "Tidak ada lagu rekomendasi yang ditemukan!" << endl;
            }
        }
    }
}

void prevSong_keongracun(adr_User user, list_lagu L){
    if (user->currentSong == nullptr){
        cout << "Tidak ada lagu yang sedang diputar!" << endl;
    } else {
        adr_lagu prevSong = nullptr;

        // Mode Playlist: ikuti urutan relasi di playlist
        if (user->activePlaylist != nullptr){
            adr_relasi R = user->activePlaylist->relasi.first;
            while (R != nullptr){
                if (R->lagu == user->currentSong){
                    if (R->prev != nullptr && R->prev->lagu != nullptr){
                        prevSong = R->prev->lagu;
                    }
                    break;
                }
                R = R->next;
            }

            if (prevSong != nullptr){
                user->currentSong = prevSong;
                cout << "\n============================================" << endl;
                cout << "          PREVIOUS SONG (PLAYLIST)          " << endl;
                cout << "============================================" << endl;
                cout << "Artis     : " << prevSong->info.nama << endl;
                cout << "Judul     : " << prevSong->info.judul << endl;
                cout << "Playlist  : " << user->activePlaylist->info.nama << endl;
                cout << "============================================" << endl;
                cout << "Lagu sedang diputar" << endl;
            } else {
                cout << "Sudah di lagu pertama dalam playlist!" << endl;
            }
        }
        // Mode Library: cari lagu mirip (genre atau tahun ±3) dari belakang
        else {
            string currentGenre = user->currentSong->info.genre;
            int currentYear = user->currentSong->info.tahun;

            // Prioritas 1: Cari genre yang sama dari belakang
            adr_lagu p = L.last;
            while (p != nullptr && prevSong == nullptr){
                if (p != user->currentSong && p->info.genre == currentGenre){
                    prevSong = p;
                }
                p = p->prev;
            }

            // Prioritas 2: Cari tahun ±3 dari belakang
            if (prevSong == nullptr){
                p = L.last;
                while (p != nullptr && prevSong == nullptr){
                    if (p != user->currentSong){
                        int rangeTahun = p->info.tahun - currentYear;
                        if (rangeTahun >= -3 && rangeTahun <= 3){
                            prevSong = p;
                        }
                    }
                    p = p->prev;
                }
            }

            if (prevSong != nullptr){
                user->currentSong = prevSong;
                cout << "\n============================================" << endl;
                cout << "       PREVIOUS SONG (REKOMENDASI)          " << endl;
                cout << "============================================" << endl;
                cout << "Artis     : " << prevSong->info.nama << endl;
                cout << "Judul     : " << prevSong->info.judul << endl;
                cout << "Genre     : " << prevSong->info.genre << endl;
                cout << "Tahun     : " << prevSong->info.tahun << endl;
                cout << "============================================" << endl;
                cout << "Lagu sedang diputar" << endl;
            } else {
                cout << "Tidak ada lagu rekomendasi yang ditemukan!" << endl;
            }
        }
    }
}

void menuMusicPlayer_keongracun(adr_User user, list_lagu &L){
    int pilihan;
    do{
        cout << "\n============================================" << endl;
        cout << "                  MUSIC PLAYER                " << endl;
        cout << "==============================================" << endl;

        // Show now playing status if any
        if (user->currentSong != nullptr){
            cout << "Now Playing: " << user->currentSong->info.judul
                 << " - " << user->currentSong->info.nama;
            if (user->activePlaylist != nullptr){
                cout << " [PLAYLIST: " << user->activePlaylist->info.nama << "]";
            } else {
                cout << " [LIBRARY]";
            }
            cout << endl << endl;
        }

        cout << "1. Pilih & Play Lagu dari Playlist" << endl;
        cout << "2. Play Lagu dari Library" << endl;
        cout << "3. Stop Lagu" << endl;
        cout << "4. Now Playing (Info Detail)" << endl;
        cout << "5. Next Song" << endl;
        cout << "6. Previous Song" << endl;
        cout << "0. Kembali ke Menu User" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:{
                clearScreen();
                displayAllPlaylist(user);

                if (user->Playlist.first != nullptr){
                    int idPlaylist;
                    cout << "\nPilih ID Playlist: ";
                    cin >> idPlaylist;

                    adr_playlist P = searchIdPlaylist(user->Playlist, idPlaylist);
                    if (P != nullptr){
                        clearScreen();
                        displaySongsInPlaylist_keongracun(P);

                        if (P->relasi.first != nullptr){
                            int idLagu;
                            cout << "\nMasukkan ID Lagu untuk diputar: ";
                            cin >> idLagu;

                            adr_lagu song = searchIdLagu_keongracun(L, idLagu);
                            if (song != nullptr){
                                playSong_keongracun(user, song, P);
                            } else {
                                cout << "Lagu tidak ditemukan!" << endl;
                            }
                        }
                    } else {
                        cout << "Playlist tidak ditemukan!" << endl;
                    }
                }
                break;
            }
            case 2:{
                clearScreen();
                displayAllLagu_keongracun(L);

                int idLagu;
                cout << "\nMasukkan ID Lagu untuk diputar: ";
                cin >> idLagu;

                adr_lagu song = searchIdLagu_keongracun(L, idLagu);
                playSongFromLibrary_keongracun(user, song);
                break;
            }
            case 3:
                stopSong_keongracun(user);
                break;
            case 4:
                showNowPlaying_keongracun(user);
                break;
            case 5:
                nextSong_keongracun(user, L);
                break;
            case 6:
                prevSong_keongracun(user, L);
                break;
            case 0:
                cout << "Kembali ke menu utama" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
    while (pilihan != 0);
}
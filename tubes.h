#ifndef TUBES_H
#define TUBES_H


#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef struct elmlist_user *adr_User;
typedef struct elmlist_lagu *adr_lagu;
typedef struct elmlist_playlist *adr_playlist;
typedef struct elmlist_relasi *adr_relasi;

// info User
struct infotype_user{
    int id;
    string username;
    string role;
};

// List Parent
struct list_playlist{
    adr_playlist first;
    adr_playlist last;
};

// Node User
struct elmlist_user{
    infotype_user info;
    adr_User next;
    list_playlist Playlist;
};

// info Child
struct infotype_lagu{
    string nama,judul, album, genre;
    int id_lagu, tahun, durasi;
};

// Node Child
struct elmlist_lagu{
    infotype_lagu info;
    adr_lagu next;
    adr_lagu prev;
};

// info Parent
struct infotype_playlist{
    int id;
    string nama;
};

// List relasi
struct list_relasi{
    adr_relasi first;
    adr_relasi last;
};

// Node Parent
struct elmlist_playlist{
    infotype_playlist info;
    adr_playlist next;
    adr_playlist prev;
    adr_relasi firstRelasi;
    list_relasi relasi;
};

// Node Relasi
struct elmlist_relasi{
    adr_playlist playlist;
    adr_lagu lagu;
    adr_relasi next;
    adr_relasi prev;
};

// List User
struct list_User{
    adr_User first;
    adr_User last;
};

// List Child
struct list_lagu{
    adr_lagu first;
    adr_lagu last;
};

//Clear Screen
void clearScreen();

// ===== CREATE LIST =====
void createUser_keongracun(list_User &U);
void createParent_keongracun(list_playlist &P);
void createChild_keongracun(list_lagu &L);
void createRelasi_keongracun(list_relasi &R);

// ===== CEK KOSONG =====
bool isUserEmpty_keongracun(list_User U);
bool isParentEmpty_keongracun(list_playlist P);
bool isChildEmpty_keongracun(list_lagu L);
bool isRelasiEmpty_keongracun(list_relasi R);

// ===== CREATE NODE =====
adr_User createNodeUser_keongracun(int id, string usn, string peran);
adr_playlist createNodeParent_keongracun(int id, string nama);
adr_lagu createNodeChild_keongracun(int idlagu, string nama, string judul, string album, string genre, int tahun, int durasi);
adr_relasi createNodeRelasi_keongracun(adr_playlist P, adr_lagu L);

// ===== fitur admin =====
void menuAdmin_keongracun(list_User &U,list_lagu &L);
void adminAddLagu_keongracun(list_lagu &L, adr_lagu song);
void displayAllLagu_keongracun(list_lagu L);
adr_lagu searchIdLagu_keongracun(list_lagu L, int idLagu);
void updateLagu_keongracun(adr_lagu L, string new_nama, string new_judul, string new_album, string new_genre, int new_tahun,
                           int new_durasi);
void adminDeleteLagu_keongracun(list_User &U, list_lagu &L, int id);
void deleteLagu_keongracun(list_lagu &L, adr_lagu &song);

// ===== fitur user =====
void addUser_keongracun(list_User &U, adr_User userBaru);
void menuUser_keongracun(adr_User user, list_lagu &L);
adr_User searchUser_keongracun(list_User U, string username);
adr_playlist searchIdPlaylist(list_playlist P, int id);
void addSongToPlaylist_keongracun(adr_playlist P, adr_lagu L);
void deleteSongFromPlaylist_keongracun(adr_playlist P, int idLagu);
void displaySongsInPlaylist_keongracun(adr_playlist P);
void userAddPlaylist_keongracun(adr_User user, int id, string nama);
void DummyLagu_keongracun(list_lagu &L);
void displayAllPlaylist(adr_User user);

// RELASI
void deleteRelasiLagu_keongracun(list_User &U, adr_lagu song);

#endif
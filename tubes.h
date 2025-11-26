#ifndef TUBES_H
#define TUBES_H

#include <iostream>
using namespace std;

typedef struct elmlist_user *adr_User;
typedef struct elmlist_lagu *adr_lagu;
typedef struct elmlist_playlist *adr_playlist;
typedef struct elmlist_relasi *adr_relasi;

struct infotype_user{
    int id;
    string username;
    string role;
};
struct elmlist_user{
    infotype_user info;
    adr_User next;
    adr_playlist playlist;
};
struct infotype_lagu{
    string judul, album, genre;
    int id_lagu, tahun, durasi;
};
struct elmlist_lagu{
    infotype_lagu info;
    adr_lagu next;
    adr_lagu prev;
};
struct infotype_playlist{
    int id;
    string nama;
};
struct elmlist_playlist{
    infotype_playlist info;
    adr_playlist next;
};
struct elmlist_relasi{
    adr_playlist playlist;
    adr_lagu lagu;
    adr_relasi next;
};

struct user{
    adr_User first;
    adr_User last;
};
struct list_lagu{
    adr_lagu first;
    adr_lagu last;
};
struct list_playlist{
    adr_playlist first;
    adr_playlist last;
};
struct list_relasi{
    adr_relasi first;
    adr_relasi last;
};

void createUser_keongracun(list_User &U);
void createParent_keongracun(list_playlist &P);
void createChild_keongracun(list_lagu &L);
void createRelasi__keongracun(list_relasi &R);

bool isUserEmpty_keongracun(adr_User U);
bool isParentEmpty_keongracun(adr_playlist P);
bool isChildEmpty_keongracun(adr_lagu L);
bool isRelasiEmpty_keongracun(adr_relasi R);

adr_User createNodeUser_keongracun(int id, string usn, string peran);
adr_playlist createNodeParent_keongracun(int id, string nama);
adr_lagu createNodeChild_keongracun(string judul, string album, string genre, int idlagu, int tahun, int durasi);
adr_relasi createNodeRelasi_keongracun(adr_playlist P, adr_lagu L);


#endif
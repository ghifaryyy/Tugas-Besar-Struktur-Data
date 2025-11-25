#ifndef TUBES_H
#define TUBES_H

#include <iostream>
using namespace std;


typedef struct elmlist_lagu* adr_lagu;
struct infotype_lagu{
    string judul, artis, album, genre;
    int tahun, durasi;
}
struct elmlist_lagu{
    infotype_lagu info;
    adr_lagu next;
};



#endif
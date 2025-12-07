#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "tubes.h"
using namespace std;

int main()
{
    list_User U;
    list_lagu L;
    list_playlist P;
    list_relasi R;
    createUser_keongracun(U);
    createChild_keongracun(L);
    createParent_keongracun(P);
    createRelasi_keongracun(R);
    DummyLagu_keongracun(L);

    adr_User userBaru1 = createNodeUser_keongracun(1, "nevia", "user");
    adr_User userBaru2 = createNodeUser_keongracun(2, "gipari", "user");
    addUser_keongracun(U, userBaru1);
    addUser_keongracun(U, userBaru2);

    int pilih;

    do {
        cout << "========================================" << endl;
        cout << "               MENU LOGIN               " << endl;
        cout << "========================================" << endl;
        cout << "1. Login Admin" << endl;
        cout << "2. Login User" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
        case 1:
            menuAdmin_keongracun(U, L);
            break;

        case 2:{
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            adr_User user = searchUser_keongracun(U, username);
            if (user != nullptr && password == user->info.username){
                cout << "Login Berhasil!" << endl;
                menuUser_keongracun(user, L);
            }
            break;
        }
        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
    while (pilih != 0);
}


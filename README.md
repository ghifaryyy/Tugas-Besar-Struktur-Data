# MUSIKKUY
## 🎵 Console Music Player & Playlist Manager
## 📝 Gambaran Umum (Overview)
Aplikasi ini adalah sistem manajemen musik dan pemutar lagu berbasis **Command Line Interface (CLI)**. Dibangun menggunakan bahasa C++, program ini mengimplementasikan struktur data kompleks menggunakan **Multi Linked List** untuk memodelkan relasi antara *User*, *Playlist*, dan *Lagu*.


## ✨ Fitur Utama (Key Features)

### 🔐 1. Sistem Autentikasi (Role-Based Login)
Aplikasi membatasi akses fitur berdasarkan peran pengguna:
* **Admin:** Akses penuh ke *backend* library musik.
* **User:** Akses ke fitur personal (playlist & player). Login divalidasi dengan mencocokkan *username* dan *password* (Contoh: user `nevia`, password `nevia`).

### 👨‍💻 2. Admin Mode (Global Music Management)
Admin bertugas mengelola **Repository Lagu Utama** dengan fitur CRUD lengkap:
* **Create (Add Song):** Menambahkan data lagu baru ke dalam Library pusat.
* **Read (View Library):** Melihat daftar seluruh lagu yang tersedia beserta atribut lengkapnya (Judul, Artis, Album, Genre, Tahun, Durasi).
* **Update:** Mengubah informasi/atribut lagu yang sudah ada.
* **Delete:** Menghapus lagu dari database utama. **PENTING:** Jika Admin menghapus sebuah lagu, maka lagu tersebut akan **otomatis terhapus juga dari seluruh playlist User** yang menyimpannya.

### 🎧 3. User Mode (Personalized Experience)
Setiap user memiliki struktur data independen dengan fitur:
* **Create Playlist:** Membuat daftar putar (playlist) baru.
* **Delete Playlist:** Menghapus playlist yang sudah tidak diinginkan.
* **Add Song to Playlist:** Menambahkan lagu dari Library utama ke dalam Playlist pribadi (Membangun relasi).
* **Remove Song from Playlist:** Menghapus lagu dari playlist tanpa menghapusnya dari Library utama.
* **Search:** Mencari lagu berdasarkan nama Artis dan Judul Lagu.

### 🎶 4. Intelligent Music Player
Pemutar musik simulasi dengan logika navigasi kontekstual:
* **Context Awareness:** Player mendeteksi apakah user sedang memutar dari *Playlist* atau *Library*.
* **Now Playing Info:** Menampilkan metadata lengkap lagu yang sedang diputar.
* **Navigation Logic:**
    * **Playlist Mode:** Tombol `Next` / `Prev` memutar lagu sesuai urutan antrian dalam playlist user.
    * **Library Mode (Smart Recs):** Jika memutar langsung dari Library, fitur `Next` / `Prev` menggunakan **Algoritma Rekomendasi**. Sistem akan mencari lagu selanjutnya yang memiliki **Genre sama** atau **Tahun rilis berdekatan (± 3 tahun)**.

## 🛠️ Spesifikasi Teknis (Data Structures)
Proyek ini menggunakan implementasi pointer manual dengan arsitektur **Full Doubly Linked List (DLL)** pada semua komponennya untuk memungkinkan traversal data dua arah (maju/mundur):

1.  **List User (DLL):** Menyimpan data akun pengguna.
2.  **List Lagu (Child - DLL):** Menyimpan data master lagu secara global.
3.  **List Playlist (Parent - DLL):** List playlist yang dimiliki oleh setiap User.
4.  **List Relasi (DLL):** Menghubungkan *Parent* (Playlist) dengan *Child* (Lagu). Memungkinkan relasi *Many-to-Many* (Satu lagu bisa ada di banyak playlist, satu playlist berisi banyak lagu).

## 🚀 Cara Menjalankan (Installation)

### Prasyarat
* Compiler C++ (MinGW / G++).
* Terminal / CMD.

### Langkah-langkah
1.  **Clone repository** atau download source code.
2.  **Compile program** (pastikan semua file .cpp dan .h dalam satu folder):
    ```bash
    g++ main.cpp tubes.cpp -o musicplayer
    ```
3.  **Jalankan aplikasi:**
    * Windows: `musicplayer.exe`
    * Linux/Mac: `./musicplayer`

## 🔑 Akun Demo (Credentials)
Gunakan akun berikut untuk pengujian fitur **User**:

| Role | Username | Password |
| :--- | :--- | :--- |
| **User 1** | `nevia` | `nevia` |
| **User 2** | `gipari` | `gipari` |

*Catatan: Pilih menu **1. Login Admin** pada halaman awal untuk masuk sebagai Admin (Developer Mode).*

## 👥 Authors
Dikembangkan untuk Tugas Besar Struktur Data.

* **Nevia** (Luthfia Maulidya Izzati)
* **Ghifary** (Ghifary Wibisono)

---
*Created with ❤️ using C++ and Doubly Linked Lists.*

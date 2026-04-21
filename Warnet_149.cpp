#include <iostream>
using namespace std;

int main() {
    int jam_mulai, menit_mulai, jam_selesai, menit_selesai;
    int total_menit, jumlah_jam, jam_asli, sisa_menit;
    int biaya, denda, total_tagihan;

    cout << "========================================" << endl;
    cout << "   SELAMAT DATANG DI WARNET JANGETKNET  " << endl;
    cout << "        BILLING SYSTEM UNI ACA          " << endl;
    cout << "========================================" << endl;

    do {
        cout << "Masukkan Jam Mulai     (0-23) : ";
        cin >> jam_mulai;
        if (jam_mulai < 0 || jam_mulai > 23) {
            cout << "Input tidak valid, masukkan lagi!" << endl;
        }
    } while (jam_mulai < 0 || jam_mulai > 23);

    do {
        cout << "Masukkan Menit Mulai   (0-59) : ";
        cin >> menit_mulai;
        if (menit_mulai < 0 || menit_mulai > 59) {
            cout << "Input tidak valid, masukkan lagi!" << endl;
        }
    } while (menit_mulai < 0 || menit_mulai > 59);

    do {
        cout << "Masukkan Jam Selesai   (0-23) : ";
        cin >> jam_selesai;
        if (jam_selesai < 0 || jam_selesai > 23) {
            cout << "Input tidak valid, masukkan lagi!" << endl;
        }
    } while (jam_selesai < 0 || jam_selesai > 23);

    do {
        cout << "Masukkan Menit Selesai (0-59) : ";
        cin >> menit_selesai;
        if (menit_selesai < 0 || menit_selesai > 59) {
            cout << "Input tidak valid, masukkan lagi!" << endl;
        }
    } while (menit_selesai < 0 || menit_selesai > 59);

    // hitung total menit
    int waktu_mulai_total   = jam_mulai   * 60 + menit_mulai;
    int waktu_selesai_total = jam_selesai * 60 + menit_selesai;

    if (jam_selesai < jam_mulai || (jam_selesai == jam_mulai && menit_selesai < menit_mulai)) {
        waktu_selesai_total = waktu_selesai_total + 1440;
    }

    total_menit = waktu_selesai_total - waktu_mulai_total;

    jam_asli   = total_menit / 60;
    sisa_menit = total_menit % 60;

    // jumlah jam untuk hitung biaya (dibulatkan ke atas)
    jumlah_jam = total_menit / 60;
    if (total_menit % 60 != 0) {
        jumlah_jam = jumlah_jam + 1;
    }

    // hitung biaya
    denda = 0;

    if (total_menit <= 30) {
        biaya = 5000;
    } else if (total_menit <= 120) {
        biaya = jumlah_jam * 7000;
    } else if (total_menit <= 300) {
        biaya = jumlah_jam * 6000;
    } else {
        biaya = jumlah_jam * 5000;
        denda = 10000;
        cout << "ANDA MELEBIHI BATAS WAKTU WAJAR! DENDA RP 10.000 DIKENAKAN." << endl;
    }

    total_tagihan = biaya + denda;

    // output struk
    cout << endl;
    cout << "--- STRUK TAGIHAN ---" << endl;

    cout << "Waktu Mulai    : ";
    if (jam_mulai < 10) cout << "0";
    cout << jam_mulai << ":";
    if (menit_mulai < 10) cout << "0";
    cout << menit_mulai << endl;

    cout << "Waktu Selesai  : ";
    if (jam_selesai < 10) cout << "0";
    cout << jam_selesai << ":";
    if (menit_selesai < 10) cout << "0";
    cout << menit_selesai << endl;

    cout << "Durasi         : " << jam_asli << " Jam " << sisa_menit << " Menit (" << total_menit << " Menit)" << endl;

    cout << "Kategori       : ";
    if (total_menit <= 30) {
        cout << "0 - 30 Menit (Flat Rp 5.000)" << endl;
    } else if (total_menit <= 120) {
        cout << "31 - 120 Menit (Rp 7.000/jam)" << endl;
    } else if (total_menit <= 300) {
        cout << "121 - 300 Menit (Rp 6.000/jam)" << endl;
    } else {
        cout << "> 300 Menit (Rp 5.000/jam)" << endl;
    }

    cout << endl;
    if (total_menit <= 30) {
        cout << "Perhitungan    : Flat = Rp " << biaya << endl;
    } else if (total_menit <= 120) {
        cout << "Perhitungan    : " << jumlah_jam << " Jam x Rp 7000 = Rp " << biaya << endl;
    } else if (total_menit <= 300) {
        cout << "Perhitungan    : " << jumlah_jam << " Jam x Rp 6000 = Rp " << biaya << endl;
    } else {
        cout << "Perhitungan    : " << jumlah_jam << " Jam x Rp 5000 = Rp " << biaya << endl;
    }

    if (denda > 0) {
        cout << "Denda          : Rp " << denda << endl;
    }

    cout << "------------------------------------" << endl;
    cout << "TOTAL TAGIHAN  : Rp " << total_tagihan << endl;
    cout << "====================================" << endl;

    return 0;
}
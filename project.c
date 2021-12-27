#include <stdio.h>
#include <stdlib.h>
#define MAKS 50

struct nomor
{
    int tahun, tebal;
};

struct string
{
    char judul[100], pengarang[100], penerbit[100], jenis[100];
    struct nomor buku;
};

struct string data_buku[MAKS] = {
    {"Dilan 1990", "Pidi Baiq", "P.T. Mizan Pustaka", "Romansa", 2014, 332},
    {"Koala Kumal", "Raditya Dika", "Gagas Media", "Komedi, Romansa", 2015, 250},
    {"Chairul Tanjung Si Anak Singkong", "Tjahja Gunawan Diredja", "PT Kompas Media Nusantara", "Biografi", 2012, 384},
};

int N = 3;

void cetak(struct string B)
{

    printf("\n-------input--------\n");
    printf("judul = %s\n", B.judul);
    printf("pengarang = %s\n", B.pengarang);
    printf("penerbit = %s\n", B.penerbit);
    printf("jenis = %s\n", B.jenis);
    printf("tahun = %d\n", B.buku.tahun);
    printf("tebal = %d\n", B.buku.tebal);
}

void cetak_buku(struct string B[])
{
    for (int i = 0; i < N; i++)
    {
        cetak(B[i]);
    }
}

void input2(struct string *B)
{

    printf("\n-------input--------\n");
    fflush(stdin);
    printf("masukkan judul= ");
    fgets((*B).judul, 30, stdin);
    printf("masukkan pengarang= ");
    fgets((*B).pengarang, 30, stdin);
    printf("masukkan penerbit= ");
    fgets((*B).penerbit, 30, stdin);
    printf("masukkan jenis= ");
    fgets((*B).jenis, 30, stdin);
    fflush(stdin);
    printf("masukkan tahun= ");
    scanf(" %d", &(*B).buku.tahun);
    printf("masukkan tebal= ");
    scanf(" %d", &(*B).buku.tebal);
}

void search2(char buku[])
{
    char judul[100];
    printf("search buku = ");
    scanf("%s", judul);
    for (int i = 0; i < N; i++)
    {
        if (strcmpi(data_buku[i].judul, buku) == 0)
        {
            cetak(data_buku[i]);
        }
    }
}

void delete (int index)
{
    for (int i = index; i < N - 1; i++)
    {
        data_buku[i] = data_buku[i + 1];
    }
    N = N - 1;
}

void tambah(int index)
{
    int n;

    printf("Masukkan jumlah buku yang ditambahkan! ");
    scanf("%d", &n);
    N = N + n; //3+2=5

    for (int i = 1; i <= n; i++)
    {
        input2(&data_buku[N - i]);
        cetak_buku(data_buku);
    }

    //cetak_(data_mhs[index]);
}

int main()
{
    char caribuku, loop = 'Y';
    int index, opt;

    do
    {
        puts("\t\t========================================\t\t");
        puts("\t\t PROTOTIPE PEMBENDAHARAAN PERPUSTAKAAN\t\t");
        puts("\t\t----------------------------------------\t\t");
        puts("\t\t                  MENU\t\t\n");
        puts("\t\t1. TAMPILKAN DAFTAR BUKU");
        puts("\t\t2. TAMBAHKAN BUKU KE DAFTAR INVENTARIS");
        puts("\t\t3. CARI BUKU");
        puts("\t\t4. HAPUS BUKU");
        puts("\t\t========================================\t\t");
        puts("\t\tPilihan: ");
        scanf("%d", &opt);

        if (opt == 1)
        {
            cetak_buku(data_buku);
        }

        else if (opt == 2)
        {
            tambah(data_buku);
        }

        else if (opt == 3)
        {
            search2(data_buku);
        }
        else if (opt == 4)
        {
            printf("delete pada index = ");
            scanf("%d", &index);
            delete (index);
            cetak_buku(data_buku);
        }

        puts("Lanjut?");
        scanf(" %c", &loop);
    }

    while (loop == 'y' || loop == 'Y');
}
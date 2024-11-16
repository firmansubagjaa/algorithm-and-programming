# Kelompok Process

## Sequence Process

- Pada sequence proses seluruh instruksi dikerjakan sesuai dengan satu demi satu sesuai dengan susunan dari instruksi pertama hingga instruks terakhir. Instruksi kedua akan dikerjakan setelah instruksi pertama selesai dikerjakan.
- Contoh:

```c
// Sequence Process
printf("Halo! ");
printf("Selamat data.");
```

- Output akan selalu menampilkan: "Halo! Selamat data." secara berurutan.

## Selection Process:

- Suatu instruksi akan boleh dikerjakan jika memenuhi persyaratan yang telah ditentukan sebelumnya. C menyediakan tiga jenis struktur seleksi dalam bentuk pernyataan, antara lain :
  - if single-selection statement
  - if...else double-selection statement
  - switch multiple-selection statement.
- Contoh:

```c
// Selection Process
int angka = 10;
if (angka > 5) {
   printf("Angka lebih besar dari 5.");
} else {
   printf("Angka tidak lebih besar dari 5.")
}
```

## Iteration process

- Suatu instruksi dapat dikerjkana berulan-ulang selama suatu kondisi terpenuhi. Misalnya jika suatu instruksi meminta inputan dari pengguna program.
- C menyediakan tiga jenis struktur iterasi dalam bentuk pernyataan, yaitu while, do...while, dan for. Pernyataan ini melakukan tugas berulang kali. Sebagai contoh:

```c
for (int i = 1; i <= 5; i++) {
   printf("%d\n",i);
}
```

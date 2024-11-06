/*
   Mendefinisikan masalah
      Membuat program untuk memasukkan dan menampilkan
      data anggota yang terdiri dari
         title,
         author,
         year
      lalu membuat sebuah fungsi yang menerima variabel
      bertipe Book dan mencetak informasi buku tersebut

   Membuat model
   mungkin lebih ke cara kerja, bisa dijelaskan pada
   perancangan algoritma.

   Perancangan Algoritma
   START
      set struct Book {
         title as string;
         author as string;
         year as int;
      }
      set function insertDataBook (title, author, year) as void
         showing "Masukkan judul buku: "
         input title from user
         showing "Masukkan pengarang buku: "
         input author from user
         showing "Masukkan tahun terbit buku: "
         input year from user
      end function

      set function showingDataBook (title, author, year) as void
         showing "Title: [title]\nAuthor: [author]\nYear: [year]"
      end function

      set main()
         set book1 as Book from struct
         call function insertDataBook(book1.title, book1.author, book1.year)
         call function showingDataBook(book1.title, book1.author, book1.year)
      end main
   END
*/

#include <stdio.h>

struct Book
{
   char title[100];
   char author[100];
   int year;
};

void insertDataBook(struct Book *bk) {
   printf("Masukkan judul buku: ");
   scanf("%s", bk->title);
   printf("Masukkan pengarang buku: ");
   scanf("%s", bk->author);
   printf("Masukkan tahun terbit buku: ");
   scanf("%d", &bk->year);
}

void showingDataBook(struct Book bk) {
   printf("Title: %s\nAuthor: %s\nYear: %d", bk.title, bk.author, bk.year);
}

int main() {
   struct Book bk1;
   insertDataBook(&bk1);
   showingDataBook(bk1);
   return 0;
}

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(){
  struct stat *a = malloc(sizeof(struct stat));
  stat("text.txt", a);
  printf("\nfile size: %ld\n", a->st_size);
  printf("mode in octal: %o\n", a->st_mode);
  printf("time of last access: %s\n", ctime(&(a->st_atime)));
  printf("readable file size:\n");
  printf("\t%ldB\n", a->st_size);
  printf("\t%ldKB\n", (a->st_size / 1024.0));
  printf("\t%ldMB\n", (a->st_size / 1024.0 / 1024.0);
  printf("\t%ldGB\n", (a->st_size / 1024.0 / 1024.0 / 1024.0);
  
}

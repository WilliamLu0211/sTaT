#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

char* get_permission(mode_t m){
  char* permission = malloc(11);
  strcpy(permission, "-");
  m %= 01000;
  char str[] = "r\0w\0x";
  char l[9];
  for (int i = 0; i < 9; i ++){
    l[8 - i] = m % 2;
    m /= 2;
  }

  int i;
  for (i = 0; i < 9; i ++)
    if (l[i])
      strcat(permission, &str[2 * (i % 3)]);
    else
      strcat(permission, "-");

  return permission;
}

int main(){
  struct stat *a = malloc(sizeof(struct stat));
  stat("text.txt", a);
  printf("\nfile size: %ld\n", a->st_size);
  printf("mode in octal: %o\n", a->st_mode);
  printf("time of last access: %s\n", ctime(&(a->st_atime)));

  printf("readable file size:\n");
  double size = a->st_size;
  printf("\t%ldB\n", (long)size);
  size /= 1024.0;
  printf("\t%lfKB\n", size);
  size /= 1024.0;
  printf("\t%lfMB\n", size);
  size /= 1024.0;
  printf("\t%lfGB\n", size);

  printf("\n");

  printf("readable permission:\n");
  printf("\t%s\n", get_permission(a->st_mode));
}

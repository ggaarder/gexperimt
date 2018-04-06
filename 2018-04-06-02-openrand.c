// $ tcc 2018-04-06-02-openrand.c
// $ ./a.out 
// errno: 0
// Segmentation fault

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>

int main() {
  int fd = open("/dev/random", O_RDONLY);
  printf("errno: %d\n", errno);
  char *buf = mmap(NULL, BUFSIZ, PROT_READ, MAP_PRIVATE, fd, 0);
  printf("%c\n", *buf);
  return 0;
}

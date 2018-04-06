// When I was writing NNMNIST I forgot to return a function and surprisingly, it returns automatically.
//
// Why?
//
// I just forgot to add `return` to a function and surprisingly found that it automatically returns itself. Why?
//
// The code is sent together as attachment.
//
// The output is:
//    $ tcc 2018-04-06-03-noret.c
//    $ ./a.out 
//    233 9.300000 X 3.140000 466 23.900000
//    $ gcc 2018-04-06-03-noret.c
//    $ ./a.out 
//    0 9.300000  3.140000 0 23.900000
//
// It shows that under tcc every function automatically returned the last initialized value, but under gcc only functions returning a real number do that.
//
// It's so strange. I thought it should have something to do with the stack.
//
// 2018-04-06 Will send this to comp.lang.c. I have no time to configure Gnus right now.

#include <stdio.h>

int a() {
  int x = 233, y;
}

float b() {
  float v = 9.30, x;
}

char c() {
  char v = 'X', x;
}

double d() {
  double v = 3.14F, x;
}

int e() {
  int x = 233, y = 466;
}

float f() {
  float x = 9.30, y = 23.9;
}

int main() {
  printf("%d %f %c %lf %d %lf\n", a(), b(), c(), d(), e(), f());
}

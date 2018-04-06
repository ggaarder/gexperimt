// Let one child segmentation fault. Will the father exit too?
//
// No.
// Result:
//   $ tcc forksegv.c; ./a.out 
//   Forked 10401
//   10401: Signal SIGSEGV (11) received
//   Daddy!
//
// Thanks the Wim Sturkenboom@linuxquestions.org gave me the idea to use signals to recognize the segmentation fault of the child process. You can see the post at www.linuxquestions.org/questions/programming-9/how-to-log-segmentation-fault-in-forked-child-380703. The child process won't print normal Segmentation Fault message to the console.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handleseg(int signum) {
  fprintf(stderr, "%d: Signal SIGSEGV (%d) received\n", getpid(), signum);
  exit(0);
}

int main() {
  int *p, pid = fork();
  signal(SIGSEGV, handleseg);

  if (pid == 0) {
    for (p = 0; ; ++p) {
      printf("Daddy!");
      putchar(*p);
    }
  } else {
    printf("Forked %d\n", pid);
    while (1);
  }
}

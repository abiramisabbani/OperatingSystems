#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#define READ  0
#define WRITE 1
#define stdin 0
#define stdout 1
#define stderr 2

void sieve(int *from_pipeline) {
  int p, n, k;
  int pid;
  int to_pipeline[2];
  close(from_pipeline[1]);

  if ((k = read(from_pipeline[0], &p, INT_SIZE)) == 0) {
    close(from_pipeline[0]);
    exit(0);
  }
  int main(int argc, char *argv[]) {
    int pid, p[2];

    pipe(p);
    if((pid = fork()) < 0) {
        fprintf(stderr, "fork error...\n");
        exit(1);
    } else if (pid > 0) {
        close(p[READ]);
        for(int i = 2; i <= 35; ++i) {
            write(p[WRITE], &i, sizeof(int));
        }
        close(p[WRITE]);
        wait(0);
        exit(0);
    } else {
        exit(0);
    }
}

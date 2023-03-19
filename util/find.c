#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int main(int argc, char *argv[]) {
    if(argc < 3) {
        fprintf(2, "usage: find files in dir...\n");
        exit(0);
    }
    find(argv[1], argv[2]);
    exit(0);
}

void find(const char* path, const char* pattern) {
    char buf[512];
    char* p;
    int fd;
    struct dirent de;
    struct stat st;

    if (0 > (fd = open(path, 0))) {
        fprintf(2, "find: cannot open %s\n", path);
        return;
    }

    if (0 > fstat(fd, &st)) {
        fprintf(2, "find: cannot stat %s\n", path);
        close(fd);
        return;
    }
	switch (st.type) {
  case T_FILE:
    if (compare(path, name) == 0) {
      printf("%s\n", path);
    }
    break;
  case T_DIR:
    strcpy(buf, path);
    p = buf + strlen(buf);
    *p++ = '/';
    while (read(fd, &de, sizeof(de)) == sizeof(de)) {
      if (de.inum == 0 || strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) {
        continue;
      }
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;
      find(buf, name);
    }
    break;
  }

  close(fd);
}

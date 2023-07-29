#ifndef CLIB_H_
#define CLIB_H_

#define STDIN 0
#define STDOUT 1
#define O_RDONLY 0

typedef unsigned long int uintptr;
typedef long int intptr;

#define SYS_read 0
#define SYS_write 1
#define SYS_open 2
#define SYS_close 3

intptr read(int fd, void *buf, uintptr count);
intptr write(int fd, const void *buf, uintptr count);
intptr open(const void *pathname, int flags);
intptr close(int fd);
#endif /* CLIB_H_ */

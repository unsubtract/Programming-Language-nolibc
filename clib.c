#include "clib.h"
#include "crt.h"

intptr read(int fd, void *buf, uintptr count) {
    return (intptr)syscall3((void*)SYS_read, (void*)(intptr)fd, (void*)buf, (void*)count);
}
intptr write(int fd, const void *buf, uintptr count) {
    return (intptr)syscall3((void*)SYS_write, (void*)(intptr)fd, (void*)buf, (void*)count);
}
intptr open(const void *pathname, int flags) {
    return (intptr)syscall3((void*)SYS_open, (void*)pathname, (void*)(intptr)flags, 0);
}
intptr close(int fd) {
    return (intptr)syscall3((void*)SYS_close, (void*)(intptr)fd, 0, 0);
}

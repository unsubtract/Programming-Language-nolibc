#!/bin/sh

CC="gcc"
CFLAGS="-Wall -Wextra -Wpedantic -ansi -Os -flto \
-fno-stack-protector -fdata-sections -ffunction-sections \
-fno-unwind-tables -fno-asynchronous-unwind-tables"
LDFLAGS="-s -nostdlib -ffreestanding -no-pie \
-Wl,-n -Wl,--gc-sections -Wl,--build-id=none"

TARGET="Programming Language"

needs_update() {
    [ -e "${1%.*}.o" ] &&
        [ "$(date -r "$1" +%s)" -lt "$(date -r "${1%.*}.o" +%s)" ] && return 1;
    return 0
}

for i in *.c *.S; do
    if needs_update "$i"; then $CC $CFLAGS -c "$i"; fi
done

$CC $LDFLAGS *.o -o "$TARGET"
strip -R .comment "$TARGET"

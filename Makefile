CC = gcc -static
CFLAGS = -Wall -Wextra -Wpedantic --std=c89 -s -Os -nostdlib -ffreestanding \
	-no-pie -fno-stack-protector -fdata-sections -ffunction-sections -fno-unwind-tables -fno-asynchronous-unwind-tables \
	-Wl,-n -Wl,--gc-sections -Wl,--build-id=none -flto

all: Programming\ Language
Programming\ Language: Programming\ Language.c clib.c clib.h crt.h crt.S
	$(CC) $(CFLAGS) Programming\ Language.c clib.c crt.S -o "$@"
	strip -R .comment "$@"

clean:
	rm -f Programming\ Language

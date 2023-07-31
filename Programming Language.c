/* Programming Language.c - Simple implementation of the
 * A programming language is a system of notation for writing
 * computer programs. (abbreviated Programming Language) programming language
 * (October 5, 2022 edition). By unsubtract, MIT License.
 */
#include "crt.h"
#include "clib.h"

/* NOT NULL TERMINATED - treat as binary and not a C string */
static const char program[77] =
    "A programming language is a system of notation for \
writing computer programs.";


int main(int argc, const char* argv[]) {
    int fd = STDIN;
    uintptr i;
    char input[sizeof(program) + 1];

    if (argc >= 2) {
        if ((fd = open(argv[1], O_RDONLY)) < 0) return EXIT_FAILURE;
    }

    /* read file and check filesize:
     * read 1 extra byte to detect if file is too big */
    if (read(fd, input, sizeof(program) + 1) != sizeof(program)) {
        if (fd != STDIN) close(fd);
        return EXIT_SUCCESS;
    }

    /* i stops short of sizeof(program) if a difference is found */
    for (i = 0; i < sizeof(program) && input[i] == program[i]; ++i);

    /* output is deliberately not EOL terminated and is treated as binary */
    if (i == sizeof(program)) write(STDOUT, program, sizeof(program));
    
    if (fd != STDIN) close(fd);
    return EXIT_SUCCESS;
}

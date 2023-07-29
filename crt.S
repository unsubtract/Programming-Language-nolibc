.intel_syntax noprefix
.text
    .global _start, syscall3

    _start:
        xor rbp, rbp
        pop rdi
        mov rsi, rsp
        and rsp, -16
        call main

        mov rdi, rax
        mov rax, 60
        syscall

    syscall3:
        mov rax, rdi
        mov rdi, rsi
        mov rsi, rdx
        mov rdx, rcx
        syscall
        ret

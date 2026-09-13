bits 64

global stub_64
section .text

stub_64:


save_pile:
pushfq
push rax
push rbx
push rcx
push rdx
push rsi
push rdi
push rbp
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15

stub:
mov rax, 0x0a2e2e2e2e59
push rax
mov rax, 0x444f4f572e2e2e2e
push rax
mov rax, 1
mov rdi, 1
mov rsi, rsp
mov rdx, 14
syscall 
add rsp, 16 ;restoring pile after using it for hardcoding "...WOODY...\n"

restore_pile:
pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop r9
pop r8
pop rbp
pop rdi
pop rsi
pop rdx
pop rcx
pop rbx
pop rax
popfq

end:

   jmp [rel oep_addr]

; modifiable stub variable
oep_addr: dq 0x1122334455667788
key_1: dq 0x1122334455667788
key_2: dq 0x1122334455667788
key_3: dq 0x1122334455667788
key_4: dq 0x1122334455667788
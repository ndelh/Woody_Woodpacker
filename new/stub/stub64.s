bits 64
default rel

global stub_64
section .text

;r15 will be used to store base eop value (pie necessary)
; r14 will be used to store 0x1122334455667788
stub_64:

push_init:
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
pushfq

stub:

stub_init: 
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

base_calculus:
mov r14, [rel place_holder_value]
lea r15, [stub_64]
cmp qword [rel positive_offset], 1
je compute_pos_base
sub r15, [rel offset]
jmp uncypher

compute_pos_base:
add r15, [rel offset]

uncypher: 

mprotect1:
lea rax, [rel mprotect2]
push rax
mov rdi, [rel phdr1]
mov rsi, [rel phdr1_size]
jmp mprotect_wrapper

mprotect2:
lea rax, [rel mprotect3]
push rax
mov rdi, [rel phdr2]
mov rsi, [rel phdr2_size]
jmp mprotect_wrapper

mprotect3:
lea rax, [push_key_on_stack]
push rax
mov rdi, [rel phdr3]
mov rsi, [rel phdr3_size]
jmp mprotect_wrapper

mprotect_wrapper: ;when enterin rdi contain phdr vaddr; rsi initial len
cmp rdi, r14
je non_existing_adress ; if this comparison is equal it means that this pt_load doesnt exist becase 112233.. is placeholder value
add rdi, r15 ;adding base to the address (needed for pie exec)
mov r8, rdi ; saving base for calculus
and rdi, -0x1000 ; while result in giving us the previous aligned address
sub r8, rdi ; compute the first len adjustement, classic end - begin
add rsi, r8 ;adding len adjustement
add rsi, 4095; compleating by pagesize - 1
and rsi, -0x1000; finalize the second len adjustement by discarding everything below 4096
mov rax, 10
mov rdx, 7
syscall 
ret

non_existing_adress:
pop rax ; removing expected return then going to push key on stack

push_key_on_stack:
push qword [rel key_4]
push qword [rel key_3]
push qword [rel key_2]
push qword [rel key_1]

uncypher_end:
add rsp, 32

restaure_protect:
r_mprotect1:
lea rax, [rel mprotect2]
push rax
mov rdi, [rel phdr1]
mov rsi, [rel phdr1_size]
mov rdx, [rel phdr1_flags]
jmp restaure_protect_wrapper

r_mprotect2:
lea rax, [rel mprotect3]
push rax
mov rdi, [rel phdr2]
mov rsi, [rel phdr2_size]
mov rdx, [rel phdr2_flags]
jmp restaure_protect_wrapper

r_mprotect3:
lea rax, [load_base_addr]
push rax
mov rdi, [rel phdr3]
mov rsi, [rel phdr3_size]
mov rdx, [rel phdr3_flags]
jmp restaure_protect_wrapper

restaure_protect_wrapper: ;almost the same wrapper as mprotect_wrapper but with a loaded flag
cmp rdi, r14
je unexisting_restaure
add rdi, r15 ;adding base to the address (needed for pie exec)
mov r8, rdi ; saving base for calculus
and rdi, -0x1000 ; while result in giving us the previous aligned address
sub r8, rdi ; compute the first len adjustement, classic end - begin
add rsi, r8 ;adding len adjustement
add rsi, 4095; compleating by pagesize - 1
and rsi, -0x1000; finalize the second len adjustement by discarding everything below 4096
mov rax, 10
syscall
ret

unexisting_restaure:
pop rax

load_base_addr:
mov rax, r15

restore_pile:
popfq
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
xchg rax, [rsp]
ret ; since the summit of the pile contain oep, its equivalent to jmp + ret move by 8 so we are at equilibrium despite the fact that we have one more push than pop

; modifiable stub variable
offset: dq 0x1122334455667788
positive_offset: dq 0x1122334455667788
key_1: dq 0x1122334455667788
key_2: dq 0x1122334455667788
key_3: dq 0x1122334455667788
key_4: dq 0x1122334455667788

phdr_table:
;segment 1
phdr1: dq 0x1122334455667788
phdr1_size: dq 0x1122334455667788
phdr1_flags: dq 0x1122334455667788
phdr2: dq 0x1122334455667788
phdr2_size: dq 0x1122334455667788
phdr2_flags: dq 0x1122334455667788
phdr3: dq 0x1122334455667788
phdr3_size: dq 0x1122334455667788
phdr3_flags: dq 0x1122334455667788
place_holder_value: dq 0x1122334455667788
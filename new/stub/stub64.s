bits 64
default rel

global stub_64
section .text

;r15 will be used to store eop value (pie necessary)
; r14 will be used to store 0x1122334455667788
; r13 will be used to store base offset (pie necessary)
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
mov r14, [rel place_holder_value]

original_eop_calculus:
lea r15, [rel stub_64]
cmp qword [rel positive_offset], 1
je compute_positive_eop

compute_negative_eop:
sub r15, [rel offset]
jmp compute_pos_base

compute_positive_eop:
add r15, [rel offset]

compute_pos_base:
xor r13, r13 ; base will be 0 if je trigger
cmp r15, qword [original_eop] ; comparison between computed eop and original eop
je uncypher ;if its equal it means that the offset is equal to 0
mov r13, r15
sub r13, [rel original_eop]


uncypher: 

unlock_init:
lea rbx, [rel phdr_table]
mov rcx, 3 ; currently this stub allow max 3 prog header

unlock_loop:
test rcx, rcx
jz push_key_on_stack
push rbx
push rcx
mov rdi, [rbx]
mov rsi, [rbx + 8]
mov rdx, 7
call mprotect_wrapper
pop rcx
pop rbx
add rbx, 24 ; 3 entry 
dec rcx
jmp unlock_loop

mprotect_wrapper: ;when enterin rdi contain phdr vaddr; rsi initial len, rdx the flags;
cmp rdi, [rel place_holder_value]
je go_next ; if this comparison is equal it means that this pt_load doesnt exist becase 112233.. is placeholder value
add rdi, r13 ;adding base to the address (needed for pie exec)
mov r8, rdi ; saving base for calculus
and rdi, -0x1000 ; while result in giving us the previous aligned address
sub r8, rdi ; compute the first len adjustement, classic end - begin
add rsi, r8 ;adding len adjustement
add rsi, 4095; compleating by pagesize - 1
and rsi, -0x1000; finalize the second len adjustement by discarding everything below 4096
mov rax, 10
mov rdx, 7
syscall
go_next:
ret

push_key_on_stack:
push qword [rel key_4]
push qword [rel key_3]
push qword [rel key_2]
push qword [rel key_1]

uncypher_init:
lea rbx, [phdr_table]
mov rcx, 3

uncypher_loop:
test rcx, rcx
jz remove_key
mov rdi, [rbx]
mov rsi, [rbx + 8]
push rbx
push rcx
call uncypher_segment
pop rcx
pop rbx
dec rcx
add rbx, 24
jmp uncypher_loop

uncypher_segment: ; rdi contain the non based value, rsi the len to uncypher
cmp rdi, [rel place_holder_value]
je skip_segment

add rdi, r13 ; adding the base value
mov rcx, rsi
shr rcx, 5 ; cause we want to fast by key_size;
jz slow_loop ; mean that the remaining size is < 32;

fast_loop: ;rcx is the 32 counter, rdi the pointer
test rcx, rcx
jz slow_loop_init
mov rax, [rsp + 24] ; +8 since entry because rsp contain ret addr
xor [rdi], rax
mov rax, [rsp + 32]
xor [rdi + 8], rax
mov rax, [rsp + 40]
xor [rdi + 16], rax
mov rax, [rsp + 48]
xor [rdi + 24], rax
add rdi, 32
dec rcx
jmp fast_loop

slow_loop_init:
lea rbx, [rsp + 24]
and rsi, 31
slow_loop: ;will use rsi as a remaining counter, rbx as a pointer to the key
test rsi, rsi
jz skip_segment
mov al, byte [rbx]
xor byte [rdi], al
inc rdi
inc rbx
dec rsi
jmp slow_loop

skip_segment:
ret


remove_key:
add rsp, 32

init_lock_loop:
lea rbx, [rel phdr_table]
mov rcx, 3 ; 

relock_loop:
test rcx, rcx
jz load_base_addr
push rbx
push rcx
mov rdi, [rbx]
mov rsi, [rbx + 8]
mov rdx, [rbx + 16]
call mprotect_wrapper
pop rcx
pop rbx
add rbx, 24 ; 3 entry 
dec rcx
jmp relock_loop

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
original_eop: dq 0x1122334455667788
key_1: dq 0x1122334455667788
key_2: dq 0x1122334455667788
key_3: dq 0x1122334455667788
key_4: dq 0x1122334455667788

phdr_table:

;segment 1
phdr1: dq 0x1122334455667788
phdr1_size: dq 0x1122334455667788
phdr1_flags: dq 0x1122334455667788

;segment2
phdr2: dq 0x1122334455667788
phdr2_size: dq 0x1122334455667788
phdr2_flags: dq 0x1122334455667788

;segment3
phdr3: dq 0x1122334455667788
phdr3_size: dq 0x1122334455667788
phdr3_flags: dq 0x1122334455667788
place_holder_value: dq 0x1122334455667788
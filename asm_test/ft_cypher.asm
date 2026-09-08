bits 64
global ft_cypher

;ft_cypher(void *to_cypher, size_t cypher_len, void *key_sum) 
; RDI = to_cypher,RSI cypher_len RDX key_sum, 

section .text
ft_cypher:

init:

mov r8, rsi
shr r8, 5 ;divide len by 32, allow fast loop usage
jz slow_loop

fast_loop:
test r8, r8
jz fast_loop_end 
mov rax, [rdx]
xor [rdi], rax
mov rax, [rdx + 8]
xor [rdi + 8], rax
mov rax, [rdx + 16]
xor [rdi + 16], rax
mov rax, [rdx + 24]
xor [rdi + 24], rax
add rdi, 32
dec r8
jmp fast_loop

fast_loop_end:
mov r8, rsi
shr r8, 5
shl r8, 5
sub rsi, r8

slow_loop:

test rsi, rsi
jz end
mov r10, rdx; storing key in r10
mov al, byte [r10]
xor byte[rdi], al
dec rsi
inc rdi
inc r10
jmp slow_loop
end:
ret


bits 32
default rel

;edx is used to compute_base

global stub_32
section .text

saving_frame: 
push eax
push ebx
push ecx
push edx
push esi
push edi
push ebp

writing_woody:
push 0x000A2E2E
push 0x2E59444F
push 0x4F572E2E
mov eax, 4
mov ebx, 1
mov ecx, esp
mov edx, 12
int 0x80
add esp, 12 
computing_eop:
call compute_stub_eop
jmp restauring_frame

compute_stub_eop:
pop edx
sub edx, (compute_stub_eop - saving_frame) ;now edx contain the real stub entrypoint

compute_current_eop:
mov ecx, [offset] ; moving the offset between oep and stub ep
sub edx, ecx ; now edx contain the true oep
ret

restauring_frame:
mov eax, edx
pop ebp
pop edi
pop esi
pop edx
pop ecx
pop ebx
xchg eax, [esp]
ret 

; modifiable stub variable
align 8
offset: dd 0x11223344
positive_offset: dd 0x11223344
original_eop: dd 0x11223344

key_1: dd 0x11223344
key_2: dd 0x11223344
key_3: dd 0x11223344
key_4: dd 0x11223344
key_5: dd 0x11223344
key_6: dd 0x11223344
key_7: dd 0x11223344
key_8: dd 0x11223344


phdr_table:

;segment 1

phdr1: dd 0x11223344
phdr1_size: dd 0x11223344
phdr1_flags: dd 0x11223344

;segment2
phdr2: dd 0x11223344
phdr2_size: dd 0x11223344
phdr2_flags: dd 0x11223344

;segment3
phdr3: dd 0x11223344
phdr3_size: dd 0x11223344
phdr3_flags: dd 0x11223344

place_holder_value: dd 0x11223344
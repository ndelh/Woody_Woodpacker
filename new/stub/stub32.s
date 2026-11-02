bits 32
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

call get_base
compute_real_entry: 
sub edx, (compute_real_entry - saving_frame)
; from now on, edx will always be base till the label restauring frame

uncypher:

delock_loop:

mprotect_wrapper:

restauring_frame:
sub edx, [edx + (offset - saving_frame)]
mov eax, edx
pop ebp
pop edi
pop esi
pop edx
pop ecx
pop ebx
xchg eax, [esp]
ret

get_base:
mov edx, [esp]
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
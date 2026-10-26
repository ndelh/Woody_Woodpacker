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
mov ecx, [offset_low] ; moving the offset between oep and stub ep
sub edx, ecx ; now edx contain the true eop
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
offset_low: dd 0x11223344
offset_up: dd 0x55667788
positive_offset_low: dd 0x11223344
positive_offset_up: dd 0x55667788
original_eop_low: dd 0x11223344
original_eop_up: dd 0x55667788
key_1_low: dd 0x11223344
key_1_up: dd 0x55667788
key_2_low: dd 0x11223344
key_2_up: dd 0x55667788
key_3_low: dd 0x11223344
key_3_up: dd 0x55667788
key_4_low: dd 0x11223344
key_4_up: dd 0x55667788

phdr_table:

;segment 1

phdr1_low: dd 0x11223344
phdr1_up: dd 0x55667788 ; unused in 32
phdr1_size_low: dd 0x11223344
phdr1_size_up: dd 0x55667788 ; unused in 32
phdr1_flags_low: dd 0x11223344
phdr1_flags_up: dd 0x55667788 ; unused in 32

;segment2
phdr2_low: dd 0x11223344
phdr2_up: dd 0x55667788 ; unused in 32
phdr2_size_low: dd 0x11223344
phdr2_size_up: dd 0x55667788 ; unused in 32 
phdr2_flags_low: dd 0x11223344
phdr2_flags_up: dd 0x55667788 ; unused in 32

;segment3
phdr3_low: dd 0x11223344
phdr3_up: dd 0x55667788 ; unused in 32
phdr3_size_low: dd 0x11223344
phdr3_size_up: dd 0x55667788 ; unused in 32 
phdr3_flags_low: dd 0x11223344
phdr3_flags_up: dd 0x55667788 ; unused in 32

place_holder_value_low: dd 0x11223344
place_holder_value_up: dd 0x55667788
#!/bin/bash
clear
nasm -f elf64 ft_cypher.asm -o cypher.o
cc -Wall -Werror -Wextra main.c cypher.o
rm -rf cypher.o

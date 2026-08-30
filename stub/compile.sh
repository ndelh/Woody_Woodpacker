#!/bin/bash

nasm -f elf64 stub64.s -o stub64.o
ld stub64.o

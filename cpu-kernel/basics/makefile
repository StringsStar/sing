#!/bin/bash

DOS = freedos.img
IMG = b.img
OBJS = main.bin
ASM = nasm
DST = /mnt/floppy
all : $(OBJS)
	sudo mount $(IMG) /mnt/floppy
	sudo rm -f /mnt/floppy/*
	sudo cp $(OBJS) $(DST) 
	sleep 0.1
	sudo umount $(DST)

main.bin : main.asm
	nasm -o $@ $<

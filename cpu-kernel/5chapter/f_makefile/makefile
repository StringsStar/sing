ENTRYPOINT	= 0x30400
CC 			= gcc
LD 			= ld
ASM			= nasm

ASMBFLAGS 	= -I boot/
ASMKFLAGS	= -I include/ -f elf
CFLAGS		= -m32 -I include/ -c -fno-builtin
LDFLAGS		= -m elf_i386 -s -Ttext $(ENTRYPOINT) 

BOOT_BIN	= boot/boot.bin
LOADER_BIN	= boot/loader.bin
KERNEL_BIN	= kernel/kernel.bin
OBJS		= kernel/kernel.o kernel/start.o lib/io.o lib/string.o
IMG			= a.img
DOS			= a_bak.img
FLOPPY		= /mnt/floppy


ifeq ($(FLOPPY), $(wildcard $(FLOPPY)))
$(shell sudo umount $(FLOPPY))	
else 
$(shell sudo mkdir $(FLOPPY))
endif

.PHONY : all
#.PHONY : all
all : $(BOOT_BIN) $(LOADER_BIN) $(KERNEL_BIN)
	dd if=/dev/zero of=$(IMG) bs=1k count=1440
	dd if=$(BOOT_BIN) of=$(IMG) bs=512 conv=notrunc
	dd if=$(DOS) of=$(IMG) bs=512 skip=1 seek=1 count=1 \
		  conv=notrunc
	dd if=$(DOS) of=$(IMG) bs=512 skip=10 seek=10 count=1 \
		  conv=notrunc
	sudo mount -o loop $(IMG) $(FLOPPY)
	sudo cp $(LOADER_BIN) $(FLOPPY) -v
	sudo cp $(KERNEL_BIN) $(FLOPPY) -v
	sleep 0.1
	sudo umount $(FLOPPY)

clean:
	rm -f $(OBJS) $(BOOT_BIN) $(LOADER_BIN) $(KERNEL_BIN)
	rm -f $(IMG)

$(BOOT_BIN) : boot/boot.asm
	$(ASM) $(ASMBFLAGS) -o $@ $<

$(LOADER_BIN) : boot/loader.asm
	$(ASM) $(ASMBFLAGS) -o $@ $<

$(KERNEL_BIN) : $(OBJS)
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) $(OBJS)
			
kernel/kernel.o : kernel/kernel.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<	

kernel/start.o : kernel/start.c
	$(CC) $(CFLAGS) -o $@ $<

lib/io.o : lib/io.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<

lib/string.o : lib/string.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<

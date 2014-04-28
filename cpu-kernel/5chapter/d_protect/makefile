BOOT:=boot.asm
LOADER:=loader.asm
KERNEL:=kernel.asm
BOOT_BIN:=$(subst .asm,.bin,$(BOOT))
LOADER_BIN:=$(subst .asm,.bin,$(LOADER))
KERNEL_BIN:=$(subst .asm,.bin,$(KERNEL))

IMG:=a.img
DOS:=dos.img
FLOPPY:=/mnt/floppy

.PHONY : all

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
	sudo umount $(FLOPPY)

clean:
	rm *.bin
	rm $(IMG)

$(BOOT_BIN) : $(BOOT)
	nasm $< -o $@

$(LOADER_BIN) : $(LOADER)
	nasm $< -o $@

$(KERNEL_BIN) : $(KERNEL)
	nasm -f elf -o $(subst .asm,.o,$(KERNEL)) $<
	ld -m elf_i386 -s -o $@ $(subst .asm,.o,$(KERNEL))



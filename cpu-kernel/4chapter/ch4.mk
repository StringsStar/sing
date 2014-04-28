BOOT:=boot.asm
LOADER:=loader.asm
BOOT_BIN:=$(subst .asm,.bin,$(BOOT))
LOADER_BIN:=$(subst .asm,.bin,$(LOADER))

IMG:=../a.img
DOS:=../freedos.img
FLOPPY:=/mnt/floppy/

.PHONY : all

all : $(BOOT_BIN) $(LOADER_BIN)
  	dd if=/dev/zero	of=$(IMG) bs=1k count=1440
	dd if=$(BOOT_BIN) of=$(IMG) bs=512 conv=notrunc
#	dd if=$(DOS) of=$(IMG) skip=0x200 seek=0x200 bs=3
#	dd if=$(DOS) of=$(IMG) skip=0x1400 seek=0x1400 bs=3
#	sudo mount -o loop $(IMG) $(FLOPPY)
#	sudo cp $(LOADER_BIN) $(FLOPPY) -v
#	sudo umount $(FLOPPY)

clean:
	rm *.bin

$(BOOT_BIN) : $(BOOT)
	nasm $< -o $@

$(LOADER_BIN) : $(LOADER)
	nasm $< -o $@
				



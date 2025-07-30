.PHONY: all run clean

all:
	gcc src/main.c src/cpu.c -o emulator

memory.bin:
	echo -ne '\x01\x08\x03\x09\x02\x0A\xFF\x00\x05\x03\x00' > memory.bin

run: all memory.bin
	./emulator

clean:
	rm -f emulator memory.bin


#include <stdio.h>
#include "cpu.h"

int main() {
	
	CPU cpu;
	cpu_init(&cpu);
	cpu_load_program(&cpu, "memory.bin");
	cpu_run(&cpu);

	printf("\nZawartość RAM (16 bajtów):\n");
	for (int i = 0; i < 16; i++) {
		printf("RAM[0x%02X] = %d\n", i, cpu.RAM[i]);
	}
	
	printf("Rejestr A: %d\n", cpu.A);
	return 0;
}

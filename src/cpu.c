#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>

void cpu_init(CPU *cpu) {
	cpu->A = 0;
	cpu->B = 0;
	cpu->PC = 0;
	cpu->FLAG = 0;
	for (int i = 0; i < 255; i++) cpu->RAM[i] = 0;
}

void cpu_load_program(CPU *cpu, const char *filename){
	FILE *f = fopen(filename, "rb");
	if (!f) {
		perror("Nie znaleziono binarnego pliku");
		exit(1);
	}
	fread(cpu->RAM, 1, 255, f);
	fclose(f);
}

void cpu_run(CPU *cpu) {
	int running = 1;
	while (running) {
		uint8_t opcode = cpu->RAM[cpu->PC++];
		uint8_t operand = cpu->RAM[cpu->PC++];
		switch (opcode) {
			case 0x01: //LDA
				cpu->A = cpu->RAM[operand];
				break;
			case 0x02: //STA
				cpu->RAM[operand] = cpu->A;
				break;
			case 0x03: //ADD
				cpu->A += cpu->RAM[operand];
				break;
			case 0x04: //SUB
				cpu->A -= cpu->RAM[operand];
				break;
			case 0x05: //JMP
				cpu->PC = operand;
				break;
			case 0x06: // JZ
				if (cpu->A == 0) cpu->PC = operand;
				break;
			case 0xFF: // HLT
				running = 0;
				break;
			default:
				printf("NIe poprawna instrukcja: 0x%02X\n", opcode);
				running = 0;
			}
		}
	}
				

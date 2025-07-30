#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef	struct CPU {
	uint8_t A;
	uint8_t B;
	uint8_t PC;
	uint8_t FLAG;
	uint8_t RAM[255];
} CPU;

void cpu_init(CPU *cpu);
void cpu_load_program(CPU *cpu, const char *filename);
void cpu_run(CPU *cpu);

#endif


#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100


int parse_reg_or_mem(const char* operand) {
    if (strncmp(operand, "reg", 3) == 0) {
        return atoi(&operand[3]);
    } else if (strncmp(operand, "mem", 3) == 0) {
        return atoi(&operand[3]);
    } else {
        return -1; 
    }
}


void assemble_line(const char* line, FILE *output) {
    char instruction[MAX_LINE_LENGTH];
    char operand1[MAX_LINE_LENGTH];
    char operand2[MAX_LINE_LENGTH];
    uint8_t opcode = 0;
    uint8_t regnum = 0, operand = 0, imm = 0;

    int num_operands = sscanf(line, "%s %s %s", instruction, operand1, operand2);

    if (strcmp(instruction, "LDR") == 0) {
        opcode = 0x00;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "ADD") == 0) {
        opcode = 0x01;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "SUB") == 0) {
        opcode = 0x02;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "MUL") == 0) {
        opcode = 0x03;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "DIV") == 0) {
        opcode = 0x04;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "RST") == 0) {
        opcode = 0x05;
        fwrite(&opcode, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "HLT") == 0) {
        opcode = 0x06;
        fwrite(&opcode, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "LDM") == 0) {
        opcode = 0x07;
        operand = parse_reg_or_mem(operand1);
        imm = atoi(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&imm, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "STM") == 0) {
        opcode = 0x08;
        regnum = parse_reg_or_mem(operand1);
        operand = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&operand, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "NOP") == 0) {
        opcode = 0x09;
        fwrite(&opcode, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "INC") == 0) {
        opcode = 0x0A;
        regnum = parse_reg_or_mem(operand1);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "DEC") == 0) {
        opcode = 0x0B;
        regnum = parse_reg_or_mem(operand1);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
    } else if (strcmp(instruction, "MOV") == 0) {
        opcode = 0x0C;
        regnum = parse_reg_or_mem(operand1);
        uint8_t destreg = parse_reg_or_mem(operand2);
        fwrite(&opcode, sizeof(uint8_t), 1, output);
        fwrite(&regnum, sizeof(uint8_t), 1, output);
        fwrite(&destreg, sizeof(uint8_t), 1, output);
    } else {
        printf("Error: Unknown instruction %s\n", instruction);
    }
}

int main() {
    FILE *input = fopen("asm.asm", "r");
    if (input == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE *output = fopen("asm.b", "wb");
    if (output == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input);
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), input)) {
        assemble_line(line, output);
    }

    fclose(input);
    fclose(output);

    printf("Assembly complete. Binary output written to asm.b\n");

    return 0;
}
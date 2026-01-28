#include <stdio.h>
#include <string.h>

typedef struct{
    char opcode[10];
    int operand;
    int address;
} Instruction;

int main()
{
    // Memory
    Instruction memory[10]={
        {"LOAD", 5, 0},
        {"ADD", 3, 0},
        {"STORE", 0, 200},
        {"HALT", 0, 0}
    };

    // Registers
    int PC = 0;
    int A = 0;
    int data_memory[256] = {0};

    printf("CPU Start Simulation...\n\n");

    while (1)
    {
        // FETCH (F)
        Instruction instr = memory[PC];
        printf("FETCH  -> PC=%d | Instruction=%s\n", PC, instr.opcode);
        PC++;

        // DECODE (D)
        printf("DECODE -> Operation=%s\n", instr.opcode);

        // EXCUTE (E)
        if (strcmp(instr.opcode, "LOAD") == 0)
        {
            A = instr.operand;
            printf("EXECUTE -> A = %d\n", A);
        }
        else if (strcmp(instr.opcode, "ADD") == 0)
        {
            A += instr.operand;
            printf("EXECUTE -> A = %d\n", A);
        }
        else if (strcmp(instr.opcode, "STORE") == 0)
        {
            data_memory[instr.address] = A;
            printf("EXECUTE -> MEM[%d] = %d\n", instr.address, A);
        }
        else if (strcmp(instr.opcode, "HALT") == 0)
        {
            printf("EXECUTE -> HALT\n");
            break;
        }
        else
        {
            printf("ERROR: Unknown Instruction!");
            break;
        }

        printf("------------------------------------\n");
    }

    printf("\nFinal State:\n");
    printf("A = %d\n", A);
    printf("MEM[200] = %d\n", data_memory[200]);

    return 0;
}
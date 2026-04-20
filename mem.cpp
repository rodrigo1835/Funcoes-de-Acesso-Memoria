#include <stdio.h>
#include <stdint.h>

//
// memoria ligada ao processador
//

#define MEM_SIZE 1024
#define DATA_SEG 512

int32_t lb(const uint32_t address, int32_t kte);

uint32_t lbu(const uint32_t address, int32_t kte);

int32_t lw(const uint32_t address, int32_t kte);

void sb(const uint32_t address, int32_t kte, int8_t dado);

void sw(const uint32_t address, int32_t kte, int32_t dado);

//
// memoria ligada ao processador
//

int8_t mem[MEM_SIZE];

int main (int argc, const char * argv[]) {

    // TESTES

    // 1. Escrita
    sw(0, 0, 0xABACADEF);
    sb(4, 0, 1);
    sb(4, 1, 2);
    sb(4, 2, 3);
    sb(4, 3, 4);

    // 2. Leitura + impressão (HEX)

    printf("a. %08x\n", lw(0, 0));

    printf("b. %08x\n", lb(0, 0));
    printf("c. %08x\n", lb(0, 1));
    printf("d. %08x\n", lb(0, 2));
    printf("e. %08x\n", lb(0, 3));

    printf("f. %08x\n", lbu(0, 0));
    printf("g. %08x\n", lbu(0, 1));
    printf("h. %08x\n", lbu(0, 2));
    printf("i. %08x\n", lbu(0, 3));     

    return 0;
}

int32_t lb(const uint32_t address, int32_t kte) {
    int8_t data = mem[address + kte];
    int32_t sign_ext = data;
    
    return sign_ext;
}

uint32_t lbu(const uint32_t address, int32_t kte) {
    uint8_t data = mem[address + kte];
    uint32_t zero_ext = data;

    return zero_ext;
}

int32_t lw(const uint32_t address, int32_t kte) {
    uint8_t byte[4];

    for(uint8_t i = 0; i < 4 ; i++){
        uint8_t data = mem[(address + kte) + i];
        byte[i] = data;
    }

    int32_t word = (byte[3] << 24) | (byte[2] << 16) | (byte[1] << 8) | byte[0];

    return word;
}

void sb(const uint32_t address, int32_t kte, int8_t dado) {
    mem[address + kte] = dado;
}

void sw(const uint32_t address, int32_t kte, int32_t dado) {
    uint8_t byte[4];
    byte[0] = dado & 0xFF;
    sb(address, kte, byte[0]);

    for(uint8_t i = 1; i < 4 ; i++ ) {
        byte[i] = (dado >> (i * 8)) & 0xFF;
        sb(address, kte + i, byte[i] );
    }
}
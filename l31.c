#include <stdio.h>
#include <dos.h>

int main() {
    /* Folosim MK_FP pentru a crea un pointer la segmentul 0x0040 si offset-urile din tabel */
    unsigned int far *com1 = (unsigned int far *)MK_FP(0x0040, 0x0000);
    unsigned int far *com2 = (unsigned int far *)MK_FP(0x0040, 0x0002);
    unsigned int far *lpt1 = (unsigned int far *)MK_FP(0x0040, 0x0008);
    unsigned int far *mem_baza = (unsigned int far *)MK_FP(0x0040, 0x0013);

    printf("--- Informatii din zona de date BIOS ---\n");
    printf("Adresa baza COM1 (0040:0000h): %04Xh\n", *com1);
    printf("Adresa baza COM2 (0040:0002h): %04Xh\n", *com2);
    printf("Adresa baza LPT1 (0040:0008h): %04Xh\n", *lpt1);
    printf("Dimensiune memorie de baza (0040:0013h): %d Ko\n", *mem_baza);

    return 0;
}
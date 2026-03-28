#include <stdio.h>
#include <dos.h>

int main() {
    int variabila_test = 100;
    
    /* Declaram un pointer 'far' (care contine atat segment cat si offset in DOS) */
    int far *ptr = (int far *)&variabila_test;

    /* Obtinem segmentul si offset-ul */
    unsigned int segment = FP_SEG(ptr);
    unsigned int offset = FP_OFF(ptr);

    printf("Adresa de memorie este: %04X:%04X\n", segment, offset);
    printf("Segment: %04Xh\n", segment);
    printf("Offset:  %04Xh\n", offset);

    return 0;
}
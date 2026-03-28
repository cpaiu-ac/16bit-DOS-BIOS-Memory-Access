#include <stdio.h>
#include <dos.h>

int main() {
    /* DECLARAM TOATE VARIABILELE LA INCEPUT PENTRU TURBO C++ */
    unsigned int far *echipamente;
    unsigned int val;
    unsigned int mod_video;
    unsigned int nr_dischete;
    unsigned int nr_seriale;
    unsigned int nr_paralele;

    /* Acum incepem executia */
    echipamente = (unsigned int far *)MK_FP(0x0040, 0x0010);
    val = *echipamente;

    printf("--- Lista Echipamente (Valoare bruta: %04Xh) ---\n", val);
    
    /* Extragem informatiile bit cu bit folosind masti */
    if (val & 1) { /* Bit 0: Prezenta disc fix */
        printf("- Disc fix instalat\n");
    }
    if (val & (1 << 1)) { /* Bit 1: Coprocesor matematic */
        printf("- Coprocesor matematic instalat\n");
    }
    
    /* Bit 4-5: Mod video */
    mod_video = (val >> 4) & 3; 
    printf("- Mod video: ");
    if (mod_video == 1) printf("40 coloane color\n");
    else if (mod_video == 2) printf("80 coloane color\n");
    else if (mod_video == 3) printf("TTL monocrom\n");
    else printf("Rezervat\n");

    /* Bit 6-7: Numar unitati discheta (doar daca exista) */
    nr_dischete = (val >> 6) & 3;
    printf("- Numar unitati discheta: %d\n", nr_dischete == 0 ? 1 : (nr_dischete == 2 ? 3 : 4));

    /* Bit 9-11: Numar porturi seriale */
    nr_seriale = (val >> 9) & 7;
    printf("- Numar porturi seriale (RS-232): %d\n", nr_seriale);

    /* Bit 14-15: Numar porturi paralele */
    nr_paralele = (val >> 14) & 3;
    printf("- Numar porturi paralele: %d\n", nr_paralele);

    return 0;
}
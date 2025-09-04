#include <stdio.h>

int main(void) 
{
    printf("\n");
    printf("\n");
    printf("\n");

    int x = 5;
    int *y = &x;  // puntatore a intero
    int **z = &y; // -->> Puntatore a un puintatore intero

    printf("x vive in %p e y vive in %p\n", y, z);

    // tutti i puntatori sono semoplicemente dei numeri di dimensione pari in bit alla dimensione
    // del bus indirizzi del processore
    printf("Dimensione Y: %d - Dimensione Z = %d\n", (int)sizeof(y), (int)sizeof(z)); 


    // Gestione di un array di caratteri con i puntatori
    // in C le variabili dichiarate come array possono essere utilizzate come un puntatore
    char mystring[] = "AABBCCDDEEFF";  
    char *sp = mystring;
    printf("At %p I can see $s\n", mystring, mystring);
    printf("%c%c%c\n",sp[0], sp[1], sp[2]);
    printf("%c%c%c\n", *sp, *(sp + 1), *(sp + 2));

    short a = 4;
    printf("La dimensione di uno short e' di: %d\n", sizeof(a));

    short *short_p = (short *)mystring;
    printf("%d\n", *short_p);

    // se incremento il puntatore a short int, che e' di due byte, avanzo di due indirizzi, ovvero della dimensione in 
    // byte del tipo puntato
    short_p += 4;
    
    printf("%d\n", *short_p);
    
    /*
        printf("%d\n", short_p[-3242352]); // Segmentation fault!! esco dallo spazio di indirizzi del programma.
    */

    int i = 0;
    char *pc = mystring;
    while (*pc != 0)
    {
        *pc = 'A';
        *pc++;
        ++i;
    }
    
    printf("%s - %d\n ", mystring, i);

    return 0;
}



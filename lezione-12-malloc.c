#include <stdio.h>
#include <stdlib.h>

/*
    Voglio in qualche modo gestire stringhe LPS cosicche possa avere stringhe con uno 0 (un byte NULL) e che comunque vengano
    gestite come in pascal.

    malloc():
    la uso per allocare la memoria all'interno di una funzione e poterla riusare fuori dalla funzione stessa.
    Vedi la funzione ps_create.
    In questo caso la memoria riservata con allocata non e' LOCALE ma rimane allocata fino a che non viene effettuata una chiamata 
    a free().

    In realta dietro le quinte c'e' la differenza tra stack e heap, 
    Le variabioli locali sono create nello stack, malloc utilizza l'heap.
*/


/* Initialize a prefixed lenght string with the specified
 * string in 'init' of lenght 'len'
 *
 * Warning: this function does not check for buffer overflows. */
void ps_init(char *s, char* init, int len) {
    unsigned char *lenptr = (unsigned char *) s;
    lenptr[0] = len;

    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }

    return;
}


/* Displayt the string s on the screen. */
void ps_print(char *s) {
    unsigned char *lenptr = (unsigned char *)s;
    
    for (int j = 0; j < *lenptr; j++)  {
        putchar(s[j + 1]);
    }

}

char *ps_create(char* init, int len) 
{
    char *s = malloc(1 + len + 1);

    char *lenptr = (unsigned char *) s;
    lenptr[0] = len;

    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }

    // terminiamo la stringa in modo C-stile in modo da poterla
    // utilizzare in altri contesti
    s[len+1] = 0;

    return s;
}


char* ps_print_c_string(char *s) {
    return s+1;
}


int main(void)  {
    //... prima version con un array di caratteri di lunghezza predefinita
    // char buf[256];
    /* ps_init(buf, "Hell\000 World\n" , 12);
    ps_print(buf);
    ps_print(buf); */

    //...in questa seconda versione anziche lavorare su un buffer predefinito di 256 byte
    // alloco direttamente la memoria che mi serve usando la funzione malloc
    // in questo caso non ho bisogno di passare il buffer da popolare, ma mi faccio restituire un puntatore
    // alla memoria della dimensione che mi serve

    char *mystring = ps_create("Hello World\n", 12); 
    ps_print(mystring);
    ps_print(mystring);
    printf("%s\n", ps_print_c_string(mystring));
    free(mystring);

    return 0;
}



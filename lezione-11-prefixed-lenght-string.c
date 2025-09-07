#include <stdio.h>

/*
    In questa lezione abbiamo visto come in realta una string, e' una sequenza di byte, che come tali possono essere interpretati
    banalmente come numeri. Si puo' quindi associare la string a un puntatore di tipo numerico (ad esempio short* o altro) che puo' andare 
    a parsare i byte trattandoli come numeri a 16 bit.
    Il valore numerico di ogni carattere nella stringa, ovvero la sequenza di bit salvata in memoria per ogni carattere, e' il valore
    specificato nella tabella ASCII

    Quando in una printf usiamo uno specificatore di formato come ad esempio %c o %d stiamo semplicemente chiedento in quale formato
    visualizzare quella particolare sequenza di bit. 
    
        %c >> stampa l'equivalente in ASCII
        %d >> stampa l'equivalente intero
    
    e cosi via.

    E' possibile quindi introdurre in una stringa anche dei byte che poi il codice puo' interpretare con significato diverso da quello di carattere, 
    ad esempio si potrebbe usare il primo byte per definire la lunghezza della stringa.
    Si parla in questo caso di prefixed lenght string.

    Per introdurre ad esempio un byte definendolo in esadecimale si usa il carattere di escape \xNN
*/

int main(void) 
{
    
    char mystring[] = "Hello World!";  //...la string e' lunga 12 carattery che in binario equivale a 00001100. In esadecimale sarebbe $0C.
                                       //...lo posso usare per  costruire una prefixed lenght string

    char pfstring[] = "\x0CHello World!";

    // ...stampo la stringa usando non una printf ma la putchar, iterando sulla lunghezza definita nel primo
    // byte (che non stampiamo)
    putchar ('\n');
    putchar ('\n');
    
    int lenght = pfstring[0];
    for (int i = 1; i <= lenght; i++)
        putchar(pfstring[i]);

    return 0;
}



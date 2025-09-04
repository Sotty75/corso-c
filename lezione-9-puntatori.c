#include <stdio.h>

void incr(int *p)
{
    *p = *p + 1;
    
    /* questo lo potremmo appunto scrivere anche come:
    
    p[0] = p[0] + 1;

    questo in teoria potrebbe anche essere piu' chiaro ed espressivo, 
    in quanto essendo p l'indirizzo base, vediamo proprio visivamente come p[0] sia 
    "l'elemnento zero registrato a quell'indirizzo di memoriua, p[1] l'elemento 1 e cosi via
    */ 
}

int main(void) 
{
    int x = 5;
    int *y = NULL;

    printf("\n");
    printf("\n");
    printf("\n");

    printf("%d\n", x);
    printf("%p\n", y);

    // assegniamo a y l'indirizzo di x
    y = &x;
    printf("La variabile x e' contenuta nell indirizzo: %p\n", y);

    // sovrascriviamo x passando dal puntatore al suo indirizzo di memoria
    // da qui si capisce perche dobbiamo dare un tipo al puntatore, cosi il compiulatore sa come 
    // interpretare l'istruzione seguente.
    *y = 10;
    printf("La variabile x e' ora uguale a: %d\n", x);

    // c'e' una strana equivalenza in C tra i puntatori e gli array.
    // il valore puntato da un puntatore puo' essere espresso come l'elemento di
    // indice 0 dell'array corrispondente
    y[0] = 20;  // e' equivalente a *y = 20
    printf("La variabile x e' ora uguale a: %d\n", x);

    // Ma perche questo meccanismo di andare a modificare una 
    // variabile tramite il suo indirizzo puo' essere utile?
    // Vediamo un esempio:
    //
    //   - potrei volere definire una funzione che agisce su una variabile int
    //   - questa funziona deve lavorare su un dato che persista dopo che usciamo
    //   - dalla funzione stessa. 
    incr(y);
    incr(&x);
    incr(y);
    incr(&x);
    printf("La variabile x e' ora uguale a: %d\n", x);

    return 0;
}



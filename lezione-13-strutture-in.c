#include <stdio.h>
#include <stdlib.h>

/* ANTEFATTO 
 Definiamo una struttura dati in memoria usando malloc per gestire
 una frazione e farci dei calcoli, ad esempio una simplify.
*/

// Supponiamo di volere un prograamma che gestisce le frazioni.
// 
// Numeratore
// Denominatore

void set_fraction(int *f, int num, int den) {

    f[0] = num;
    f[1] = den;
    
    return;
}

// faccio direttamente allocare alla funzione malloc la memoria 
// per la frazione


/* INTRODUZIONE ALLE STRUTTURE 
 Il C ci riserva una sorpresa, ovvero il concetto di struttura
 E' l'unico del C in cui si esce dall'idea di manipolare numeri.
 Sono tutti numeri meno le strutture, che in realta' e' un vero tipo di dato.
 E' una aggregazione di diversi dati.
 Tanto che io posso dichiarare una variabiole del tipo struttura.
*/

struct frac 
{
    int num;
    int den;
};

struct char_frac 
{
    unsigned char color;
    int num;
    int den;
};

struct frac_char
{
    int num;
    int den;
    unsigned char color;
};

struct frac_3_char
{
    int num;
    int den;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct frac *create_fraction(int num, int den)
{
    struct frac *f = malloc(sizeof(struct frac));
    if (f == NULL) return NULL; //malloc error checking
    f->num = num;
    f->den = den;

    return f;
}

void print_fraction(struct frac *f)
{
     printf("%d/%d\n", f->num, f->den);
}

void simplify_fraction(struct frac *f)
{
    for (int d = 2; d <= f->num && d <= f->den; d++)
    {
        while (f->num % d == 0 && f->den % d ==0)
        {
            f->num /= d;
            f->den /= d;
        }
    }
}



int main(void) {
    int *f = malloc(2 * sizeof(int));
    
    //   f0   f1
    // +---------+
    // |1111|2222|
    // +----=----+

    // f[0]  primo intero
    // f[1] secondo intero 
#if 0
    set_fraction(f, 1, 2);
    printf("\n");
    print_fraction(f);
    free(f);

    f = create_fraction(10, 20);
    printf("\n");
    print_fraction(f);
    simplify_fraction(f);
    print_fraction(f);
#endif

    printf("%d\n", sizeof(struct frac));  // Stampa 8 che e' l'aggregato dei due 
                                        // interi che compongono la struttura.

    // se aggiungo un char come dato vedo in realta' 12 byte (anche se il primo membro ne occupa solo uno)
    // infatti il c garantisce che ogni membro e' memorizzatio in una posizione che e' un multiplo della sua dimensione.
    // quindi questo forza a riservare 4 byte per il primo membro. Un byte di dato piu' uno di padding.
    // la struttura mi deve garantire anche che e' allineata al tipo piu grande, e che questa regola vale anche 
    // per array di strutture, e questo richiede che questo allineamento sia sempre presente. 
    printf("%d\n", sizeof(struct char_frac));

    // quello che si puo' fare per ottimizzare la dimensione della struttura, e' impacchettare i membri di dimensione
    // minore alla dimensione massima uno dopo l'altro, im modo da ridurre lo spazio speso in padding.
    // ad esempio se avessiomo tre undigned char, potremmo meterli uno dietro l'altro.
    printf("%d\n", sizeof(struct frac_3_char));

    // ora vediamo come usare la struttura
    // definisco una variabile come di tipo struct frac
    struct frac a;
    a.num = 10;
    a.den = 20;

    // se definisco un puntatore a una struttura, per
    // accedere ai campi uso la freccia 
    // questo perche il C e' disegnato per essere esplicito, 
    // non perche il compilatore abbia un hint sul tipo di dato).
    struct frac *b = malloc(sizeof(struct frac));
    b->num = 3;
    b->den = 4;

    // riscrivo il programma di prima
    struct frac *f1 = create_fraction(10,20);
    struct frac *f2 = create_fraction(4,7);
    simplify_fraction(f1);
    print_fraction(f1);
    print_fraction(f2);

    // e' importante osservare che essendo una struttura effettivamente un tipo di dato
    // lo posso ritornare ad esempio dalla create_fract direttamente, senza usare una malloc 
    // ma definendo una variabile di quel tipo e restituendola.
    // ritornare una struttura per valore, effettivamente, non lo si fa mai per un motivo di efficienza.
    // quando si ritorna la variabile locale per inizializzare la variabile "chiamante" il c infatti
    // esegue implicitamente una copia di byte che nel caso di puntatori non e' necessaria.
    // questa operazione in piu' di copia rende il programma inefficiente.

}

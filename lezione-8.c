#include <stdio.h>



// questa versione, a meno di ottimizzazioni del comiplatore,
// creera per ogni chiamata della ricorsione un nuovo stack-frame.
// la rinominiamo vanilla e ne creiamo una diversa che non fa questa costa 
// ma usa invece il goto.
void conta_ricorsiva(int start, int end)
{
	if (start > end) return;
	printf("%d\n", start);
	conta_ricorsiva(start+1, end);
}

// non cambia niente, e' equivaluente a una ricorsione perche rieseguo lo stesso 
// pezzo di codice cambiando l'input
//
// - questa implementazione si chiama TAIL CALL OPTIMIZATION e si puo' fare quando la
//   funzione ricorsiva e' una chiamata di coda.
void conta_goto(int start, int end)
{
iterate:
	if (start > end) return;
	
	printf("%d\n", start);
	start++;
	goto iterate;
}



// ovviamente benche il goto permetta di eseguire questo tipo di ottimizzazione in C,
// in generale si utilizzano costrutti di piu' alto livello, come ad esempio il while ed i for.

void conta_while(int start, int end)
{
	printf("Ciclo WHILE:\n");
	int i = start;	

	while (i < end)
	{
		printf("%d\n", i);
		i++;
	}
}

// Il ciclo for in realta' non e' altro che un While mascherato.

void conta_for(int start, int end)
{
	printf("Ciclo FOR:\n");

	int i = start;	

	for (int i = start; i < end;++i)
		printf("%d\n", i);
}


// piccola variante in cui non inizializzo il ciclo for ma ne esco con un break
void conta_for_break(int start, int end)
{
	printf("Ciclo FOR:\n");

	int i = start;	

	for (; ; ++i) {
		if (i >=10) break; // in pratica ho un ciclo infinito dal quale esco con un break.
		printf("%d\n", i);
	}
		

	for (;;)  // >>>>> Ciclo Infinito!!
	{
		if (i >=10) break; // in pratica ho un ciclo infinito dal quale esco con un break.
		printf("%d\n", i);
		i++;
	}

	while (1)  // >>>>> Ciclo Infinito!! E' del tutto equivalente!!!
	{
		if (i >=10) break; // in pratica ho un ciclo infinito dal quale esco con un break.
		printf("%d\n", i);
		i++;
	}
}


int main(void)
{
	// conta_while(0, 10);
	// printd("Ciclo FOR:\n");
	// conta_for(0, 10);

	// la condizione di uscita del for non deve necessariamente essere su i, ma puo' essere
	// valutata su un valore dipendente da i, come ad esempio il valore di un elemento di 
	// indice i

	int a[] = {3, 4, 3, 8, 9, 0};

	int i;
	for (i = 0; a[i] != 0; i++)
	{
		printf("%d\n", a[i]);
	}

	// do-while
	// e' una alternativa con una semantica un po' diversa.
	// viene fatta sempre una prima iterazione e il controllo sulla condizione
	// viene fatta sempre alla fine. a volte e' utile ma in generale si puo' sostituire con 
	// altri costrutti equivalenti basati wul while con ad esempio una if.
	printf("\n");
	printf("Esercizio do-while\n");
	i=0;
	do {
		i++;
		printf("%d\n", i);
	} while (i < 10);
	

	// switch
	// lo switch e' mnolto simile al caso di if >> else if >> else
	// c'e' una differenza importante!!!
	// - senza il break vengono eseguite le istruzioni associate al case e a tutti quelli successivi!!!
	// - non si possono dichiarare variabili dentro il case, a meno che non metta esplicitamente le parentesi graffe del blocco.
	printf("\n");
	printf("Esercizio Switch:\n");
	i = 5;

	switch(i)
	{
		case 5: printf("E' un 5!\n"); break;
		case 6: printf("E' un 6!\n"); break;
		case 7: printf("E' un 7!\n"); break;
		default: printf("Qualche altro numero!\n"); break;break;
	}


	return 0;
}


	


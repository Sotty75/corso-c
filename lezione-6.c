#include <stdio.h>

void conta(int start, int end)
{
	if (start > end) return;
	printf("%d\n", start);
	conta(start+1, end);
}

int main(void)
{
	int parte = 3;

	// Primo esempio
	if (parte == 0)
	{

		// cose da notare
	//
	// 1. blocchi tra parentesi graffe, non sono necessari in C nel caso sia una sola istruzione
	// 2. E' piu' comodo porre in questo caso tutto nella stessa riga. cosi facendo si riduce anche la lunghezza del codice sorgente
	//    e mi devo spostare meno per vedere il codice. E' una questione squisitamente stilistica
	// 3. E' importante non focalizzarsi su questioni di stile, perche' ognuno ha il suo gusto estetico. Ovviamente ci vogliono dei limiti.
	
	int i = 5;

	if (i > 3) 
	{
		printf("i > 3\n");
	}
	else
	{
		printf("i <= 3\n");
	}

	// E' interessante il fatto che io possa mettere un blocco ovunque
	{
		// ...anche senza nessun motivo
	}

	// ma ancora piu' interessante e' che questo blocco in realta definisce una area 
	// di esistenza delle variabili locali

	{
		int i = 4;
		printf ("Questa i vale: %d\n", i);
	}

	printf ("Questa i vale: %d\n", i);


	// proviamo ora ad accedere alla variabile i come se fosse un puntatore, in modo da verificare che siano
	// effettivamente oggetti distinti in memoria
	printf("\n");
	printf("\n");

	{
		int i = 4;
		printf ("La i locale e' registrata all'indirizzo: %p\n", &i);
	}

	printf ("La i globale e' registrata all'indirizzo: %p\n", &i);

	}
	
	if (parte == 1) 
	{
		int i = 0;

		// queste si chiamano etichette!! come in assembly o addiritttura in basic.
		again:
			printf("i equals: %d\n", i);
			i++;
			if (i < 10) goto again;
				
	}

	//...sostituire un ciclo while con un if + goto
	// lo scope mi sembra piu' pedagogico, nel senso che il risultato e' del codice che assomiblia molto 
	// a come lo scriveremmo in linguaggio assembly, con delle etichette
	// 
	// in questo caso contiamo fino a 9 con un while, e poi lo implementiamo semplicemente
	// sostituendo con un uso accorto di if e goto
	// in realta' ha senso, pensando al fatto che il goto richiama una porzione di codice, che in questo caso 
	// facciamo comunque. in realta' questo modo di lavorare, genera per ogni chiamata allocazioni in memoria creando un nuovo stack frame per
	// ogni chiamata, che pero' e' poco efficiente in termine di ottimizzazione dell'utilizzo dello stackframe.
	// quindi va fatto in modo accorto e se ha senso nella risoluzione di un problema. 
	if (parte == 2)
	{
		int i = 0;   // inizializziamo il nostro contatore a 0

		// while (i < 10)
		// {
		// 		printf("%d\n", i);
		// 		i++;
		// }

	loop:
		if (i < 10) goto next_iteration;
		goto skip;

		next_iteration:
		printf("%d\n",i);
		i++;
		goto loop;


	skip:

	}

	// ora proviamo a fare il calcolo solo con delle if, usando la ricorsione
	// non mi e' chiaro dove vuole arrivare ma ok.
	// definiamo una funzone ricorsiva che chiamiamo conta() e la chiamiamo.
	if (parte == 3)
	{
		conta(0, 9);
	}
	


	return 0;
}


	


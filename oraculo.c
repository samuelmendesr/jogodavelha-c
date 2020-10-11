/* 
	oraculo 1.0
	
	@autor Samuel Mendes Rodrigues

	data de criação: 	08/06/2016
	ultima atualização: 09/06/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Low  1
#define High 10

/*		
	Legenda:

	"X" ~> Jogada de oraculo() 
	"O" ~> Jogada do usuário
	"?" ~> Alguma jogada no local
	"!" ~> Talvez alguma jogada no local

	OBS 1: A situação de jogo nos comentarios também abrange suas rotações.

			[X][ ][ ]   [ ][ ][X]
		Ex:	[ ][O][X] = [ ][O][ ].
			[ ][ ][ ]   [ ][X][ ]

	OBS 2: As jogadas de oraculo() correspondem ao seguinte mapa(diferente do usuário):
		
		[0][1][2]
		[3][4][5]
		[6][7][8]
*/

int oraculo(int* g, int t)
{
	int i, 
		finalizar = 0, chutar = 0, chutar_par = 0, chutar_impar = 0, 
		par = 0, impar = 0, c = 0, 
		jogada, jogada_ruim;

	int *chute_par, *chute_impar, *chute;
	
	chute_par = (int*)calloc(5, sizeof(int));
	chute_impar = (int*)calloc(4, sizeof(int));
	chute = (int*)calloc(9, sizeof(int));

	/*
		Primeira jogada deve ser aleatória.
	*/
	if(!t)
	{
		srand((unsigned int)time(NULL));

		jogada = rand()%9;

		finalizar = 1;
	}

	/*	
		Se oraculo() for o segundo a jogar e o meio estiver vago, a jogada será no meio.
	*/
	if((!(*(g + 4)))&&(t == 1))
	{
		jogada = 4;
		finalizar = 1;
	}

	/*	
		Se oraculo() for o terceiro a jogar, 6 situações precisarão ser analisadas. 
	*/
	if((!finalizar)&&(t == 2))
	{
		/*
                        [?][ ][ ]                   [?][ ][ ]
			Situação 1:	[ ][?][ ] , melhor jogada:  [ ][?][ ].
				        [ ][ ][ ]                   [ ][ ][X]
		*/
		if((*(g + 0) + *(g + 4) + *(g + 8)) == Low + High)
		{
			if(!(*(g + 0)))
			{
				jogada = 0;
				finalizar = 1;
			}
			else if(!(*(g + 8))) 
			{
				jogada = 8;
				finalizar = 1;
			}
		}
		else if((*(g + 6) + *(g + 4) + *(g + 2)) == Low + High)
		{
			if(!(*(g + 6)))
			{
				jogada = 6;
				finalizar = 1;
			}
			else if(!(*(g + 2))) 
			{
				jogada = 2;
				finalizar = 1;
			}
		}
		/*
                        [ ][!][ ]		             [ ][!][ ]
			Situação 2:	[!][ ][!] , melhor jogada:   [!][X][!].
				        [ ][!][ ]                    [ ][!][ ]
		*/
		else if((*(g + 1) + *(g + 3) + *(g + 5) + *(g + 7)) == Low + High)
		{
			jogada = 4;
			finalizar = 1;
		}
		/*
                        [X][!][!]                   [X][!][!]
			Situação 3:	[ ][ ][!] , melhor jogada:  [ ][ ][!].
				        [ ][!][!]                   [X][!][!]
		*/
		else if((*(g + 0) + *(g + 2) + *(g + 6) + *(g + 8)) >= High)
		{
			if((*(g + 0) + *(g + 3) + *(g + 6)) == High)
			{
				if(!(*(g + 0)))
				{
					jogada = 0;
					finalizar = 1;
				}
				else if(!(*(g + 2)))
				{
					jogada = 6;
					finalizar = 1;
				}
			}
			else if((*(g + 2) + *(g + 5) + *(g + 8)) == High)
			{
				if(!(*(g + 2)))
				{
					jogada = 2;
					finalizar = 1;
				}
				else if(!(*(g + 8)))
				{
					jogada = 8;
					finalizar = 1;
				}
			}
		}
		/*
                        [ ][ ][ ]                    [ ][ ][ ]
			Situação 4:	[O][X][ ] , melhor jogada:   [O][X][ ].
                        [ ][ ][ ]                    [ ][X][ ]
		*/
		else if((*(g + 1) + *(g + 3) + *(g + 5) + *(g + 7)) == Low)
		{
			if((*(g + 1) + *(g + 4) + *(g + 7)) == Low)
			{
				jogada = 1;
				finalizar = 1;
			}
			else if((*(g + 3) + *(g + 4) + *(g + 5)) == Low)
			{
				jogada = 3;
				finalizar = 1;
			}
		}
		/*
                        [ ][ ][ ]                   [ ][ ][ ]
			Situação 5:	[X][O][ ] , jogada ruim:    [X][O][X]. 
                        [ ][ ][ ]                   [ ][ ][ ]
		*/
		else if(*(g + 4) == Low)
		{
			if(*(g + 1) == High)
			{
				jogada_ruim = 7;
				finalizar = 1;
				chutar = 1;
			}
			else if(*(g + 3) == High)
			{
				jogada_ruim = 5;
				finalizar = 1;
				chutar = 1;
			}
			else if(*(g + 5) == High)
			{
				jogada_ruim = 3;
				finalizar = 1;
				chutar = 1;
			}
			else if(*(g + 7) == High)
			{
				jogada_ruim = 1;
				finalizar = 1;
				chutar = 1;
			}
		}
		/*
                            [ ][ ][ ]		          [ ][ ][ ]
			Situação 6:	    [X][ ][ ], melhor jogada: [X][ ][ ]. 
                            [ ][ ][O]                 [X][ ][O]
		*/
		else if(!(*(g + 4)))
		{
			if((*(g + 1) + *(g + 2) + *(g + 3) + *(g + 6)) == High + Low)
			{
				jogada = 0;
				finalizar = 1;
			}
			else if((*(g + 0) + *(g + 1) + *(g + 5) + *(g + 8)) == High + Low)
			{
				jogada = 2;
				finalizar = 1;
			}
			else if((*(g + 0) + *(g + 3) + *(g + 7) + *(g + 8)) == High + Low)
			{
				jogada = 6;
				finalizar = 1;
			}
			else if((*(g + 2) + *(g + 5) + *(g + 6) + *(g + 7)) == High + Low)
			{
				jogada = 8;
				finalizar = 1;
			}
		}	
	}

	/*	
		Os procedimentos a seguir são para analizar se existe uma jogada
		para vencer a partida. 
	*/
	if(!finalizar)
	{
		for(i = 0; i < 3; i++)
		{
			if((*(g + i*3) + *(g + i*3 + 1) + *(g + i*3 + 2)) == 2*High)
			{
				if(!(*(g + i*3)))
				{
					jogada = i*3;
					finalizar = 1;
				}
				else if(!(*(g + i*3 + 1)))
				{
					jogada = i*3 + 1;
					finalizar = 1;
				}
				else 
				{
					jogada = i*3 + 2;
					finalizar = 1;
				}
			}
		   
		    if((*(g + i) + *(g + i + 3) + *(g + i + 6)) == 2*High)
			{
				if(!(*(g + i)))
				{
					jogada = i;
					finalizar = 1;
				}
				else if(!(*(g + i + 3)))
				{
					jogada = i + 3;
					finalizar = 1;
				}
				else
				{ 
					jogada = i + 6;
					finalizar = 1;
				}
			}
		}
	}

	if(!finalizar)
	{
		if((*(g + 0) + *(g + 4) + *(g + 8)) == 2*High)
		{
			if(!(*(g + 0)))
			{
				jogada = 0;
				finalizar = 1;
			}
			else if(!(*(g + 4)))
			{
				jogada = 4;
				finalizar = 1;
			}
			else 
			{
				jogada = 8;
				finalizar = 1;
			}
		}

		if((*(g + 6) + *(g + 4) + *(g + 2)) == 2*High)
		{
			if(!(*(g + 6)))
			{
				jogada = 6;
				finalizar = 1;
			}
			else if(!(*(g + 4)))
			{
				jogada = 4;
				finalizar = 1;
			}
			else 
			{
				jogada = 2;
				finalizar = 1;
			}
		}
	}

	/*	
		Os procedimentos a seguir são para analisar se é necessário
		impedir uma vitória do usuário na jogada seguinte.	 
	*/
	if(!finalizar)
	{
		for(i = 0; i < 3; i++)
		{
			if((*(g + i*3) + *(g + i*3 + 1) + *(g + i*3 + 2)) == 2*Low)
			{
				if(!(*(g + i*3)))
				{
					jogada = i*3;
					finalizar = 1;
				}
				else if(!(*(g + i*3 + 1)))
				{
					jogada = i*3 + 1;
					finalizar = 1;
				}
				else 
				{
					jogada = i*3 + 2;
					finalizar = 1;
				}
			}

			if((*(g + i) + *(g + i + 3) + *(g + i + 6)) == 2*Low)
			{
				if(!(*(g + i)))
				{
					jogada = i;
					finalizar = 1;
				}
				else if(!(*(g + i + 3)))
				{
					jogada = i + 3;
					finalizar = 1;
				}
				else
				{ 
					jogada = i + 6;
					finalizar = 1;
				}
			}
		}
	}

	if(!finalizar)
	{
		if((*(g + 0) + *(g + 4) + *(g + 8)) == 2*Low)
		{
			if(!(*(g + 0)))
			{
				jogada = 0;
				finalizar = 1;
			}
			else if(!(*(g + 4)))
			{
				jogada = 4;
				finalizar = 1;
			}
			else 
			{
				jogada = 8;
				finalizar = 1;
			}
		}
		else if((*(g + 6) + *(g + 4) + *(g + 2)) == 2*Low)
		{
			if(!(*(g + 6)))
			{
				jogada = 6;
				finalizar = 1;
			}
			else if(!(*(g + 4)))
			{
				jogada = 4;
				finalizar = 1;
			}
			else 
			{
				jogada = 2;
				finalizar = 1;
			}
		}
	}

	/*	
		Se oraculo() for o quarto a jogar, 3 situações precisarão ser analisadas.
	*/
	if((!finalizar) && (t == 3))
	{
		/*
			            [O][ ][ ]			       [O][ ][ ]
			Situação 1:	[ ][X][ ] , melhor jogada: [ ][X][ ]. 
					    [ ][ ][O]                  [ ][X][O]
		*/
		if(((*(g + 0) + *(g + 8)) == 2*Low) && (*(g + 4) == High))
		{
			chutar_impar = 1;
			finalizar = 1;
		}
		else if(((*(g + 6) + *(g + 2)) == 2*Low) && (*(g + 4) == High))
		{
			chutar_impar = 1;
			finalizar = 1;
		}
		else if((*(g + 1) + *(g + 3) + *(g + 5) + *(g + 7)) == 2*Low)
		{
			/*
						[!][ ][!]		   [!][ ][!]
				Situação 2:	[O][ ][ ] , melhor jogada: [O][ ][ ](uma jogada em um dos cantos). 
						[!][O][!]                  [!][O][!]
			*/
			if(!(*(g + 4)))
			{
				chutar_impar = 1;
				finalizar = 1;
			}
			/*
                            [ ][ ][ ]		         [ ][ ][X]
				Situação 3:	[O][X][ ] , jogada ruim: [O][X][ ]. 
                            [ ][O][ ]                [ ][O][ ]
			*/
			else
			{
				if((*(g + 5) + *(g + 7)) == 2*Low)
				{
					jogada_ruim = 0;
				}
				else if((*(g + 3) + *(g + 7)) == 2*Low)
				{
					jogada_ruim = 2;
				}
				else if((*(g + 1) + *(g + 5)) == 2*Low)
				{
					jogada_ruim = 6;
				}
				else if((*(g + 1) + *(g + 3)) == 2*Low)
				{
					jogada_ruim = 8;
				}
			}
		}
	}

	/*	
		Se oraculo() for o quainto a jogar, 2 situações precisarão ser analisadas.
	*/
	if((!finalizar) && (t == 4))
	{
		/*
			            [ ][O][ ]			       [ ][O][ ]
			Situação 1:	[O][X][ ] , melhor jogada: [O][X][ ]. 
					    [ ][X][ ]                  [ ][X][X]
		*/
		if(((*(g + 1) + *(g + 3) + *(g + 5) + *(g + 7)) == 2*Low + High)&&(*(g + 4) == High))
		{
			if(*(g + 1) == Low)
			{
				jogada = 8;
				finalizar = 1;
			}
			else if(*(g + 3) == Low)
			{
				jogada = 2;
				finalizar = 1;
			}
			else if(*(g + 5) == Low)
			{
				jogada = 6;
				finalizar = 1;
			}
			else if(*(g + 7) == Low)
			{
				jogada = 4;
				finalizar = 1;
			}
		}
		/*
                        [X][!][X]		             [X][!][X]
			Situação 2:	[!][ ][ ] , melhor jogada:   [!][ ][ ]. 
                        [!][ ][ ]                    [!][ ][X]
		*/
		else if((*(g + 0) + *(g + 1) + *(g + 2) + *(g + 3) + *(g + 6)) == 2*High + 2*Low)
		{
			jogada = 8;
			finalizar = 1;
		}
		else if((*(g + 0) + *(g + 1) + *(g + 2) + *(g + 5) + *(g + 8)) == 2*High + 2*Low)
		{
			jogada = 6;
			finalizar = 1;
		}
		else if((*(g + 0) + *(g + 3) + *(g + 6) + *(g + 7) + *(g + 8)) == 2*High + 2*Low)
		{
			jogada = 2;
			finalizar = 1;
		}
		else if((*(g + 2) + *(g + 5) + *(g + 6) + *(g + 7) + *(g + 8)) == 2*High + 2*Low)
		{
			jogada = 0;
			finalizar = 1;
		}
	}

	/*	
		Se nenhuma boa jogada for encontrada, serão calculados os espaços disponíveis
		para um chute. Formas diferentes de chute serão feitas dependendo de instruções
		anteriores.
	*/	
	if(!finalizar)
	{
		for(i = 0; i < 9; i++)
		{
    	    if((!(*(g + i)))&&(i != jogada_ruim))
			{	
				if(!(i%2))
				{
					*(chute_par + par) = i;
					par++;
					chutar_par = 1;
				}
			}
		}				

		if(chutar_par)
		{
			srand((unsigned int)time(NULL));

			i = rand()%par;

			jogada = *(chute_par + i);
		}
		else
			chutar_impar = 1;
	}

	if(chutar_impar)
	{
		for(i = 0; i < 9; i++)
		{
    	    if(!(*(g + i))&&(i != jogada_ruim))
			{	
				if(i%2)
				{
					*(chute_impar + impar) = i;
					impar++;
				}
			}
		}

		srand((unsigned int)time(NULL));

		i = rand()%impar;

		jogada = *(chute_impar + i);
	}

	if(chutar)
	{
		for(i = 0; i < 9; i++)
		{
    	    if(!(*(g + i))&&(i != jogada_ruim))
			{	
				*(chute + c) = i;
				c++;
			}
		}

		srand((unsigned int)time(NULL));

		i = rand()%c;

		jogada = *(chute + i);

		finalizar = 1;
	}

	free(chute);
	free(chute_par);
	free(chute_impar);

	return jogada;			
}

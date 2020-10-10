All: jogodavelha

jogodavelha:	main.o jogo_da_velha.o oraculo.o
	gcc main.o jogo_da_velha.o oraculo.o -o jogodavelha

main.o:	main.c jogo_da_velha.h oraculo.h
	gcc -c main.c

jogo_da_velha.o: jogo_da_velha.c jogo_da_velha.h
	gcc -c jogo_da_velha.c

oraculo.o:	oraculo.c oraculo.h
	gcc -c oraculo.c	

clean:
	rm -f *.o projeto

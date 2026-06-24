all:
	gcc main.c prime_api.c -o main -lm 
	./main 
	rm main

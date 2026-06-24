# PrimeNumberChallenge


een challenge gebaseerd op de volgende reddit post: "https://www.reddit.com/r/learnprogramming/comments/du8bii/find_first_100_billion_primes/"
daarin staat de uitdaging om de eerste 100 miljard priemgetallen onder de minuut te vinden.



    

In de eerste aanpak (approach) heb ik alle priem getallen onder 1 miljoen gevonden in 0,287 seconden.
Dus voor 1 miljard zou het betekenen dat het 287 seconden zou duren.
En voor 100 miljard minstens (zal zeker langer duren aangezien je met hogere getallen werkt) 28700 seconden en dat is gelijk aan 7,97uren





In de tweede aanpak heb ik alle priem getallen onder 1 miljoen gevonden in  0,011496 seconden.
Door gebruik te maken van het zeef van eratosthenes (indien je er meer over wilt leren https://www.geeksforgeeks.org/c/c-program-to-implement-sieve-of-eratosthenes/)
Dus voor 1 miljard zou het betekenen dat het 11,496 seconden zou duren.
En voor 100 miljard minstens (zal zeker langer duren aangezien je met hogere getallen werkt) 1149,6 seconden en dat is gelijk aan 19,16 minuten
Ik heb het gerunned voor 1 miljard getallen en dit is de output:
Er zijn onder 1000000000: 50847534 priemgetallen gevonden
Uitvoeringstijd: 21.866018 seconden





In de derde aanpak heb ik alle priem getallen onder 1 miljoen gevonden in 0,010288 seconden.
Door gebruik te maken van het zeef van eratosthenes 
En enkele optimalisatie trucs namelijk:
Namelijk segmented sieves dat is een truc om het werk op te splitsen in kleinere delen.
Daarmee bedoel ik dat je in de tweede aanpak werkte met 1 grote blok aan memory dat betekent dat je constant naar ram moet schrijven.
Maar met segmented sieves deel je die grote blok (1 miljard bytes) op in S (S is 100000 in mijn derde aanpak) delen, dus je deelt 1 Miljard door S.
En zoveel blokken moet je dan verwerken. Het voordeel hierin is dat zon kleine blok meestal in de CPU caches past. En dat je daardoor betere resultaten opvangt.
Ik heb het gerunned voor 1 miljard getallen en dit is de output:
Er zijn onder 1000000000: 50847534 priemgetallen gevonden
Uitvoeringstijd: 11.005430 seconden

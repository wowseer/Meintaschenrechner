#include <stdio.h>

int main () {

    if(menu() == 1){
        addieren();
    }else if(menu() == 2){
        subtrahieren();
    }else if(menu() == 3){
        multiplizieren();
    }else if(menu() == 4){
        dividieren();
    }else{
        printf("Falsche Eingabe\n");
    }
    return 0;
}

int menu(){
    int selection;

    printf("Hallo ich bin dein Persönlicher Taschenrechner\n");
    printf("Bitte Gib an ob du Addieren(1), Subtrahieren(2), Multiplizieren(3) oder Dividieren(4) möchtest.\n");
    printf("\n\n");
    scanf("%d", &selection);

    return selection;
}
int zahlenEingabe(int *anzahl, int *zahlen){
    // int *zahlen;
    // int anzahl = 0;
    int *eingabe;
    // zahlen = (int*)malloc(sizeof(int));

    printf("Bitte gib die Anzahl der Zahlen ein die du eingeben möchtest, mit -1 Kommst du zurück.\n");
    scanf("%d",anzahl);
   // (int*)realloc(zahlen, (*anzahl)*sizeof(int));
    zahlen = (int*)realloc(zahlen, *anzahl * sizeof(int)); // Speicher anpassen

    for(int i = 0; i < *anzahl; i++){
        scanf("%d", eingabe);
        zahlen[i] = *eingabe;
    }
    // for(int i = 0; i < *anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    // }
    // free(eingabe);
    return anzahl;
}

void addieren(){
    int anzahl = 0;
    int *zahlen =(int*)malloc(sizeof(int));
    zahlenEingabe(&anzahl, zahlen);

    int summe = 0;
    // for(int i = 0; i < anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    // }
    for(int i = 0; i < anzahl; i++){
        summe += zahlen[i];
    }

    printf("Die Summe der Zahlen ist: %d\n", summe);
}

void subtrahieren(){
    int anzahl = 0;
    int *zahlen =(int*)malloc(sizeof(int));
    zahlenEingabe(&anzahl, zahlen);

    int summe = 0;
    // for(int i = 0; i < anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    // }
   for (int i = 0; i < anzahl; i++) {
    if (i == 0) {
    summe = zahlen[i]; // Erste Zahl zuweisen
    } else {
    summe -= zahlen[i]; // Restliche Zahlen abziehen
    }
}

    printf("Die Differenz der Zahlen ist: %d\n", summe);

}

void multiplizieren(){
    int anzahl = 0;
    int *zahlen =(int*)malloc(sizeof(int));
    zahlenEingabe(&anzahl, zahlen);

    int summe = 1;
    // for(int i = 0; i < anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    // }
    for(int i = 0; i < anzahl; i++){
        summe *= zahlen[i];
    }

    printf("Das Produkt der Zahlen ist: %d\n", summe);
}

void dividieren(){
    int anzahl = 0;
    int *zahlen =(int*)malloc(sizeof(int));
    zahlenEingabe(&anzahl, zahlen);

    int summe = 1;
    // for(int i = 0; i < anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    // }
    for(int i = 0; i < anzahl; i++){
        summe /= zahlen[i];
    }

    printf("Der Quotient der Zahlen ist: %d\n", summe);
}

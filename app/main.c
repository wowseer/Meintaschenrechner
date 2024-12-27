#include <stdio.h>

int main () {

    int selection = menu();

        if(selection == 1){
            addieren();
        }else if(selection == 2){
            subtrahieren();
        }else if(selection == 3){
            multiplizieren();
        }else if(selection == 4){
            dividieren();
        }else{
            printf("Falsche Eingabe\n");
            printf("Bitte wähle eine der Optionen 1, 2, 3 oder 4\n");
            printf("\n\n");
            main();
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

    printf("Bitte gib die Anzahl der Zahlen ein die du eingeben möchtest. \n");
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

    // for(int i = 0; i < anzahl; i++){
    //     printf("%d\n", zahlen[i]);
    //
    if (anzahl > 0) {
        double quotient = zahlen[0]; // Erste Zahl zuweisen, double für genauere Ergebnisse
        for (int i = 1; i < anzahl; i++) {
            if (zahlen[i] == 0) { // Division durch Null abfangen
                fprintf(stderr, "Fehler: Division durch Null!\n");
                free(zahlen); // Speicher freigeben
                return;
            }
            quotient /= zahlen[i];
        }
        printf("Der Quotient der Zahlen ist: %f\n", quotient);
    } else {
        printf("Keine Zahlen eingegeben.\n");
    }

}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int selection = menu();
  do {
        selection = menu();

        switch (selection) {
            case 1:
                addieren();
                break;
            case 2:
                subtrahieren();
                break;
            case 3:
                multiplizieren();
                break;
            case 4:
                dividieren();
                break;
            case 0: // Option zum Beenden hinzugefügt
                printf("Programm beendet.\n");
                break;
            default:
                printf("Falsche Eingabe\n");
                printf("Bitte wähle eine der Optionen 1, 2, 3, 4 oder 0 zum Beenden\n");
                printf("\n\n");
        }
    } while (selection != 0); // Schleife läuft, bis der Benutzer 0 wählt
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


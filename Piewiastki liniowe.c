#include <stdio.h>



#define    BRAK_PIERWIASTKOW                      0
#define    JEDEN_PIERWIASTEK                      1
#define    NIESKONCZENIE_WIELE_PIERWIASTKOW     -1



int rozwiazanie_rownania_liniowego(float a, float b, float *x) {
    int liczba_pierwiastkow;



    if (a != 0) {
        liczba_pierwiastkow = JEDEN_PIERWIASTEK;
        *x = -b/a;
    }
    else if (b != 0)
        liczba_pierwiastkow = BRAK_PIERWIASTKOW;
    else
        liczba_pierwiastkow = NIESKONCZENIE_WIELE_PIERWIASTKOW;



    return liczba_pierwiastkow;
}



int main() {
    float wsp_kier, wyr_wolny, pierwiastek;
    int lp;    /* liczba pierwiastków */

    printf("Podaj wspolczynnik kierunkowy: ");
    scanf("%f", &wsp_kier);



    printf("Podaj wyraz wolny: ");
    scanf("%f", &wyr_wolny);



    lp = rozwiazanie_rownania_liniowego(wsp_kier, wyr_wolny, &pierwiastek);



    if (lp == JEDEN_PIERWIASTEK)
        printf("Rownanie ma jeden pierwiastek: %f\n", pierwiastek);
    else if (lp == BRAK_PIERWIASTKOW)
        printf("Rownanie nie posiada pierwiastkow.");
    else
        printf("Wystepuje nieskonczenie wiele pierwiastkow.");



    return 0;
}

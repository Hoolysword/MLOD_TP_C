#include <stdio.h>
#include <stdlib.h>

enum mois {
    janvier,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre,
};
typedef struct {
    int jour;
    enum mois mois;
    int annee;
} Date;

void initialiseDate(Date *date){
    scanf("%i",(int *)&date->jour);
    scanf("%i",(int *)&date->mois);
    scanf("%i",(int *)&date->annee);
}
void afficheDate(Date *date){
    printf("%i/%i/%i",date->jour,date->mois,date->annee);
}
Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}

Date *newDate(){
    Date *date;
    date = malloc(sizeof(Date));
    initialiseDate(date);
    return date;
}
int main(void) {
//version 1
/*Date d;
initialiseDate(&d); //Pourquoi a t-on ajouté un &?
afficheDate(&d);*/
//version 2
/*Date d;
d = creerDateParCopie();
afficheDate(&d);*/
//version 3
Date *date;
date = newDate();
afficheDate(date);
//...
free(date);


} 
#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e) {
	printf("%s ",(char*)e);
}
void detruireElement(Element e){

}
bool equalsElement(Element e1, Element e2){
	return strcmp((char *)e1,(char *)e2)==0;
}

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("a",l);
	l = ajoutTete("boo",l);
	l = ajoutTete("c",l);
	l = ajoutTete("a",l);
	l = ajoutTete("d",l);
	l = ajoutTete("f",l);
	l = ajoutTete("b",l);
	l = ajoutTete("a",l);
	l = ajoutTete("e",l);

 	afficheListe_i(l);

	ajoutFin_r("r",l);
	 afficheListe_i(l);

	ajoutFin_r("v",l);
	afficheListe_i(l); 
		ajoutFin_i("v",l);
	afficheListe_i(l); 
 
	p = cherche_i("h",l);
	printf("cherche_i(h) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("a",l);
	if(estVide(p))
		printf("cherche_i(a) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(a) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("h",l);
	printf("cherche_r(h) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("a",l);
	if(estVide(p))
		printf("cherche_r(a) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(a) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}


	printf("retirePremier_i(e)   : ");
	l = retirePremier_i("e",l);
	afficheListe_r(l);

	
	printf("retirePremier_i(b)   : ");
	l = retirePremier_i("b",l);
	afficheListe_r(l);

	printf("retirePremier_i(h) : ");
	l = retirePremier_i("h",l);
	afficheListe_r(l);

	printf("retirePremier_i(e)   : ");
	l = retirePremier_i("e",l);
	afficheListe_r(l);

	printf("retirePremier_i(b)   : ");
	l = retirePremier_i("b",l);
	afficheListe_r(l);

	printf("retirePremier_i(99)  : ");
	l = retirePremier_i("c",l);
	afficheListe_r(l);
	printf("afficheEnvers  : ");
 afficheEnvers_r(l);
 
	detruire_r(l);
	return EXIT_SUCCESS;
}

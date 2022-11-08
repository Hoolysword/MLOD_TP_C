#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
    Liste newl=malloc(sizeof(Cellule));
        newl->val=v;
        newl->suiv =NULL;
	return newl;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste new =creer(v);
    new->suiv=l;
	return new;
}


extern void afficheElement(Element e);

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(estVide(l)){
    }
	else{
    	while(!estVide(l)){
			afficheElement(l->val);
    		l=(l->suiv);
    }
	}
}

// version recursive
void afficheListe_r(Liste l) {
    if(estVide(l)){
    }
    else{
	    afficheElement((*l).val);
        afficheListe_r((*l).suiv);
    }
}

extern void detruireElement(Element e);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant;
	Liste courant = l;
	if(estVide(l)){
    }
	else{
    	while((*l).suiv!=NULL){
			suivant=courant->suiv;
			detruireElement(courant->val);
			free(courant);
    		courant=suivant;
    }

	}
}


// version récursive
void detruire_r(Liste l) {
	Liste suivant;
	Liste courant=l;
  if(estVide(l)){
    }
    else{
		suivant=courant->suiv;
		detruireElement(courant->val);
		free(courant);
        detruire_r(suivant);


    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste c=l;
	if(estVide(l)){
		return creer(v);
	}
	while((*l).suiv!=NULL){
    		l=(l->suiv);
    }
	l->suiv=creer(v);
	return c;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	if(estVide(l->suiv)){
		l->suiv=creer(v);
	}
	else
	{
		ajoutFin_r(v,l->suiv);
	}
	
	return l;
	
}

// compare deux elements
extern bool equalsElement(Element e1, Element e2);


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) ){
		if(equalsElement(l->val,v)){
			return l;}
		else{
			l=l->suiv;}
}
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if( !estVide(l) ){
		if(equalsElement(l->val,v)){
			return l;}
		else{
		cherche_r(v,l->suiv);}
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent,p;
	if(estVide(l)){
		return l;
	}
	if(equalsElement(l->val,v)){
		p=l->suiv;
		l->suiv=NULL;
				detruire_i(l);
		return p;
	}
	precedent =l;
	p = l->suiv;
	while(!estVide(p) && !equalsElement(p->val,v)){
		precedent = p;
		p=p->suiv;
	}
	if(!estVide(p)){

		precedent->suiv =p->suiv;
		p->suiv =NULL;
				detruire_i(p);
	}
    return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(!estVide(cherche_r(v,l))){
		detruireElement(cherche_r(v,l)->val);
}
return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		afficheEnvers_r(l->suiv);
		afficheElement((*l).val);
	}

}


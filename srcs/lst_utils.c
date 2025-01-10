#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_list *initialisation();
void afficherListe(t_list *liste);
void insertion(t_list *liste, int nvNombre);
void suppression(t_list *liste);
void destruction(t_list *liste);

int main()
{
	t_list *maListe = initialisation();
	suppression(maListe);
	insertion(maListe, 4);
	// insertion(maListe, 8);
	// insertion(maListe, 15);
	// suppression(maListe);

	afficherListe(maListe);
	// destruction(maListe);
	suppression(maListe);
	afficherListe(maListe);
	free(maListe);

	return (0);
}

t_list *initialisation()
{
	t_list *liste = malloc(sizeof(*liste));
	t_element *element = malloc(sizeof(*element));
	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	liste->nb_element = 1;
	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;
	return (liste);
}

void insertion(t_list *liste, int nvNombre)
{
	t_element *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
	liste->nb_element += 1;
}

void afficherListe(t_list *liste)
{
	if (liste == NULL)
		exit(EXIT_FAILURE);

	t_element *actuel = liste->premier;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\tnb element  : %d\n", liste->nb_element);
}

void suppression(t_list *liste)
{
	if (liste == NULL)
		exit(EXIT_FAILURE);
	if (liste->premier != NULL)
	{
		t_element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
		liste->nb_element -= 1;
	}
}

void destruction(t_list *liste)
{
	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->premier != NULL)
	{
		t_element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
}
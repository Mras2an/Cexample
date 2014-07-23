#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mras2an_struct Mras2an_struct;
struct Mras2an_struct{
   int compt;
   Mras2an_struct * suivant;
};

int estVide(Mras2an_struct * l)
{
   return(l == NULL);
}

int nbElement(Mras2an_struct * l)
{
   int nb = 0;
   while (l != NULL)
   {
      nb++;
      l = l->suivant;
   }
   return nb;
}

int nbElementRec(Mras2an_struct * l)
{
   if ( l==NULL )
   {
      return 0;
   }
   else
   {
      return( 1 + nbElementRec(l->suivant) );
   }
}

void affichage(Mras2an_struct* l)
{
   if (!estVide(l))
   {
      printf("%d\n",l->compt);
      return(affichage(l->suivant));
   }
}

void affichageInv(Mras2an_struct * l)
{
   if (!estVide(l))
   {
      return(affichageInv(l->suivant));
      printf("%d\n",l->compt);
   }
}

Mras2an_struct * ajouterDebut(Mras2an_struct * l, int X)
{
   Mras2an_struct * p;
   p = malloc(sizeof(Mras2an_struct));
   p->compt=X;
   p->suivant=l;
   return p;
}

Mras2an_struct * ajouterFin(Mras2an_struct * l, int X)
{
   while (!estVide(l))
   {
      l= l->suivant;
   }
   Mras2an_struct * p = malloc(sizeof(Mras2an_struct));
   p->compt = X;
   p->suivant = l;
   return p;
}

Mras2an_struct * suppDebut(Mras2an_struct * l)
{
   Mras2an_struct * temp;
   if (estVide(l))
   {
      return NULL;
   }
   else
   {
      temp=l;
      l = l->suivant;
      free(temp);
      return l;
   }
}

Mras2an_struct * suppFin(Mras2an_struct * l)
{
   if(nbElement(l) < 2)
   {
      return suppDebut(l);
   }
   else
   {
      Mras2an_struct * p = malloc(sizeof(Mras2an_struct));
      p = l;
      while (p->suivant->suivant!=NULL)
      {
         p=p->suivant;
      }
      free(p->suivant);
      p->suivant = NULL;
      return l;
   }
}

int recherche(Mras2an_struct * l, int X)
{
   if (estVide(l))
   {
      return 0;
   }
   else
   {
      if (X == l->compt)
      {
         return 1;
      }
      else
      {
         return(recherche(l->suivant,X));
      }
   }
}

Mras2an_struct * element(Mras2an_struct * l, int X)
{
   Mras2an_struct * tmp, *p;
   if (estVide(l))
   {
      return NULL;
   }
   else
   {
      if (X == l->compt)
      {
         return suppDebut(l);
      }
      else
      {
         tmp=l;
         while ((tmp->suivant != NULL) && (tmp->suivant->compt != X))
         {
            tmp=tmp->suivant;
         }
         if (tmp->suivant!=NULL)
         {
            p = tmp->suivant;
            tmp->suivant = p->suivant;
            free(p);
         }
         return l;
      }
   }
}

int main()
{
   Mras2an_struct * myStruct = NULL;
   
   /*Add new element*/
   myStruct = ajouterFin(myStruct, 11);
   myStruct = ajouterDebut(myStruct, 10);
   myStruct = ajouterDebut(myStruct, 9);
   myStruct = ajouterDebut(myStruct, 8);
   
   /*print nb elements*/
   printf("nbElement: %d\n",nbElement(myStruct));
   printf("nbElementRec: %d\n",nbElementRec(myStruct));

   /*print elements*/
   affichage(myStruct);

   /*search nb 10*/
   if (recherche(myStruct, 10))
   {
      printf("Nb found\n");   
   }
   else
   {
      printf("Nb not found\n");   
   }

   /*search nb 20*/
   if (recherche(myStruct, 20))
   {
      printf("Nb found\n");   
   }
   else
   {
      printf("Nb not found\n");   
   }

   /*removing the first and last element*/
   myStruct = suppDebut(myStruct);
   myStruct = suppFin(myStruct);
   
   /*print*/
   printf("nbElement: %d\n",nbElement(myStruct));
   printf("nbElementRec: %d\n",nbElementRec(myStruct));
   affichage(myStruct);

   /*removing the nb 9*/
   myStruct = element(myStruct, 9);
   printf("nbElement: %d\n",nbElement(myStruct));
   affichage(myStruct);

   return 0;
}


#ifndef MCDUCK_H
#define MCDUCK_H
#include <stdlib.h>
#include <stdbool.h>

struct mcduck {
    char *name;
    char *firstname;
    char *surname;
};

typedef struct mcduck* mcduck;

struct family_member {
    struct mcduck *valeur;
    struct family_member *parent1;
    struct family_member *parent2;
    struct family_member *partner;
    struct family_member *child;
	struct family_member *Sdchild;
	struct family_member *Tdchild;
};

typedef struct family_member* family_member;




void the_wedding_present(family_member partner1 , family_member partner2);

family_member create_node(mcduck familymember,void (*print_it)(mcduck))
{
     family_member FM = (family_member) malloc( sizeof(struct family_member) );

	if(FM == NULL)
	{
		printf("Erreur allocation memoire.\n");
		exit(EXIT_FAILURE);
	}
	(*FM).valeur = familymember;
	(*FM).parent1 = NULL;
	(*FM).parent2 = NULL;
	(*FM).partner = NULL;
	(*FM).child = NULL;
	(*FM).Sdchild = NULL;
	(*FM).Tdchild = NULL;
    print_it((*FM).valeur);
    printf("\n");

	return FM;
}
void the_wedding_present(family_member partner1 , family_member partner2){
        family_member FM1 = partner1;
        family_member FM2 = partner2;
        (*FM1).partner = partner2;
        (*FM2).partner = partner1;
}


void add_sibling(family_member sibling , family_member child){
     family_member FM3 = sibling;
     family_member FM4 = child;
     family_member FM1 = FM3->parent1;
     family_member FM2 = FM3->parent2;
        if(FM1!=NULL)
         {
            if(!((*FM1).Sdchild))
             {
                 (*FM1).Sdchild = child;
                 (*FM4).parent1 = FM1;
             }

             else if(!((*FM1).Tdchild))
             {
                 printf("yepyep ");
                (*FM1).Tdchild = child;
                (*FM4).parent1 = FM1;
             }
         }
          if(FM2!=NULL)
         {
           if(!((*FM2).Sdchild))
             {
                 (*FM2).Sdchild = child;
                 (*FM4).parent2 = FM2;
             }

             else if(!((*FM2).Tdchild))
             {
                 printf("yepyep ");
                (*FM2).Tdchild = child;
                (*FM4).parent2 = FM2;
             }
         }

}

void add_child(family_member parent1 , family_member parent2 , family_member child){
     family_member FM1 = parent1;
     family_member FM2 = parent2;
     family_member FM3 = child;
     if((parent1==NULL)&&(parent2==NULL))
     {
         printf("aucun parent.\n");
		exit(EXIT_FAILURE);
     }
     else
     {
         if(parent1!=NULL)
         {
             if(!((*FM1).child))
             {
                 (*FM1).child = child;
                 (*FM3).parent1 = parent1;
             }
             else
                if(!((*FM1).Sdchild))
                 {
                     (*FM1).Sdchild = child;
                     (*FM3).parent1 = parent1;
                 }

                 else if(!((*FM1).Tdchild))
                 {
                    // printf("yepyep ");
                    (*FM1).Tdchild = child;
                    (*FM3).parent1 = parent1;
                 }
               // add_sibling((*FM1).child , child);
         }
         if(parent2!=NULL)
         {
             if(!((*FM2).child))
             {
                 (*FM2).child = child;
                 (*FM3).parent2 = parent2;
             }
             else
                if(!((*FM2).Sdchild))
                 {
                     (*FM2).Sdchild = child;
                     (*FM3).parent2 = parent2;
                 }

                 else if(!((*FM2).Tdchild))
                 {
                    // printf("yepyep ");
                    (*FM2).Tdchild = child;
                    (*FM3).parent2 = parent2;
                 }
                //add_sibling((*FM2).child , child);

         }


     }

}



void delete_from_parent(family_member *parent,family_member *child,bool (*comparer)(mcduck,mcduck)){

void show(family_member node){
    print(node->valeur);
    if(node->partner)
    printf("------ %s  %s",print_char(node->partner->valeur),strchr(showit(node), '('));
    else
    printf("------ SANS :(  %s",strchr(showit(node), '('));

}

char const* showit(family_member node){

    char * familymembers = malloc(sizeof(char)*(count(node)*30+30));;
    strcpy(familymembers," ");
    if(!node) return ;

    else
        {
           //strcpy(familymembers," ");
            if(node->child)
                {
                    strcpy(familymembers,print_char(node->valeur));
                    strcat(familymembers,"( ");
                    strcat(familymembers,showit(node->child));
                }
            else
               {
                   strcpy(familymembers,print_char(node->valeur));
                   return familymembers;
               }

            if(node->Sdchild)
                {
                    strcat(familymembers," , ");
                    strcat(familymembers,showit(node->Sdchild));
                }
            else
                 {
                     strcat(familymembers," ) ");
                     return familymembers;
                 }

             if(node->Tdchild)
                {
                    strcat(familymembers," , ");
                    strcat(familymembers,showit(node->Tdchild));
                    strcat(familymembers,"  )");
                }
            else
                {
                    strcat(familymembers," ) ");
                     return familymembers;
                }
            return familymembers;
        }


}

/*! Fonction d'affichage générique
 * \param md la structure à afficher : l'argument est void* pour permettre la généricité
 */
void print(mcduck md) {

    mcduck tmp = (mcduck)md;
    strcmp((*tmp).surname,"") == 0 ? printf("%s %s\t", (*tmp).firstname, (*tmp).name) :
    printf("%s \"%s\" %s\t", (*tmp).firstname, (*tmp).surname, (*tmp).name);

}

/*!fonction return la structure en chaine de caractére
 * c comme void print mais avec un return de type char*
 */
char const * print_char(void* md) {

    mcduck tmp = (mcduck)md;
    static char printFM[30];
    if (strcmp((*tmp).surname,"") == 0 )
        {
            strcpy(printFM,(*tmp).firstname);
            strcat(printFM," ");
            strcat(printFM,(*tmp).name);
        }
    else
        {
            strcpy(printFM,(*tmp).firstname);
            strcat(printFM," \"");
            strcat(printFM,(*tmp).surname);
            strcat(printFM,"\" ");
            strcat(printFM,(*tmp).name);
            }
       //printf("%s",printFM);
    return printFM;
}


int count(family_member node)
{
	if(node == NULL)
		return 0;
    //printf("%s  ",print_char(node->valeur));
	return (count(node->child) + count(node->Sdchild) + count(node->Tdchild) + 1);
}


void printm(void* md) {

    family_member tmp = (family_member)md;
    print(tmp->valeur);

}
void printch(void* md) {

    family_member tmp = md;
    family_member tmp2 = tmp->child;
    print(tmp2->valeur);
   // print(tmp2->valeur);

}

/*! Fonction déterminant l'égalité de deux mcduck
 * \param m le premier élément à comparer
 * \param m1 le deuxième élément à comparer
 * \return vrai si les deux personnages sont identiques, faux sinon
 */
bool is_same(mcduck m, mcduck m1) {

    mcduck tmp = m;
    mcduck tmp1 = m1;
    return (strcmp(tmp->name, tmp1->name) == 0 && strcmp(tmp->firstname, tmp1->firstname) == 0 && strcmp(tmp->surname, tmp1->surname) ==0);

}

#endif

#include "familytree.h"
#include "mcduck.h"

static mcduck create_mcduck(char *, char*, char *);

int main(void) {

    //family_tree mcduck_tree = init_tree();

    /* Création des variables de l'arbre */
    mcduck DD_HD = create_mcduck("Duck", "Huey", "");
    mcduck DD_DD = create_mcduck("Duck", "Dewey", "");
    mcduck DD_LD = create_mcduck("Duck", "Louie", "");
    mcduck DD_DeD = create_mcduck("Duck", "Della", "");
    mcduck DD_DoD = create_mcduck("Duck", "Donald", "");
    mcduck MD_MAM = create_mcduck("McDuck", "Matilda", "");
    mcduck MD_SM = create_mcduck("McDuck", "Scrooge", "");
    mcduck MD_HM = create_mcduck("McDuck", "Hortense", "");
    mcduck MD_FOM = create_mcduck("McDuck", "Fergus", "Old Scotty");
    mcduck MD_JM = create_mcduck("McDuck", "Jake", "");
    mcduck MD_DDM = create_mcduck("McDuck", "Dingus", "Dirty");
    mcduck MD_QM = create_mcduck("McDuck", "Quagmire", "");
    mcduck MD_APM = create_mcduck("McDuck", "Angus", "Pothole");
    mcduck MA_MM = create_mcduck("McDuck", "Mallard", "");
    mcduck MD_HSM = create_mcduck("McDuck", "Hugh", "Seafoam");
    mcduck MD_MMM = create_mcduck("McDuck", "Malcom", "Matey");
    mcduck OD_DO = create_mcduck("O'Drake", "Downy", "");
    mcduck CO_CO = create_mcduck("Coot", "Cornelius", "");

    /* Création des noeuds racine de l'arbre */
    family_member HSM = create_node(MD_HSM,print);
    family_member MMM = create_node(MD_MMM,print);
    family_member MM = create_node(MA_MM,print);
    family_member DO = create_node(OD_DO,print);
    family_member CC = create_node(CO_CO,print);
    /* Création des autres noeuds */
    family_member DDM = create_node(MD_DDM,print);
    family_member QM = create_node(MD_QM,print);
    family_member DD = create_node(DD_DD,print);
    family_member HD = create_node(DD_HD,print);
    family_member LD = create_node(DD_LD,print);
    family_member DeD = create_node(DD_DeD,print);
    family_member DoD = create_node(DD_DoD,print);
    family_member MAM = create_node(MD_MAM,print);
    family_member SM = create_node(MD_SM,print);
    family_member HM = create_node(MD_HM,print);
    family_member FOM = create_node(MD_FOM,print);
    family_member JM = create_node(MD_JM,print);
    family_member APM = create_node(MD_APM,print);

    /* Ajout des racines */
    //add_root(mcduck_tree,HSM);
    //add_root(mcduck_tree,MMM);
    //add_root(mcduck_tree,DO);
    //add_root(mcduck_tree,CC);

    /* Heureux évènements */
    the_wedding_present(DO,FOM);
    the_wedding_present(MM,DDM);

    /* Ajout de l'ensemble des enfants : lorsque les parents ont déjà des enfants
     * on l'ajoute alors comme sibling des children existants
     * (on suppose qu'on n'a pas de familles recomposées, mais les familles monoparentales sont possibles)
     */
    add_child(NULL,HSM,DDM);
    add_child(NULL,HSM,QM);
    add_child(NULL,MMM,MM);
    add_child(MM,DDM,APM);
    add_child(MM,DDM,JM);
    add_child(MM,DDM,FOM);
    add_child(DO,FOM,MAM);
    add_child(DO,FOM,SM);
    add_child(DO,FOM, HM);
    add_child(HM,NULL,DeD);
    add_child(HM,NULL,DoD);
    add_child(DeD,NULL,HD);
    add_child(DeD,NULL,DD);
    add_child(DeD,NULL,LD);

    // Affichage de l'arbre depuis une racine, avec ensemble des siblings, children et le/la spouse si existant
    show(HSM);
    delete_from_node(&DeD,is_same);
    puts("");

    /* Recherche du membre MD_QM à partir du noeud DDM, is_same étant la fonction
     * du fichier mcduck.h permettant de tester l'égalité de deux personnages
     */
    family_member found=search(DDM,MD_QM,is_same);
    if(found == NULL)
        printf("Not found\n");
    else
        printf("Found\n");

    //delete_tree(&mcduck_tree,is_same);

    return EXIT_SUCCESS;

}

static mcduck create_mcduck(char *name, char *firstname, char *surname) {

    mcduck duck = (mcduck) malloc( sizeof(struct mcduck) );
    (*duck).name = name;
    (*duck).firstname = firstname;
    (*duck).surname = surname;

    return duck;
}

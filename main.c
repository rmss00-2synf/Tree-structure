#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Root
{
    int val;
    struct Root *letf;
    struct Root *right;
};
typedef struct Root *Tree;
int taille(Tree Root)
{
    if (!Root)
        return 0;
    if (!Root->letf && !Root->right)
        return 0;
    if (!Root->letf)
        return 1 + taille(Root->right);
    if (!Root->right)
        return 1 + taille(Root->letf);
    return 2 + taille(Root->letf) + taille(Root->right);
}

int profondeur(Tree Root)
{
    if (!Root)
        return 0;
    if (taille(Root->letf) <= taille(Root->right))
        return 1 + profondeur(Root->right);
    else
        return 1 + profondeur(Root->letf);
}
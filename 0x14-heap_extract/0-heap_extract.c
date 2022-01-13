#include "binary_trees.h"
/**
* tight - tight
* @arbe: arbe
* Return: level
**/

size_t tight(const heap_t *arbe)
{
size_t l, r;

if (!arbe)
return (0);
if (!arbe->left && !arbe->right)
return (0);

r = tight(arbe->right) + 1;
l = tight(arbe->left) + 1;
if (l > r)
return (l);
else
return (r);
}
/**
* ordfunc - ordfunc
* @arbe: arbe
* @nd: nd the tree
* @ok: ok
* @degree: degree of arbre
* Return: 0
**/
int ordfunc(heap_t *arbe, heap_t **nd, size_t ok, size_t degree)
{
if (!arbe)
return (0);
if (ok == degree)
*nd = arbe;

degree++;

if (arbe->left)
ordfunc(arbe->left, nd, ok, degree);
if (arbe->right)
ordfunc(arbe->right, nd, ok, degree);
return (0);
}

/**
* heap_extract - heap_extract
* @root: root
* Return: sorted
**/

int heap_extract(heap_t **root)
{
int v, fde;
size_t level = 0;
heap_t *plus, *nd;

if (!root || !*root)
return (0);
plus = *root;
v = plus->n;
if (!plus->left && !plus->right)
{
*root = NULL;
free(plus);
return (v);
}
ordfunc(plus, &nd, tight(plus), level);
while (plus->left || plus->right)
{
if (!plus->right || plus->left->n > plus->right->n)
{
fde = plus->n;
plus->n = plus->left->n;
plus->left->n = fde;
plus = plus->left;
}
else if (!plus->left || plus->left->n < plus->right->n)
{
fde = plus->n;
plus->n = plus->right->n;
plus->right->n = fde;
plus = plus->right;
}
}
plus->n = nd->n;
if (nd->parent->right)
nd->parent->right = NULL;
else
nd->parent->left = NULL;
free(nd);
return (v);
}

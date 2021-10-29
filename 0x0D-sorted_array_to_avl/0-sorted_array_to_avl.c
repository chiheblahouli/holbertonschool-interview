#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
* neonode - create a new node
* @list: list
* @b: the b index
* @c: the end index
* @pr: pr
* Return: nd
*/
avl_t *neonode(int *list, size_t b, size_t c, avl_t *pr)
{
avl_t *nd;
size_t a;

nd = malloc(sizeof(avl_t));
if (nd == NULL)
return (NULL);
a = (b + c) / 2;
nd->n = list[a];
nd->parent = pr;
if (a != b)
nd->left = neonode(list, b, a - 1, nd);
else
nd->left = NULL;
if (a != c)
nd->right = neonode(list, a + 1, c, nd);
else
nd->right = NULL;
return (nd);
}

/**
* sorted_array_to_avl - sorted_array_to_avl
*
* @array: array
* @size: size
* Return: node
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *fde;

if (array == NULL)
return (NULL);
if (size)
{
fde = neonode(array, 0, size - 1, NULL);
return (fde);
}
return (NULL);
}

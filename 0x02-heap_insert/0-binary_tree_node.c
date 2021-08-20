#include "binary_trees.h"

/**
* binary_tree_node - binary_tree_node
* @parent: parent pointer
* @value: integer value
*
* Return: a pointer to new node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *nnd;

nnd = malloc(sizeof(binary_tree_t));
if (!nnd)
return (NULL);
nnd->n = value;
nnd->parent = parent;
nnd->left = NULL;
nnd->right = NULL;
return (nnd);
}

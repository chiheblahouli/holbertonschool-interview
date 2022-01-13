#include "search.h"

/**
* linear_skip - linear_skip
* @list: list pointer
* @value: element to search
*
* Return: pointer
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *fde, *nd, *backup;

if (!list)
return (NULL);
fde = list;
while (fde)
{
if (fde->express == NULL)
{
nd = fde->express;
for (backup = list; backup; backup = backup->next)
{
if (backup->next == NULL)
{
printf("Value found between indexes [%lu] and [%lu]\n",
fde->index, backup->index);
break;
}
}
break;
}
if (fde->express->n >= value)
{
nd = fde->express;
printf("Value checked at index [%lu] = [%d]\n", nd->index, nd->n);
printf("Value found between indexes [%lu] and [%lu]\n",
fde->index, nd->index);
break;
}
fde = fde->express;
printf("Value checked at index [%lu] = [%d]\n", fde->index, fde->n);
}
while (fde)
{
printf("Value checked at index [%lu] = [%d]\n", fde->index, fde->n);
if (fde->n == value)
return (fde);
fde = fde->next;
}
return (NULL);
}

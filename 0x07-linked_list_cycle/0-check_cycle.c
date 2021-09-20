#include "lists.h"
/**
 * check_cycle - check_cycle
 * @list: linked list
 * Return: 1 or 0
 */

int check_cycle(listint_t *list)
{
listint_t *a, *b;

if (!list)
return (0);
if (list->next == NULL)
return (0);

a = list->next;
b = list->next->next;

while (a && b && b->next)
{
if (a == b->next)
return (1);
a = a->next;
b = b->next->next;
}
return (0);
}

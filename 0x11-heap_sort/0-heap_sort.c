#include "sort.h"

/**
*	fdefun - fdefun function
*	@tab: tableau
*	@n: taille tableau
*	@start: start
*	@fin: fin
*/
void fdefun(int *tab, size_t n, size_t start, size_t fin)
{
size_t parent = start;
size_t fils, fde;
int backup;
while (parent * 2 + 1 <= fin)
{
fils = 2 * parent + 1;
fde = parent;
if (tab[fde] < tab[fils])
fde = fils;

if (fils + 1 <= fin && tab[fde] < tab[fils + 1])
fde = fils + 1;

if (fde != parent)
{
backup = tab[parent];
tab[parent] = tab[fde];
tab[fde] = backup;
print_array(tab, n);
parent = fde;
}
else
break;
}
}

/**
*	heap_sort - heap_sort
*
*	@array: array
*	@size: size
*/
void heap_sort(int *array, size_t size)
{
size_t fin;
int backup;
long beg;
beg = (size - 2) / 2;

if (size < 2)
return;

while (beg >= 0)
fdefun(array, size, beg--, size - 1);

fin = size - 1;
while (fin > 0)
{
backup = array[fin];
array[fin] = array[0];
array[0] = backup;
print_array(array, size);
fdefun(array, size, 0, --fin);
}
}

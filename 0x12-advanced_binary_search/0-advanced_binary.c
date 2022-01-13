#include "search_algos.h"

/**
* pr - pr funct
* @tab: tab
* @beg: beg
* @n: array size
*
* Return: void
*/
void pr(int *tab, size_t beg, size_t n)
{
if (beg > n)
return;
printf("%d", tab[beg]);
if (beg < n)
printf(", ");
pr(tab, beg + 1, n);
}

/**
* advanced_binary - advanced_binary
* @array: aa
* @size: size
* @value: v
*
* Return: index or -1
*/
int advanced_binary(int *array, size_t size, int value)
{
size_t f = 0;
size_t a = size - 1;
size_t l;

if (!array)
return (-1);
while (f <= a)
{
printf("Searching in array: ");
pr(array, f, a);
printf("\n");

l = (f + a) / 2;
if (array[l] == value && array[l - 1] != value)
return (l);
else if (array[l] < value)
f = l + 1;
else
a = l;
}
return (-1);
}

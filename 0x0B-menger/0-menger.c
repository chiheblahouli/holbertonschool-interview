#include "menger.h"

/**
* _myfunc - _myfunc
* @i: ligne
* @j: col
*
* Return: #
*/
char _myfunc(size_t i, size_t j)
{
while (i && j)
{
if (i % 3 == 1 && j % 3 == 1)
return (' ');
i = i / 3, j = j / 3;
}
return ('#');
}

/**
* menger - munger func
* @level: level
*
* Return: Void
*/
void menger(int level)
{
size_t f, i, j;
if (level < 0)
return;
f = pow(3, level);
for (i = 0; i < f; ++i)
{
for (j = 0; j < f; ++j)
printf("%c", _myfunc(i, j));
printf("\n");
}
}

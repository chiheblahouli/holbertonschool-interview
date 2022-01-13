#include <stdlib.h>
#include <unistd.h>

/**
* fdefun - fdefun two strings of digits
* @n01: first number
* @n02: second number
* @a: first number length
* @b: second number length
* Return: 98 on error or 0 on success
*/
int fdefun(char n01[], char n02[], long int a, long int b)
{
long int i;
long int j;
int fde;
char *rez, *start;
long int ok;

rez = malloc(a + b + 1);
if (rez == NULL)
{
write(1, "Error\n", 6);
return (98);
}
for (i = 0; i < a + b + 3; i++)
rez[i] = 0;
for (i = a - 1; i >= 0; i--)
for (j = b - 1; j >= 0; j--)
{
rez[i + j + 1] += ((n01[i] - '0') *
		  (n02[j] - '0'));
for (ok = i + j + 1; rez[ok] > 9;
ok--)
{
fde = rez[ok] / 10;
rez[ok - 1] += fde;
rez[ok] %= 10;
}
}
for (i = a + b - 1; i >= 0; i--)
rez[i] += '0';
for (start = rez; *start == '0' && start[1] != 0; start++)
a--;
a += b;
write(1, start, a);
write(1, "\n", 1);
free(rez);
return (0);
}

/**
* main -  main program
* @argc: argc
* @argv: argv
* Return: 98 or 0
*/
int main(int argc, char *argv[])
{
char *inc, *j;
long int a, b;

if (argc != 3)
{
write(1, "Error\n", 6);
return (98);
}
a = 0;
for (inc = argv[1]; *inc != 0; inc++, a++)
if (*inc < '0' || *inc > '9')
{
write(1, "Error\n", 6);
return (98);
}
b = 0;
for (j = argv[2]; *j != 0; j++, b++)
if (*j < '0' || *j > '9')
{
write(1, "Error\n", 6);
return (98);
}
if (a == 0 || b == 0)
{
write(1, "Error\n", 6);
return (98);
}
for (inc = argv[1]; *inc == '0' && inc[1] != 0; a--)
inc++;
for (j = argv[2]; *j == '0' && j[1] != 0; b--)
j++;
return (fdefun(inc, j, a, b));
}


/**
 * is_palindrome - Function to check unsigned long
 * @n: number to check
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
unsigned long i;
unsigned long rev = 0;
unsigned long backup = n;

while (n)
{
i = n % 10;
rev = rev * 10 + i;
n /= 10;
}
if (backup == rev)
return (1);
return (0);
}

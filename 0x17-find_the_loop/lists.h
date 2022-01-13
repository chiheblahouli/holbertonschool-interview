#ifndef _LIST_H_
#define _LIST_H_
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: intger
 * @next: points o the next node
 *
 * Description: ingly linked list node structure
 * for Holberton prject
 */
typedef struct listint_s
{
int n;
struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif

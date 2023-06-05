#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise = head;
	const listint_t *hare = head;
	size_t nodes = 0;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			do {
				nodes++;
				tortoise = tortoise->next;
			} while (tortoise != hare);

			return (nodes);
		}
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	size_t index;

	nodes = looped_listint_len(head);

	for (index = 0; head != NULL && (index < nodes || nodes == 0); index++)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	if (nodes > 0)
		printf("-> [%p] %d\n", (void *)head, head->n);

	return (nodes);
}

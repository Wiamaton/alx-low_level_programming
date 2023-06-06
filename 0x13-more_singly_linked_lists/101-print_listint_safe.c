#include "lists.h"

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
	int loop_found = 0;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			loop_found = 1;
			break;
		}
	}

	if (loop_found)
	{
		do {
			nodes++;
			tortoise = tortoise->next;
		} while (tortoise != hare);
	}

	return (nodes);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 1;
	size_t loop_length = looped_listint_len(head);

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;

		if (nodes == loop_length)
		{
			if (loop_length > 0)
				printf("-> [%p] %d\n", (void *)head->next, head->next->n);

			break;
		}

		head = head->next;
	}

	return (nodes);
}

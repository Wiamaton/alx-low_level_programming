#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current = *h;
	listint_t *next = NULL;

	if (h == NULL || *h == NULL)
		return (0);

	while (current != NULL)
	{
		next = current->next;

		/* Check if current node has been visited before */
		if (current < next)
		{
			free(current);
			len++;
			current = next;
		}
		else
		{
			free(current);
			break;
		}
	}

	*h = NULL;

	return (len);
}

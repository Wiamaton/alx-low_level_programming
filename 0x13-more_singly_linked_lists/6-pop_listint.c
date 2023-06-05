#include "lists.h"

/**
 * pop_listint - deletes the head node of
 * a linked list
 * @head: head of a list.
 *
 * Return: head node's data.
 */
int pop_listint(listint_t **head)
{
	int hnode = 0;
	listint_t *next_node = NULL;

	if (*head != NULL)
	{
		hnode = (*head)->n;
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}

	return (hnode);
}

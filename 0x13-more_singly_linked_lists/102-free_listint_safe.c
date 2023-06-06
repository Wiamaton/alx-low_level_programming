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
        listint_t *current, *next;

        if (h == NULL || *h == NULL)
                return (0);

        while (*h != NULL)
        {
                current = *h;
                next = current->next;

                /* Check for a loop */
                if (next >= current)
                {
                        free(current);
                        len++;
                        *h = NULL;
                        break;
                }

                /* Free current node */
                free(current);
                len++;
                *h = next;
        }

        return (len);
}

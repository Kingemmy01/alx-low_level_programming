#include "lists.h"

/**
* get_nodeint_at_index - returns returns the nth node of
* a listint_t linked list.
* @head: first node in the linked list
* @index: index of the node to return
*
* Return: pointer to the nth node, or NULL
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int x = 0;

	while (temp != NULL && x < index)
	{
	temp = temp->next;
	temp++;
	}

	if (temp == NULL)
	{
		return (NULL);
	}

	return (temp);
}

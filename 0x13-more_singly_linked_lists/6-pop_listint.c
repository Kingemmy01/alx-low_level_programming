#include "lists.h"

/**
* pop_listint - deletes the head node of a listint_t
* @head: pointer to the first element in the linked list
* Return: the data inside the elements that was deleted
* if the linked list is empty return 0
*/
int pop_listint(listint_t **head)
{
	listint_t *temp = *head;
	int n;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	n = temp->n;

	*head = temp->next;
	free(temp);

	return (n);
}

#include "lists.h"
#include <stdlib.h>

/**
 * delete_node - Responsible for reodering the nodes around the select node
 * and freeing the select node
 * @head: Address of the pointer to the select node
 * @index: Index of the select node in the list
 * @saved_head: The original head of the list
 */
void delete_node(dlistint_t **head, unsigned int index, dlistint_t *saved_head)
{
	dlistint_t *tmp = NULL;

	if (index == 0)
	{
		tmp = (*head)->next;
		free(*head), *head = tmp;

		if (tmp != NULL)
			tmp->prev = NULL;
	}
	else
	{
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		(*head)->prev->next = (*head)->next;

		free(*head);
		*head = saved_head;
	}
}

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t  *saved_head;
	unsigned int p;

	if (!head || !*head)
	{
		return (-1);
	}

	saved_head = *head;
	p          = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}

	delete_node(head, index, saved_head);

	return (1);
}

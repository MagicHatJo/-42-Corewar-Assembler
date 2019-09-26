/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:23:28 by jochang           #+#    #+#             */
/*   Updated: 2019/09/24 21:23:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*initqueue(void)
{
	t_queue *q;

	if (!(q = malloc(sizeof(t_queue))))
		return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void	enqueue(t_queue *queue, void *content)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return;
	new->content = content;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
}

void	*dequeue(t_queue *queue)
{
	t_node	*node;
	void	*c;

	if (!queue->first)
		return (NULL);
	node = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	node->next = NULL;
	c = node->content;
	free(node);
	return (c);
}

void	*peek(t_queue *queue)
{
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int		isEmpty(t_queue *queue)
{
	return (queue->first ? 0 : 1);
}

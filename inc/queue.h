/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:24:58 by jochang           #+#    #+#             */
/*   Updated: 2019/09/24 21:24:59 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

#include <stdlib.h>

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	struct s_node	*first;
	struct s_node	*last;
}				t_queue;

t_queue	*initqueue(void);
void	enqueue(t_queue *queue, void *content);
void	*dequeue(t_queue *queue);
void	*peek(t_queue *queue);
int		isEmpty(t_queue *queue);

#endif

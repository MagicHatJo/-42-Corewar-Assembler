/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:47:26 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:47:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint32_t	calc_num(t_line *line, char *label, t_deque *labels)
{
	int		i;
	t_node	*current;

	i = -1;
	current = labels->begin;
	while (++i < labels->size)
	{
		if (ft_strequ(label, ((t_lookup*)(current->content))->label))
			return ((uint32_t)(((t_lookup*)(current->content))->value -
					line->prior_data));
		current = current->next;
	}
	return (0);
}

uint8_t	process_labels(t_table *table)
{
	int		i;
	int		k;
	t_node *current;

	i = -1;
	current = table->commands->begin;
	while (++i < table->commands->size)
	{
		k = -1;
		while (++k < ((t_line*)(current->content))->argc)
		{	
			if (((t_line*)(current->content))->param_label[k])
			{
				((t_line*)(current->content))->parameters[k] =
				calc_num(((t_line*)(current->content)),
					((t_line*)(current->content))->param_label[k],
					table->labels);
				if (((t_line*)(current->content))->parameters[k] == 0)
					return (return_error("Label could not be processed"));
			}
		}
		current = current->next;
	}
	return (1);
}
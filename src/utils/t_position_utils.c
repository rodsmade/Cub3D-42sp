/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_position_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:24:22 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/31 06:41:16 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	t_position_copy(t_position *destination, const t_position source)
{
	destination->line = source.line;
	destination->column = source.column;
	return ;
}

bool	t_position_compare_ptr(t_position *a, t_position *b)
{
	if (!a && !b)
		return (true);
	if ((a && !b) || (!a && b))
		return (false);
	if (a->line == b->line && a->column == b->column)
		return (true);
	return (false);
}

bool	t_position_compare(t_position a, t_position b)
{
	if (a.line == b.line && a.column == b.column)
		return (true);
	return (false);
}

t_position	t_position_create_tuple(int line, int column)
{
	t_position	tuple;

	tuple.line = line;
	tuple.column = column;
	return (tuple);
}

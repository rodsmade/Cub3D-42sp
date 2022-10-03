/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/03 19:02:18 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_position
{
	int		line;
	int		column;
}		t_position;

bool	is_map_surrounded_by_one(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]) && (map[i][j] != '1'
				&& map[i][j] != ' '))
				return false;
			if ((j == 0 || !map[i][j + 1]) && (map[i][j] != '1'
				&& map[i][j] != ' '))
				return false;
			j++;
		}
		i++;
	}
	return true;
}

void	print_locale(char **map, int line, int column)
{
	printf("\nLOCALE:\n");
	// LINE - 1
	printf("[ ");
	if (line > 0 && column > 0 && map[line - 1][column - 1])
		printf("%c", map[line - 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (line > 0 && map[line - 1][column])
		printf("%c", map[line - 1][column]);
	else
		printf("x");
	printf("   , ");
	if (line > 0 && map[line - 1][column + 1])
		printf("%c", map[line - 1][column + 1]);
	else
		printf("x");
	printf("]\n");
	
	// LINE
	printf("[ ");
	if (map[line] && map[line][column - 1])
		printf("%c", map[line][column - 1]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column])
		printf(" ( %c ) ", map[line][column]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column + 1])
		printf("%c", map[line][column + 1]);
	else
		printf("x");
	printf("]\n");

	// LINE + 1
	printf("[ ");
	if (map[line + 1] && map[line + 1][column - 1])
		printf("%c", map[line + 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (map[line + 1] && map[line + 1][column])
		printf("%c", map[line + 1][column]);
	else
		printf("x");
	printf("   , ");
	if (map[line + 1] && map[line + 1][column + 1])
		printf("%c", map[line + 1][column + 1]);
	else
		printf("x");
	printf("]\n");
}

bool	t_position_compare(t_position *a, t_position *b)
{
	if (!a && !b)
		return (true);
	if ((a && !b) || (!a && b))
		return (false);
	if (a->line == b->line && a->column == b->column)
		return (true);
	return (false);
}

void	decide_where_to_go_next(char ***map, t_position *prev_pos, t_position curr_pos, t_position *next_pos)
{
	// check north
	if (curr_pos.line > 0 && (*map)[curr_pos.line - 1][curr_pos.column] == '1')
	{
		next_pos->line = curr_pos.line - 1;
		next_pos->column = curr_pos.column;
		if (!t_position_compare(prev_pos, next_pos))
		{
			printf(" ⭫ ");
			return ;
		}
	}
	// check east
	if ((*map)[curr_pos.line][curr_pos.column + 1] && (*map)[curr_pos.line][curr_pos.column + 1] == '1')
	{
		next_pos->line = curr_pos.line;
		next_pos->column = curr_pos.column + 1;
		if (!t_position_compare(prev_pos, next_pos))
		{
			printf(" ⭬  ");
			return ;
		}
	}
	// check south
	if ((*map)[curr_pos.line + 1] && (*map)[curr_pos.line + 1][curr_pos.column] == '1')
	{
		next_pos->line = curr_pos.line + 1;
		next_pos->column = curr_pos.column;
		if (!t_position_compare(prev_pos, next_pos))
		{
			printf(" ⭭ ");
			return ;
		}
	}
	// check west
	if (curr_pos.column > 0 && (*map)[curr_pos.line][curr_pos.column - 1] == '1')
	{
		next_pos->line = curr_pos.line;
		next_pos->column = curr_pos.column - 1;
		if (!t_position_compare(prev_pos, next_pos))
		{
			printf(" ⭪  ");
			return ;
		}
	}
	// provavlemente precisa dar um free aqui pq se a parada virar null nunca vai dar
	next_pos = NULL;
	return ;
}

void	find_starting_point(t_position *pivot, char ***map)
{
	pivot->line = -1;
	while ((*map)[++pivot->line])
	{
		pivot->column = -1;
		while ((*map)[pivot->line][++pivot->column])
		{
			if ((*map)[pivot->line][pivot->column] == '1')
				break;
		}
		if ((*map)[pivot->line][pivot->column] && (*map)[pivot->line][pivot->column] == '1')
			break;
	}
	// print_locale((*map), (*line), (*column));
}

void	t_position_copy(t_position *dst, t_position src)
{
	dst->line = src.line;
	dst->column = src.column;
}

void	trace_contour(char ***map)
{
	t_position	starting_point;
	t_position	*pivot;
	t_position	*came_from;
	t_position	*goes_to;

	came_from = malloc(sizeof(*came_from));
	goes_to = malloc(sizeof(*goes_to));
	pivot = malloc(sizeof(*pivot));
	if (!came_from || !goes_to || !pivot)
		return ;
	find_starting_point(pivot, map);
	t_position_copy(&starting_point, *pivot);
	decide_where_to_go_next(map, NULL, *pivot, goes_to);
	while (goes_to && !t_position_compare(goes_to, &starting_point))
	{
		t_position_copy(came_from, *pivot);
		t_position_copy(pivot, *goes_to);
		decide_where_to_go_next(map, came_from, *pivot, goes_to);
	}
	printf("\n");
	if (!goes_to)
	{
		printf ("mapa errado ??\n");
		return ;
	}
}

/*
// antiga:
void	trace_contour(char ***map)
{
	// char	*pivot;
	char	*came_from;
	char	*goes_to;
	int		line;
	int		column;

	find_starting_point(&line, &column, map);
	// pivot = &((*map)[line][column]);
	came_from = NULL;
	goes_to = decide_where_to_go_next(map, line, column);
	if (!goes_to || goes_to == came_from)
	{
		printf (RED "mapa errado ??" RESET "\n");
		return ;
	}
	else
		printf("1\n");
}
*/

bool	is_valid_map(char*** map)
{
	// if (!is_map_surrounded_by_one(map))
	// 	return false;
	trace_contour(map);
	return true;
}

void	save_map(int input_fd, t_map_parameters *map_params)
{
	char	*map_stringified;
	char	*temp;

	map_params->line = ft_charjoin(map_params->line, '\n');
	map_stringified = ft_strdup("");
	while (map_params->line)
	{
		temp = map_stringified;
		map_stringified = ft_strjoin(map_stringified, map_params->line);
		ft_free_ptr((void *)&temp);
		ft_free_ptr((void *)&map_params->line);
		map_params->line = get_next_line(input_fd);
	}
	map_params->map = ft_split(map_stringified, '\n');
	ft_free_ptr((void *)&map_stringified);
}

void	print_map_read(t_map_parameters *map_params)
{
	int	i;

	i = -1;
	while(map_params->map[++i])
	{
		printf("linha do mapa: >>%s<<\n", map_params->map[i]);
	}
}

void	validate_map(int input_fd, t_map_parameters *map_params)
{
	(void) input_fd;

	save_map(input_fd, map_params);
	ft_free_ptr((void *)&map_params->line);
	// print_map_read(map_params);
	close(input_fd);
	if (!is_valid_map(&(map_params->map)))
		print_err_exit(INVALID_MAP, map_params);
	return ;
}

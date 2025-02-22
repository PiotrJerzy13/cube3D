/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:00:26 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/10 15:01:20 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	count_rows(t_map *map)
{
	int				rows;
	const t_list	*temp;

	rows = 0;
	temp = map->list;
	while (temp)
	{
		rows++;
		temp = temp->next;
	}
	map->height = rows;
}

void	allocate_grid(t_map *map, t_memory *mem)
{
	map->grid = mem_alloc(mem, sizeof(char *) * (map->height + 1));
	if (!map->grid)
		exit(1);
}

void	fill_grid(t_map *map, t_memory *mem)
{
	int				i;
	int				len;
	const t_list	*temp;
	char			*line;

	temp = map->list;
	i = 0;
	map->width = 0;
	while (temp)
	{
		line = ft_strdup_cub(temp->line, mem);
		if (!line)
			exit(1);
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->grid[i] = line;
		if ((int)ft_strlen(line) > map->width)
			map->width = ft_strlen(line);
		i++;
		temp = temp->next;
	}
	map->grid[i] = NULL;
}

void	list_to_array(t_map *map, t_memory *mem)
{
	count_rows(map);
	allocate_grid(map, mem);
	fill_grid(map, mem);
}

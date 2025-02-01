/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:39:53 by piotrwojnar       #+#    #+#             */
/*   Updated: 2025/02/01 12:26:51 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	list_to_array(t_map *map, t_memory *mem)
{
	int		i;
	int		len;
	int		rows;
	t_list	*temp;
	char	*line;

	i = 0;
	rows = 0;
	temp = map->list;
	while (temp)
	{
		rows++;
		temp = temp->next;
	}
	printf("[DEBUG] Total rows in map list: %d\n", rows);
	map->height = rows;
	map->grid = mem_alloc(mem, sizeof(char *) * (rows + 1));
	if (!map->grid)
	{
		printf("[ERROR] Failed to allocate memory for map grid.\n");
		exit(1);
	}
	temp = map->list;
	while (temp)
	{
		line = ft_strdup_cub(temp->line, mem);
		if (!line)
		{
			printf("[ERROR] Failed to duplicate map line.\n");
			exit(1);
		}
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->grid[i++] = line;
		temp = temp->next;
	}
	map->grid[rows] = NULL;
	printf("[DEBUG] Map list successfully converted to grid array.\n");

    for (i = 0; i < rows; i++)
    {
        int line_length = strlen(map->grid[i]);
        if (line_length > map->width)
        {
            map->width = line_length;
        }
    }
    printf("[DEBUG] Map dimensions - Height: %d, Width: %d\n", map->height, map->width);

}

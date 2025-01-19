/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:53:32 by piotrwojnar       #+#    #+#             */
/*   Updated: 2025/01/19 13:17:08 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_list1(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
	{
		printf("[ERROR] Linked list is NULL.\n");
		return ;
	}
	while (list)
	{
		if (list->line)
			printf("[DEBUG] List Node %d: '%s'\n", i, list->line);
		else
			printf("[ERROR] List Node %d: (NULL line)\n", i);
		list = list->next;
		i++;
	}
}

int	put_on_list(char *line, t_list **list, t_memory *mem)
{
	t_list	*node;
	t_list	*temp;

	if (!line || *line == '\0' || *line == '\n')
	{
		printf("[ERROR] Cannot add an empty or NULL line to the list.\n");
		return (0);
	}
	node = mem_alloc(mem, sizeof(t_list));
	if (!node)
	{
		printf("[ERROR] Failed to allocate memory for map list node.\n");
		return (0);
	}
	node->line = ft_strdup_cub(line, mem);
	if (!node->line || node->line[0] == '\0')
	{
		printf("[ERROR] Failed to duplicate map line content.\n");
		return (0);
	}
	node->next = NULL;
	if (!(*list))
	{
		*list = node;
		printf("[DEBUG] Added first node to map list: '%s'\n", node->line);
	}
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		printf("[DEBUG] Added node to map list: '%s'\n", node->line);
	}
	printf("[DEBUG] Current state of the linked list:\n");
	print_list1(*list);
	return (1);
}

int	calculate_map_dimensions(char **grid, int *height, int *width)
{
	int	max_width;
	int	row_count;
	int	row_length;
	int	i;

	max_width = 0;
	row_count = 0;
	i = 0;
	if (!grid || !height || !width)
	{
		printf("[ERROR] Invalid grid or dimension pointers.\n");
		return (-1);
	}
	while (grid[i] != NULL)
	{
		row_count++;
		row_length = strlen(grid[i]);
		printf("[DEBUG] Processing Grid Row %d: '%s' (Length: %d)\n",
			i, grid[i], row_length);
		if (row_length > max_width)
		{
			max_width = row_length;
		}
		i++;
	}
	*height = row_count;
	*width = max_width;
	if (*height == 0 || *width == 0)
	{
		printf("[ERROR] Invalid map dimensions. Height=%d, Width=%d\n",
			*height, *width);
		return (-1);
	}
	printf("[DEBUG] Map dimensions calculated successfully.");
	return (0);
}

void	validate_map(t_map *map)
{
	ft_printf("[DEBUG] ----- Validating Map Structure -----\n");
	if (calculate_map_dimensions(map->grid, &map->height, &map->width) != 0)
	{
		ft_printf("[ERROR] Failed to calculate map dimensions.\n");
		exit(1);
	}
	ft_printf("[DEBUG] Map dimensions calculated: Height=%d, Width=%d\n",
		map->height, map->width);
	ft_printf("[DEBUG] Validating map boundaries...\n");
	validate_map_boundary(map);
	ft_printf("[DEBUG] Map boundaries validated.\n");
	ft_printf("[DEBUG] ----- Map Structure Validated Successfully -----\n");
}

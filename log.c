/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:09:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 15:31:35 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "fdf.h"

void	log_matrix(t_matrix m)
{
	int	x;
	int	y;

	printf("matrice (%i, %i) = {\n", m.x, m.y);
	y = 0;
	while (y < m.y)
	{
		printf("\t[");
		x = 0;
		while (x < m.x)
		{
			printf("% .2f ", m.self[y][x]); 
			x++;
		}
		printf("]\n");
		y++;
	}
	printf("}\n\n");
}

void	log_vec3(t_vec3 v)
{
	printf("Position : {%f, %f, %f}\n", v.x, v.y, v.z);
}

void	log_vec2(t_vec2 v)
{
	printf("{%f, %f}\n", v.x, v.y);
}

void	log_print_map(t_list *start_lines_list, t_map map)
{
	t_list	*ptr;

	ft_printf("X %i // Y %i \n", map.x_size, map.y_size);
	ptr = start_lines_list;
	while (ptr)
	{
		int i = 0;
		int	*val = (int *)ptr->content;
		while (i < map.x_size)
		{
			ft_printf("%i ", val[i]);
			i++;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
}

void	log_final_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->y_size * map->x_size)
	{
			log_vec3(map->vertices[i]);
			i++;
	}
}


void	log_edges(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->n_edges)
	{
		log_vec3(map->vertices[map->edges[i].a]);
		log_vec3(map->vertices[map->edges[i].b]);
		ft_printf("\n");
		i++;
	}
}
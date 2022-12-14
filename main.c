/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:48 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/22 11:24:38 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <errno.h>
#include <stdio.h>
#include "fdf.h"
#include "libft/libft.h"
#include "read_map/read_map.h"
#include "minilibx_macos/mlx.h"
#include "projection/projection.h"

static int	chec_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_map	map;

	if (chec_args(argc, argv))
		return (0);
	if (read_map(argv[1], &map))
		terminate("Erreur lors de la lecture de la map");
	create_edges(&map);
	display(&map);
	return (0);
}

static int	chec_args(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		ft_printf("Mauvais nombre d'arguments ! (%i au lieu de %i)\n",
			argc - 1, 1);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len == 0)
	{
		ft_printf("La chaine de caracter entree est vide\n", argc - 1, 1);
		return (1);
	}
	if (ft_strncmp(&(argv[1][len - 4]), ".fdf", 4))
	{
		ft_printf("Le programme n'accepte que les fichiers \'.fdf\'\n");
		return (1);
	}
	return (0);
}

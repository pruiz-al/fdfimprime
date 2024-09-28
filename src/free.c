/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-al <pruiz-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:44:54 by pruiz-al          #+#    #+#             */
/*   Updated: 2024/09/28 20:53:36 by pruiz-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_isom(t_fdf **fdf, t_map *map)
{
    int	h;
    int	w;

    h = 0;
	w = 0;
    while (h < map->height)
    {
        while (w < map->width)
        {
            if ((*fdf)->isom[h][w] != NULL)
                free((*fdf)->isom[h][w]);
            w++;
        }
        if ((*fdf)->isom[h] != NULL)
            free((*fdf)->isom[h]);
        h++;
    }
    if ((*fdf)->isom != NULL)
        free((*fdf)->isom);
}

void	free_map(t_fdf **fdf)
{
    int	i;

	i = 0;
    while (i < (*fdf)->map->height)
    {
        free((*fdf)->map->points[i]);
		i++;
    }
    free((*fdf)->map->points);
    free((*fdf)->map);
}

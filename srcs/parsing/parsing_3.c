/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:44:13 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 15:15:39 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_rgb_sky(t_cub *cub)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = ft_strtrim(cub->parse->rgb_sky, "C ");
	while (str[i] != ',')
		i++;
	cub->parse->str_r = ft_master_strndup(str, 0, i);
	i++;
	j = i;
	while (str[i] != ',')
		i++;
	cub->parse->str_g = ft_master_strndup(str, j, i);
	i++;
	j = i;
	while (str[i] != ',' && str[i])
		i++;
	cub->parse->str_b = ft_master_strndup(str, j, i);
	cub->parse->r_sky = ft_atoi(cub->parse->str_r);
	cub->parse->g_sky = ft_atoi(cub->parse->str_g);
	cub->parse->b_sky = ft_atoi(cub->parse->str_b);
	free(str);
}

int	check_rgb_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == c || str[i] == ' ')
			i++;
		else if (str[i] == ',')
		{
			i++;
			count++;
		}
		else
			return (1);
	}
	if (count != 2)
		return (1);
	return (0);
}

int	check_rgb_int(t_cub *cub)
{
	if (cub->parse->r_sky < 0 || cub->parse->r_sky > 255)
		return (1);
	if (cub->parse->g_sky < 0 || cub->parse->g_sky > 255)
		return (1);
	if (cub->parse->b_sky < 0 || cub->parse->b_sky > 255)
		return (1);
	if (cub->parse->r_floor < 0 || cub->parse->r_floor > 255)
		return (1);
	if (cub->parse->g_floor < 0 || cub->parse->g_floor > 255)
		return (1);
	if (cub->parse->b_floor < 0 || cub->parse->b_floor > 255)
		return (1);
	return (0);
}

// void	join_rgb_sky(t_cub *cub)
// {
// 	cub->parse->hexa = ft_calloc(COLORSIZE, 4);
// 	//cub->parse->test = ft_calloc(COLORSIZE, 4);
// 	cub->parse->test = ft_itoa(cub->parse->r_sky);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	free(cub->parse->test);
// 	cub->parse->test =  ft_itoa(cub->parse->g_sky);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	free(cub->parse->test);
// 	cub->parse->test =  ft_itoa(cub->parse->b_sky);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	cub->game->rgb_sky = ft_atoi(cub->parse->hexa);
// }

// void	join_rgb_floor(t_cub *cub)
// {
// 	cub->parse->hexa = ft_calloc(COLORSIZE, 4);
// 	//cub->parse->test = ft_calloc(COLORSIZE, 4);
// 	cub->parse->test = ft_itoa(cub->parse->r_floor);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	free(cub->parse->test);
// 	cub->parse->test =  ft_itoa(cub->parse->g_floor);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	free(cub->parse->test);
// 	cub->parse->test =  ft_itoa(cub->parse->b_floor);
// 	cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
// 	cub->game->rgb_floor = ft_atoi(cub->parse->hexa);
// }

void join_rgb_sky(t_cub *cub)
{
    char *temp;

    cub->parse->hexa = ft_strdup(""); // Initialiser une chaîne vide
    if (!cub->parse->hexa)
        return; // Gérer une éventuelle erreur d'allocation

    // Ajouter la valeur rouge
    cub->parse->test = ft_itoa(cub->parse->r_sky);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Ajouter la valeur verte
    cub->parse->test = ft_itoa(cub->parse->g_sky);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Ajouter la valeur bleue
    cub->parse->test = ft_itoa(cub->parse->b_sky);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Convertir en entier et libérer
    cub->game->rgb_sky = ft_atoi(cub->parse->hexa);
    free(cub->parse->hexa);
}

void join_rgb_floor(t_cub *cub)
{
    char *temp;

    cub->parse->hexa = ft_strdup(""); // Initialiser une chaîne vide
    if (!cub->parse->hexa)
        return;

    // Ajouter la valeur rouge
    cub->parse->test = ft_itoa(cub->parse->r_floor);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Ajouter la valeur verte
    cub->parse->test = ft_itoa(cub->parse->g_floor);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Ajouter la valeur bleue
    cub->parse->test = ft_itoa(cub->parse->b_floor);
    if (!cub->parse->test)
        return (free(cub->parse->hexa));
    temp = cub->parse->hexa;
    cub->parse->hexa = ft_strjoin(cub->parse->hexa, cub->parse->test);
    free(temp);
    free(cub->parse->test);

    // Convertir en entier et libérer
    cub->game->rgb_floor = ft_atoi(cub->parse->hexa);
    free(cub->parse->hexa);
}


int	check_rgb(t_cub *cub)
{
	if (check_rgb_str(cub->parse->rgb_sky, 'C') == 1)
		return (1);
	if (check_rgb_str(cub->parse->rgb_floor, 'F') == 1)
		return (1);
	split_rgb_sky(cub);
	join_rgb_sky(cub);
	free(cub->parse->str_r);
	free(cub->parse->str_g);
	free(cub->parse->str_b);
	split_rgb_floor(cub);
	join_rgb_floor(cub);
	if (check_rgb_int(cub) == 1)
		return (1);
	return (0);
}

int	valid_texture(t_cub *cub)
{
	int	h;
	int	w;

	cub->game->north_texture = mlx_xpm_file_to_image(cub->game->mlx_ptr,
			cub->parse->north_path, &h, &w);
	if (!cub->game->north_texture)
		return (1);
	cub->game->south_texture = mlx_xpm_file_to_image(cub->game->mlx_ptr,
			cub->parse->south_path, &h, &w);
	if (!cub->game->south_texture)
		return (1);
	cub->game->east_texture = mlx_xpm_file_to_image(cub->game->mlx_ptr,
			cub->parse->east_path, &h, &w);
	if (!cub->game->east_texture)
		return (1);
	cub->game->west_texture = mlx_xpm_file_to_image(cub->game->mlx_ptr,
			cub->parse->west_path, &h, &w);
	if (!cub->game->west_texture)
		return (1);
	return (0);
}

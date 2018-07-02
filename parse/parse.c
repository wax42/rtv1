/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 21:32:06 by vguerand          #+#    #+#             */
/*   Updated: 2018/06/04 23:10:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rtv1.h"

#define SPHERE 6
#define PLAN 3

int *parse_ligne(int nbr_of_int, char *line)
{
    int i;
    int n;
	int tmp;
    int *ret[5];

	ft_memset((void*)ret, 0, 5);
    n = 0;
    i = 0;
    while (line[i])
    {
        if (n == nbr_of_int)
            return (ret);
        else
        {
			while(line[i] || line[i] == ' ')
				i++;
			if ((tmp = ft_atoi(line + i)) != -1)
			{
				ret[n] = tmp;
				n++;
			}
			else
				return (ret);
			while (ft_isdigit(line[i]))
				i++;
        }
    }
	return (NULL);
}

//// IL RESTE JUSTE A PARSER LE NOMBRE DE SPHERE ET DE PLAN AU DEBUT AFIN DE SAVOIR LA TAILLE

int	*parse_type(t_info *info, char *line, int type, int l_nb[5])
{
	int ret;
	int	point;

	if ((line = ft_strstr(line, "SPHERE")) != NULL)
		point = 0;
	else if ((line = ft_strstr(line, "PLAN")) != NULL)
		point = 1;
	else if ((line = ft_strstr(line, "LIGHT")) != NULL)
		point = 2;
	else if ((line = ft_strstr(line, "CONE")) != NULL)
		point = 3;
	else if ((line = ft_strstr(line, "CYLINDRE")) != NULL)
		point = 4;
	if (type == 1)
		l_nb[point] = (int)parse_ligne(1, line);
	else if (type == 2)
		info->obj->l_obj[point] = parse_ligne(0, line);
	return (l_nb);
}

/*
**	ret[0] nbr_of_plan;
**	ret[1] nbr_of_sphere
**	ret[2] nbr_of_light
**	ret[3] nbr_of_cone
**	ret[4] nbr_of_cylindre
**	ret[5] return value;
*/

void parse_malloc(t_list *list)
{
	if (list->l_obj[0] > 0)
	{
		if (!(list->sphere = (t_sphere*)malloc(sizeof(t_sphere) * list->l_obj[0]) + 1))
			ft_exit(0, "SPHERE", NULL);
	}
	else
		list->sphere = NULL;
	if (list->l_obj[1] > 0)
	{
		if (!(list->plan = (t_plan*)malloc(sizeof(t_plan) * list->l_obj[1]) + 1))
			ft_exit(0, "PLAN", NULL);
	}
	else
		list->plan = NULL;
	if (list->l_obj[2] > 0)
	{
		if (!(list->light =  (t_light*)malloc(sizeof(t_light) * list->l_obj[2]) + 1))
			ft_exit(0, "LIGHT", NULL);
	}
	else
		list->light = NULL;
	if (list->l_obj[3] > 0)
	{
		if (!(list->cone =  (t_cone*)malloc(sizeof(t_cone) * list->l_obj[3]) + 1))
			ft_exit(0, "CONE", NULL);
	}
	else
		list->light = NULL;
	if (list->l_obj[4] > 0)
	{
		if (!(list->cylindre = (t_cylindre*)malloc(sizeof(t_cylindre) * list->l_obj[4]) + 1))
			ft_exit(0, "CYLINDRE", NULL);
	}
	else
		list->cylindre = NULL;
}

uint8_t parse_resolution(t_info *info, char *line)
{
	if ((info->resolution[0] = ft_atoi(line)) == -1)
		return (0);	 //ERROR PARSING
	if ((line = ft_strstr(line, "ResolutionY")) == NULL)
		return (0); //ERROR PARSING
	if ((info->resolution[1] = ft_atoi(line)) == -1)
		return (0);
	return (1);
}

int parsing(t_info *info, char *str)
{
    int fd;
    char *line;
	int l_nbr[5];
	int ret;
	uint8_t parse;

	parse = 0;
    if ((fd = open(str, O_RDONLY)) < 0)
		return (0); //ERREUR DE LECTURE
    if (get_next_line(fd, &line) == -1 || ft_strlen(line) > 10) //le strlen pour controler un overflow ( limite faire un strlen de ft_isnum de i a n)
		return (0); //ERREUR DE MALLOC
	if ((line = ft_strstr(line, "ResolutionX")) != NULL)
		parse_resolution(info, line);
	else
		ft_memcpy((void*)info->resolution, (int[2]){RESOLUTION_X, RESOLUTION_Y}, sizeof(int[2])); //SINON SET LA RESOLUTION A 800
	if (ft_strstr(line, "<HEAD"))
		parse = 1;
	ft_strdel(&line);
	ft_memset((void*)l_nbr, 0, 5);
	ft_memset((void*)info->obj->l_obj, 0, 5);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
		if (ft_strstr(line, "<HEAD"))
			parse = 1;
		if (ft_strstr(line, "HEAD>"))
			parse = 0;
		if (ft_strstr(line, "<BODY"))
		{
			parse_malloc(info->obj);
			parse = 2;
		}
		parse_type(info, line, parse, l_nbr);
		ft_strdel(&line);
    }
	if (ret == -1)
		return (0); //ERROR MALLOC
	return (1);
}

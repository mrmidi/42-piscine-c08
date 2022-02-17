/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashabeln <ashabeln@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:17:20 by ashabeln          #+#    #+#             */
/*   Updated: 2022/02/17 18:44:29 by ashabeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src, int length)
{
	int		i;
	char	*result;

	length = ft_strlen(src);
	result = (char *)malloc(length * sizeof(char) + 1);
	if (result == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < length)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;
	int			size;

	tab = (t_stock_str *)malloc(ac * sizeof(t_stock_str));
	i = 0;
	while (i < ac - 1)
	{
		size = ft_strlen(av[i + 1]);
		tab[i].size = size;
		tab[i].str = av[i + 1];
		tab[i].copy = ft_strdup(av[i + 1], size);
		i++;
	}
	tab[i].str = (void *)0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:57:03 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/14 12:27:45 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	create_array_from_ints(int argc, char **argv, t_tab *tab)
{
	int	i;

	i = 0;
	tab->tab = malloc(sizeof(long int) * (argc));
	while (argc)
	{
		if (!check_args(argv[i + 1], tab->tab, i) || !check_dup(tab->tab, i))
		{
			free(tab->tab);
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		i++;
		argc--;
	}
	tab->size = i;
}

static void	create_array_from_string(char **argv, t_tab *tab)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i++])
		;
	tab->tab = malloc(sizeof(long int) * (i));
	i = 0;
	while (temp[i])
	{
		if (!check_args(temp[i], tab->tab, i) || !check_dup(tab->tab, i))
		{
			free(tab->tab);
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		free(temp[i]);
		i++;
	}
	free(temp);
	tab->size = i;
}

static void	ft_free(t_tabs *tab)
{
	free(tab->tab_a->tab);
	free(tab->tab_b->tab);
	free(tab->tab_a);
	free(tab->tab_b);
}

int	main(int argc, char **argv)
{
	t_tabs	tabs;
	int		*copy;
	int		j;

	copy = NULL;
	tabs.tab_a = malloc(sizeof(t_tab));
	tabs.tab_b = malloc(sizeof(t_tab));
	if (!tabs.tab_a || !tabs.tab_b)
		return (0);
	j = 0;
	tabs.tab_b->size = 0;
	if (argc-- == 1)
		exit(0);
	if (argc == 1)
		create_array_from_string(argv, tabs.tab_a);
	else
		create_array_from_ints(argc, argv, tabs.tab_a);
	copy = get_ordered_array(&tabs, copy);
	tabs.tab_a->tab = to_radix(&tabs, copy);
	preliminary_check(&tabs);
	if (!check_order(tabs.tab_a))
		ft_algo(&tabs);
	ft_free(&tabs);
	return (0);
}

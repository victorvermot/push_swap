/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:57:03 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/10 15:27:52 by vvermot-         ###   ########.fr       */
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

void	solve_three(t_tabs *tabs)
{
	if (tabs->tab_a->tab[0] > tabs->tab_a->tab[1]
		&& tabs->tab_a->tab[0] > tabs->tab_a->tab[2])
	{
		rotate(tabs->tab_a, RA);
		if (!check_order(tabs->tab_a))
			swap(tabs->tab_a, SA);
	}
	else if (tabs->tab_a->tab[0] > tabs->tab_a->tab[1]
		&& tabs->tab_a->tab[0] < tabs->tab_a->tab[2])
		swap(tabs->tab_a, SA);
	else if (tabs->tab_a->tab[0] < tabs->tab_a->tab[1]
		&& tabs->tab_a->tab[0] < tabs->tab_a->tab[2])
	{
		tabs->tab_b->tab = push_b(tabs);
		swap(tabs->tab_a, SA);
		tabs->tab_a->tab = push_a(tabs);
	}
}

void	preliminary_check(t_tabs *tabs)
{
	if (tabs->tab_a->size == 2 && !check_order(tabs->tab_a))
		swap(tabs->tab_a, SA);
	else if (tabs->tab_a->size == 3 && !check_order(tabs->tab_a))
		solve_three(tabs);
}

int	main(int argc, char **argv)
{
	t_tabs	tabs;
	int		j;

	tabs.tab_a = malloc(sizeof(t_tab));
	tabs.tab_b = malloc(sizeof(t_tab));
	j = 0;
	tabs.tab_b->size = 0;
	if (argc == 1)
		exit(0);
	argc--;
	if (argc == 1)
		create_array_from_string(argv, tabs.tab_a);
	else
		create_array_from_ints(argc, argv, tabs.tab_a);
	preliminary_check(&tabs);
	ft_algo(&tabs);
	while (j < tabs.tab_a->size)
	{
		printf("%d\n", tabs.tab_a->tab[j]);
		j++;
	}
	free(tabs.tab_a->tab);
	free(tabs.tab_b->tab);
	return (0);
}

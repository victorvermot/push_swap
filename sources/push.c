/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:31:12 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/14 12:35:56 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	redefine_tab(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		tab->tab[i] = tab->tab[i + 1];
		i++;
	}
}

int	*push_a(t_tabs *tabs)
{
	int	*new_tab;
	int	i;
	int	j;

	new_tab = malloc(sizeof(long int) * (tabs->tab_a->size + 1));
	i = 0;
	j = 0;
	if (tabs->tab_b->size != 0)
	{
		new_tab[0] = tabs->tab_b->tab[0];
		while (i < tabs->tab_a->size)
			new_tab[++i] = tabs->tab_a->tab[j++];
	}
	free(tabs->tab_a->tab);
	tabs->tab_a->size += 1;
	tabs->tab_b->size -= 1;
	redefine_tab(tabs->tab_b);
	ft_putstr_fd("pa\n", 1);
	return (new_tab);
}

int	*push_b(t_tabs *tabs)
{
	int	*new_tab;
	int	i;
	int	j;

	new_tab = malloc(sizeof(long int) * (tabs->tab_b->size + 1));
	i = 0;
	j = 0;
	if (tabs->tab_a->size != 0)
	{
		new_tab[0] = tabs->tab_a->tab[0];
		while (i < tabs->tab_b->size)
			new_tab[++i] = tabs->tab_b->tab[j++];
	}
	free(tabs->tab_b->tab);
	tabs->tab_b->size += 1;
	tabs->tab_a->size -= 1;
	redefine_tab(tabs->tab_a);
	ft_putstr_fd("pb\n", 1);
	return (new_tab);
}

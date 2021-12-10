/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:25:51 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/10 14:14:21 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_order(t_tab *tab)
{
	int	i;
	int	temp;

	temp = tab->tab[0];
	i = 0;
	while (i < tab->size - 1)
	{
		if (temp > tab->tab[i + 1])
			return (0);
		i++;
		temp = tab->tab[i];
	}
	return (1);
}

void	swap(t_tab *tab, int opt)
{
	int	temp;

	if (tab->size >= 2)
	{
		temp = tab->tab[0];
		tab->tab[0] = tab->tab[1];
		tab->tab[1] = temp;
	}
	if (opt == SA)
		ft_putstr_fd("sa\n", 1);
	else if (opt == SB)
		ft_putstr_fd("sb\n", 1);
	else if (opt == SS)
		ft_putstr_fd("ss\n", 1);
}

void	rotate(t_tab *tab, int opt)
{
	int	i;
	int	temp;

	(void)opt;
	i = 0;
	temp = tab->tab[i];
	tab->tab[i++] = tab->tab[tab->size - 1];
	tab->tab[tab->size - 1] = temp;
	while (i < tab->size - 1)
	{
		temp = tab->tab[i];
		tab->tab[i] = tab->tab[i - 1];
		tab->tab[i - 1] = temp;
		i++;
	}
	if (opt == RA)
		ft_putstr_fd("ra\n", 1);
	else if (opt == RB)
		ft_putstr_fd("rb\n", 1);
	else if (opt == RR)
		ft_putstr_fd("rr\n", 1);
}

void	inv_rotate(t_tab *tab, int opt)
{
	int	i;
	int	temp;

	i = 0;
	(void)opt;
	temp = tab->tab[i];
	tab->tab[i] = tab->tab[tab->size - 1];
	tab->tab[tab->size - 1] = temp;
	while (i < tab->size - 1)
	{
		temp = tab->tab[i];
		tab->tab[i] = tab->tab[i + 1];
		tab->tab[i + 1] = temp;
		i++;
	}
	if (opt == RRA)
		ft_putstr_fd("ra\n", 1);
	else if (opt == RRB)
		ft_putstr_fd("rb\n", 1);
	else if (opt == RRR)
		ft_putstr_fd("rr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:26 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/13 18:07:10 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_three(t_tabs *tabs)
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
	else if (tabs->tab_a->tab[0] < tabs->tab_a->tab[1]
		&& tabs->tab_a->tab[0] > tabs->tab_a->tab[2])
		inv_rotate(tabs->tab_a, RRA);
}

static void	solve_four(t_tabs *tabs)
{
	int	min;
	int	i;
	int	size;
	int	get_both;

	get_both = 0;
	size = tabs->tab_a->size;
	i = 0;
	min = get_min(tabs);
	while (i < tabs->tab_a->size)
	{
		if (tabs->tab_a->tab[0] == min)
		{
			tabs->tab_b->tab = push_b(tabs);
			break ;
		}
		else
			rotate(tabs->tab_a, RA);
		i++;
	}
	if (!check_order(tabs->tab_a))
		solve_three(tabs);
	if (!check_order(tabs->tab_b))
		swap(tabs->tab_b, SB);
	tabs->tab_a->tab = push_a(tabs);
}

static void	solve_five_2(t_tabs *tabs)
{
	if (!check_order(tabs->tab_a))
		solve_three(tabs);
	if (!check_order(tabs->tab_b))
		swap(tabs->tab_b, SB);
	tabs->tab_a->tab = push_a(tabs);
	tabs->tab_a->tab = push_a(tabs);
	rotate(tabs->tab_a, RA);
}

static void	solve_five(t_tabs *tabs)
{
	int	min;
	int	max;
	int	i;
	int	size;
	int	get_both;

	get_both = 0;
	size = tabs->tab_a->size;
	i = 0;
	min = get_min(tabs);
	max = get_max(tabs);
	while (i < tabs->tab_a->size)
	{
		if (tabs->tab_a->tab[0] == min || tabs->tab_a->tab[0] == max)
		{
			i = -1;
			tabs->tab_b->tab = push_b(tabs);
			if (++get_both == 2)
				break ;
		}
		else
			rotate(tabs->tab_a, RA);
		i++;
	}
	solve_five_2(tabs);
}

void	preliminary_check(t_tabs *tabs)
{
	if (tabs->tab_a->size == 2 && !check_order(tabs->tab_a))
		swap(tabs->tab_a, SA);
	else if (tabs->tab_a->size == 3 && !check_order(tabs->tab_a))
		solve_three(tabs);
	else if ((tabs->tab_a->size == 4)
		&& !check_order(tabs->tab_a))
		solve_four(tabs);
	else if ((tabs->tab_a->size == 5)
		&& !check_order(tabs->tab_a))
		solve_five(tabs);
}

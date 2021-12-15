/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:20:15 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/13 19:29:16 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_max_bits(t_tabs *tab)
{
	int	i;
	int	size;
	int	temp;
	int	max_bits;

	max_bits = 0;
	i = 0;
	size = tab->tab_a->size;
	temp = get_max(tab);
	while (temp >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	ft_algo(t_tabs *tab)
{
	int	j;
	int	i;
	int	size;
	int	max_bits;

	i = 0;
	j = 0;
	size = tab->tab_a->size;
	max_bits = get_max_bits(tab);
	while (i < max_bits)
	{
		while (j < size)
		{
			if ((tab->tab_a->tab[0] >> i) & 1)
				rotate(tab->tab_a, RA);
			else
				tab->tab_b->tab = push_b(tab);
			j++;
		}
		j = 0;
		i++;
		while (tab->tab_b->size)
			tab->tab_a->tab = push_a(tab);
	}
}

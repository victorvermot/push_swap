/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:20:15 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/10 16:33:26 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_tabs *tab)
{
	int	j;
	int	i;
	int	size;

	i = 0;
	j = 0;
	size = tab->tab_a->size;
	while (!check_order(tab->tab_a))
	{
		while (j < size)
		{
			if ((tab->tab_a->tab[0] >> i) & 1)
				rotate(tab->tab_a, RA);
			else
				tab->tab_b->tab = push_b(tab);
			//printf("%d\n", (tab->tab_a->tab[0]));
			j++;
		}
		j = 1;
		i++;
		while (tab->tab_b->size)
		{
			tab->tab_a->tab = push_a(tab);
			printf("%d\n", tab->tab_b->size);
		}
	}
}

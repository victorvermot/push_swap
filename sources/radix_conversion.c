/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:52:25 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/13 14:06:25 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int	*get_ordered_array(t_tabs *tab, int *copy)
{
	int	size;
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = -1;
	j = 1;
	size = tab->tab_a->size;
	copy = malloc(sizeof(int) * size);
	while (++i < size)
		copy[i] = tab->tab_a->tab[i];
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (copy[i] > copy[j])
				ft_swap(&copy[i], &copy[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (copy);
}

int	*to_radix(t_tabs *tab, int *copy)
{
	int	i;
	int	j;
	int	size;
	int	*new_tab;

	i = 0;
	j = 0;
	size = tab->tab_a->size;
	new_tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		while (j < size)
		{
			if (tab->tab_a->tab[i] == copy[j])
			{
				new_tab[i] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(tab->tab_a->tab);
	return (new_tab);
}

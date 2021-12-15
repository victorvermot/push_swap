/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:40:39 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/13 16:35:39 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_tabs *tab)
{
	int	i;
	int	temp;

	i = 0;
	temp = tab->tab_a->tab[i];
	while (i < tab->tab_a->size)
	{
		if (temp > tab->tab_a->tab[i])
			temp = tab->tab_a->tab[i];
		i++;
	}
	return (temp);
}

int	get_max(t_tabs *tab)
{
	int	i;
	int	temp;

	i = 0;
	temp = tab->tab_a->tab[i];
	while (i < tab->tab_a->size)
	{
		if (temp < tab->tab_a->tab[i])
			temp = tab->tab_a->tab[i];
		i++;
	}
	return (temp);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			write(fd, &s[i], sizeof(s[i]));
	}
}

int	check_args(char *argv, int *num, int i)
{
	long int	temp;

	if (argv[0] == '0')
	{
		num[i] = 0;
		return (1);
	}
	temp = ft_atoi(argv);
	if (temp < -2147483648 || temp > 2147483647 || temp == 0)
		return (0);
	num[i] = temp;
	return (1);
}

int	check_dup(int *nums, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < i)
	{
		if (nums[j] == nums[i])
		{
			k++;
			break ;
		}
		j++;
		k++;
	}
	if (k != j)
		return (0);
	return (1);
}

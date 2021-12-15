/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:06:29 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/15 09:31:01 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

enum	e_operations{
	SA = 1,
	SB,
	SS,
	PA = 1,
	PB,
	RA = 1,
	RB,
	RR,
	RRA = 1,
	RRB,
	RRR
};

typedef struct s_tab_a{
	int	size;
	int	*tab;
}		t_tab;

typedef struct s_tab{
	t_tab	*tab_a;
	t_tab	*tab_b;
}		t_tabs;

int		check_args(char *argv, int *num, int i);
int		check_dup(int *nums, int i);
void	ft_putstr_fd(char *s, int fd);
void	swap(t_tab *tab_a, int opt);
int		*push_a(t_tabs *tabs);
int		*push_b(t_tabs *tabs);
void	rotate(t_tab *tab, int opt);
void	inv_rotate(t_tab *tab, int opt);
int		check_order(t_tab *tab);
void	ft_algo(t_tabs *tab);
int		*get_ordered_array(t_tabs *tab, int *copy);
int		*to_radix(t_tabs *tab, int *copy);
void	preliminary_check(t_tabs *tabs);
int		get_max(t_tabs *tab);
int		get_min(t_tabs *tab);

#endif

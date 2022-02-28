/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:11:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 20:50:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest(t_list *a)
{
	int		biggest;
	t_list	*tmp;

	tmp = a;
	biggest = (intptr_t)tmp->content;
	while (tmp)
	{
		if (biggest < (intptr_t)tmp->content)
			biggest = (intptr_t)tmp->content;
		tmp = tmp->next;
	}
	return (biggest);
}

int	ft_smallest(t_list *a)
{
	int		smallest;
	t_list	*tmp;

	tmp = a;
	smallest = (intptr_t)tmp->content;
	while (tmp)
	{
		if (smallest > (intptr_t)tmp->content)
			smallest = (intptr_t)tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

static void	stack_to_tab(t_list *a, int *tab, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = a;
	while (i < size)
	{
		tab[i] = (intptr_t)tmp->content;
		i++;
		tmp = tmp->next;
	}
}

static void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_mid(t_stack *stack, t_list *a_b, int size)
{
	int	*tab;
	int	mid;

	tab = malloc(sizeof(intptr_t) * size);
	if (!tab)
		quit_error(stack);
	ft_bzero(tab, sizeof(intptr_t) * size);
	stack_to_tab(a_b, tab, size);
	ft_sort_tab(tab, size);
	mid = tab[size / 2];
	free(tab);
	return (mid);
}

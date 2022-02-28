/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:42:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/05 12:41:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	action_sepa(t_stack *stack, int size)
{
	int	mid;
	int	i;

	i = 0;
	mid = find_mid(stack, stack->a, size);
	size = ft_lstsize(stack->a);
	while (i < size / 2)
	{
		if ((intptr_t)stack->a->content < mid)
		{
			ft_pb(stack, 1);
			i++;
		}
		else
			ft_ra(stack, 1);
	}
}

static void	action_b_stack(t_stack *stack)
{
	int	count;
	int	mid;
	int	i;
	int	size;

	while (stack->b)
	{
		count = 0;
		mid = find_mid(stack, stack->b, ft_lstsize(stack->b));
		size = ft_lstsize(stack->b);
		i = size;
		while (i > size / 2)
		{
			if ((intptr_t)stack->b->content >= mid)
			{
				ft_pa(stack, 1);
				i--;
				count++;
			}
			else
				ft_rb(stack, 1);
		}
		ft_lstadd_front(&stack->part_size, ft_lstnew((void *)(intptr_t)count));
	}
}

static void	action_one_part(t_list *part_size, t_stack *stack)
{
	int	i;
	int	j;
	int	mid;

	i = -1;
	j = 0;
	mid = find_mid(stack, stack->a, (intptr_t)part_size->content);
	while (++i < (intptr_t)part_size->content)
	{
		if ((intptr_t)stack->a->content >= mid)
		{
			ft_ra(stack, 1);
			j++;
		}
		else
			ft_pb(stack, 1);
	}
	i = 0;
	while (i++ < j)
		ft_rra(stack, 1);
	b_to_a(stack);
	while (j--)
		ft_pb(stack, 1);
	b_to_a(stack);
}

static void	sort_all(t_stack *stack)
{
	t_list	*tmp;

	stack->part_size = NULL;
	action_b_stack(stack);
	tmp = stack->part_size;
	while (tmp)
	{
		if ((intptr_t)tmp->content == 1)
		{
			ft_ra(stack, 1);
		}
		else if ((intptr_t)tmp->content == 2)
		{
			if ((intptr_t)stack->a->content > (intptr_t)stack->a->next->content)
				ft_sa(stack, 1);
			ft_ra(stack, 1);
			ft_ra(stack, 1);
		}
		else
			action_one_part(tmp, stack);
		tmp = tmp->next;
	}
}

void	ft_num_more(t_stack *stack)
{
	int	size;
	int	size2;
	int	i;

	i = 0;
	size = ft_lstsize(stack->a);
	action_sepa(stack, size);
	size2 = ft_lstsize(stack->a);
	sort_all(stack);
	while (i < size2)
	{
		ft_pb(stack, 1);
		i++;
	}
	sort_all(stack);
}

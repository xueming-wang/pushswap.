/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_less_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:16:16 by xuwang            #+#    #+#             */
/*   Updated: 2021/11/09 15:06:47 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

void	ft_num_three(t_stack *stack)
{
	int	biggest;

	biggest = ft_biggest(stack->a);
	if (biggest == (intptr_t)stack->a->content)
	{
		ft_ra(stack, 1);
		if ((intptr_t)stack->a->content > (intptr_t)stack->a->next->content)
			ft_sa(stack, 1);
	}
	else if (biggest == (intptr_t)stack->a->next->content)
	{
		ft_rra(stack, 1);
		if ((intptr_t)stack->a->content > (intptr_t)stack->a->next->content)
			ft_sa(stack, 1);
	}
	else if (biggest == (intptr_t)stack->a->next->next->content)
	{
		if ((intptr_t)stack->a->content > (intptr_t)stack->a->next->content)
			ft_sa(stack, 1);
	}
}

void	ft_num_five(t_stack *stack)
{
	int	biggest;
	int	smallest;

	biggest = ft_biggest(stack->a);
	smallest = ft_smallest(stack->a);
	while (ft_lstsize(stack->b) != 2)
	{
		if ((intptr_t)stack->a->content == biggest
			|| (intptr_t)stack->a->content == smallest)
			ft_pb(stack, 1);
		else
			ft_ra(stack, 1);
	}
	ft_num_three(stack);
	if ((intptr_t)stack->b->content > (intptr_t)stack->b->next->content)
		ft_sb(stack, 1);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
	ft_ra(stack, 1);
}

void	b_to_a(t_stack *stack)
{
	int	tmp;
	int	biggest;
	int	smallest;

	tmp = (intptr_t)stack->a->content;
	while (stack->b)
	{
		biggest = ft_biggest(stack->b);
		smallest = ft_smallest(stack->b);
		if ((intptr_t)stack->b->content == smallest)
		{
			ft_pa(stack, 1);
			ft_ra(stack, 1);
		}
		else if ((intptr_t)stack->b->content == biggest)
			ft_pa(stack, 1);
		else
			ft_rb(stack, 1);
	}
	while ((intptr_t)stack->a->content != tmp)
		ft_ra(stack, 1);
}

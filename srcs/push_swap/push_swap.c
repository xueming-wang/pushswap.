/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:52:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/05 16:25:26 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	list_is_sort(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		if (tmp->next && ((intptr_t)tmp->content
				> (intptr_t)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_alog(t_stack *stack)
{
	if (list_is_sort(stack))
		quit_success(stack);
	else if (ft_lstsize(stack->a) <= 3)
		ft_num_three(stack);
	else if (ft_lstsize(stack->a) <= 5)
		ft_num_five(stack);
	else
		ft_num_more(stack);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		quit_error(stack);
	ft_bzero(stack, sizeof(t_stack));
	stack->a = num_to_stack(stack, argc, argv);
	if (!stack->a)
		return (0);
	ft_alog(stack);
	quit_success(stack);
	return (0);
}

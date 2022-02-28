/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:54:31 by xuwang            #+#    #+#             */
/*   Updated: 2021/11/09 15:06:28 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_clean(t_stack *stack)
{
	if (stack)
	{
		if (stack->part_size)
			ft_lstclear(&stack->part_size, NULL);
		if (stack->a)
			ft_lstclear(&stack->a, NULL);
		if (stack->b)
			ft_lstclear(&stack->b, NULL);
		free (stack);
		stack = NULL;
	}
}

void	quit_success(t_stack *stack)
{
	if (stack)
		ft_clean(stack);
	exit(EXIT_SUCCESS);
}

void	quit_error(t_stack *stack)
{
	if (stack)
		ft_clean(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

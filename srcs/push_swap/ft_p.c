/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/11/09 15:06:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack, int print)
{
	void	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b->next;
	stack->b->next = stack->a;
	stack->a = stack->b;
	stack->b = tmp;
	if (print == 1)
		printf("pa\n");
}

void	ft_pb(t_stack *stack, int print)
{
	void	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a->next;
	stack->a->next = stack->b;
	stack->b = stack->a;
	stack->a = tmp;
	if (print == 1)
		printf("pb\n");
}

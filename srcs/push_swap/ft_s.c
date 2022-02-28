/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:45:44 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 19:23:28 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int print)
{
	void	*tmp;

	if (!stack->a || !stack->a->next)
		return ;
	tmp = stack->a->content;
	stack->a->content = stack->a->next->content;
	stack->a->next->content = tmp;
	if (print == 1)
		printf("sa\n");
}

void	ft_sb(t_stack *stack, int print)
{
	void	*tmp;

	if (!stack->b || !stack->b->next)
		return ;
	tmp = stack->b->content;
	stack->b->content = stack->b->next->content;
	stack->b->next->content = tmp;
	if (print == 1)
		printf("sb\n");
}

void	ft_ss(t_stack *stack, int print)
{
	ft_sa(stack, print);
	ft_sb(stack, print);
	if (print == 1)
		printf("ss\n");
}

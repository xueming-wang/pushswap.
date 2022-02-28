/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:47:34 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 19:10:48 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack, int print)
{
	t_list	*tmp;

	if (!stack->a || !stack->a->next)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack->a, tmp);
	if (print == 1)
		printf("ra\n");
}

void	ft_rb(t_stack *stack, int print)
{
	t_list	*tmp;

	if (!stack->b || !stack->b->next)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack->b, tmp);
	if (print == 1)
		printf("rb\n");
}

void	ft_rr(t_stack *stack, int print)
{
	ft_ra(stack, print);
	ft_rb(stack, print);
	if (print == 1)
		printf("rr\n");
}

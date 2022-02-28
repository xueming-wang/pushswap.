/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:48:16 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 19:56:53 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack, int print)
{
	t_list	*last_tmp;
	t_list	*tmp;

	if (!stack->a || !stack->a->next)
		return ;
	last_tmp = ft_lstlast(stack->a);
	tmp = stack->a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(&stack->a, last_tmp);
	if (print == 1)
		printf("rra\n");
}

void	ft_rrb(t_stack *stack, int print)
{
	t_list	*last_tmp;
	t_list	*tmp;

	if (!stack->b || !stack->b->next)
		return ;
	last_tmp = ft_lstlast(stack->b);
	tmp = stack->b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(&stack->b, last_tmp);
	if (print == 1)
		printf("rrb\n");
}

void	ft_rrr(t_stack *stack, int print)
{
	ft_rra(stack, print);
	ft_rrb(stack, print);
	if (print == 1)
		printf("rrr\n");
}

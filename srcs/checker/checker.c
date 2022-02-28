/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:49:08 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/04 18:44:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char**argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		quit_error(NULL);
	ft_bzero(stack, sizeof(t_stack));
	stack->a = num_to_stack(stack, argc, argv);
	read_and_check(stack);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_instruct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:13:07 by fclivaz           #+#    #+#             */
/*   Updated: 2023/04/24 17:13:15 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_pswap *pswap, int mode)
{
	t_list	*temp;

	if (mode == 1)
	{
		temp = pswap->astack;
		pswap->astack = pswap->astack->next;
		temp->next = NULL;
		ft_lstadd_back(&pswap->astack, temp);
		ft_putendl_fd("ra", 1);
	}
	if (mode == 2)
	{
		temp = pswap->bstack;
		pswap->bstack = pswap->bstack->next;
		temp->next = NULL;
		ft_lstadd_back(&pswap->bstack, temp);
		ft_putendl_fd("rb", 1);
	}
}

void	revrotate(t_pswap *pswap, int mode)
{
	t_list	*temp;
	t_list	*rotate;

	if (mode == 1)
	{
		temp = ft_lstlast(pswap->astack);
		rotate = pswap->astack;
		while (rotate->next->next != NULL)
			rotate = rotate->next;
		rotate->next = NULL;
		ft_lstadd_front(&pswap->astack, temp);
		ft_putendl_fd("rra", 1);
	}
	if (mode == 2)
	{
		temp = ft_lstlast(pswap->bstack);
		rotate = pswap->bstack;
		while (rotate->next->next != NULL)
			rotate = rotate->next;
		rotate->next = NULL;
		ft_lstadd_front(&pswap->bstack, temp);
		ft_putendl_fd("rrb", 1);
	}
}

void	doubleswap(t_pswap *pswap)
{
	swap(pswap, 1);
	swap(pswap, 2);
}

void	doublerotate(t_pswap *pswap)
{
	rotate(pswap, 1);
	rotate(pswap, 2);
}

void	doublerevrotate(t_pswap *pswap)
{
	revrotate(pswap, 1);
	revrotate(pswap, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:28:37 by fclivaz           #+#    #+#             */
/*   Updated: 2023/04/26 17:28:49 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_pswap *pswap)
{
	int	*cont;
	int	*cont2;
	int	*cont3;

	cont = (int *)pswap->astack->content;
	cont2 = (int *)pswap->astack->next->content;
	cont3 = (int *)pswap->astack->next->next->content;
	if (cont[1] < cont2[1] && cont[1] < cont3[1])
	{
		swap(pswap, 1);
		rotate(pswap, 1);
	}
	else if (cont[1] > cont2[1] && cont[1] < cont3[1])
		swap(pswap, 1);
	else if (cont[1] < cont2[1] && cont[1] > cont3[1])
		revrotate(pswap, 1);
	else if (cont[1] > cont2[1] && cont2[1] < cont3[1])
		rotate(pswap, 1);
	else if (cont[1] > cont2[1] && cont2[1] > cont3[1])
	{
		swap(pswap, 1);
		revrotate(pswap, 1);
	}
}

void	sort_four(t_pswap *pswap, int mode)
{
	int	*cont;
	int	*cont2;
	int	*cont3;

	cont = (int *)pswap->astack->content;
	cont2 = (int *)pswap->astack->next->content;
	cont3 = (int *)pswap->astack->next->next->content;
	if (cont[1] == mode)
		;
	else if (cont2[1] == mode)
		swap(pswap, 1);
	else if (cont3[1] == mode)
	{
		rotate(pswap, 1);
		rotate(pswap, 1);
	}
	else
		revrotate(pswap, 1);
	if (checker(pswap->astack, 0))
	{
		push(pswap, 1);
		sort_three(pswap);
		push(pswap, 2);
	}
}

void	sort_five(t_pswap *pswap)
{
	int	*cont;
	int	*cont2;
	int	*cont3;

	cont = (int *)pswap->astack->content;
	cont2 = (int *)pswap->astack->next->content;
	cont3 = (int *)pswap->astack->next->next->content;
	five_helper(pswap, cont, cont2, cont3);
	if (checker(pswap->astack, 0))
	{
		push(pswap, 1);
		sort_four(pswap, 1);
		push(pswap, 2);
	}
}

void	radix(t_pswap *pswap, int nbr)
{
	int	x;
	int	y;
	int	*cont;

	x = 0;
	while (x < 32)
	{
		y = 0;
		while (y < nbr)
		{
			cont = (int *)pswap->astack->content;
			if ((cont[1] >> x) & 1)
				rotate(pswap, 1);
			else
				push(pswap, 1);
			++y;
		}
		++x;
		while (pswap->bstack->content != NULL)
			push(pswap, 2);
		if (!checker(pswap->astack, 1))
			return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:38:09 by fclivaz           #+#    #+#             */
/*   Updated: 2023/04/24 16:38:19 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_actually(t_list *list, char c)
{
	t_list	*cool;
	int		size;
	int		x;
	int		*i;

	cool = list;
	size = ft_lstsize(list);
	x = -1;
	while (x != size || list->content != NULL)
	{
		i = (int *)cool->content;
		ft_printf("Stack %c position %d\t stores number %d!\t index %d!\n",
			c, i[1], i[0], i[2]);
		if (cool->next != NULL)
			cool = cool->next;
		else
			break ;
	}
	ft_putendl_fd("-----", 1);
}

static void	print_list(t_list *list, char c)
{
	ft_putendl_fd("-----", 1);
	if (list->content == NULL || !list)
	{
		ft_printf("List %c does not exist!\n", c);
		ft_putendl_fd("-----", 1);
		return ;
	}
	print_actually(list, c);
}

void	print_lists(t_pswap *pswap)
{
	print_list(pswap->astack, 'a');
	print_list(pswap->bstack, 'b');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:52:48 by fclivaz           #+#    #+#             */
/*   Updated: 2023/04/25 20:52:58 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	five_helper(t_pswap *pswap, int *cont, int *cont2, int *cont3)
{
	int	*cont4;

	cont4 = (int *)pswap->astack->next->next->next->content;
	if (cont[1] == 0)
		;
	else if (cont2[1] == 0)
		swap(pswap, 1);
	else if (cont3[1] == 0)
	{
		rotate(pswap, 1);
		rotate(pswap, 1);
	}
	else if (cont4[1] == 0)
	{
		revrotate(pswap, 1);
		revrotate(pswap, 1);
	}
	else
		revrotate(pswap, 1);
}

int	checker(t_list *astack, int mode)
{
	int		*i;
	int		*j;
	t_list	*list;

	list = astack;
	while (list->next != NULL)
	{
		i = (int *)list->content;
		j = (int *)list->next->content;
		if (i[mode] > j[mode])
			return (1);
		list = list->next;
	}
	return (0);
}

void	freearray(char **array)
{
	int	x;

	x = -1;
	while (array[++x] != NULL)
		free(array[x]);
	free(array);
}

void	freexit(t_pswap *pswap)
{
	t_list	*cool;

	while (pswap->astack)
	{
		free(pswap->astack->content);
		cool = pswap->astack->next;
		free(pswap->astack);
		pswap->astack = cool;
	}
	free(pswap->astack);
	while (pswap->bstack)
	{
		free(pswap->bstack->content);
		cool = pswap->bstack->next;
		free(pswap->bstack);
		pswap->bstack = cool;
	}
	free(pswap->bstack);
	exit (0);
}

void	error_generic(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

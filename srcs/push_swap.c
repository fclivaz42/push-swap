/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:57:13 by fclivaz           #+#    #+#             */
/*   Updated: 2023/03/30 14:57:22 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_smallest(t_list *lst)
{
	t_list	*cool;
	int		*cont;
	int		i;

	cool = lst;
	i = INT_MAX;
	while (cool != NULL)
	{
		cont = (int *)cool->content;
		if (i > cont[0] && cont[2] == 0)
			i = cont[0];
		cool = cool->next;
	}
	return (i);
}

static void	flip_byte(t_list *lst, int smolest, int index)
{
	t_list	*cool;
	int		*cont;

	cool = lst;
	cont = (int *)cool->content;
	while (cool != NULL)
	{
		cont = (int *)cool->content;
		if (cont[0] == smolest)
		{
			cont[1] = index;
			cont[2] = 1;
		}
		cool = cool->next;
	}	
}

static void	presort(t_list *stack)
{
	int		index;
	int		smallest;

	index = 0;
	while (index != ft_lstsize(stack))
	{
		smallest = find_smallest(stack);
		flip_byte(stack, smallest, index);
		++index;
	}
}

static void	sort(t_pswap *pswap)
{
	int	size;

	size = ft_lstsize(pswap->astack);
	if (size == 2)
		swap(pswap, 1);
	else if (size == 3)
		sort_three(pswap);
	else if (size == 4)
		sort_four(pswap, 0);
	else if (size == 5)
		sort_five(pswap);
	else
		radix(pswap, ft_lstsize(pswap->astack));
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		pswap.onearg = ft_split(argv[1], ' ');
		if (pswap.onearg == NULL || !pswap.onearg[0])
			error_generic();
		pswap.astack = check_args(pswap.onearg);
		freearray(pswap.onearg);
	}
	else
		pswap.astack = check_args(&argv[1]);
	pswap.bstack = ft_lstnew(NULL);
	if (!checker(pswap.astack, 0))
		freexit(&pswap);
	presort(pswap.astack);
	if (DEBUG)
		print_lists(&pswap);
	sort(&pswap);
	if (DEBUG)
		print_lists(&pswap);
	freexit(&pswap);
	exit (0);
}

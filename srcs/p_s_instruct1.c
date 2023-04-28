/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_instruct1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:12:42 by fclivaz           #+#    #+#             */
/*   Updated: 2023/04/24 17:12:50 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	apush(t_pswap *pswap)
{
	t_list	*temp;

	temp = pswap->astack;
	pswap->astack = temp->next;
	if (pswap->bstack->content != NULL)
		ft_lstadd_front(&pswap->bstack, temp);
	else
	{
		free(pswap->bstack);
		pswap->bstack = temp;
		pswap->bstack->next = NULL;
	}
	if (pswap->astack == NULL)
		pswap->astack = ft_lstnew(NULL);
	if (pswap->astack == NULL)
		error_generic();
	ft_putendl_fd("pb", 1);
}

static void	bpush(t_pswap *pswap)
{
	t_list	*temp;

	temp = pswap->bstack;
	pswap->bstack = temp->next;
	if (pswap->astack->content != NULL)
		ft_lstadd_front(&pswap->astack, temp);
	else
	{
		free(pswap->astack);
		pswap->astack = temp;
		pswap->astack->next = NULL;
	}
	if (pswap->bstack == NULL)
		pswap->bstack = ft_lstnew(NULL);
	if (pswap->bstack == NULL)
		error_generic();
	ft_putendl_fd("pa", 1);
}

void	push(t_pswap *pswap, int mode)
{
	if (mode == 1)
		apush(pswap);
	if (mode == 2)
		bpush(pswap);
}

void	swap(t_pswap *pswap, int mode)
{	
	t_list	*temp;

	if (mode == 1)
	{
		temp = pswap->astack->next;
		pswap->astack->next = temp->next;
		ft_lstadd_front(&pswap->astack, temp);
		ft_putendl_fd("sa", 1);
	}
	if (mode == 2)
	{
		temp = pswap->bstack->next;
		pswap->bstack->next = temp->next;
		ft_lstadd_front(&pswap->bstack, temp);
		ft_putendl_fd("sb", 1);
	}
}

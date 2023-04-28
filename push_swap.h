/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:33:27 by fclivaz           #+#    #+#             */
/*   Updated: 2023/03/30 15:33:31 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_pswap
{
	t_list	*astack;
	t_list	*bstack;
	char	**onearg;
}	t_pswap;

// --- PUSH_SWAP MAIN UTILS --- //

void	swap(t_pswap *pswap, int mode);
void	push(t_pswap *pswap, int mode);
void	rotate(t_pswap *pswap, int mode);
void	revrotate(t_pswap *pswap, int mode);
void	doubleswap(t_pswap *pswap);
void	doublerotate(t_pswap *pswap);
void	doublerevrotate(t_pswap *pswap);

// --- EXTRA UTILS --- //

t_list	*check_args(char **argv);
void	freexit(t_pswap *pswap);
void	freearray(char **array);
int		checker(t_list *astack, int mode);

// --- SORTING UTILS --- //

void	radix(t_pswap *pswap, int nbr);
void	sort_three(t_pswap *pswap);
void	sort_four(t_pswap *pswap, int mode);
void	sort_five(t_pswap *pswap);
void	five_helper(t_pswap *pswap, int *cont, int *cont2, int *cont3);

// --- BUNGIE SPECIFIC --- //

void	error_generic(void);

// --- DEBUG STUFF --- //

void	print_lists(t_pswap *pswap);

# ifndef DEBUG
#  define DEBUG 0
# endif

#endif
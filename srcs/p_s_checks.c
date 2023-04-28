/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:45:02 by fclivaz           #+#    #+#             */
/*   Updated: 2023/03/30 15:45:11 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*check_overflow(char *src, int pos)
{
	int		*ret;
	char	*check;

	ret = (int *)ft_calloc(3, sizeof(int));
	if (ret == NULL)
		error_generic();
	ret[1] = pos;
	ret[0] = ft_atoi(src);
	check = ft_itoa(ret[0]);
	if (check == NULL)
		error_generic();
	if (ft_strncmp(src, check, ft_strlen(src)))
		error_generic();
	free(check);
	return (ret);
}

static void	check_numeric(char *str)
{
	int	x;

	x = 0;
	if (str[0] == '-')
	{
		if (str[1] != 0)
			x = 0;
		else
			error_generic();
	}
	else
		x = -1;
	while (str[++x])
		if (ft_isdigit(str[x]) == 0)
			error_generic();
}

static void	check_duplicates(t_list *current, t_list *lst)
{
	t_list	*temp;
	int		*nbr;
	int		*check;

	temp = lst;
	check = (int *)current->content;
	while (temp->next != NULL)
	{
		nbr = (int *)temp->content;
		if (check[0] == nbr[0])
			error_generic();
		temp = temp->next;
	}
}

t_list	*check_args(char **argv)
{
	int		x;
	t_list	*init;
	t_list	*temp;

	x = -1;
	while (argv[++x])
	{
		check_numeric(argv[x]);
		if (x == 0)
		{
			init = ft_lstnew(check_overflow(argv[x], x));
			if (init == NULL)
				error_generic();
		}
		if (x > 0)
		{
			temp = ft_lstnew(check_overflow(argv[x], x));
			if (temp == NULL)
				error_generic();
			ft_lstadd_back(&init, temp);
			check_duplicates(temp, init);
		}
	}
	return (init);
}

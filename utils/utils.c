/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:20:40 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/14 09:25:04 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(const char *nbr)
{
	long	sign;
	long	res;
	char	*nb;

	sign = 1;
	res = 0;
	nb = (char *)nbr;
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (*nb == '+' || *nb == '-')
	{
		if (*nb == '-')
			sign *= -1;
		nb++;
	}
	while (*nb != '\0' && (*nb >= '0' && *nb <= '9'))
	{
		res = res * 10 + (*nb - 48);
		nb++;
	}
	return (res * sign);
}

void	free_lst(t_push_swap **lst)
{
	t_push_swap	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nb = 0;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

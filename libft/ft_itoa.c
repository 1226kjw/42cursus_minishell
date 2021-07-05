/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:07:45 by jinukim           #+#    #+#             */
/*   Updated: 2020/10/02 17:40:55 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	deg(unsigned int un)
{
	unsigned int	d;
	int				c;

	c = 0;
	d = 1;
	if (un >= 1000000000)
		return (10);
	while (d <= un)
	{
		d *= 10;
		c++;
	}
	return (c);
}

static char	*return_p(int n, int *l)
{
	char	*p;

	if (n < 0)
		p = (char *)ft_calloc((*l + 2), sizeof(char));
	else
		p = (char *)ft_calloc((*l + 1), sizeof(char));
	if (!p)
		return (0);
	if (n < 0)
	{
		p[0] = '-';
		++*l;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				l;
	char			*p;

	if (n < 0)
		un = -n;
	else if (n > 0)
		un = n;
	else
		return (ft_strdup("0"));
	l = deg(un);
	p = return_p(n, &l);
	if (!p)
		return (0);
	while (un)
	{
		p[--l] = un % 10 + '0';
		un /= 10;
	}
	return (p);
}

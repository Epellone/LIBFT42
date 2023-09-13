/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:44:28 by epellone          #+#    #+#             */
/*   Updated: 2023/02/08 12:14:20 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sizen(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	ln;

	ln = n;
	len = sizen(ln);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (ln == 0)
		str[0] = 48;
	str[len--] = 0;
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[len--] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (str);
}

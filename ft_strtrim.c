/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:21:53 by epellone          #+#    #+#             */
/*   Updated: 2023/02/02 17:02:39 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_set(s1[start], set))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_set(s1[len - 1], set))
		len--;
	str = (char *) malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	end = 0;
	while (start < len)
	{
		str[end] = s1[start];
		end++;
		start++;
	}
	str[end] = '\0';
	return ((char *)str);
}

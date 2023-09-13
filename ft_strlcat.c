/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:27:49 by epellone          #+#    #+#             */
/*   Updated: 2023/01/31 15:17:22 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	j = 0;
	i = 0;
	len_src = ft_strlen(src);
	if (!dest && !src)
		return (0);
	if (dstsize == 0)
		return (len_src);
	while (dest[j] != '\0' && j < dstsize)
		j++;
	while (src[i] != '\0' && (j + i) < dstsize - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j < dstsize)
		dest[j + i] = '\0';
	return (j + len_src);
}

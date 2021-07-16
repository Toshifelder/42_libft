/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:08:55 by towatana          #+#    #+#             */
/*   Updated: 2021/07/16 12:57:43 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	heystack_len;
	size_t	needle_len;

	heystack_len = ft_strlen(heystack);
	needle_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)heystack);
	if (needle_len > heystack_len || heystack_len > len)
		return (NULL);
	i = 0;
	while (heystack[i])
	{
		if (ft_strncmp(&heystack[i], needle, needle_len) == 0)
			return ((char *)&heystack[i]);
		i++;
	}
	return (NULL);
}

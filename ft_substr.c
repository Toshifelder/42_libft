/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:48 by towatana          #+#    #+#             */
/*   Updated: 2021/11/01 17:45:49 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	sub_s_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		sub_s_len = ft_strlen(s) - start;
	else
		sub_s_len = len;
	sub_s = malloc(sizeof(char) * (sub_s_len + 1));
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, &s[start], sub_s_len + 1);
	return (sub_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 06:59:15 by towatana          #+#    #+#             */
/*   Updated: 2021/07/30 06:53:02 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start_i;
	size_t	end_i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	start_i = 0;
	while (start_i < s1_len && ft_strchr(set, s1[start_i]))
		start_i++;
	end_i = s1_len;
	while (end_i >= 0 && ft_strrchr(set, s1[end_i - 1]))
		end_i--;
	return (ft_substr(s1, start_i, end_i - start_i));
}

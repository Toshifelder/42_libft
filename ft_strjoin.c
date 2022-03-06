/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:51 by towatana          #+#    #+#             */
/*   Updated: 2022/02/26 17:09:59 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*connected_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	connected_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (connected_str == NULL)
		return (NULL);
	ft_strlcpy(connected_str, s1, s1_len + 1);
	ft_strlcpy(&connected_str[s1_len], s2, s2_len + 1);
	return (connected_str);
}

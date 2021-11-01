/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:58 by towatana          #+#    #+#             */
/*   Updated: 2021/11/01 17:45:59 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_malloc_error(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	get_arr_size(char const *s, char c)
{
	size_t	i;
	size_t	arr_size;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	arr_size = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		arr_size++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (arr_size);
}

static void	get_next_str(char **next_str, size_t *next_str_len, char c)
{
	size_t	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**s_arr;
	char	*next_str;
	size_t	next_str_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_arr = malloc(sizeof(char *) * (get_arr_size(s, c) + 1));
	if (!s_arr)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < get_arr_size(s, c))
	{
		get_next_str(&next_str, &next_str_len, c);
		s_arr[i] = malloc(sizeof(char) * (next_str_len + 1));
		if (!s_arr[i])
			return (free_malloc_error(s_arr));
		ft_strlcpy(s_arr[i], next_str, next_str_len + 1);
		i++;
	}
	s_arr[i] = NULL;
	return (s_arr);
}

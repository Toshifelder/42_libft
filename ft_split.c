/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 06:53:41 by towatana          #+#    #+#             */
/*   Updated: 2021/08/29 17:22:30 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_arr_size(char const *s, char c)
{
	size_t	i;
	size_t	arr_i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	arr_i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		arr_i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (arr_i);
}

static char	**allocate_arr(const char *s, char c)
{
	char	**s_arr;
	size_t	arr_size;

	arr_size = cnt_arr_size(s, c);
	s_arr = malloc(sizeof(char *) * arr_size + 1);
	if (s_arr == NULL)
		return (NULL);
	s_arr[arr_size] = NULL;
	return (s_arr);
}

static char	*create_arr_one_part(const char *s, char c, size_t	*i)
{
	size_t	start;
	size_t	s_len;

	s_len = ft_strlen(s);
	start = 0;
	while (*i < s_len && s[*i] == c)
		(*i)++;
	start = *i;
	while (*i < s_len && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

char	**ft_split(char const *s, char c)
{
	char	**s_arr;
	size_t	i;
	size_t	arr_i;

	if (s == NULL)
		return (NULL);
	s_arr = allocate_arr(s, c);
	if (c == '\0')
	{
		s_arr[0] = ft_strdup(s);
		return (s_arr);
	}
	i = 0;
	arr_i = 0;
	while (arr_i < cnt_arr_size(s, c))
	{
		s_arr[arr_i] = create_arr_one_part(s, c, &i);
		if (s_arr[arr_i] == NULL)
		{
			free(s_arr[arr_i]);
			return (NULL);
		}
		arr_i++;
	}
	return (s_arr);
}

// int main(){
// 	char s1[100] = "AAbbBBbbCC";
// 	char s2 = 'b';
// 	char **str;
// 	int i = 0;

// 	str = ft_split(s1, s2);
// 	while (str[i])
// 	{
// 		printf("%s", str[i]);
// 		i++;
// 	}
// 	return 0;
// }

void end(void)__attribute__((destructor));
void end(void)
{
 int ret = system("leaks a.out &> leaks.txt");
 if (ret) printf("\e[31m!leak detected!\e[0m\n");
}

// int main(){
// 	char s1[100] = "tripouille";
// 	char s2 = 0;
// 	char **str;
// 	int i = 0;

// 	str = ft_split(s1, s2);
// 	while (str[i])
// 	{
// 		printf("%s", str[i]);
// 		i++;
// 	}
// 	printf("\n%s\n", str[1]);
// 	printf("%s\n", str[0]);
// 	return 0;
// }

int main(){
	char *invalidReadCheck = 0;
	char **str;
	int i = 0;

	str = ft_split(invalidReadCheck, 0);
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
	return 0;
}
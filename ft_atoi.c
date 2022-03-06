/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:36 by towatana          #+#    #+#             */
/*   Updated: 2022/02/26 17:09:46 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign_cnt;
	long	to_int;

	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	sign_cnt = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_cnt *= -1;
		i++;
	}
	to_int = 0;
	while (ft_isdigit(str[i]))
	{
		to_int = to_int * 10 + (str[i] - '0');
		if (to_int > 2147483647 && sign_cnt == 1)
			return (-1);
		if (to_int > 2147483648 && sign_cnt == -1)
			return (0);
		i++;
	}
	return (sign_cnt * to_int);
}

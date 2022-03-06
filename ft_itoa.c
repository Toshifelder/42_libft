/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towatana <towatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:46:03 by towatana          #+#    #+#             */
/*   Updated: 2022/03/06 02:15:43 by towatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_negative(int	n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		sign_cnt;
	char	*s;

	if (n < 0)
		sign_cnt = -1;
	else
		sign_cnt = 1;
	digits = get_digits(n);
	s = malloc(sizeof(char) * (digits + 1));
	if (!s)
		return (NULL);
	s[digits] = '\0';
	digits--;
	while (digits >= 0)
	{
		s[digits] = handle_negative(n % 10) + '0';
		n = handle_negative(n / 10);
		digits--;
	}
	if (sign_cnt == -1)
		s[0] = '-';
	return (s);
}

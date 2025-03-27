/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:04:43 by sbouaa            #+#    #+#             */
/*   Updated: 2025/03/08 03:30:34 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_res(int s)
{
	if (s == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char	*str)
{
	int					i;
	unsigned long long	res;
	int					signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((res > MAX_L / 10)
			|| ((res == MAX_L / 10) && ((str[i] - 48) > MAX_L % 10)))
			return (res * signe);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * signe);
}

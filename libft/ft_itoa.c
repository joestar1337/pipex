/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:39:51 by sbouaa            #+#    #+#             */
/*   Updated: 2024/11/19 02:25:48 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static void	ft_def(int	*ii, long int	*num, int n)
{
	*ii = 0;
	*num = n;
}

char	*ft_itoa(int n)
{
	char		*p;
	int			digits;
	int			i;
	long int	number;

	ft_def(&i, &number, n);
	digits = ft_count_digits(number);
	if (number < 0 || number == 0)
		digits++;
	p = malloc((digits + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (number < 0)
	{
		number = number * -1;
		p[0] = '-';
		i++;
	}
	p[digits] = '\0';
	while (digits-- > i)
	{
		p[digits] = (number % 10) + 48;
		number = number / 10;
	}
	return (p);
}

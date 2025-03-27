/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:10:44 by sbouaa            #+#    #+#             */
/*   Updated: 2024/11/17 16:05:15 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && count && count > 18446744073709551615ULL / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}

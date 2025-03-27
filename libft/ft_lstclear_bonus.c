/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:18:34 by sbouaa            #+#    #+#             */
/*   Updated: 2024/11/18 23:15:26 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*root;
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	root = *lst;
	while (root != NULL)
	{
		temp = root -> next;
		del (root -> content);
		free(root);
		root = temp;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:53:40 by sbouaa            #+#    #+#             */
/*   Updated: 2025/02/13 05:53:42 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

void	ft_putstr(char	*str);
void	print_error(void);
void	ft_free(char	**str);
char	*find_path(char	*cammand, char	**env);
void	ft_execute(char	*av, char	**env);

#endif
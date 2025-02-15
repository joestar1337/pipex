/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:53:34 by sbouaa            #+#    #+#             */
/*   Updated: 2025/02/13 05:53:35 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	procces_1(char **av, char	**env, int	*fd)
{
	int		filein;

	filein = open(av[1], O_RDONLY);
	if ((filein == -1) || (access(av[1], R_OK) == -1))
		print_error();
	if ((dup2(fd[1], 1) < 0) || (dup2(filein, 0) < 0))
		print_error();
	close(fd[0]);
	ft_execute(av[2], env);
}

void	procces_2(char **av, char	**env, int	*fd)
{
	int		fileout;

	fileout = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0744);
	if ((fileout == -1) || (access(av[4], W_OK) == -1))
		print_error();
	if ((dup2(fd[0], 0) < 0) || (dup2(fileout, 1) < 0))
		print_error();
	close(fd[1]);
	ft_execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	pid_t	id;
	int		fd[2];

	if (ac != 5)
		return (1);
	if (pipe(fd) == -1)
		print_error();
	id = fork();
	if (id == -1)
		print_error();
	if (id == 0)
		procces_1(av, env, fd);
	waitpid(id, NULL, 0);
	procces_2(av, env, fd);
	return (0);
}

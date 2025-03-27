/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:53:34 by sbouaa            #+#    #+#             */
/*   Updated: 2025/03/10 04:07:41 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	procces_1(char **av, char	**env, int	*fd)
{
	int		filein;

	close(fd[0]);
	filein = open(av[1], O_RDONLY);
	if (filein == -1)
	{
		perror("Error opening infile file ");
		close(fd[1]);
		exit(1);
	}
	if ((dup2(fd[1], 1) < 0) || (dup2(filein, 0) < 0))
	{
		close(filein);
		close(fd[1]);
		print_error(NULL);
	}
	close(filein);
	close(fd[1]);
	ft_execute(av[2], env);
}

void	procces_2(char **av, char	**env, int	*fd)
{
	int		fileout;

	close(fd[1]);
	fileout = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0744);
	if (fileout == -1)
	{
		perror("Error opening output file ");
		close(fd[0]);
		exit(1);
	}
	if ((dup2(fd[0], 0) < 0) || (dup2(fileout, 1) < 0))
	{
		close(fileout);
		close(fd[0]);
		print_error(NULL);
	}
	close(fileout);
	close(fd[0]);
	ft_execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	pid_t	id1;
	pid_t	id2;
	int		fd[2];

	if (ac != 5)
		return (1);
	if (pipe(fd) == -1)
		print_error(NULL);
	id1 = fork();
	if (id1 == -1)
		print_error(fd);
	if (id1 == 0)
		procces_1(av, env, fd);
	id2 = fork();
	if (id2 == -1)
		print_error(fd);
	if (id2 == 0)
		procces_2(av, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}

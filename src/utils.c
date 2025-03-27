/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <sbouaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:53:46 by sbouaa            #+#    #+#             */
/*   Updated: 2025/03/14 12:19:23 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int *fd)
{
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
	perror("  <<< Failed >>>  ");
	exit(1);
}

static void	ft_free(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static char	*find_path(char	*cammand, char	**env)
{
	char	**all_paths;
	char	*path;
	char	*part_of_path;
	int		i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == NULL)
		i++;
	if (!env[i])
		return (NULL);
	all_paths = ft_split(env[i] + 5, ':');
	i = 0;
	if (!all_paths)
		return (NULL);
	while (all_paths[i])
	{
		part_of_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(part_of_path, cammand);
		free(part_of_path);
		if (access(path, X_OK | F_OK) == 0)
			return (ft_free(all_paths), path);
		(free(path), i++);
	}
	return (ft_free(all_paths), NULL);
}

static void	ft_handle_path(char	*av, char	**env)
{
	char	**cammand;

	cammand = ft_split(av, ' ');
	if (!cammand)
		return ;
	if (access(cammand[0], F_OK | X_OK) == -1)
	{
		ft_free(cammand);
		ft_putstr_fd("Command not found \n", 2);
		exit(1);
	}
	if ((execve(cammand[0], cammand, env) == -1))
	{
		ft_free(cammand);
		print_error(NULL);
	}
}

void	ft_execute(char	*av, char	**env)
{
	int		i;
	char	**cammand;
	char	*path;

	i = 0;
	if (!av || !av[0])
		(ft_putstr_fd("Command not found \n", 2), exit(1));
	if (ft_strchr(av, '/'))
		ft_handle_path(av, env);
	else
	{
		cammand = ft_split(av, ' ');
		if (!cammand)
			(ft_putstr_fd("cammand not found \n", 2), exit(1));
		path = find_path(cammand[0], env);
		if (!path || !cammand[0])
			(ft_free(cammand), ft_putstr_fd("Command not found \n", 2), exit(1));
		if ((execve(path, cammand, env) == -1))
		{
			ft_free(cammand);
			free(path);
			print_error(NULL);
		}
	}
}

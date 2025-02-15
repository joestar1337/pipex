/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouaa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:53:46 by sbouaa            #+#    #+#             */
/*   Updated: 2025/02/13 05:53:48 by sbouaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(void)
{
	perror("  <<< Failed >>>  :");
	exit(1);
}

void	ft_free(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*find_path(char *cammand, char	**env)
{
	char	**all_paths;
	char	*path;
	char	*part_of_path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	all_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		part_of_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(part_of_path, cammand);
		free(part_of_path);
		if (access(path, X_OK) == 0)
		{
			ft_free(all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(all_paths);
	return (0);
}

void	ft_handle_path(char	*av, char	**env)
{
	char	**cammand;

	if (access(av, F_OK) == -1)
		print_error();
	cammand = ft_split(av, '/');
	int count = 0;
	int i = 0;
	while (cammand[i] != NULL)
	{
		count++;
		i++;
	}
	char **a = ft_split(cammand[count - 1], ' ');
	if ((execve(av, a, env) == -1))
		print_error();
}

void	ft_execute(char	*av, char	**env)
{
	int		i;
	char	**cammand;
	char	*path;

	i = 0;
	if (!av || !av[0])
		print_error();
	if (av[0] == '/')
		ft_handle_path(av, env);
	else
	{
		cammand = ft_split(av, ' ');
		path = find_path(cammand[0], env);
		if (!path)
		{
			ft_free(cammand);
			perror("Failed ");
			exit(127);
		}
		if ((execve(path, cammand, env) == -1))
			print_error();
	}

}

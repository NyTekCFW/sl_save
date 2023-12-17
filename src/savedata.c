/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <lchiva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:18:13 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/17 23:47:42 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/savedata.h"

void	read_save(t_settings *sets, char *file)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd > 0)
	{
		sv_memset(sets, 0, sizeof(t_settings));
		i = read(fd, sets, sizeof(t_settings));
		sets = encrypt(sets, sizeof(t_settings), EKEY);
		if (i != sizeof(t_settings))
		{
			sv_memset(sets, 0, sizeof(t_settings));
			error_handler(1);
		}
		write(1, "Save as been loaded\n", 20);
		free(sets);
		return ;
	}
	error_handler(5);
}

void	make_save(t_settings *sets, char *file)
{
	void	*copy;
	int		fd;

	copy = encrypt(sets, sizeof(t_settings), EKEY);
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd > 0)
	{
		write(fd, copy, sizeof(t_settings));
		close(fd);
		write(1, "Save as been exported\n", 22);
		if (copy)
			free(copy);
		return ;
	}
	error_handler(4);
}

void	parse_args(char **argv, t_settings *sets)
{
	if (!sv_strcmp(argv[1], "read"))
		read_save(sets, argv[2]);
	else if (!sv_strcmp(argv[1], "make"))
		make_save(sets, argv[2]);
	else
		error_handler(3);
}

int	main(int argc, char **argv)
{
	t_settings	sets;

	sets.level = 1;
	sets.prestige = 10;
	sets.time_played = 1551222550;
	sets.total_steps = 5000;
	sets.xp = 120;
	if (argc == 3)
		parse_args(argv, &sets);
	else
		error_handler(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:25:16 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/17 02:30:12 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/savedata.h"

size_t	sv_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_handler(int ce)
{
	char	*error;

	error = "Error code not defined\n";
	if (ce == 0)
		error = "Error: arguments are not correctly defined!\n";
	if (ce == 1)
		error = "Error: invalid size!\n";
	if (ce == 2)
		error = "Error: malloc fail!\n";
	if (ce == 3)
		error = "Error: type is not read or make!\n";
	if (ce == 4)
		error = "Error: fail during save export!\n";
	if (ce == 5)
		error = "Error: fail opening save!\n";
	write(1, error, sv_strlen(error));
	exit (0);
}

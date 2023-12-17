/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:18:04 by lchiva            #+#    #+#             */
/*   Updated: 2023/12/17 07:23:33 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVEDATA_H
# define SAVEDATA_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <malloc.h>

typedef struct settings_s
{
	unsigned int		xp;
	unsigned int		level;
	unsigned int		prestige;
	unsigned long long	time_played;
	unsigned long long	total_steps;
}	t_settings;

# define EKEY 0x5F

void	error_handler(int ce);
void	*encrypt(void *mem, size_t size, unsigned char key);
void	*sv_memset(void *s, int c, size_t n);
int		sv_strcmp(char *s1, char *s2);
#endif
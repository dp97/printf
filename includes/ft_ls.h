/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:47:56 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/06 15:45:08 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
/*	TEMPORARY	*/
# include <stdio.h>
# include <string.h>

typedef struct		s_dir
{
	char			name[256];
	struct s_dir	*next;
}					t_dir;

void				list_dir(const char *file_name);
void				inspect_file(const char *path);
#endif

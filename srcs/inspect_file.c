/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:48:01 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/06 16:58:40 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			list_perm(mode_t mode)
{
	char		buf[10];

	buf[0] = (mode & S_IRUSR) ? 'r' : '-';
	buf[1] = (mode & S_IWUSR) ? 'w' : '-';
	buf[2] = (mode & S_IXUSR) ? 'x' : '-';
	buf[3] = (mode & S_IRGRP) ? 'r' : '-';
	buf[4] = (mode & S_IWGRP) ? 'w' : '-';
	buf[5] = (mode & S_IXGRP) ? 'x' : '-';
	buf[6] = (mode & S_IROTH) ? 'r' : '-';
	buf[7] = (mode & S_IWOTH) ? 'w' : '-';
	buf[8] = (mode & S_IXOTH) ? 'x' : '-';
	buf[9] = '\0';
	printf("%s\n", buf);
}

void			inspect_file(const char *path)
{
	struct stat	file_stat;

	if (stat(path, &file_stat) < 0)
		printf("err stat\n");
	printf("Type: %s", (file_stat.st_mode & S_IFDIR) ? "d"\
			: (file_stat.st_mode & S_IFLNK) ? "l"\
			: (file_stat.st_mode & S_IFREG) ? "-"\
			: (file_stat.st_mode & S_IFSOCK) ? "s" : "?");
	list_perm(file_stat.st_mode);
}

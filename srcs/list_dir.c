/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:23:14 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/06 13:42:15 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				push(t_dir **head, char name[256])
{
	t_dir			*new_node;
   
	if ((new_node = malloc(sizeof(t_dir))) == NULL)
		printf("err");
	strcpy(new_node->name, name); // HERE
	new_node->next = *head;
	*head = new_node;
}

void				print_list(t_dir *head)
{
	t_dir			*current;

	current = head;
	while (current != NULL)
	{
		printf("%s\n", current->name);
		current = current->next;
	}
}

void				sort_list_alpha(t_dir *head)
{
	t_dir			*current;
	char			tmp[256];

	current = head;
	while (current->next)
	{
		if (strcmp(current->name, current->next->name) > 0)
		{
			tmp[0] = '\0';
			strcpy(tmp, current->name);
			strcpy(current->name, current->next->name);
			strcpy(current->next->name, tmp);
			current = head;
		}
		else
			current = current->next;
	}
}

void				list_dir(const char *file_name)
{
	DIR				*dir;
	struct dirent	*sdir;
	t_dir			*name_list;

	name_list = NULL;
	if ((dir = opendir(file_name)) == NULL)
		printf("ERROR openning the file !\n");
	while ((sdir = readdir(dir)) != NULL)
	{
		if (sdir->d_name[0] != '.')
		{
			push(&name_list, sdir->d_name);
		}
	}
	sort_list_alpha(name_list);
	print_list(name_list);
	(void)closedir(dir);
}

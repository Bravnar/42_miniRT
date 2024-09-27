/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:04 by smuravye          #+#    #+#             */
/*   Updated: 2023/11/03 18:05:15 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	found_new_line(t_gnl *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	count_until_nl(t_gnl *list)
{
	int	i;
	int	length;

	if (!list)
		return (0);
	length = 0;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
			{
				length++;
				return (length);
			}
			i++;
			length++;
		}
		list = list->next;
	}
	return (length);
}

t_gnl	*gnl_last(t_gnl *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	node_string_to_result(t_gnl *list, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->line[i])
		{
			if (list->line[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->line[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	clean_all(t_gnl **list, t_gnl *node_continued, char *leftover)
{
	t_gnl	*current;

	if (!list)
		return ;
	while (*list)
	{
		current = (*list)->next;
		free((*list)->line);
		free(*list);
		*list = current;
	}
	if (!node_continued && !leftover)
		return ;
	*list = NULL;
	if (node_continued->line[0])
		*list = node_continued;
	else
	{
		free(leftover);
		free(node_continued);
	}
}

/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*s3;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i++] = s2[j];
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
 */

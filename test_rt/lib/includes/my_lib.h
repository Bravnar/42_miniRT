/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:16:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/31 10:15:57 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "garbage.h"

/* ************************************************************************** */
/*                        ARR UTILS FUNCTIONS                                 */
/* ************************************************************************** */

int		strarr_len(char **arr);
char	**arr_insert(char **arr, int pos, char *elem);
char	**strarr_pop(char **arr, int index);

/* ************************************************************************** */
/*                          CONVERTER FUNCTIONS                               */
/* ************************************************************************** */

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strtoupper(char *str);

/* ************************************************************************** */
/*                          GET NEXT LINE                                     */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	char			*line;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
void	buf_to_node(t_gnl **list, int fd);
int		found_new_line(t_gnl *list);
void	extend_list(t_gnl	**list, char *buffer);
t_gnl	*gnl_last(t_gnl *lst);
char	*parse_result_line(t_gnl *list);
int		count_until_nl(t_gnl *list);
void	node_string_to_result(t_gnl *list, char *str);
void	cleanup_list(t_gnl **list);
void	clean_all(t_gnl **list, t_gnl *node_continued, char *leftover);

/* ************************************************************************** */
/*                          IS FUNCTIONS                                      */
/* ************************************************************************** */

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_strisalpha(char *str);

/* ************************************************************************** */
/*                          LINKED LIST FUNCTIONS                             */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
/*                          MEMORY FUNCTIONS                                  */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	ft_free_arr(char **arr);

/* ************************************************************************** */
/*                          MY PRINTF                                         */
/* ************************************************************************** */

int		ft_printf(const char *str, ...);
int		ft_fprintf(int fd, const char *str, ...);
int		print_s(const char *str, int fd);
int		print_x(unsigned int n, int fd, const char token);
int		print_id(int n, int fd);
int		print_p(unsigned long long n, int fd);
int		print_u(unsigned int n, int fd);
int		token_converter(va_list args, const char token, int fd);

/* ************************************************************************** */
/*                          PUT FUNCTIONS                                     */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_megasplit(char *str, char *charset);
char	*ft_better_join(char *s1, char *s2, int free_);
char	*ft_superstrchr(char *s, char *chars);
int		ft_arr_len(char **split);

#endif

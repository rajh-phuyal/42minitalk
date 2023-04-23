/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:15:19 by rphuyal           #+#    #+#             */
/*   Updated: 2022/12/29 19:44:18 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define HEXMIN "0123456789abcdef"
# define HEXMAX "0123456789ABCDEF"
# define DECIMAL "0123456789"

/* if the buffersize is not manully defined during compilation*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>

/* 
structure for nodes to contain a content pointer 
an a link to the next node
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* functions that handel individual chars*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int ch);
int		ft_tolower(int ch);

/* functions that puts number, chars, or strings in a given fd*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* functions that handel memory operations*/
int		ft_memcmp(const void *m1, const void *m2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);

/* functions that manipulate, concatiante, compare, etc with strings*/
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* functions for linked list operations */
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


/* prototypes for printf */
int		ft_putcharprintf(char c);
int		get_hex_len(unsigned long long n);
int		ft_printf(const char *str, ...);
char	*ft_getintstr(long n);
char	*ft_gethexstr(unsigned long long num, char *base);
int		ft_putstr(char *str);
char	*ft_strrev(char *str);

/* function prototypes for getnextline*/
void	clear_buffer(char *buffer);
size_t	getuntilnl(char *str);
int		create_line(char **line_ptr, char *buffer, size_t size);
int		manage_buffer(char *buffer);
char	*get_next_line(int fd);

#endif 

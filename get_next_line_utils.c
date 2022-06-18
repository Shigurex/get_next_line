/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:47:01 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/27 14:49:32 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (!s[i])
			break ;
		i++;
	}
	return (NULL);
}

static size_t	ft_malloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
		return (1);
	else if (s_len + 1 < start + len)
		return (s_len - start + 1);
	else
		return (len + 1);
}

char	*ft_substr_size_t(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*substring;

	if (s == NULL)
		return (NULL);
	substring = malloc(sizeof(char) * ft_malloc_size(s, start, len));
	if (substring == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		substring[0] = '\0';
		return (substring);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*full_script;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	full_script = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (full_script == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		full_script[i] = ((char *)s1)[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		full_script[i] = ((char *)s2)[i - len_s1];
		i++;
	}
	full_script[i] = '\0';
	return (full_script);
}

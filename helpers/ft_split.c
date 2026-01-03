/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:20:44 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 17:28:56 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static size_t	ft_strcount(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static char	*ft_allocate(const char *s, char c, size_t index)
{
	char	*ptr;
	size_t	counter;

	counter = 0 ;
	while (s[index] == c)
		index++;
	while (s[index] && s[index] != c)
	{
		index++;
		counter++;
	}
	ptr = malloc((counter + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*ft_fill(const char *s, char c, size_t	*index)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_allocate(s, c, *index);
	if (!ptr)
		return (NULL);
	while (s[*index] == c)
		(*index)++;
	while (s[*index] && s[*index] != c)
	{
		ptr[i++] = s[*index];
		(*index)++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**ft_free(char **ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	strings;
	char	**ptr;

	i = 0;
	strings = 0;
	index = 0;
	if (s == NULL )
		return (NULL);
	strings = ft_strcount(s, c);
	ptr = malloc((strings + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < strings)
	{
		ptr[i] = ft_fill(s, c, &index);
		if (!ptr[i])
			return (ft_free(ptr, i));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

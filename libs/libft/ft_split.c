/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:27:19 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/05 19:53:39 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**free_table(char **table, int i)
{
	while (i >= 0)
	{
		free(table[i]);
		i--;
	}
	free(table);
	return (NULL);
}

char	**split(char **table, const char *s, char c, size_t size_word)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				size_word = ft_strlen(s);
			else
				size_word = ft_strchr(s, c) - s;
			table[i] = ft_substr(s, 0, size_word);
			if (!table[i])
				return (free_table(table, i - 1));
			s += size_word;
			i++;
		}
	}
	table[i] = NULL;
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	size_word;

	if (!s)
		return (NULL);
	table = (char **)malloc((sizeof(char *) * (ft_count_words(s, c) + 1)));
	if (!table)
		return (NULL);
	size_word = 0;
	table = split(table, s, c, size_word);
	return (table);
}

/*
int	main(void)
{
	char		**table;
	char const	*str;
	char		c;
	int			len_str;
	int			i;

	str = "Lorem Ipsum has been the ";
	c = ' ';
	len_str = ft_strlen(str);
	table = ft_split(str, c);
	//table = ft_split(str, c);
	//table = NULL;
	//table = ft_split("hello!", 32);
	i = 0;
	while (table[i])
	{
		printf("%s\n", table[i]);
		free(table[i]);
		i++;
	}
	free(table);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:19:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static void	ft_free(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		word_len;
	int		i;
	int		s_i;

	buffer = (char **)ft_calloc(sizeof(char *), (ft_count_words(s, c) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	s_i = 0;
	while (i < ft_count_words(s, c))
	{
		while (s[s_i] == c)
			s_i++;
		word_len = ft_word_len(&s[s_i], c);
		buffer[i] = ft_substr(s, s_i, word_len);
		if (!buffer[i])
		{
			ft_free(buffer);
			return (NULL);
		}
		i++;
		s_i += word_len;
	}
	return (buffer);
}

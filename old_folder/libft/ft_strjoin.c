/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:44:53 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/04 20:56:04 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*res;

	if (s1 == 0)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		++j;
	}
	res[i + j] = '\0';
	return (res);
}

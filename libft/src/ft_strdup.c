/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:19:31 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/25 17:44:50 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*buffer;

	size = ft_strlen(s1);
	buffer = malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_strcpy(buffer, (char *)s1);
	return (buffer);
}

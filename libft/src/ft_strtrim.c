/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:07:06 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 11:55:38 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				j = 0;
			}
			else
				j++;
		}
		return (i);
	}
	return (i);
}

static int	check_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (s1[i] != 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i--;
				j = 0;
			}
			else
				j++;
		}
		return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	int		start;
	int		end;
	int		len;
	int		i;

	i = 0;
	start = check_start(s1, set);
	end = check_end(s1, set);
	len = end - start + 1;
	if (len < 0)
		len = 0;
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (start + i <= end)
	{
		buffer[i] = s1[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/*
int	main()
{

	size_t count = 5;
    size_t size = sizeof(int);

 	void *ptr1 = ft_calloc(count, size);
    void *ptr2 = calloc(count, size);

    if (ptr1 == NULL || ptr2 == NULL) {
        printf("Memory allocation failed\n");
    }

    if (memcmp(ptr1, ptr2, count * size) == 0) {
        printf("Memory content is identical\n");
    } else {
        printf("Memory content differs\n");
    }
    free(ptr1);
    free(ptr2);

  return 0;
}*/

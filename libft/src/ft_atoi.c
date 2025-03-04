/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:42:57 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/03 10:19:55 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	new_num;

	i = 0;
	negative = 1;
	new_num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = negative * -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((new_num == 214748364) && (str[i] == '8') && (negative == -1))
			return (-2147483648);
		new_num = (new_num * 10) + (str[i] - '0');
		i++;
	}
	return (new_num * negative);
}
/*
int main(void) {

  char str[] = "  \n --1234ab567";
  int orig_atoi = atoi(str);
  printf ("orig %d \n", orig_atoi);

  int el_atoi = ft_atoi(str);
  printf ("FT %d \n", el_atoi);

  return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_addition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:42 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/09 00:22:58 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

size_t	binarylen(int32_t num)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num >>= 1;
		len++;
	}
	return (len);
}

char	*binary_add(unsigned a, unsigned b, char *binary)
{
	int32_t	num;
	size_t	len;
	size_t	i;

	i = 0;
	num = a + b;
	len = binarylen(num);
	printf("len: %zu\n", len);
	binary[len] = '\0';
	while (len--)
	{
		if ((num >> i & 1) == 1)
			binary[len] = '1';
		else
			binary[len] = '0';
		i++;
	}
	return (binary);
}

int32_t	main(void)
{
	char	test[8];

	printf("%s", binary_add(100, 0, test));
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:40:42 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/08 22:21:57 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*DuplicateEncoder(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*out;

	i = 0;
	j = 0;
	len = strlen(str);
	out = calloc(len + 1, sizeof(char));
	while (str[j])
	{
		while (str[i])
		{
			if ((str[j] == str[i] || str[j] == str[i] + ('a' - 'A') || \
				str[j] == str[i] - ('a' - 'A')) && j != i)
			{
				out[j] = ')';
				break ;
			}
			i++;
		}
		if (!out[j])
			out[j] = '(';
	i = 0;
	j++;
	}
	return (out);
}

int32_t	main(void)
{
	printf("test: %s\n", DuplicateEncoder("Prespecialized"));
	printf("test: )()())()(()()(");
	return (EXIT_SUCCESS);
}

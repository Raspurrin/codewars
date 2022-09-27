/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:34:55 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/08 22:41:19 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*repeat_str(size_t count, const char *src)
{
	char	*out;
	size_t	j;
	size_t	i;
	size_t	len;

	i = 0;
	j = 0;
	len = strlen(src);
	out = malloc(((len * count) * sizeof(char)) + 1);
	while (j < count * len)
	{
		while (i < len)
			out[j++] = src[i++];
		i = 0;
	}
	out[j] = '\0';
	return (out);
}

int32_t	main(void)
{
	printf("test: %s", repeat_str(3, "hello"));
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringincrementer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 03:24:59 by mialbert          #+#    #+#             */
/*   Updated: 2022/09/27 21:40:16 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

size_t	intlen(int32_t nbr)
{
	size_t	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int32_t nbr)
{
	char	*out;
	size_t	i;

	i = intlen(nbr);
	out = malloc(i + 1 * sizeof(char));
	if (nbr == 0)
		out[0] = '0';
	else if (nbr < 0)
	{
		out[0] = '-';
		nbr = abs(nbr);
	}
	out[i--] = '\0';
	while (nbr > 0)
	{
		out[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (out);
}

char	*strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*out;
	size_t	len;

	i = 0;
	j = 0;
	len = strlen(str1) + strlen(str2);
	out = calloc(len + 1, sizeof(char));
	while (str1[i])
	{
		out[i] = str1[i];
		i++;
	}
	while (str2[j])
		out[i++] = str2[j++];
	return (out);
}

char	*incrementstring(const char *str)
{
	size_t	i;
	int32_t	nbr;
	size_t	len;
	char	*out;
	char	*substr;

	i = 0;
	len = 0;
	len = strlen(str);
	while (isalpha(str[i]))
		i++;
	if (!str[i])
		return (strjoin((char *)str, "1"));
	if (!atoi(str + i))
		return ((char *)str);
	nbr = atoi(str + i);
	substr = malloc(len - intlen(nbr));
	nbr++;
	if (intlen(nbr) > intlen(nbr - 1))
		len++;
	out = malloc(len * sizeof(char) + 1);
	return (strjoin(strncpy(substr, str, len - intlen(nbr)), \
	ft_itoa(nbr)));
}

int32_t	main(void)
{
	printf("%s\n", incrementstring("foobar23"));
	printf("%s\n", incrementstring("foobar000"));
	printf("%s\n", incrementstring("foobar999"));
	printf("%s\n", incrementstring("foobar001"));
	printf("%s\n", incrementstring("foo33bar34"));
	printf("%s\n", incrementstring("foobar99"));
	printf("%s\n", incrementstring("foobar0099"));
	printf("%s\n", incrementstring("foo"));
	printf("%s\n", incrementstring("1"));
	return (EXIT_SUCCESS);
}

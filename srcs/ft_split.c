/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:21:09 by timothee          #+#    #+#             */
/*   Updated: 2024/12/28 15:58:23 by timothee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sep(char str, char sep);
int count_world(char *str, char sep);

char **ft_split(char *str, char sep)
{
	int i;
	int j;
	int k;
	char **result;

	result = malloc(sizeof(char *) * (count_world(str, sep) + 1));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep))
		{
			j = 0;
			result[k] = malloc(10000);
			while (str[i] && !is_sep(str[i], sep))
				result[k][j++] = str[i++];
			result[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	result[k] = 0;
	return (result);
}

int count_world(char *str, char sep)
{
	int compteur;
	int i;
	int result;

	result = 0;
	i = 0;
	compteur = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep) && compteur == 0)
		{
			result += 1;
			compteur = 1;
		}
		else if (is_sep(str[i], sep) && compteur == 1)
			compteur = 0;
		i++;
	}
	return (result);
}

int is_sep(char str, char sep)
{
	if (str != sep)
		return (0);
	return (1);
}

// void	printf_tab(char **str)
// {
// 	int i = 0;
// 	while (str[i])
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// }

// int main()
// {
// 	char *str = "plage l coucouc caca     ";
// 	char **string;
// 	string = ft_split(str, ' ');
// 	printf_tab(string);
// 	for (int i = 0;i < count_world(str, ' ');i++)
// 		free (string[i]);
// 	free (string);
// 	return (0);
// }
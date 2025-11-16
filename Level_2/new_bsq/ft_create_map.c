/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:35:23 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/12 00:05:57 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static bool		ft_isnumber(char *str)
{
	while (*str)
	{
		// If it doesn't contain numbers returns 0
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	// If it has a number returns true
	return (1);
}

int				ft_map_header(t_map *map, FILE *file)
{
	char	*line;
	size_t	len;
	char	*ptr;
	int		i;
	char	num_str[32];
	int		j;
	
	// Read the first line using getline
	line = NULL;
	len = 0;
	if (getline(&line, &len, file) == -1)
	{
		if (line) free(line);
		return (1);
	}
	
	// Parse the line: number empty obstacle full
	ptr = line;
	
	// Skip leading whitespace
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	
	// Extract number
	i = 0;
	while (ptr[i] >= '0' && ptr[i] <= '9')
		i++;
	if (i == 0)
	{
		free(line);
		return (1);
	}
	
	j = 0;
	while (j < i && j < 31)
	{
		num_str[j] = ptr[j];
		j++;
	}
	num_str[j] = '\0';
	
	if (!ft_isnumber(num_str))
	{
		free(line);
		return (1);
	}
	
	map->rows = ft_atoi(num_str);
	if (map->rows <= 0)
	{
		free(line);
		return (1);
	}
	
	// Move past number and whitespace
	ptr += i;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	
	// Get empty character
	if (!*ptr || *ptr == '\n')
	{
		free(line);
		return (1);
	}
	map->empty = *ptr++;
	
	// Skip whitespace
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	
	// Get obstacle character
	if (!*ptr || *ptr == '\n')
	{
		free(line);
		return (1);
	}
	map->obstacle = *ptr++;
	
	// Skip whitespace
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	
	// Get full character
	if (!*ptr || *ptr == '\n')
	{
		free(line);
		return (1);
	}
	map->full = *ptr++;
	
	// Skip whitespace and check for newline (handle both \r\n and \n)
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (*ptr == '\r')
		ptr++;
	if (*ptr != '\n' && *ptr != '\0')
	{
		free(line);
		return (1);
	}
	
	// Debug
	fprintf(stderr, "header ok rows=%d empty=%c obstacle=%c full=%c\n", map->rows, map->empty, map->obstacle, map->full);
	
	// Validate that characters are different
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
	{
		free(line);
		return (1);
	}
	
	free(line);
	return (0);
}

t_map	*ft_create_map(char *file_name)
{
	t_map	*map;
	FILE	*file;

	// If it receives the parameter as Stdin
	if (!ft_strcmp(file_name, "STDIN"))
		// File receives what is typed at the terminal
		file = stdin;
	// Otherwise it receives the file in reading mode
	else
		file = fopen(file_name, "r");

	// If it can't open the file returns the error message
	if (file == NULL)
		return (ft_map_error());

	// makes memory allocation
	map = (t_map *)malloc(sizeof(t_map));

	// If it has any error in the map header Free memory and prints the error message
	// otherwise stores the header values on the list
	if (ft_map_header(map, file))
	{
		free(map);
		if (file != stdin) fclose(file);
		return (ft_map_error());
	}

	if (ft_get_matrix(map, file))
	{
		fprintf(stderr, "matrix error after header. rows=%d cols=%d\n", map->rows, map->cols);
		ft_free_map(map);
		if (file != stdin) fclose(file);
		return (ft_map_error());
	}

	// Closes the file
	if (file != stdin) fclose(file);
	map->square_size = 0;
	return (map);
}

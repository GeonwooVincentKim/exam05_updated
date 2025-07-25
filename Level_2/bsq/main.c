#include "bsq.h"

	ssize_t		map_array = 0;	
	char		empty = 0;
	char		obstacle = 0;
	char		full = 0;


// clear && gcc -g main.c bsq.c bsq.h && cat bsq_test_maps/map_valid_1.txt | valgrind --leak-check=full --show-leak-kinds=all ./a.out
// clear && gcc -g main.c bsq.c bsq.h && valgrind --leak-check=full --show-leak-kinds=all ./a.out bsq_test_maps/map_valid_1.txt

void	free_map(char **map)
{
	ssize_t		array = 0;

	while (map[array])
		free(map[array++]);
	free(map);
}

bool	firstline_checker(char *line, ssize_t nread)
{
	(void)nread; // Suppress unused parameter warning
	ssize_t		index = 0;

	//First
	while (line[index])
	{
		if (line[index] == ' ')
		{
			if (index == 0)
				return (false);
			break ;
		}
		else if (line[index] == '\n')
			return (false);
		else if (line[index] < '0' || line[index] > '9')
			return (false);

		map_array = (map_array * 10) + line[index] - '0';
		index++;
	}
	while (line[index] == ' ')
		index++;
	if (line[index] == '\n')
		return (false);
	fprintf(stdout, "[number]--> %li\n", map_array);

	while (line[index] && line[index] != '\n')
	{
		if (empty == 0)
			empty = line[index];
		else if (obstacle == 0)
		{
			obstacle = line[index];
			if (empty == obstacle)
				return (false);
		}
		else if (full == 0)
		{
			full = line[index];
			if (empty == full || obstacle == full)
				return (false);
		}
		if (line[++index] != ' ' && line[index] != '\n')
		{
			printf("I have returned false hee!\n");
			return (false);
		}
		while (line[index] == ' ')
				index++;
	}
	fprintf(stdout, "[line] %c\n", empty);
	fprintf(stdout, "[line] %c\n", obstacle);
	fprintf(stdout, "[line] %c\n", full);
	if (!empty || !obstacle || !full)
		return (false);
	return (true);
}

int		main(int argc, char ** argv)
{

	//scenarios
	//	1) less than 2 args
	//	2) more than or equal 2 args
	if (argc < 2)
	{
		char	*line = NULL;
		size_t	len = 0;
		ssize_t	nread;

		if ((nread = getline(&line, &len, stdin)) != -1)
		{
			//getline(&line, &len, stdin);
			fprintf(stdout, "[Line] %s\n", line);
			fprintf(stdout, "nread = %zd\n", nread);

			if (nread > 0 && line)
			{
				if (firstline_checker(line, nread))
				{
					printf("first_line test correct!!! Time to do some working!\n");
				}
			}
		}
		else
			return (1);
		if (line)
		{
			free(line);
			line = NULL;
			len = 0;
		}

		char	**map = (char **)calloc(map_array + 1, sizeof(char *));
		size_t	array = 0;
		size_t	index = 0;

		while ((nread = getline(&line, &len, stdin)) != -1 && array < (size_t)map_array)
		{
			fprintf(stdout, "%s\n", line);
			map[array] = (char *)calloc(len + 1, sizeof(char));
			index = 0;
			while (index < len)
			{
				map[array][index] = line[index];
				index++;
			}
			map[array][index] = '\0';
			array++;

			free(line);
			line = NULL;
			len = 0;
		}
		map[array] = NULL;
		// file now must be able to read from stdin and check the if map is valid
		// ft_bsq_from_stdin()

		if (line)
			free(line);

		if (map)
			free_map(map);
	}
	else //(argc >= 2)
		ft_bsq(argv);
	return (0);
} 
#include "pipex.h"

static int ft_free_split(char **sp_str, int kdx)
{
	while (kdx >= 0)
		free(sp_str[kdx--]);
	free(sp_str);
	return (0);
}

static int	ft_counter(char *s, char c)
{
	int		counter;
	size_t	idx;

	idx = -1;
	counter = 0;
	while (++idx < ft_strlen(s))
	{
		counter += (s[idx] != c && idx == 0);
		counter += (idx && s[idx] != c && s[idx - 1] == c);
	}
	return (counter);
}

static int	ft_allocate(char *s, char c, char **sp_str)
{
	int	idx;
	int	jdx;
	int	kdx;

	idx = 0;
	kdx = 0;
	while (s[idx])
	{
		jdx = 0;
		while (s[idx] == c)
			idx++;
		while (s[idx] && s[idx] != c)
		{
			idx++;
			jdx++;
		}
		if (jdx > 0)
			sp_str[kdx] = malloc(sizeof(char) * (jdx + 1));
		if (jdx > 0 && !sp_str[kdx])
			return (ft_free_split(sp_str, kdx));
		kdx++;
	}
	return (1);
}

char	**ft_assign(char *s, char c, char **sp_str)
{
	int		idx;
	int		jdx;
	int		kdx;

	idx = 0;
	jdx = 0;
	while (s[idx])
	{
		kdx = 0;
		while (s[idx] == c)
			idx++;
		while (s[idx] && s[idx] != c)
			sp_str[jdx][kdx++] = s[idx++];
		if (kdx > 0)
			sp_str[jdx++][kdx] = '\0';
	}
	sp_str[jdx] = NULL;
	return (sp_str);
}

char	**ft_split(char *s, char c)
{
	char	**sp_str;

	if (!s)
		return (NULL);
	sp_str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (sp_str && ft_allocate(s, c, sp_str) != 0)
		return (ft_assign(s, c, sp_str));
	return (NULL);
}
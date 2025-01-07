#include "pipex.h"

size_t  ft_strlen(const char *s)
{
    size_t  len;

    if (*s == '\0' || s == NULL)
        return 0;
    len = 0;
    while (s[len])
        len++;
    return (len);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    int     i;
    int     j;

    if (!s1 && !s2)
        return NULL;
    // if (!s1)
    //     return (ft_strdup(s2));
    // if (!s2)
    //     return (ft_strdup(s1));
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    i = -1;
    while(s1[++i])
        str[i] = s1[i];
    j = 0;
    while(s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}

char    *ft_strdup(const char *s)
{
    char    *str;
    int     i;

    i = -1;
    str = malloc(ft_strlen(s) + 1);
    if (!str)
        return (NULL);
    while (s[++i])
        str[i] = s[i];
    str[i] = '\0';
    return(str);
}

int ft_free(char **sp_str)
{
    int i;

    i = 0;
	while (sp_str[i])
		free(sp_str[i++]);
	free(sp_str);
	return (1);
}

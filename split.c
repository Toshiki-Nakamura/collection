#include <stdlib.h>
#include <stdio.h>

char	**free_set(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		free(s[i++]);
	free(s);
	return (NULL);
}

int	word_cnt(char *s, char sep)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			cnt++;
		i++;
	}
	return (cnt);
}

char	*word_set(int start, char *s, char sep)
{
	int		i;
	int		len;
	char	*str;

	i = start;
	len = 0;
	while (s[i] != sep && s[i])
	{
		len++;
		i++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	len = 0;
	while (s[i] != sep && s[i])
		str[len++] = s[i++];
	str[len] = '\0';
	return (str);
}

char	**split(char *s, char sep)
{
	int		i;
	int		j;
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (word_cnt(s, sep) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
		{
			new[j++] = word_set(i, s, sep);
			if (new[j - 1] == NULL)
				return (free_set(new));
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}

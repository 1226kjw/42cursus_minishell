#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

void	free_all(char **strs);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspdigit(char *str);
void	err_msg(char *str);
int		ft_numlen(int ret);

#endif

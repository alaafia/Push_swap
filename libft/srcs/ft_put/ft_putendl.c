#include "libft.h"

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

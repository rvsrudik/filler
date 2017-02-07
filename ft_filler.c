
#include "filler.h"

static char *ft_read_out()
{
	int		ret;
	char	*buff;
	char	*tmp;
	char	*out;

	tmp = NULL;
	buff = NULL;
	buff = ft_strnew(BUFF_SIZE);
	tmp  = ft_strnew(0);
	ret = 0;
	while ((ret = read(0, buff, 20)))
	{
		buff[ret] = '\0';
		out = ft_strjoin(tmp, buff);
		if (tmp)
			ft_strdel(&tmp);
		tmp = out;
		if (buff)
			ft_strdel(&buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	return (out);
}

int main(void)
{
	char		*out;
	t_filler	*params;

	params = (t_filler*)malloc(sizeof(*params));
	out = ft_read_out();
	ft_determ_param(params, out);
	ft_determ_borders(params);
	ft_print_params(params);

	return (0);
}
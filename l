	t_opt	*new;
	t_flags	flags;
	char	*av_now;
	size_t	len;
	size_t	i;

	av_now = av[now];
	new = NULL;
	len = ft_strlen(av_now);
	i = 0;
	while (++i < len)
	{
		if (av_now[i] == 's')
		{
			if (i < len - 1)
				new = new_opt(flags, get_string(&av_now[i + 1]));
			else
				new = new_opt(flags, get_string(av[now + 1]));
			break ;
		}
		else if (av_now[i] == 'p')
		{
			new = new_opt(flags, get_data(0, NULL));
			break ;
		}
		else if (av_now[i] == 'q')
			flags = (t_flags){.r = 0, .q = 1};
		else if (av_now[i] == 'r' && flags.q == 0)
			flags.r = 1;
	}
	if (new == NULL)
		new = new_opt(flags, get_data(open_fd(av[now + 1]), av[now + 1]));
	return (new);

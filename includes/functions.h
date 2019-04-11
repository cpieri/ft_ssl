/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:44:05 by cpieri            #+#    #+#             */
/*   Updated: 2019/04/11 17:33:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*
**	Functions for Parsing
*/
t_parse				parsing(const int ac, char **av);
t_opt				*hash_opts(const int ac, char **av, t_opt *opts, int now);
t_opt				*base64_opts(const int ac, char **av, t_opt *opts, int now);
int					open_fd(const char *file);
t_data				*get_data(const int fd, const char *fd_name);
t_data				*get_file(const int fd, const char *fd_name);
t_data				*get_string(char *s);

/*
**	Functions for Lst_opt
*/
t_opt				*new_opt(t_flags flags, t_data *data);
void				add_to_end_lst(t_opt *new, t_opt **lst);
void				print_lst(t_opt **lst);

/*
**	Functions for Hashing msg and display final hash
*/
void				hashing(t_parse *parse);
void				printing_hash(t_data *data, const char *hash_type,
		t_flags flags);

/*
**	Functions for Exit, Clean, Error
*/
void				exit_error(void);
void				exit_error_free(void **to_free);
void				print_error(const char *msg_1);
void				print_usage(const int usage_int, const char *command);
void				clean_prog(t_parse *parse);

#endif

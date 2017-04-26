/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:50:31 by jerasmus          #+#    #+#             */
/*   Updated: 2017/01/10 10:16:40 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef unix

#  include <wait.h>

# endif

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>

# define BUF_SIZE 	1024

typedef struct	s_var
{
	char		*line;
	char		*eexit;
	char		*home;
	char		*cd_path;
	char		*old;
	char		*pwd;
	char		**args;
	char		**path;
	char		cwd[512];
	char		**env;
	char		**origin_env;
}				t_var;

char			*ft_getline(void);
void			ft_freeargs(t_var *v);
void			ft_exit(t_var *v);
int				ft_echo(t_var *v);
char			*ft_getenv(const char *name, t_var *v);
void			ft_loop(t_var *v);
void			ft_dquote(char *str);
void			ft_squote(char *str);
int				ft_countq(char *str);
int				ft_count_arr(char **arr);
char			*ft_argsjoin(char **args);
void			ft_cd(t_var *v);
void			ft_env(t_var *v);
int				ft_setenv(const char *name, const char *value,
		int overwrite, t_var *v);
int				ft_unsetenv(const char *name, t_var *v);
void			ft_freearr(char **arr);
int				ft_fork(t_var *v);
void			ft_freetmp(char *str);

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA 	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define RESET   	"\x1b[0m"

#endif

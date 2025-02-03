/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:36:56 by zzetoun           #+#    #+#             */
/*   Updated: 2025/01/11 19:36:56 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "str_uti.h"
# include "pipe_pars.h"
# include "pipe_uti.h"
# include "freedom.h"

# define EARGS "error: invalid arguments"
# define EUNKN "error: unknown error"
# define ECFND "error: command not found"
# define ENOENT "error: no such file or directory"



#endif
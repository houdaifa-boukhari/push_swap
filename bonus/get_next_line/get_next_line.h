/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:49:04 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/16 00:50:58 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_management(int fd, char **temp, char *buffer);
char	*get_next_line(int fd);
int		strlen_(char *str);
char	*strjoin(char *str, char *str1);
char	*update(char *str);
char	*last_word(char *str);
int		check_line(char *str);
char	*ft_strdup(char *str);

#endif
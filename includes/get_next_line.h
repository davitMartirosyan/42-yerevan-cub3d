/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:27:36 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/06 12:06:19 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strchr_(const char *buffer, int ch);
char	*join(char *s1, char *s2);
char	*after(char *buffer);
char	*before(char *buffer);
#endif

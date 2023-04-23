/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:14:00 by rphuyal           #+#    #+#             */
/*   Updated: 2023/04/23 20:13:35 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

void	encode_and_send_sig(pid_t server_pid, int s_time, int c);
void	send_message(pid_t server_pid, char *message);
void	decode_and_print_char(int sig, siginfo_t *info, void *context);

#endif
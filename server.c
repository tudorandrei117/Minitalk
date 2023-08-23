/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:31:59 by tburlacu          #+#    #+#             */
/*   Updated: 2023/08/23 03:14:58 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
	{
		i |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

void	setup_signal_handling(void)
{
	struct sigaction	signal;

	signal.sa_sigaction = ft_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
}

void	start_server(void)
{
	ft_printf("\033[34mThis is your PID %d\n Use it in the client file\n",
		getpid());
	ft_printf("\033[33mWaiting for your message..\n");
	while (1)
	{
		pause();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("Error\nFormat: %s\n", argv[0]);
		return (0);
	}
	setup_signal_handling();
	start_server();
	return (0);
}

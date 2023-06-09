/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:41:39 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/07/04 13:23:29 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

bool Socket::initSocket()
{
	int opt = 1;
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (this->sockfd == -1)
	{
		logg(LOG_ERROR) << "Socket creation failed.\n";
		return false;
	}
	lenaddr = sizeof(sockaddr_in);

	// Clear memory buffers and address
	bzero(&addr, sizeof(addr));
	bzero(buff_tx, buff_size);
	bzero(buff_rx, buff_size);

	addr.sin_family = AF_INET;

	if (setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0)
	{
		logg(LOG_ERROR) << "Failed setsockopt.\n";
		exit(EXIT_FAILURE);
	}
	if (fcntl(this->sockfd, F_SETFL, O_NONBLOCK) < 0)
	{
		logg(LOG_ERROR) << "Failed fcntl.\n";
		exit(EXIT_FAILURE);
	}
	return true;
}

Socket::Socket()
{
	if (!this->initSocket())
		exit(EXIT_FAILURE);
}

Socket::Socket(const uint16_t port)
{
	if (!this->initSocket())
		exit(EXIT_FAILURE);

	// Setting server socket structure
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons((uint16_t)(port));
	logg(LOG_DEBUG) << "Socket successfully created\n";
}

Socket::~Socket()
{
	close(this->sockfd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:04 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/05 16:22:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <list>

#include "User.hpp"
#include "Channel.hpp"
#include "ListUsers.hpp"
#include "ListChannels.hpp"

#include "CommandHandler.hpp"
#include "IRCServer.hpp"
#include "Message.hpp"
// #include <string>
#include <optional>

// socket libs
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <netdb.h>
#include <ctime>
#include <cstring> //needed for linux
#include <fcntl.h>

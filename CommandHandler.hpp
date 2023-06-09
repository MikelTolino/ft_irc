/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:43:37 by mmateo-t          #+#    #+#             */
/*   Updated: 2023/06/23 11:17:29 by mmateo-t         ###   ########.fr       */
/*   Updated: 2023/06/26 16:20:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP
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
#include "IRCServer.hpp"
#include "Message.hpp"
#include "Reply.hpp"

class User;
class ListUsers;
class ListChannels;
class ResultCmd;
class Message;
class Reply;
class IRCServer;

class CommandHandler
{
private:
	IRCServer *server;
	ListUsers *_listUsers;
	ListChannels *_listChannels;
	User *_sender;
	Message _msg;
	int _firstTimeFlag;

	typedef void (CommandHandler::*CommandFunction)(std::list<std::string>, std::list<Reply> &); // Define the function pointer type
	std::map<std::string, CommandFunction> commandMap;

	void initCommandMap();

public:
	CommandHandler(IRCServer *server, ListUsers *listUsers, ListChannels *listChannels);
	~CommandHandler();
	void executeCmd(std::list<Reply> &);
	ListUsers *getUsers();
	Message getMessage() const;
	void setMessage(const Message &msg);
	void setUser(const int fd);
	std::list<std::string> parseList(const std::string &);

	std::string getPrefix(const User *) const;
	bool sendAsyncMessage(int fd, std::string prefix, std::string msg);

	// Command functions
	void oper(std::list<std::string> params, std::list<Reply> &replies);
	void kill(std::list<std::string> params, std::list<Reply> &replies);
	void nick(std::list<std::string> params, std::list<Reply> &);
	void user(std::list<std::string> params, std::list<Reply> &);
	void quit(std::list<std::string> params, std::list<Reply> &);
	void privmsg(std::list<std::string> params, std::list<Reply> &replies);
	void notice(std::list<std::string> params, std::list<Reply> &replies);
	void cap(std::list<std::string> params, std::list<Reply> &replies);
	void ping(std::list<std::string> params, std::list<Reply> &replies);
	void pong(std::list<std::string> params, std::list<Reply> &replies);
	void join(std::list<std::string> params, std::list<Reply> &replies);
	void part(std::list<std::string> params, std::list<Reply> &replies);
	void pass(std::list<std::string> params, std::list<Reply> &replies);
	void kick(std::list<std::string> params, std::list<Reply> &replies);
	void invite(std::list<std::string> params, std::list<Reply> &replies);
	void topic(std::list<std::string> params, std::list<Reply> &replies);
	void mode(std::list<std::string> params, std::list<Reply> &replies);
	void error(const std::string reason, const int fd);

};

#endif

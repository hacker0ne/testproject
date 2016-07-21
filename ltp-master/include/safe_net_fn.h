/*
 * Copyright (c) 2016 Cyril Hrubis <chrubis@suse.cz>
 * Copyright (c) 2015 Fujitsu Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SAFE_NET_FN_H__
#define SAFE_NET_FN_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

char *tst_sock_addr(const struct sockaddr *sa, socklen_t salen, char *res,
		    size_t len);

int safe_socket(const char *file, const int lineno, void (cleanup_fn)(void),
		int domain, int type, int protocol);

int safe_bind(const char *file, const int lineno, void (cleanup_fn)(void),
	      int socket, const struct sockaddr *address,
	      socklen_t address_len);

int safe_listen(const char *file, const int lineno, void (cleanup_fn)(void),
		int socket, int backlog);

int safe_connect(const char *file, const int lineno, void (cleanup_fn)(void),
		 int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int safe_getsockname(const char *file, const int lineno,
		     void (cleanup_fn)(void), int sockfd, struct sockaddr *addr,
		     socklen_t *addrlen);

#endif /* SAFE_NET_FN_H__ */

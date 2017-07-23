/*
 * Copyright (C) 2017 Joerg-Christian Boehme
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _INCLUDE__HELLO_WORLD__CLIENT_H_
#define _INCLUDE__HELLO_WORLD__CLIENT_H_

#include <hello_world_session/hello_session.h>
#include <base/rpc_client.h>
#include <base/log.h>

namespace helloworld { struct Session_client; }


struct helloworld::Session_client : Genode::Rpc_client<Session>
{
	Session_client(Genode::Capability<Session> cap)
	: Genode::Rpc_client<Session>(cap) { }

	void say_hello()
	{
		Genode::log("issue RPC for saying hello");
		call<Rpc_say_hello>();
		Genode::log("returned from 'say_hello' RPC call");
	}

	int add(int a, int b)
	{
		return call<Rpc_add>(a, b);
	}
};

#endif /* _INCLUDE__HELLO_WORLD__CLIENT_H_ */

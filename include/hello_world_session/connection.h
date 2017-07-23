/*
 * Copyright (C) 2017 Joerg-Christian Boehme
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */


#ifndef _INCLUDE__HELLO_WORLD__CONNECTION_H_
#define _INCLUDE__HELLO_WORLD__CONNECTION_H_

#include <hello_world_session/client.h>
#include <base/connection.h>

namespace helloworld { struct Connection; }


struct helloworld::Connection : Genode::Connection<Session>, Session_client
{
	Connection(Genode::Env &env)
	:
		/* create session */
		Genode::Connection<helloworld::Session>(env, session(env.parent(),
		                                                "ram_quota=6K")),

		/* initialize RPC interface */
		Session_client(cap()) { }
};

#endif /* _INCLUDE__HELLO_WORLD__CONNECTION_H_ */

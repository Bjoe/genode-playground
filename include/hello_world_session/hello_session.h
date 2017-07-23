/*
 * Copyright (C) 2017 Joerg-Christian Boehme
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */


#ifndef _INCLUDE__HELLO_WORLD__HELLO_SESSION_H_
#define _INCLUDE__HELLO_WORLD__HELLO_SESSION_H_

#include <session/session.h>
#include <base/rpc.h>

namespace helloworld { struct Session; }


struct helloworld::Session : Genode::Session
{
	static const char *service_name() { return "Hello"; }

    enum { CAP_QUOTA = 2 };

	virtual void say_hello() = 0;
	virtual int add(int a, int b) = 0;


	/*******************
	 ** RPC interface **
	 *******************/

	GENODE_RPC(Rpc_say_hello, void, say_hello);
	GENODE_RPC(Rpc_add, int, add, int, int);

	GENODE_RPC_INTERFACE(Rpc_say_hello, Rpc_add);
};

#endif /* _INCLUDE__HELLO_WORLD__HELLO_SESSION_H_ */

/*
 * Copyright (C) 2017 Joerg-Christian Boehme
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <base/component.h>
#include <base/log.h>
#include <base/heap.h>
#include <root/component.h>
#include <hello_world_session/hello_session.h>
#include <base/rpc_server.h>

namespace helloworld {
	struct Session_component;
	class Root_component;
	struct Main;
}


struct helloworld::Session_component : Genode::Rpc_object<Session>
{
	void say_hello() {
		Genode::log("I am here... Hello."); }

	int add(int a, int b) {
		return a + b; }
};


class helloworld::Root_component
:
	public Genode::Root_component<Session_component>
{
	protected:

		Session_component *_create_session(const char *args)
		{
			Genode::log("creating hello session");
			return new (md_alloc()) Session_component();
		}

	public:

		Root_component(Genode::Entrypoint &ep,
		               Genode::Allocator &alloc)
		:
			Genode::Root_component<Session_component>(ep, alloc)
		{
			Genode::log("creating root component");
		}
};


struct helloworld::Main
{
	Genode::Env &env;

	/*
	 * A sliced heap is used for allocating session objects - thereby we
	 * can release objects separately.
	 */
	Genode::Sliced_heap sliced_heap { env.ram(), env.rm() };

        helloworld::Root_component root { env.ep(), sliced_heap };

	Main(Genode::Env &env) : env(env)
	{
		/*
		 * Create a RPC object capability for the root interface and
		 * announce the service to our parent.
		 */
		env.parent().announce(env.ep().manage(root));
	}
};


void Component::construct(Genode::Env &env)
{
	Genode::Ram_session& ramSession = env.ram();
    Genode::Ram_quota available = ramSession.avail_ram();
	Genode::log("Available RAM: ", available);

    Genode::Ram_quota quota = ramSession.ram_quota();
	Genode::log("Quota RAM: ", quota);

    Genode::Ram_quota used = ramSession.used_ram();
	Genode::log("Used RAM: ", used);

	const char* ramName = ramSession.service_name();
	Genode::log("RAM service name: ", ramName);

        static helloworld::Main main(env);
}

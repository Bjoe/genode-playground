/*
 * Copyright (C) 2017 Joerg-Christian Boehme
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <base/attached_rom_dataspace.h>
#include <base/component.h>
#include <base/log.h>
#include <base/env.h>
#include <base/stdint.h>
#include <util/xml_node.h>
#include <region_map/region_map.h>
#include <ram_session/ram_session.h>
#include <cpu_session/cpu_session.h>
#include <pd_session/pd_session.h>
#include <timer_session/connection.h>
#include <hello_world_session/connection.h>

class Timeout
{
  Genode::Env &env_;
  Timer::Connection myTimer_ { env_ };
  Genode::Signal_handler<Timeout> signalHandler { env_.ep(), *this, &Timeout::handle };

public:
  Timeout(Genode::Env &env) : env_(env)
  {
	myTimer_.sigh(signalHandler);
	Genode::log("register two-seconds timeout...");
	myTimer_.trigger_periodic(2*1000*1000);
  }

  void handle()
  {
	Genode::log("Time out");
  }
};


class Main
{
  Genode::Env &env_;
  Timeout timeout_ { env_ };

  Genode::Attached_rom_dataspace config_ { env_, "config" };

public:
  Main(Genode::Env &env) : env_(env)
  {}
};

void Component::construct(Genode::Env &env)
{
  Genode::Ram_session& ramSession = env.ram();
  Genode::Cap_quota cap = ramSession.cap_quota();
  Genode::log("Cap quota: ", cap);


  Genode::Ram_quota available = ramSession.avail_ram();
  Genode::log("Available RAM: ", available);

  Genode::Ram_quota quota = ramSession.ram_quota();
  Genode::log("Quota RAM: ", quota);

  Genode::Ram_quota used = ramSession.used_ram();
  Genode::log("Used RAM: ", used);

  const char* ramName = ramSession.service_name();
  Genode::log("RAM service name: ", ramName);

  Genode::Cpu_session& cpuSession = env.cpu();

  Genode::Pd_session& pdSession = env.pd();
  const char* pdName = pdSession.service_name();

  Genode::Capability<Genode::Region_map> addressSpace = pdSession.address_space();
  //Genode::String<128> o;
  //addressSpace.print(o);

  Genode::Capability<Genode::Region_map> stackArea = pdSession.stack_area();
  //stackArea.print(o);

  Genode::Capability<Genode::Region_map> linkerArea = pdSession.linker_area();
  //linkerArea.print(o);

  //Genode::log("pdSession: ", o);

  Genode::Region_map& regionMapSession = env.rm();

  helloworld::Connection hello(env);

  Genode::log("Available RAM: ", ramSession.avail_ram());
  Genode::log("Quota RAM: ", ramSession.ram_quota());
  Genode::log("Used RAM: ", ramSession.used_ram());

  //Genode::Xml_node node = config_.xml();
  //node.print();

  hello.say_hello();

  int const sum = hello.add(2, 5);
  Genode::log("added 2 + 5 = ", sum);

  Genode::log("hello test ...");

  static Main main(env);
}

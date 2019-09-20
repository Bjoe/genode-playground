#include <libc/component.h>
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

void testFunction()
{
  //boost::thread::id tid = boost::this_thread::get_id();
  Genode::log("Thread started.....");
}

void Libc::Component::construct(Libc::Env&)
{
  Genode::log("Start boost.thread test....");
  boost::thread t(testFunction);
  Genode::log("boost.thread is created");
  t.join();
  Genode::log("boost.thread test ended.");

  boost::asio::io_service io;
  Genode::log("boost.asio Create io_service.");
  boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
  Genode::log("boost.asio We wait 5 sec.");
  timer.wait();
  Genode::log("boost.asio 5 sec are over.");

  Genode::log("boost tests are done.");
}

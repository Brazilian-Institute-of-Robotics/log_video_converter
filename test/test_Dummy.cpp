#include <boost/test/unit_test.hpp>
#include <log2video/Dummy.hpp>

using namespace log2video;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    log2video::DummyClass dummy;
    dummy.welcome();
}

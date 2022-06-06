/**
 * author : dhan71@naver.com
 */

#include <sys/time.h>
#include <stop_watch.h>

/**
 * default ctor
 */
stop_watch::stop_watch()
{
  start();
  _stop.tv_sec = _start.tv_sec;
  _stop.tv_usec = _start.tv_usec;
}
/**
 * dtor
 */
stop_watch::~stop_watch()
{
}

/**
 * start watch
 */
void
stop_watch::start()
{
  gettimeofday(&_start, nullptr);
}
/**
 * stop watch
 */
void
stop_watch::stop()
{
  gettimeofday(&_stop, nullptr);
}

/**
 * return the elapsed seconds from the started time
 */
long
stop_watch::get_elapsed_seconds()
{
  stop();
  return _stop.tv_sec - _start.tv_sec;
}
/**
 * return the elapsed microseconds from the started time
 */
long
stop_watch::get_elapsed_useconds()
{
  stop();
  return (_stop.tv_sec * 1E6) + _stop.tv_usec - (_start.tv_sec * 1E6) - _start.tv_usec;
}

/**
 * return the elapsed seconds.microseconds time from the started time
 */
double
stop_watch::get_elapsed_time()
{
  long usec = get_elapsed_useconds();
  return 1.0 * usec / 1E6;
}


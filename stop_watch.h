/**
 * author : dhan71@naver.com
 */
#pragma once

struct timeval;

class stop_watch
{
public:
  /**
   * default ctor
   */
  stop_watch();
  /**
    * dtor
    */
  virtual ~stop_watch();

public:
  /**
   * start watch
   */
  void start();

protected:
  /**
   * stop watch
   */
  void stop();

public:
  /**
   * return the elapsed seconds from the start time
   */
  long get_elapsed_seconds();
  /**
   * return the elapsed microseconds from the start time
   */
  long get_elapsed_useconds();

  /**
   * return the elapsed seconds.microseconds time from the start time
   */
  double get_elapsed_time();

protected:
  /** start time */
  struct timeval _start;
  /** stop time */
  struct timeval _stop;
};


#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include <iostream>
#include <chrono>
#include <stop_watch.h>
#include <unistd.h>
using namespace std;


class Tests : public CppUnit::TestFixture
{
public:
  void setUp()
  {
    //cout << "Tests::setUp called" << endl;
  }
  void tearDown()
  {
    //cout << "Tests::tearDown called" << endl;
  }

  void title(const char* h)
  {
    cout << "-------------------\n"
         << h << "\n"
         << "--------------------\n";
  }

public:
  void test_ctor1()
  {
    title("Tests::test_ctor1 called");
    stop_watch w;
    CPPUNIT_ASSERT(0 == w.get_elapsed_time());
  }

  void test_get_time_1()
  {
    title("Tests::test_get_time_1 called");
    stop_watch w;
    sleep(1);
    double t = w.get_elapsed_time();
    cout << " elapsed time = " << t << endl;

    CPPUNIT_ASSERT(0.999 < t && t < 1.001);
  }
  void test_get_time_2()
  {
    title("Tests::test_get_time_2 called");
    
    stop_watch w;
    sleep(2);
    double t = w.get_elapsed_time();
    cout << " elapsed time = " << t << endl;

    CPPUNIT_ASSERT(1.999 < t && t < 2.001);
  }
  void test_get_time_n()
  {
    title("Tests::test_get_time_n called");
    
    auto start = std::chrono::high_resolution_clock::now();
    stop_watch w;
    sleep(2);
    double t = w.get_elapsed_time();
    long ms = w.get_elapsed_useconds();
    auto end = std::chrono::high_resolution_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << " elapsed time = " << t << endl;
    cout << " elapsed micro seconds = " << ms << endl;
    cout << " elapsed duration = " << d.count() << endl;

    CPPUNIT_ASSERT(1.999 < t && t < 2.001);
  }
    
public:
  static CppUnit::Test* suite()
  {
    CppUnit::TestSuite* s = new CppUnit::TestSuite(" Test Test ");

    s->addTest(new CppUnit::TestCaller<Tests>("test_get_time_1", &Tests::test_get_time_1));
    s->addTest(new CppUnit::TestCaller<Tests>("test_get_time_2", &Tests::test_get_time_2));
    s->addTest(new CppUnit::TestCaller<Tests>("test_get_time_n", &Tests::test_get_time_n));

    return s;
  }
};

int
main()//int argc, char* argv[])
{
  CppUnit::TextTestRunner r;
  r.addTest(Tests::suite());
  r.run();
  return 0;
}


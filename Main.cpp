#include "TestHarness.h"
#include <iostream>
#include "WidgetCalculations.h""

int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));
  WidgetCalculations data("WidgetData.txt");

  //Output the report
  std::stringstream os;
  data.streamReport(os);
  std::cout << os.str();

  TestResult tr;
  TestRegistry::runAllTests(tr);

  return 0;
}

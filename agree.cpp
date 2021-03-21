#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "system.h"
#include "executor.h"

using namespace std;

/** Entity responsible for starting the system and reading the commands entered.
 * 
 * @return int 
 */
int main() {
  System system;
  Executor executor(system);
  
  executor.start(cin, cout);

  return 0;
}
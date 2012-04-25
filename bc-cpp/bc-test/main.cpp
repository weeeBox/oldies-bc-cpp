//
//  main.c
//  UnitTesting
//
//  Created by Alex Lementuev on 3/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "tut.hpp"
#include "tut_reporter.h"

using std::exception;
using std::cerr;
using std::endl;

namespace tut
{
    test_runner_singleton runner;
}

int main()
{
    tut::reporter reporter;
    tut::runner.get().set_callback(&reporter);
    
    tut::runner.get().run_tests();

	system("pause");
    return !reporter.all_ok();
}

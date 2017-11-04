/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#include "test.h"
#include <bx/thread.h>

int32_t threadExit0(bx::Thread* _thread, void*)
{
	BX_UNUSED(_thread);

	return bx::kExitSuccess;
}

int32_t threadExit1(bx::Thread* _thread, void*)
{
	BX_UNUSED(_thread);

	return bx::kExitFailure;
}

TEST_CASE("thread", "")
{
	bx::Thread th;

	REQUIRE(!th.isRunning() );

	th.init(threadExit0);
	REQUIRE(th.isRunning() );
	th.shutdown();

	REQUIRE(!th.isRunning() );
	REQUIRE(th.getExitCode() == 0);

	th.init(threadExit1);
	REQUIRE(th.isRunning() );
	th.shutdown();

	REQUIRE(!th.isRunning() );
	REQUIRE(th.getExitCode() == 1);
}

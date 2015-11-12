#include "CppUTest/TestHarness.h"
#include "mem.h"

TEST_GROUP(Basic)
{
};

TEST(Basic, check_memory_mgmt)
{
	void *p = mem_alloc(10);
	CHECK(p != NULL);

	mem_free(p);

	p = mem_calloc(10, 10);
	CHECK(p != NULL);

	mem_free(p);

	p = NULL;
	mem_free(p);
}

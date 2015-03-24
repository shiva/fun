#include "CppUTest/TestHarness.h"

#include "Object.h"

TEST_GROUP(OOC)
{
    void setup()
    {
    }

    void teardown() 
    {
    }
};

static int Any_differ(const void* _self, const void *b)
{
	return 0; /* Any equals anything */
}


TEST(OOC, SimpleAdditionTest)
{
	void *o = create(Object);
	const void *Any = create(Class, "Any", Object, sizeof(o), differ, Any_differ, 0);
	void *a = create(Any);
    CHECK(o);
    CHECK(Any);
    CHECK(a);

    /*
	puto(Any, stdout);
	puto(o, stdout);
	puto(a, stdout);

	CHECK(differ(o, o) == differ(a,a));
	if (differ(o, o) == differ(a,a))
		puts("ok");

	CHECK(differ(o, a) != differ(a, o));
	if (differ(o, a) != differ(a, o))
		puts("not commutative");

	destroy(o), destroy(a);
	destroy((void *) Any);
    CHECK(!o);
    CHECK(!a);
    CHECK(!Any);
    */
}


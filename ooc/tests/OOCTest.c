#include <stdio.h>
#include "CUnit/Basic.h" 
#include "Object.h"

static int Any_differ(const void* _self, const void *b)
{
	return 0; /* Any equals anything */
}

void simpleTest(void) {
	void *o = new(Object);
	const void *Any = new(Class, "Any", Object, sizeof(o), differ, Any_differ, 0);
	void *a = new(Any);

	puto(Any, stdout);
	puto(o, stdout);
	puto(a, stdout);

	if (differ(o, o) == differ(a,a))
		puts("ok");

	if (differ(o, a) != differ(a, o))
		puts("not commutative");

	delete(o), delete(a);
	delete((void *) Any);
}

int main (int argc, char** argv) {
 
    CU_pSuite pSuite = NULL;
 
        /* initialize the CUnit test registry */ 
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
 
   /* add a suite to the registry */ 
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }
 
   /* add the tests to the suite */ 
   if (NULL == CU_add_test(pSuite, "Simple Addition Test", simpleTest)) {
      CU_cleanup_registry();
      return CU_get_error();
   }
 
   /* Run all tests using the CUnit Basic interface */ 
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(Basic);
IMPORT_TEST_GROUP(LinkedList);

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

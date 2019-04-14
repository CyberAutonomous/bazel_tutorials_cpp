#include "test1.h"
#include "calc.h"

int main()
{
test_level1();
int i = 2;
printf("i value before:%d\n", i);
calculate(&i);
printf("i value after:%d\n", i);
return 1;
}

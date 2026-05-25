// STATIC USE CASE 1, 2 (C LANG)

static int num = 100;   // FILE OR TRANSLATION UNIT WIDE GLOBAL VARIABLE 
static void test(void);    // FILE OR TRANSLATION UNIT WIDE GLOBAL FUNCTION 

int x;  // PROJECT WIDE GLOBAL VARIABLE, WILL REQUIRE EXTERN TYPE DECLARATION BEFORE USING IN OTHER FILES OF PROJECT 
void test2(void); // PROJECT WIDE GLOBAL FUNCTION , WILL REQUIRE EXTERN TYPE DECLARATION BEFORE USING IN OTHER FILES OF PROJECT 

// STATIC USE CASE 3 (C LANG)

void test(void)
{
    int x; // dynamic, per function call, stack, function call lifetime 
    static int y = 100; // static, once, data, program lifetime 
    static int z; // static, once, bss, program lifetime 
}


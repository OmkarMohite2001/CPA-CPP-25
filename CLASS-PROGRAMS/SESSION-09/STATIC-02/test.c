int globalNum = 500; 

void test(void)
{
    int localNum; 
    static int firstLocalStatic = 100; 
    static int secondLocalStatic; 

    firstLocalStatic = 500; 
    secondLocalStatic = 100; 
}

int main(void)
{
    return (0); 
}
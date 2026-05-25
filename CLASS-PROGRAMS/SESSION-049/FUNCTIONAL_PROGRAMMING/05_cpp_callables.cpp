//  CPP Callables: 
//  What is a CPP callable? Any entity which is compatible with call operator ! 
/* 
    STAGE 1: 
        Named Function provided by procedural programming. 
        void myFunction(formal_parameter_list)
        {
        
        }

        You can put a call operator around myFunction() 

    STAGE 2: 
        Call operator overloading in C++ 98. 
        
        class C
        {
            public: 
                operator()(formal_parameter_list)
                {
                
                }
        }; 

        objC = C(data)
        return_val = objC(actual_parameter_list); 

    <INSIGHT : Rest of the callables are internally callable object>

    STAGE 3: 
        Lambda expression provided by C++ 11 

        auto result = [capture_list](format_parameter_list)->return_type 
                    {
                        // BODY 
                        return object; 
                    }(actual_parameter_list); 
        
        OR 

        auto f = [capture_list](format_parameter_list)->return_type 
                {
                    // BODY 
                    return object; 
                } 
        
        result = f(actual_parameter_list)

    STAGE 4: 
        std::function<Tr(formal_parameter_list)> functionObject(initializationFunction); 

        initializationFunction should have the prototype Tr(formal_parameter_list) 

        Tr result = functionObject(actual_parameter_list); 

    STAGE 5: 
        class C
        {
            private: 
                // data 
            public: 
                C operator+(const C& other) const 
                {   
                    //  Logic of adding this and other 
                    return result; 
                }
        };

        std::plus<C> addC; 

        C obj1(init_data), obj2(init_data);
        
        C result = addC(obj1, obj2); 
*/
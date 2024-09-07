
#define f std::formate
#define var auto
typedef std::map<std::string_view,std::string_view> dict


import std;

var __main__ = [] {

    print( f("Hello {}!\n", "world") )
    println("{0:s} {2:s}{1:s}!\n", "Hello", 23, "WhichLang");

    dict cnt = {
        {"Name","AAA"},
        {"Score",1145},
        {"ID",1919}
    }
    for(var [value,type]:cnt)
        println(value + " " + type);
    
    return 0;
}();





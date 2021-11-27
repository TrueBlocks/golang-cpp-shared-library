typedef struct MyNewClass MyNewClass;
typedef struct MyCClass MyCClass;

struct MyCClass {
    int kk;
    int gg;
    int ff;
};

struct MyNewClass {
    int bar;
    int foo;
    MyCClass c;
};
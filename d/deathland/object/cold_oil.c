

#include "../echobomber.h"

inherit OBJECT;

void create()
{
    set_name("Cold oil","�䶳��");
    add("id",({"oil",}));
    set_short("a cold oil","�䶳��");
    set_long("a cold oil, you can apply it.\n",
             "�䶳��,�������������Ϳ(apply)������.\n");
    set("weight",1);
    set("no_sale",1);
    set("value",({ 1,"copper"}) );
    set("applied",0);
}

void init()
{
     add_action("to_apply","apply");
}

int to_apply(string str)
{
    
    if (!id(str)) return 0;
    
    set("applied",1);
    set("prevent_drop",1);
    set("extra_look","$N seems apply some special thing");
    set("c_extra_look","$N�����ƺ�Ϳ��һ������Ķ���.\n");
    set("invisible",1);
    write("�����Ϳ������.\n"); 
    return 1;
}

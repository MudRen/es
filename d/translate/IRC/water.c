// This is a drink in IRC pub
// water.c
// Elon@Eastern.Stories Sat  08-20-94
 
inherit "/u/e/elon/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("water","ˮ");
    set_short("water","�׿�ˮ");
    set_long("A cup of clear liquid -- water.\n",
    "һ���׿�ˮ.\n");
    set("unit","��");  // ƿ, ��, ��, ��(?)
    set("e_unit","cup"); // can, bottle, cup, bag(?)
 
    set("recycle",1);
    set("value",({10,"silver"}));
 
    set("tp",10);
}

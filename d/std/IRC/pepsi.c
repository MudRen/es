// This is an example file..
// pepsi.c, unit is can (��װ)
// Elon@Eastern.Stories Mon  08-01-94
 
inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("pepsi","���¿���");
    set_short("Pepsi Cola","���¿���");
    set_long("Pepsi, Uh-Huh!\n",
    "�������İ��¿���.\n");
    set("unit","��");  // ƿ, ��, ��, ��(?)
    set("e_unit","can"); // can, bottle, cup, bag(?)
    set("value",({45,"silver"}));
    set("tp",45);
}

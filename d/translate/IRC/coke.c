// This is an example file..
// coke.c basic setup for drink.. use as little set's as possible
// Elon@Eastern.Stories Mon  08-01-94
 
inherit "/d/translate/tmp/drink.c";
 
void create()
{
    ::create();
    seteuid(getuid());
    set_name("coke","����");
    set_short("Coca Cola","�ɿڿ���");
    set_long("Gotta have a Coke!\n",
    "�ɿڿ���, ��һƿ��!\n");
    set("tp",50);
}

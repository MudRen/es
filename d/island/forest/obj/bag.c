#include <mudlib.h>

inherit CONTAINER;

void create()
{
    ::create();
    set_name("Small Bag","����С����");
    add("id",({ "bag" }) );
    set_short("����С����");
    set_c_open_long("����һ��ð�ռҰ��õ�С������������װ���ٶ���Ŷ��\n");
    set("weight",10);
    set("weight_apply",60);
    set("max_load",200  );
    set("value",({100,"silver"}) );
    set("prevent_insert",1);
    set("prevent_put_money",1);
}
    
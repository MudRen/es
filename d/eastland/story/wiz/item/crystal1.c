#include <mudlib.h>
inherit OBJECT;
void create()     
{
        set_name( "crystal glass", "ˮ��������" );
	add("id",({"glass"}));
	set_long(@LONG
һ�ž�Ө��͸��ˮ�����������ө������ʹ������ʱ�ںڰ��з���Щ΢�׹⡣	
LONG
        );	
	set_short("ˮ��������");
	set( "unit", "��" );
	set("weight", 40);
	set("value", ({ 100, "silver" }));
        set("light",1);
        call_out("disappear",1800,this_object());
}
void disappear(object ob)
{
    object owner;
    owner=environment(this_object());
    if (!owner)
       printf("���ˮ�����ϵ�ө������ҵ�����Ĵ���ʧȥ������...��\n");
    remove();
}

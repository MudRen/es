#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Thorny sword", "��������" );
        add( "id",({ "sword", "longsword" }) );
        set_long(@LONG
����һ����ɫ��ڵĳ�����������������̣������е���һ��ʹ�������ɡ�
LONG
        );
        set_short( "��������" );
        set( "unit", "��");
	set( "weapon_class", 40 );
        set( "type", "longblade" );
	set( "min_damage", 17 );
        set( "max_damage", 40 );
        set( "nosecond",1);
        set( "weight", 210 );
        set( "value", ({ 10, "silver" }) );
        set( "bleeding",20);
}



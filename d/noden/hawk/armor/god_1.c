#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Diamond Ring","ά��˹����" );
        add( "id", ({ "ring","diamond ring" }) );
	set_short( "ά��˹����" );
        set_long(
                "����ϣ������ά��˹�Ľ�ָ����������İ������˼���޽��еġ�\n"
        );
        set( "unit", "ֻ" );
	set("material","adv");
        set( "type", "finger" );
        set( "armor_class",0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}

#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Jupiter armband","������ڽ�ۻ�" );
        add( "id", ({ "armband","jupiter armband" }) );
        set_short( "������ڽ�ۻ�" );
        set_long(
                "������������Ƶ�����ۻ�, �ڽ���Ǽ��亱�еĲ��ϡ�\n"
        );
        set( "unit", "ֻ" );
        set("material","thief");
        set( "type", "arms" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 4700, "silver" }) );
}

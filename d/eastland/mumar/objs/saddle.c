#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name( "golden saddle", "��ɫ��" );
        add( "id", ({ "saddle" }) );
        set_short( "��ɫ��" );
        set_long(
        "����һ����ɫ��Ƥ��������������������������硣\n"
        );
        set( "type", "saddle" );
        set( "material", "leather" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 320, "silver" }) );
}

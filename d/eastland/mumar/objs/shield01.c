#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("square shield","�ط���");
        add("id",({"shield"}) );
        set_short("�ط���");
        set_long(
"����һ�淽�εĶܣ����滭���˻�����ͼ�Ρ�\n"
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "value", ({ 1500 , "silver" }) );
}

#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Fire-Cloud war armor","����ս��");
        add("id",({"armor"}) );
        set_short( "a red-shining armor","����ս��");
        set_long(
"This is a red, shining war armor which is sparkling wiht little fire.\n",
"����һ�����ɫ��ս�ף���ʱ��ҫ��СС�Ļ𻨡�\n"
        );
        set( "unit", "��" );
        set( "weight",180 );
        set( "type", "body" );
        set( "armor_class", 31 );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "value", ({ 300, "gold" }) );
        set( "special_defense", ([ "none": 10,"cold":30 ]) );
}
#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Thunder Cloak", "�׵�����");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "�׵�����");
        set_long(@AAA
����һ�������׵羫������������
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 5);
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["electric":5])) ;
	set( "weight", 15 );
        set( "value", ({ 500, "silver" }) );
}

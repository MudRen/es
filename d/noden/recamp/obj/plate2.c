#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Turtle plate", "����ս��");
        add( "id", ({ "plate" }) );
        set_short("Turtle plate", "����ս��");
        set_long(@AAA
����һ���������״�����ɣ��Եĺ������ȡ�
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 40 );
        set( "defense_bonus", 10 );
        set("material","stone");
        set("special_defense",(["fire":5,"cold":15])) ;
        set( "weight", 500 );
        set( "value", ({ 1000, "silver" }) );
}

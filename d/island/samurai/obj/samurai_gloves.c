#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_gloves ", "��ʿ���� ");
        add( "id", ({ "gloves" }) );
        set_short("samurai_gloves ", "��ʿ���� ");
        set_long(@AAA
һ����ʿ�Ǵ������ϵķ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 70 );
        set( "value", ({ 500, "silver" }) );
}

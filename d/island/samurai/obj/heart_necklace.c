#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "heart necklace","��������");
        add( "id", ({ "necklace","amulet","heart" }) );
        set_short("heart necklace","��������");
        set_long(@AAA
һ����������,�� �� ˵������Ů�������Ķ���֮��
AAA
        );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","element");
        set( "weight", 50 );
        set( "value", ({ 1000, "silver" }) );
}

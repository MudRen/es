#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Red scarf", "��ɫΧ��");
        add( "id", ({ "scarf"}) );
        set_short("Red scarf", "��ɫΧ��");
        set_long(@AAA
����һ����ɫ��Χ�������߼Ӷ����ذ��õ�Χ����˵
���ȿ�������֯������
AAA
        );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set("material","cloth");
        set("special_defense",([ "fire" : 20 ]));
        set( "weight", 20 );
        set( "value",({ 660, "silver" }) );
}

#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Cloak", "��ѩ����");
        add( "id", ({ "snow","cloak" }) );
        set_short("Snow Cloak", "��ѩ����");
        set_long(@AAA
����һ��ѩ��ɫ�����磬���ø߼�˿�����������ϻ��֯�ɵģ����ṩ��
���ߵķ�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 1200, "silver" }) );
}

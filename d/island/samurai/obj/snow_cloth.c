#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Clothes", "��ѩ����");
        add( "id", ({ "snow","clothes" }) );
        set_short("Snow Clothes", "��ѩ����");
        set_long(@AAA
����һ��ѩ��ɫ�ĳ��ۣ����ø߼�˿�����������ϻ��֯�ɵģ����ṩ��
���ߵķ��������������ӵı߽ǻ����к�ɫ�Ĵ��ӣ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 6 );
        set("material","cloth");
        set("special_defense",(["cold":-15,"fire":15]));
        set( "weight", 90 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver" }) );
}

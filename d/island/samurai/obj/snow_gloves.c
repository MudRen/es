#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Gloves", "��ѩ����");
        add( "id", ({ "snow","gloves" }) );
        set_short("Snow Gloves", "��ѩ����");
        set_long(@AAA
����һ��ѩ��ɫ�����ף����ø߼�˿�����������ϻ��֯�ɵģ����ṩ��
���ߵķ���������
AAA
        );
        set( "unit", "��"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 980, "silver" }) );
}

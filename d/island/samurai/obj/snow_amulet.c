#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Amulet", "��ѩ����");
        add( "id", ({ "snow","amulet" }) );
        set_short("Snow Amulet", "��ѩ����");
        set_long(@AAA
����һ��ѩ��ɫ�Ļ���������ϸ���ѩ֮�����ף��
AAA
        );
        set( "unit", "��"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":10]));
        set( "weight", 10 );
        set( "no_sale",1);
        set( "value", ({ 880, "silver" }) );
}

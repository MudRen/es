#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "black vest","��ɫս��");
        add( "id", ({ "vest" }) );
        set_short( "black vest","��ɫս��" );
        set_long(@AAA
һ����ɫ��ս��,�����ؽ������Ƴɵ�,���Էǳ�����,������ͨ�˿����õķ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 24 );
        set( "defense_bonus", 5 );
        set("material","heavy_metal");
        set("special_defense",(["fire":10 ,"evil":10]));
        set( "weight", 270 );
        set( "value", ({ 1200, "silver" }) );
}

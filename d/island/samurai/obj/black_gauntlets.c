#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "black gauntlets","��ɫ����");
        add( "id", ({ "gauntlets" }) );
        set_short("black gauntlets","��ɫ����" );
        set_long(@AAA
һ����ɫ�Ļ���,�����ؽ������Ƴɵ�,���Էǳ�����,������ͨ�˿����õķ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","heavy_metal");
        set( "weight", 100 );
        set( "value", ({ 650, "silver" }) );
}

#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "white_headband", "��ͷ��");
        add( "id", ({ "headband","white" }) );
        set_short("white_headband", "��ͷ��");
        set_long(@AAA
һ����ɫ��ͷ��,���滹��һ�ɺ���ζ
AAA
        );
        set( "unit", "��"); 
        set( "type", "head" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 30 );
        set( "value", ({ 300, "silver" }) );
}

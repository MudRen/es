#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "a_shu_la_chainmail", "������֮��");
        add( "id", ({ "chainmail" }) );
        set_short("a_shu_la_chainmail", "������֮��");
        set_long(@AAA
������ʿ�ӳ�Լ�޼Ҵ������� �����Ͽ���һ�����������ͼ��
�������˸е�һ��ŨŨ��ɱ��
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 4 );
        set("material","heavy_metal");
        set( "weight", 250 );
        set( "value", ({ 1200, "silver" }) );
}

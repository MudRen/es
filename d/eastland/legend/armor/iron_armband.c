#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("iron armband", "����ͨ��");
        add( "id", ({"armband", }) );
        set_short("����ͨ��");
        set_long(@C_LONG
���ί�ж�����½������ʦ������æұ�������置���õ���һ�������󣬶�����
��������������������������Ƿ��Ļ��ߣ��������е�����ͨ�ۡ�        
C_LONG
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "material","heavy_metal" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}

#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper plate", "��ͭ����" );
        add( "id", ({ "plate" }) );
        set_short( "��ͭ����");
        set_long(
@C_LONG
��������ͭ������ĺ������ף������׵ı��沢��ӡ��֩��ļǺ�
�����Ǻڰ�������ʿ��ϲ���ķ��ߣ�����Ч�ı����������ܵ��˵�
������
C_LONG
        );
        set( "unit", "��");
        set( "type", "body" );
        set( "material", "heavy_metal" );
        set( "armor_class", 16 );
        set( "defense_bonus", 4 );
        set( "special_defense",
        ([ "fire" : 12, "cold" : -8 ]) );
        set( "weight", 200 );
        set( "value", ({ 970, "silver" }) );
}

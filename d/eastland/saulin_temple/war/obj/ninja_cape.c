
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja cape", "��������" );
        add( "id", ({ "cape" }) );
        set_short( "��������" );
        set_long(@C_LONG
����һ����ɫ�����磬�����и�ʽ������ֵ��Բʻ��ơ������
��˵�е����� �� �������ıر�������
C_LONG
        );
        set( "unit", "��" );
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 4);
        set( "weight", 70 );
	set( "special_defense", ([ "evil":5,"divine":-7 ]) );
        set( "value", ({ 1200, "silver" }) );
}


#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "evil katana", "����" );
        set_short( "������������" );
        set_long(@C_LONG
����һ�ѳ�����ʿ����ѩ���ĵ���ɢ��������ĺ�⣬�ഫ
��ѵ��Ѿ�������ϲ�����������Ѫ�������������ǵС�
C_LONG
        );
        set( "unit", "��" );
        set( "type", "longblade" );
        set( "weight", 90 );
        set( "weapon_class", 36 );
	set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "bleeding", 10 );
        set( "value", ({ 2700, "silver" }) );
}

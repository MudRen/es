#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("axe", "���츫");
	add( "id", ({ "axe" }) );
	set_short("An axe", "���츫");
	set_long(@AA
��Ѹ�ͷ�����������ֵĻ��ƣ������������õ���ͷ���ۻ���������
ת��¶��������������
AA
	);
	set( "unit", "��" );
	set( "weight", 250 );
	set( "weapon_class",37);
	set( "min_damage",21);
	set( "max_damage",41);
	set( "type","axe");
        set( "bleeding", 10 );
	set( "value", ({ 980, "silver" }) );
}

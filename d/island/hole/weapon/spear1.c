#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Black Spear","��ɫ��ì" );
	add( "id",({ "spear" }) );
	set_short( "��ɫ��ì" );
	set_long(@LONG
	���ǰ���ͨ�ĳ�ì���䲻�����������������
	����������
LONG
	);
	set( "unit","��" );
	set( "type","thrusting" );
	set( "weapon_class",28 );
	set( "min_damage",20 );
	set( "max_damage",30 );
	set( "weight",200 );
	set( "value",({ 1000,"silver" }) );
}
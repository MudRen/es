#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire cloak", "������" );
	add( "id", ({ "fire","cloak" }) );
	set_short( "fire cloak", "������" );
	set_long(@C_LONG
	һ���ǳ����ص����磬�������ޣ���ɢ�����������������춺���ϵ
	�Ĺ���������ķ���������
C_LONG
	);
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 6 );
	set( "defense_bonus", 7 );
	set( "special_defense",
          ([ "cold":10 ]) ) ;
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
}

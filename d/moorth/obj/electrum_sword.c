#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "electrum sword", "��⽣" );
	add( "id", ({ "short sword", "sword" }) );
   set_short( "��⽣" );
	set_long(
             "����һ����Ĭ��˹����������������ɵĶ���, ��ɫ�ĵ���������\n"
             "͸����˿���ƵĹ�â��\n"
	);
	set( "unit", "��" );
	set( "type", "shortblade" );
   set( "weight", 72 );
   set( "second", 1 );
   set( "weapon_class", 35 );
   set( "min_damage", 19 );
   set( "max_damage", 30 );
   set( "value", ({ 999, "silver" }) );
}

#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "Fun-Tain Halberd","����ս�" );
	add( "id",({ "polearm","halberd" }) );
	set_short( "����ս�" );
	set_long(@LONG
	����������ս��ָ�ӹٲ����ʸ�ʹ�õ�������
LONG
		);
	set( "unit","��" );
	set( "type","polearm" );
	set( "weapon_class",40 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",130 );
	set( "value",({ 6750,"silver" }) );
	set( "prevent_insert",1 );
}
#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Fun-Tain Halberd","�����" );
	add( "id",({ "polearm","halberd" }) );
	set_short( "�����" );
	set_long(@LONG
	����������ս��ָ�ӹٲ����ʸ�ʹ�õ�������
LONG
		);
	set( "unit","��" );
	set( "type","polearm" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",130 );
	set( "value",({ 11750,"silver" }) );
//	set( "no_sale",1 );
	set( "prevent_insert",1 );
}
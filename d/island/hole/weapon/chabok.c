#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Magic Chabok","ħ������" );
	add( "id",({ "chabok","whip" }) );
	set_short( "ħ������" );
	set_long(@LONG
	һ����������ɵĳ��ޣ����������˼�˾--��
	����--������ħ�����յĽ����ʹ����ӵ����
	���ħ����
LONG
	);
	set( "unit","��" );
	set( "type","whip" );
	set( "weapon_class",33 );
	set( "min_damage",15 );
	set( "max_damage",30 );
	set( "weight",120 );
	set( "value",({ 1280,"silver" }) );
	set_c_verbs( ({ "%s��%s�ͳ�һ��" }) );
}
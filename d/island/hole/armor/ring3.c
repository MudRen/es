#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( " Ring","��ӡ��ָ" );
	add( "id", ({ "ring" }) );
	set_short( "��ӡ��ָ" );
	set_long(@LONG
	������ħ���µĽ�ָ��������������ӡ�ڱ���
	���ϣ����ö�ħ�ı�����
LONG
           );
	set( "unit","ֻ" );
	set( "weight",5 );
	set( "type","finger" );
	set( "material","element" );
	set( "defense_bonus",7 );
	set( "special_defense",([ "evil":20,"devine":-15 ]) );
	set( "value",({ 2440,"silver" }) );
}

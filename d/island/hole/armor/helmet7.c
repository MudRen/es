#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Holy helm","ʥ��" );
	add( "id", ({ "helm","helmet" }) );
	set_short( "ʥ��" );
	set_long(@LONG
	�������ʥ��֮����ͷ�ڣ�����ͷ�Ͽ����ܵ�
	ʥ�ߵı�����
LONG
		);
	set( "unit","��" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","light_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 3650,"silver" }) );
}

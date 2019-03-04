#include "../legend.h"

inherit MONSTER;

void create()
{

	::create();
	set_level(16);
	set_name( "crystal shapeshifter", "ˮ�����γ�" );
	add( "id",({ "shapeshifter" }) );
        set_short( "ˮ�����γ�" );
	set_long(@LONG
һֻͨ��͸���ı��γ棬��״��������һ�㣬������������ǰ�䶯�������γ�һ��һ
����ʳ����ޱ��ϸ��Ĺ�������������ڣ�����ʮ����Ȥ�� 
LONG	);
	set_skill( "dodge", 100);
	set( "alignment", 1000 );
	set( "max_hp",300);
	set( "hit_points", 300);
	set( "special_defense",([ "all":80, "none":30 ]));
	set( "max_fp",1000);
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 10, 200 );
	set_natural_weapon( 80, 15, 20 );
        equip_armor( LARMOR"kernel1" );
}

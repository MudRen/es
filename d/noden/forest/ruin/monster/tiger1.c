#include "../ruin.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "earless tiger", "�޶���" );
	add( "id", ({ "tiger" }) );
	set_short( "�޶���" );
	set_long(@C_LONG
һֻ���͵��ϻ�, ��֪Ϊ��, ��ʧȥ��Ӧ�е�һ�Զ��䡣
C_LONG
	);
	set("unit","ֻ");
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "int", 10 );
	set_skill("unarmed", 70 );
	set_skill("dodge", 70);
	set("aggressive", 1);
	set("killer", 1);
	set("max_hp", 600);
	set("hit_points", 600);
	set("special_defense", ([ "all":35, "none":20, ]) );
	set("aim_difficulty",
		([ "critical":45, "vascular":55, "weakest":25, "ganglion":60 ]) );
    set_natural_armor( 60, 15 );
    set_natural_weapon( 60, 10, 25 );
	set("alignment", -500 );

	set_c_verbs( ({ "%s���͵���%sһ��ҧȥ", "%sѸ�ٵ�����%s" }) );
	set_c_limbs( ({ "��ͷ", "������", "�Ľ�" }) );
}

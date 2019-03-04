#include "saulin_monk.c"

void create()
{
	::create();
	set_level(11);
	set_name( "A monk with staff", "����ɮ" );
	add ("id", ({ "monk", "staff", }) );
	set_short( "����ɮ" );
	set_long(@DESC
����һ��������У���Ϊ����ϰ������ѧ����С�ɣ����ڸ���һ��
�������������������͵�������������ܷ����ľ�����
DESC
	);
	set("alignment", 200);
	set("gender", "male");
	set("race", "orc");
	set("unit", "λ");
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 18 );
	set("wealth/gold", 15 );
	set("max_hp", 450);
	set("hit_points", 450);
	set("max_fp", 950);
        set("force_effect", 2);
        set("attack_skill",CLASS"fu_mo");
        set("gonfus/fu_mo",80);
	set("force_points", 950);
	set("special_defense", ([ "all" : 20, "none" : 10 ]) );
	set("aim_difficulty", ([ "critical" : 25, "vascular" : 20 ]) );
	set_natural_weapon( 3, 1, 7);
	set_natural_armor( 60, 20 );
	set_skill("bo",75);
	set_skill("parry",80);
	wield_weapon( SAULIN_OBJ"copper_club");
}

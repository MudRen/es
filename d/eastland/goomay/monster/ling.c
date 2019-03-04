#include "../goomay.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Ling", "���" );
	add ("id", ({  "girl" }) );
	set_short( "���" );
	set_long(
"�����Լ��ʮһ��һ��װ����������ʵ�������������������ӯӯ��Ц \n" 
"�������Ů���ɵ����е�ٮٮ�ߡ���Ů��������ֻ��Ů���ӣ���������ʹ�� \n" 
"̰ɫ������֮ͽ��������ʦ�������ش������ǽ�������ר��������ɱɫ�ǡ� \n"
"���������ϰ�˽������ѵ����洫��רɱ���º�ɫ֮ͽ�� \n"
	);
	set( "alignment",1000);
	set( "gender", "female" );
	set( "race", "imp" );
	set( "unit", "λ" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "piety", 25);
	set_skill("longblade",80);
	set_skill("dodge",80);
        set_skill("parry",100);
	set("defense_type","defense");
	set("special_defense", ([ "all":35, "none":25 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":27, ]) );
	set("max_hp", 500);
	set("max_fp", 1000);
	set("hit_points", 500);
	set("force_effect", 1);
	set("force_points", 1000);
	set("attack_skill","monster/sword1");
	set("wealth/gold", 100);
	set_natural_weapon(21,10,13);
	set_natural_armor( 69, 18 );
	wield_weapon( Obj"rainbow_sword" );
	equip_armor( Obj"gold_necklace" );
	equip_armor( Obj"green_cloth" );
}

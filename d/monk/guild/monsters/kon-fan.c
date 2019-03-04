#include "saulin_monk.c"

void create()
{
	::create();
	set_level(9);
	set_name( "kon fan", "�շ���ɮ" );
	add ("id", ({ "kon", "fan","monk" }) );
	set_short( "�շ���ɮ" );
	set_long( @LONG
�շ���ʦΪ�˴Ⱥͣ���������С��ɮ�°���������ƽ�Ӳ����������ֳ�
�İ������֣�����Ц������֮�ơ���ר���黨ָ��\����ÿ�ζ���������
���������������ˣ��Ǹ������𾴵ĳ��ߡ�
LONG
	);
    set( "alignment",2500);
    set( "gender", "male" );
    set( "race", "elf" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
        set("special_defense", ([ "all":40, "none":30, "monk":15 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("class", "monk");
	set("forgetful", 1);
          set("attack_skill",CLASS"keep_flower");    
          set("defense_skill",CLASS"chu_han");
          set("monk_gonfu/keep-flower",10);
          set("monk_gonfu/chu-han",10);
	set("wealth/gold", 10);
	set_natural_weapon( 35, 18, 30 );
	set_natural_armor( 60, 39 );
        set("weight", 700);
    equip_armor( SAULIN_OBJ"cloth3.c" );
    equip_armor( SAULIN_OBJ"necklace2.c" );
}

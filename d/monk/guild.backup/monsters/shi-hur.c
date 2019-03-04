#include "saulin_monk.c"

void create()
{
	::create();
	set_level(9);
	set_name( "shi hur", "��ϴ�ʦ" );
	add ("id", ({ "shi", "hur","monk" }) );
	set_short("��ϴ�ʦ" );
	set_long( @LONG
����Ǹ���ͨ�������־�������ɮ��һ���������֣�����������ȥ����
��ϴ�ʦΨһ����Ȥ�������䣬�����ܵ�������ͽ������ĸ�����!!!
����(���� ���� )����������ɮ�ϰ����һ��ȭ�������������
���Կ˵���ʤ���������ֵڰ˴�����ԪԪ��ʦ�����Ʒ������ᾭ������
�������������ֵ�����ȭ����
LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "lizardman" );
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
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("class", "monk");
	set("forgetful", 1);
          set("attack_skill",CLASS"bolo_fist");
          set("defense_skill",CLASS"chu_han");
          set("defense_type","berserk");    
          set("monk_gonfu/bolo-fist",10);
          set("monk_gonfu/chu-han",10);
	set("wealth/gold", 10);
	set_natural_weapon( 40, 18,28 );
	set_natural_armor( 55, 35 );
        set("weight", 700);
	set("att_chat_output", ({
	    "���˵�� �������Ƶ����������˰ɡ�\n ", 
	}) );
    equip_armor( SAULIN_OBJ"cloth2.c" );
    equip_armor( SAULIN_OBJ"ring1.c" );
}

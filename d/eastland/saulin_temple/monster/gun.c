#include "saulin_monk.c"

void create()
{
	::create();
	set_level(17);
	set_name( "master kon gun", "����Ժ���� �ո�" );
	add ("id", ({ "master", "kon", "gun","kon gun" }) );
	set_short( "����Ժ���� �ո�" );
	set_long(
@C_LONG
����Ժ����������ɮ֮���ʹ�������ɮ�˻�����ĵ�һ���±��Ǹ�����Ժ
����������εĹ�\�����ո������������Ը���ң��޾��κ�а���ǿ������
һ�˵�������ʮ���֣���ս���죬ԡѪ����... ������������ѡΪ��������
����
C_LONG
	);
	set( "alignment",1600);
	set( "gender", "male" );
	set( "race", "human" );
	set( "unit", "λ" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 21 );
	set_skill("unarmed",100);
	set_skill("block",90);
	set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_points", 500);
	set("wealth/gold", 50);
	set_natural_weapon( 25, 24, 37 );
	set_natural_armor( 45, 40 );
	set("weight", 500);
	set("chat_chance", 10);
	set("chat_output", ({
		"�ո�˵: ������ɮ�������: ������, ����а, ������ .....\n",
	}) ); 
	set("att_chat_output", ({
	    "�ոպ�ʮ������ʩ����������´�ɱ�䣬�����ҿո����ɻ���� !��\n",
	}) );
	set("attack_skill",CLASS"dragon_claw");
	set("monk_gonfu/dragon-claw",10);
//	wield_weapon( SAULIN_OBJ"go.c" );
	equip_armor( SAULIN_OBJ"cloth2a.c" );
//	equip_armor( SAULIN_OBJ"shield2.c" );
	equip_armor( SAULIN_OBJ"armband1.c" );
}

#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(10);
	set_name( "Lizardman Sergeant", "�����˰೤" );
	add( "id", ({ "lizardman","sergeant" }) );
	set_short( "�����˰೤" );
	set_long(@LONG
�㿴������һλս���ϵ��ϱ���������������
���Ĵ�ɱ�У���ͼ�������
LONG
	);
	set( "unit", "��" );
	set( "race", "lizardman" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set( "natural_armor",40 );
	set( "natural_defense_bonus",12 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 15 );
	set( "wealth/silver", 50 );
//	set( "aggressive", 1 );
//	set( "pursuing", 1 );
//	set( "moving", 1 );
//	set( "speed", 30 );
	set( "tactic","melee" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 20 );
	set_skill( "shortblade", 60 );
	set_skill( "parry", 60 );
	set_skill( "block", 60 );
	set_skill( "tactic", 60 );
	set_skill( "defend", 60 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"\n�����˰೤���: С����󵨣���������ս��\n\n",
	}) );
	wield_weapon( HWEAPON"shortsword" );
	
}



#include "../saulin_temple.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(17);
	set_name("master shi hun","���������� ����");
	add("id",({"shi","hun","monk","master"}) );
	set_short("���������� ����");
	set_long(@C_LONG
������ר���о����Ÿ��ɵ���ѧ������ʹ�������ӵܽ�����������ʱ����
֪��֪�˰�ս��ʤ... ���԰�����������Ȼ��ͨ�������Ÿ�������... ��
���Ǹ���ʮ�����ɮ�������������֣���������ɳգ������ھ���ָ����
�˳ơ��׷��𡹡����Խ������Ÿ�����ѧĪ������ָ�ƣ�������ʮ�����
��������տ�˵��¯���ࡣ
C_LONG
	);
	set( "alignment", 1300 );
	set( "gender", "male" );
	set( "race", "human");
	set( "unit", "λ" );
	set_perm_stat( "dex",27);
	set_perm_stat( "str",28);
	set_perm_stat( "int",23);
	set("max_hp", 800);
	set("hit_points", 800);
	set("max_fp", 4150);
	set("force_points", 4150);
	set("wealth/gold", 70 );
	set_natural_weapon( 10, 9, 9 );
	set_natural_armor( 50, 12 );
	set("special_defense", ([ "all" : 60, "none" : 48 ]) );
	set("aim_difficulty",([ "critical" : 56, "vascular" : 60 ]) );
	set("weight", 840);
	wield_weapon( SAULIN_OBJ"thu" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"glove1" ); 
	equip_armor( SAULIN_OBJ"necklace2" );
	equip_armor( SAULIN_OBJ"armband2" ); 
 set("special_attack",(["damage_type" : "mental","main_damage" : 40,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n�������ε�˵��ʩ�������Ϊ��Ī����ɮ������!!!\n\n"+
"��������˫�ֺ�ʮ��˫����������ʯ�ذ��У�ͻȻһ���Ϻȣ�ʹ��������ʮ��\n"+
"������һָ����... ������һ�䣬���д��һ��ǿ�ҵ���������ֻ�е�һ�ɾ�\n"+
"�����ˮ���̰����... ��\n\n" );
set("c_room_msg","\n�������ε�˵��ʩ�������Ϊ��Ī����ɮ������!!!\n\n"+
"��������˫�ֺ�ʮ��˫����������ʯ�ذ��У�ͻȻ���һ����ʹ��������ʮ��\n"+
"������һָ����... ������һ�䣬���д��һ��ǿ�ҵ�����������");
set("c_room_msg2", "������ ...\n");
}


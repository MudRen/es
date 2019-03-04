#include "../nodania.h"

#define KNIGHTS ({ "baron", "vicomte", "earl", "marquess", "duke", "lord", "overlord" })
#define WARSCORE ({ 2000, 5000, 10000, 25000, 50000, 100000, 500000 })
inherit "/d/noden/nodania/monster/knight";

void create()
{
	::create();
	set_level(19);
	set_name( "yaramon", "Ү����" );
	add ("id", ({ "king", "yaramon xi" }) );
	set_short( "����Ү����ʮһ��" );
	set_long(@LONG
������˹���Ү����ʮһ�����ˣ�����Լ�ġ���ʮ�꣬�����������д���
�Ͱ�������Ŀ���������ʱҮ��������΢΢һЦ��������ۻ����㹻��ս
�����������Ҫ��(request)뷷��λ��
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );

	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 25 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "block", 100 );

	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set( "alignment", 2500 );
	set( "wealth/gold", 500 );

	set_natural_weapon( 20, 10, 30 );
	set_natural_armor( 50, 60 );
	
   set( "special_defense", ([ "all": 75 , "none": 50 ]) );
	
	set( "aim_difficulty",([ "critical":30,"vascular":30,"weakest":30,"ganglion":30 ]) );
	set( "tactic_func", "my_tactic" );
	set( "war_score", 1000000 );

	wield_weapon( "/d/noden/nodania/obj/king_sword" );
	equip_armor( NODANIA"obj/crown" );
	equip_armor( "/d/knight/fortress/armors/silver_plate" );

	equip_armor( "/d/knight/fortress/armors/silver_leggings" );
	equip_armor( "/d/knight/fortress/armors/silver_gauntlets" );
	equip_armor( NODANIA"obj/red_cape" );

}

void init()
{
	::init();
	// This command allows the King to grant Knighthood.
	add_action( "request", "request" );
}

// This function is called when the monster is attacked, with the attacker
// as argument. Return 1 if this attack is blocked or 0 for attack is allowed
int stop_attack(object player)
{
	call_out( "defend_king", 1, player);
	return 0;
}

void defend_king(object obj)
{
	int i;
	object env, *inv, atk;

	env = environment( this_object() );
	if( !env ) return;

	inv = all_inventory(env);
	atk = query_attacker();
	for( i=0; i<sizeof(inv); i++ ) {
		if( (string)inv[i]->query("class")=="knight" && inv[i]!=atk){
	//	&& (!atk || member_array( inv[i], atk )==-1) ) {
			tell_room( env,
				inv[i]->query("c_name") + "�嵽������ǰ��׼��Ϊ����������ս��\n",
				inv[i] );
			inv[i]->force_me( "protect king" );
			inv[i]->kill_ob(atk);
		}
	}
	return;
}

int my_tactic()
{
	int hp;

	hp = (int)query("hit_points");
	if( hp<300 && random(20)<3 ) {
		tell_room( environment(this_object()),
			"�����������еĽ��������૵������ħ���Ļָ����� ....��\n",
			this_object() );
		receive_healing( 60 );
		return 1;
	}
	return 0;
}

int request()
{
	int ws, order, nws;
	string knighthood;

	if ( (string)this_player()->query("class") != "knight" ) return 0;
	ws = (int)this_player()->query("war_score");
	knighthood = (string)this_player()->query("knighthood");
	order = member_array( knighthood, KNIGHTS );
	
	for( nws = 0; nws<sizeof(WARSCORE); nws++ )
		if( ws < WARSCORE[nws] ) break;
	nws--;

	// Cannot advance knighthood
	if( nws <= order ) {
		tell_room( environment(),
			"\n����˵��: ���ս��ֻ��������Ŀǰ����ݵ�λ������Ŭ���ɡ�\n");
		return 1;
	}
	
	tell_room( environment(),
		"\n�����߾������彣����" + this_player()->query("c_name") +
		"��ͷ�ϼ���������һ��ԲȦ��\n"
		"\n���������ú�������������:\n"
		"\n    ���ڣ��ҷ���Ϊ" + this_player()->query("c_name") + 
		to_chinese(KNIGHTS[order+1]) + "��\n\n"  );
	this_player()->set("knighthood", KNIGHTS[order+1] );
	this_player()->set("title", this_player()->query_title());
	return 1;
}

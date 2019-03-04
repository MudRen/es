#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman Imperial Akaba","������" );
	add( "id",({ "lizardman","imperator","akaba" }) );
	set_short( "�����˴󽫾� ������" );
	set_long(@LONG
������������һλ����ս�Ĵ󽫾�����˵���������ھ����е�ʱ��
�������Բб���ÿ�γ�����ʱ������ɱ��Ϊ�֣�������ɱ���˷ܣ���
�����и����--ħ�������Ѿ���֪������Ӣ�ۺú�ɥ��������˫��
֮���ˡ�
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",-500000 );
//	set( "time_to_heal",8 );
	set_natural_armor( 55,20 );
	set_natural_weapon( 30,20,22 );
	set_natural_weapon2( 30,20,24 );
	set( "max_hp",1000 );
	set( "hit_points",1000 );
	set( "spell_points",10000 );
	set_perm_stat( "str",30 );
	set_perm_stat( "kar",25 );
	set_perm_stat( "dex",30 );
	set_skill( "parry",100 );
	set_skill( "axe",100 );
	set_skill( "two-weapon",100 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set( "wealth/gold",150 );
	set( "special_defense",([ "fire":50,"cold":50,"energy":50,"magic":50,"none":40 ]) );
	set( "aim_difficulty",
	([ "vascular":80,"critical":70,"weakest":50,"ganglion":80 ])  );
	set( "stun_difficulty",60 );
	set( "tactic","assault" );
	wield_weapon( HWEAPON"axe1" );
	equip_armor( HARMOR"cloak2" );
	equip_armor( HARMOR"ring3" );
	equip_armor( HARMOR"plate9" );
	equip_armor( HARMOR"helmet5" );
}

void init()
{
	::init();
	add_action( "to_embattle","embattle" );
	add_action( "to_demand","demand" );
}

int to_embattle()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"�����ͺݺݵĵ���"+c_him+"һ��˵��������ս���붼���룬�����ɡ�\n",player );
	tell_object( player,"�����ͺݺݵĵ�����һ��˵��������ս���붼���룬�����ɡ�\n" );
	command( "kill "+him );
	return 1;
}

int to_demand()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"�����ͺݺݵĵ���"+c_him+"һ��˵�����Ұ��֣��붼���룬�ԹԵ����ɡ�\n",player );
	tell_object( player,"�����ͺݺݵĵ�����һ��˵�����Ұ��֣��붼���룬�ԹԵ����ɡ�\n" );
	command( "kill "+him );
	return 1;
}

void die()
{
	this_object()->set( "alignment",-1000 );
	::die();
}

#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman Marshal Knight","ս��ָ�ӹ�" );
	add( "id", ({ "lizardman","marshal","knight" }) );
	set_short( "������ս��ָ�ӹ�" );
	set_long(@LONG
    �㿴������һλ��ս����ʿ�����ȴ���һ���Ѿ���֪���ȶ�ã�
�˷ܵ�������ɱ����ʾ��ף������ñ𿿽��������Ϊ�������
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-1150 );
	set_natural_weapon( 37,11,22 );
	set_natural_armor( 68,30 );
	set( "max_hp",500 );
	set( "hit_points",750 );
	set( "special_defense",
	([ "fire":50,"cold":50,"energy":40,"electric":40,"none":50 ]) );
	set( "aim_difficulty",
	([ "critical":90,"vascular":45,"weakest":60,"ganglion":100 ]));
	set( "stun_difficulty",90 ); 
	set( "wealth/silver",890 );
	set( "tactic","melee" );
	set( "killer",1 );
	set( "justice",50 );
	set( "pursuing",1 );
	set_perm_stat( "str",27 );
	set_perm_stat( "dex",24 );
	set_skill( "polearm",100 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set( "chat_chance",10 );
	set( "att_chat_output",({
	"\n������ָ�ӹ������˵������û�����ܴ��ҵ����������ģ��ԹԵ������ɣ�\n\n",
	"\n������ָ�ӹٲ�м��˵�������������ʤ���ң��ٻؼ���ʮ��ɣ�\n\n" }) );
	set( "tactic_func","my_tactic" );
	wield_weapon( IWARO"polearm" );
	equip_armor( IWARO"shield4" );
	equip_armor( IWARO"helmet3" );
	equip_armor( IWARO"arms4" );
	equip_armor( IWARO"amulet2" );
	equip_armor( IWARO"plate6" );
}

int my_tactic()
{
	string him;
	object victim;
	
	victim=query_attacker();
	him=victim->query( "c_name" );
	if( !victim || victim->query( "conditions/bleeding" ) ) return 0;
	if ( random(99) >14 ) return 0;
	tell_object( victim,
	"\n������ָ�ӹ�ͻȻ�ɿ���������Ŵ̳�һǹ���㷢�����ؿ�\n"+
	"�϶���һ�����Ŀ�������Ѫ����Ȫ�㲻�ϵ�ð������\n\n" );
	tell_room( environment( victim ),
	"\n������ָ�ӹ�ͻȻ�ɿ����"+him+"�����Ŵ̳�һǹ���㷢��\n"
	+him+"���ؿڶ���һ�����Ŀ�������Ѫ����Ȫ�㲻��ð������\n\n",victim );	
	victim->set( "conditions/bleeding",({ 2,15,4 }) );
	return 1;
}

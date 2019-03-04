#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman swordman Abon","�ǰ�" );
	add( "id",({ "lizardman","swordman","abon" }) );
	set_short( "�����˽���ʦ �ǰ�" );
	set_long(@LONG
    �㿴������һλ����Ƿ��Ľ��ͣ���������Ҫ��ѵ��������Ϊ��
����˵������ʱ������������Ѩ�����˼����ޡ������롻��ս����
��ҹ����춻��������ϵ���Ƭ�ǳ���Ӳ�����ϻ��������������ޱȣ�
�޷��ӽ�������ʼ�ղ������¡����������ֻ�����������һ���ط���
��Ƭ���䣬��ǳ���ȱ�ڷ���һ������춽�������ɱ��������������
�����Ƭ�ǳ����죬���˳�ֽ��������Ƥ���¡���������������Ƥ
�ø���ʱ�������Ĺ���������˹���о���������˹�������������Ƭ
���������ˡ�����ս�ס��������뻤�ۡ���������ܡ��͡����뽣����
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",-800 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,35 );
	set_natural_weapon( 35,10,15 );
	set( "max_hp",950 );
	set( "hit_points",950 );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",25 );
	set_perm_stat( "kar",25 );
	set_perm_stat( "int",20 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set_skill( "shortblade",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/gold",150 );
	set( "special_defense",([ "none":20,"fire":80 ]) );
	set( "aim_difficulty",
	([ "weakest":70,"critical":70,"vascular":45,"ganglion":80 ]) );
	set( "stun_difficulty",80 );
	wield_weapon( HWEAPON"scale_sword" );
	equip_armor( HARMOR"arms5" );
	equip_armor( HARMOR"plate3" );
	equip_armor( HARMOR"shield7" );
}

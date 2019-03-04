#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Lizardman Colonel Arthur","��ɪ" );
	add( "id", ({ "lizardman","colonel","arthur","knight" }) );
	set_short( "��������ʿ���ų� ��ɪ" );
	set_long(@LONG
    �㿴������һλ���͵���ʿ�������͵���ʿ��ս���ϵĳ�ʤ����
��˵���������˺�ħ���ս���У������˾��ǿ���֧��ŵ�ٴ�½��ѵ
��������ʿ���Ż�ʤ�ġ�
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-500 );
	set( "max_hp",650 );
	set( "hit_points",650 );
	set_natural_weapon( 20,22,30 );
	set_natural_armor( 58,15 );
	set( "special_defense",
	([ "fire":80,"cold":80,"energy":80,"electric":80,"none":80 ]) );
	set("aim_difficulty",
	([ "critical":90,"vascular":30,"weakest":65,"ganglion":100 ]));
	set( "wealth/silver",200 );
	set( "tactic","assault" );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",26 );
	set_skill( "jousting",100 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
//	set_skill( "dodge",100 );
	wield_weapon( HWEAPON"jousting2" );
	equip_armor( HARMOR"shield6" );
	equip_armor( HARMOR"tail3" );
	equip_armor( HARMOR"cloak3" );
	equip_armor( HARMOR"plate5" );
	equip_armor( HARMOR"amulet3" );
	equip_armor( HARMOR"helmet6" );
}
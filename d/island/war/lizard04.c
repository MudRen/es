#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Knight","��������ʿ" );
	add( "id", ({ "lizardman","knight" }) );
	set_short( "��������ʿ" );
	set_long(@LONG
    �㿴�������������������Ҳ���������˾�����ս������ǿ��һ
֧����Ȼ�������Ǻ����Ƶ�һ�����壬�������Ǿ��������������Э��
��������ò�Ҫ��Ϊ���ĵ��ˡ�
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-300 );
	set_natural_armor( 59,20 );
	set_natural_weapon( 38,13,25 );
	set( "special_defense",
	([ "fire":20,"cold":15,"none":30 ]) );
	set( "aim_difficulty",
	([ "critical":75,"vascular":70,"weakest":50,"ganglion":100 ]));
	set( "stun_difficulty",60 );
	set( "wealth/silver",710 );
	set( "killer",1 );
        set( "justice",12 );
	set( "tactic","assault" );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_skill( "jousting",90 );
	set_skill( "parry",90 );
	set_skill( "tactic",90 );
	set_skill( "block",90 );
	set_skill( "dodge",70 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n��������ʿ��У�������̫�����ˣ������˾����������ܵ��ģ�\n\n",
	"\n��������ʿ�����ǵ���ʿ���žͿ쵽�ˣ������еͶ���ɣ�\n\n" }) );
	wield_weapon( IWARO"lance1" );
	equip_armor( IWARO"shield1" );
	equip_armor( IWARO"boots1" );
	equip_armor( IWARO"bracer1" );
	equip_armor( IWARO"plate1" );
}
#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(15);
	set_name( "Lizardman Lieutenant","��������ξ" );
	add( "id",({ "lizardman","lieutenant" }) );
	set_short( "��������ξ" );
	set_long(@LONG
    �㿴������һΪӢ�������ľ��٣��������������Ĳ�����ս����
�������������������赲���ˣ�ʹ�᷽�г�ԣ��ʱ��׼����
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment", -300 );
	set_natural_armor( 60,35 );
	set_natural_weapon( 30,0,0 );
	set( "special_defense", ([ "fire":20,"cold":15,"none":30 ]) );
	set( "aim_difficulty",
	([ "critical":60, "vascular":30, "weakest":80 ]));
	set( "wealth/silver", 100 );
	set( "tactic","melee" );
	set( "killer",1 );
	set( "justice",10 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 15 );
	set_skill( "axe", 80 );
	set_skill( "parry", 80 );
	set_skill( "tactic", 80 );
	set_skill( "block", 80 );
	set( "chat_chance", 20 );
	set( "att_chat_output",
	({ "\n��������ξ���: ���������������������֮���ˣ�\n\n",}) );
	wield_weapon( IWARO"axe2" );
	equip_armor( IWARO"shield5" );
	equip_armor( IWARO"bracer2" );
	equip_armor( IWARO"plate7" );
	equip_armor( IWARO"helmet4" );
}
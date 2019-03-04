#include "../hole.h"

inherit ENEMY;
void create()
{
	::create();
	set_level(16);
	set_name( "Lizardman Lifeguard", "�����˽�����" );
	add( "id", ({ "lizardman","guard","lifeguard" }) );
	set_short( "Lizardman Soldier", "�����˽�����" );
	set_long(@LONG
    �㿴������һλ����������������
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",500 );
	set( "wealth/silver",300 );
	set_natural_armor( 40,25 );
	set_natural_weapon( 20,5,8 );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_skill( "shortblade",90 );
	set_skill( "jousting",90 );
	set_skill( "tactic",90 );
	set_skill( "parry",90 );
	set( "tactic","melee" );
	set( "chat_chance",10 );
	set( "att_chat_output",({
	"����������˵������������ɱ�����ˣ������Ҳ���Ź���ģ�\n",
	"����������˵��û�µı������ﶺ����ȥ��ĵط�׬����ֵ�ɣ�\n" }) );
	wield_weapon( HWEAPON"lance2" );
	equip_armor( HARMOR"tail2" );
	equip_armor( HARMOR"plate8" );
}
#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "Yang Chun", "�" );
	add("id",({"yang","chun"}));
	set_short( "�" );
	set_long(
		"��������ǰ׻��ߣ����ݽ������ˣ�ʹһ�����ϡ���Ϊ��ɽ�����С�뽫\n"
		"��Զ̽����ͷ�죮����㲻�����Ļ�����ñ�ȥ��������\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -220 );
	set_perm_stat( "str", 19 );
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar", 11 );
	set_skill( "blunt", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 300 );
	set( "max_hp", 300 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 22, 8 );
        set( "chat_chance",20);
	set("att_chat_output",
	"\n ���: �޴��ļһ���ҹ�����ɽ��.....\n\n");
	wield_weapon( TWEAPON"ironhammer" );
        equip_armor( TARMOR"white_warcape");
        equip_armor( TARMOR"wool_hat");
        equip_armor( TARMOR"blue_cloak");
}

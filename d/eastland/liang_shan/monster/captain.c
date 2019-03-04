#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(14);
	set_name("captain","ɽ��С�ӳ�");
	add ("id", ({ "thief","bandit" }) );
	set_short("ɽ��С�ӳ�");
	set_long(
		"ɽ��С�ӳ�����ɽɽ���Ļ�����ս��λ���쵼�ˣ�����ͨ��ָ����\n"
		"��ʮ����ɽ����ͨ���Ǵ��ڶ�ɽ����ѡ�����վ������������߾�֮\n");
	set_perm_stat("dex", 12);
	set_perm_stat("kar", 15);
	set_perm_stat("str", 11);
        set("unit","λ");
	set_skill( "longblade", 60 );
	set_skill( "parry", 50 );
	set_skill( "anatomlogy", 50 );
	set( "aiming_loc", "weakest" );
	set( "attack_skill","monk/general/tai_zuo");
	set( "max_fp", 100 );
	set( "max_hp", 380 );
	set( "hit_points", 380 );
	set( "force_points", 100 );
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", -300 );
	set( "wealth/gold", 32 );
	set_natural_armor( 10, 10 );
	set_natural_weapon( 12, 7, 15 );
        set ("special_defense",(["fire":2,"cold":-2,"magic":2]));
        wield_weapon(TWEAPON"yanlin");
        equip_armor(TARMOR"bandit_armor");
}               


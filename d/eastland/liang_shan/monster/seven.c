#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Zhuan Shiao Chi", "��С��" );
	add("id",({"zhuan","shiao","chi"}));
	set_short( "��С��" );
	set_long(
		"��С����Ż����ޣ�С����С��������磬���Դ���ά������\n"
		"��������������ݣ��־�Ϊˮ��ͷ�죮�����������������С������\n"
		"����ʲ�����顣\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -80 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 11 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 25 );
	set_skill( "dodge", 40 );

	set( "wealth/gold", 30 );
	set( "special_defense", (["all": 16 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );
        set( "inquiry",([
        "whirl" : "@@ask_whirl",
        "brother" : "@@ask_brother"
        ]));
	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
void ask_whirl()
{
write(
"��С��˵��: ���ߵ���������һ����˵���ں������ס��һֻǧ��Ĵ�Ӱ�\n"
"��������ˮ����ˮʱ���Ͳ����˺��е����У������������Ҳ�����....\n");
return 0;
}
void ask_brother()
{
write(
"�Ҹ����С��ǰ��˵���ں��з�����һ�������ܣ�������һ���˵�����\n"
"��������ڶ�������Ӱ���������˵���....\n");
return 0;
}

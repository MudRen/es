#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "Zhuan Shiao Er", "��С��" );
	add("id",({"zhuan","shiao","er"}));
	set_short( "��С��" );
	set_long(
		"��С���������̫�꣬С�壬С�������ܵܣ����Դ���ά������\n"
		"��������������ݣ��־�Ϊˮ��ͷ�죮�������ƺ���������ʲ�ᶫ����\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -200 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar", 11 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 15 );
	set_skill( "dodge", 50 );
        set( "inquiry" ,([
        "shell" : "@@ask_shell"]));
	set( "wealth/gold", 20 );
	set( "special_defense", (["all": 17 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );

	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
void ask_shell()
{
write(
"��С���е�: ����������������˵�е�ǧ���Ӱ�����Ȼ��Ĵ��ڣ����Ѿ���������\n"
"һ���ˣ������ƺ�����û�˵�Ҫ��?? ���ܰ��ҽ��������??\n");
return 0;
}
#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "patrick", "������" );
	add( "id", ({ "captain" }) );
   set_short( "�����˴���" );
	set_long(
		"�����˴����ո�Ϊ�˻���ծ�������Ĵ������ˣ�һ������������ƾơ�\n"
		"�����ʶ��Ļ�����Ҫ������ǰ���𡸴�(ship)������֡�\n"
	);
	set( "race", "lizardman" );
	set( "gender", "male" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 13 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );

	set( "tactic", "assault" );
	set( "wealth/gold", 25 );
	set( "inquiry", ([
		"ship" : "@@ask_ship"
	]) );

	wield_weapon( "/d/noden/bluesand/item/long_cutlass" );
	equip_armor( "/d/noden/bluesand/item/eye_patch" );
	equip_armor( "/d/noden/bluesand/item/boots" );
}


void ask_ship(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
                 "�����˴���ŭ���: ����Ҳ��ȡЦ�ң����ҽ������С�����������ʣ�\n",
			this_object() );
	} else {
            tell_room( environment(),
                    "�����˴�������һ����һ��ף����: ��С�ӣ��㲻Ҫ���ˣ�\n",
			this_object() );
		kill_ob( player );
	}
}

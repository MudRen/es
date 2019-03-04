#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "visitor", "�۹��" );
	set_short( "�۹��" );
	set_long(
		"����һ����������Ĺ۹�ͣ����ڶ������������ָָ��㡣\n"
	);
        set ("gender", "male");
        set ("race", "human");
        set("unit","��");
        set_natural_armor( 28, 10 );
        set_natural_weapon( 6, 5, 13 );
        set_perm_stat( "str", 12 );
        set_perm_stat( "dex", 12 );
	set_skill( "dodge", 60 );
	set( "chat_chance", 15 );
	set( "att_chat_output", ({
		"�۹�Ϳ���������ǿ����������ʲ�ᶼ���� !! ��Ҫɱ�� !!����\n",
	}) );
        set ("wealth", ([ "silver": 50 ]) );
        equip_armor( Obj"glasses" );
}

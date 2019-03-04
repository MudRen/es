#include <mudlib.h>
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("yamor", "��Ĭ");
	add ("id", ({ "elder", "adventurer" }) );
   	set_short( "��Ĭ����");
	set_long(
		"��Ĭ������һ���������ܴ�������ˣ��������ʱ��������������������\n"
		"�еĵط��������������ˣ�ס�����ｫ�Լ��ľ���������Щ����һ����\n"
		"��ð�յ������ˣ��������Ҫ����(help)�Ļ�������������\n" 
	);
	set_perm_stat("strength", 25);
	set_perm_stat("dexterity", 25);
	set_skill( "blunt", 100 );
	set_skill( "dodge", 80 );
	set( "max_hp", 560 );
	set( "hit_points", 560 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1200 );
	set_natural_armor( 120, 35 );
	set_natural_weapon( 25, 13, 30 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("aim_difficulty",
			([ "vascular":25, "ganglion":30 ]) );
	set( "tactic_func", "my_tactic" );

	set( "inquiry", ([
		"help" : "@@help_me"
	]) );
	wield_weapon("/d/adventurer/hall/weapons/wiser_staff");
	equip_armor("/d/adventurer/hall/armors/wiser_amulet");
}

void help_me( object who )
{
	tell_room( environment(),
		"��Ĭ����΢Ц��˵��: �������Ҫ�����Ļ���ȥŵ�����Ǹ����������ҵ����֡�\n",
		this_object()
	);
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	tell_room( environment(this_object()), 
		"��Ĭ�����ٻ�ȫ���ߵ��������㿴��������߳���һ�Ź���....Ȼ����ʧ��\n",
		this_object() );
	this_object()->receive_healing(100);
	return 1;
}

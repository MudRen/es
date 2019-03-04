#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2, ob3, ob4, ob5, ob6;

	::create();
	set_level(19);
	set_name( "Moorth Warlord", "Ĭ��˹ָ�ӹ�" );
	add( "id", ({ "warlord" }) );
	set_short( "Ĭ��˹ָ�ӹ�" );
	set_long(
		"�㿴��Ĭ��˹���ӵ�ָ�ӹ٣��������跨ռ��ŵ����������һ�������Ա�\n"
		"�������¾ݵ㡣\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set_natural_armor(50,30);
	set_natural_weapon(15,12,15);
	set( "wealth/silver", 400 );
	set( "hit_points", 650 );
	set( "max_hp", 650 );
	set( "special_defense", ([ "all": 40,"none":20 ]) );
	set( "aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":30, "ganglion":15 ]));
        	     
	set( "pursuing", 1 );
	set( "killer", 1 );
// set( "war_value", 100 );
   set( "war_value", 200 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "defend", 100 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹ָ�ӹ���Ц��: ���Ǹ��赲��Ĭ��˹�����ߣ���ɱ���ۣ�\n",
		"Ĭ��˹ָ�ӹ�˵��: ��ƾ��������ͣ�Ҳ��������ǰ��Ұ��\n",
		"Ĭ��˹ָ�ӹ�˵��: Ĭ��˹�Ĵ�����Ͼͻ�ͻ�ƽ�磬���ǵľ����Ǿ��Ե���ס�ģ�\n"
	}) );

	wield_weapon("/d/moorth/obj/moraz_blade");
	equip_armor("/d/moorth/obj/cape");
	equip_armor("/d/moorth/obj/shield");
	equip_armor("/d/moorth/obj/platemail");
	equip_armor("/d/moorth/obj/helmet");
	ob6 = new( "/d/moorth/obj/gauntlets" );
	equip_armor("/d/moorth/obj/gauntlets");
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("warlord") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({ this_object() }) );
		add_temp( "protectees", ({ who }) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹ָ�ӹ�ͦ����" + who->query("c_name") + "��\n",
		this_object() );
}

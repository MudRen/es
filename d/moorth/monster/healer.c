#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "Moorth Military Healer", "Ĭ��˹��ҽ" );
	add( "id", ({ "healer", "military healer" }) );
	set_short( "Ĭ��˹��ҽ" );
	set_long(
		"�㿴��һ����ɫ���Ƶ�Ī��˹�ˣ�������һ��Ī��˹�������ս������\n"
		"����ֻ��Э������ͬ����ս���л���ȥ��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "special_defense", ([ "all": 30,"none":20 ]) );
    set("aim_difficulty",
        ([ "critical":20, "vascular":40, "weakest":30, "ganglion":30 ]));

	set_natural_armor( 30, 35 );
	set_natural_weapon( 5, 10, 10 );
	set( "wealth/silver", 800 );
	set( "wimpy", 30 );
	set( "tactic_func", "my_tactic" );
// set( "war_value", 80 );
   set( "war_value", 160 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_perm_stat( "kar", 24 );
	set_skill( "dagger", 80 );
	set_skill( "dodge", 80 );
	set_skill( "anatomlogy", 100 );
   set( "aiming_loc", "ganglion" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹��ҽ˵��: ���ǻ��Ƿ����ɣ����ǵľ��������ǵ���ס�ģ�\n",
		"Ĭ��˹��ҽ˵��: ��������Ͷ���ɡ�\n",
		"Ĭ��˹��ҽ˵��: �����ѵ���������\n"
	}) );

	wield_weapon( "/d/moorth/obj/moraz_dagger" );
	equip_armor( "/d/moorth/obj/robe" );
	equip_armor( "/d/moorth/obj/ring" );
}

void init()
{

   object knight, victim;
   int khp;

   knight = present( "moorth knight", environment(this_object()) );
   if( knight ) {
    khp = (int)knight->query("hit_points");
    victim = knight->query("last_attacker");
   }

   if( present("moorth knight", environment(this_object())) &&
        victim && khp < 100 )
   this_object()->kill_ob(victim);

}

int my_tactic()
{
	object *people;

	if( random(20)<4 ) {
		tell_room( environment(this_object()), 
			"Ĭ��˹��ҽ�������: Sh'ak - Bad-mi-guraj la-thu .....\n"
			"һ����͵Ĺ�â�ӵ������𣬴��ڳ�������Ī��˹������������Ȼ����ʧ��\n",
			this_object() );
		people = all_inventory(environment());
		people->heal_moorth(35);
		return 1;
	} else return 0;
}

void help_me_moorth(object who, object victim)
{
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹��ҽͦ��....Э��" + who->query("c_name") + "��ս��\n",
		this_object() );
}

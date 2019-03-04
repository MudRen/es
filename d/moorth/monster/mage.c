#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "Moorth Magician", "Ĭ��˹ħ��ʦ" );
	add( "id", ({ "magician" }) );
	set_short( "Ĭ��˹ħ��ʦ" );
	set_long(
		"�㿴��һ��Ĭ��˹��ħ��ʦ�����Ŀ������૵�����....�������������ģ�\��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -800 );
	set( "hit_points", 350 );
	set( "max_hp", 350 );
	set( "special_defense", ([ "all": 40,"none":20 ]) );
    set("aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":15, "ganglion":30 ]));
	
	set_natural_armor(30,30);
	set_natural_weapon(10,10,10);
	set( "wealth/silver", 600 );
	set( "wimpy", 15 );
	set( "killer", 1 );
	set( "tactic_func", "my_tactic" );
// set( "war_value", 80 );
   set( "war_value", 160 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_skill( "wand", 100 );
	set_skill( "dodge", 90 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹ħ��ʦ���: ������Щ�޴���֪��ŵ���ˣ�ͨͨ�����µ���ȥ�ɣ�\n",
		"Ĭ��˹ħ��ʦ˵��: ɱ��������Щ������ֱ�����˷��ҵ�ʱ�䣡\n",
		"Ĭ��˹ħ��ʦ˵��: ŵ���������������������\n"
	}) );

	ob1 = new( "/d/moorth/obj/wand" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/robe" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

int my_tactic()
{
	object *victim;

	if( !(victim= query_attackers()) ) return 0;
	if( random(20)<4 ) {
		tell_room( environment(this_object()), 
			"Ĭ��˹ħ��ʦ�������: Kha-ta-mig'sen-gyr-da .....\n"
			"ͻȻ��һ��ȼ�������һ�Ĺ���������ǰ���䡹��һ��ը������е�һ�����ȵľ�ʹ��\n",
			this_object() );
		victim->receive_special_damage("fire", 50);
		return 1;
	} else return 0;
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("magician") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹ħ��ʦͦ����" + who->query("c_name") + "��\n",
		this_object() );
}

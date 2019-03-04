#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2, ob3, ob4;

	::create();
	set_level(16);
	set_name( "Moorth Knight", "Ĭ��˹��ʿ" );
	add( "id", ({ "knight" }) );
	set_short( "Ĭ��˹��ʿ" );
	set_long(
		"�㿴��һ��Ĭ��˹����ʿ��������Ѱ�ҵ��ˡ���������ͼ����ս��\��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(10,10,10);
	set_natural_armor(30,30);
	    set( "special_defense", ([ "all": 20,"none":10 ]) );
    set("aim_difficulty",
        ([ "critical":20, "vascular":20, "weakest":15, "ganglion":15 ]));

	set( "wealth/silver", 250 );
	set( "killer", 1 );
// set( "war_value", 50 );
   set( "war_value", 100 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 20 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 90 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹��ʿ���: ������ʣ���ҫ����Ĭ��˹��\n",
		"Ĭ��˹��ʿ˵��: ������������Ҫ����ν�ĵֿ���\n",
		"Ĭ��˹��ʿ˵��: ������ЩҰ���ˣ�����Ĭ��˹�۹�Ͷ����\n"
	}) );

	ob1 = new( "/d/moorth/obj/bastardsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/platemail" );
	ob2->move( this_object() );
	equip_armor(ob2);

	ob3 = new( "/d/moorth/obj/helmet" );
	ob3->move( this_object() );
	equip_armor(ob3);

	ob4 = new( "/d/moorth/obj/gauntlets" );
	ob4->move( this_object() );
	equip_armor(ob4);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹��ʿͦ����" + who->query("c_name") + "��\n",
		this_object() );
}

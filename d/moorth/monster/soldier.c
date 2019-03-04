#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1;

	::create();
	set_level(8);
	set_name( "Moorth Soldier", "Ĭ��˹ʿ��" );
	add( "id", ({ "soldier" }) );
	set_short( "Ĭ��˹ʿ��" );
	set_long(
		"�㿴��һ��Ĭ��˹��ʿ����������Ѱ�ҵ��ˡ���������ͼ����ս��\��\n"
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set( "wealth/silver", 50 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 30 );
// set( "war_value", 5 );
   set( "war_value", 10 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 30 );
	set_skill( "defend", 40 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"Ĭ��˹ʿ�����: ������˹Ů�ʱ������꣡\n",
		"Ĭ��˹ʿ��˵��: ������������Թ������ɣ�\n",
		"Ĭ��˹ʿ��˵��: ���ǲ�����Ӯ�ģ�ʤ�������Ĭ��˹�۹��ģ�\n"
	}) );

	ob1 = new( "/d/moorth/obj/shortsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("soldier") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"Ĭ��˹ʿ��ͦ����" +who->query("c_name") +"��\n",
		this_object() );
}

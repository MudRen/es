#include "../farwind.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "smith", "����" );
	add( "id", ({ "old smith" }) );
	set_short( "������" );
	set_long("@@query_long");
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 800 );

	set( "chat_chance", 20 );
	set( "chat_output", ({
		"���������պ���������ˮ�У�����һ�����̵�������\n",
		"������˵��: ���У�����ˮ���ҺȺ���\n",
		"�������ù��ڲ����ϵ�ë�������\n"
	}) );
	set("max_hp", 200);
	set("hit_points", 200);
	set( "wealth/silver", 40 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon( 4, 2, 2 );
	set_natural_armor( 30, 10 );
	wield_weapon( FARWIND"items/hammer" );
}

string query_long()
{
	if( query("chat_chance") )
		return "�������������Ŭ����������������󺹵����ӣ��������������һ��ˮ\n"
		"�ȣ���һ�����л�㡣\n";
	else return "�������������ڵع��������������������ƺ��������С�\n";
}

int accept_item(object who,object item)
{
    if ( !item->query("quest_smith") ) return 1;
    if ( !item->query_filled() ) {
         tell_room( environment(), 
			"������̾�˿���: �Һ�æ�����ÿձ��Ӻ��ҿ���Ц��\n");
			command("give cup to "+who->query("name"));
			return 1; 
	     }
	 item->remove();  
	 set( "chat_chance", 0 );

     tell_room( environment(), 
	    sprintf("��������%s(%s)��ͷ΢Ц��˵��: лл��\n",
		who->query("c_name"),who->query("name") )
		,who );
	tell_object( who,"�����������ͷ΢Ц��˵��: лл��\n");
	if( (int)who->query_quest_level("smith") < 1 ) {
		who->finish_quest("smith", 1);
		tell_object( who, 
			"[������� Smith ���񣬵õ� 1000 �㾭��]\n"
			);
		who->gain_experience(1000);
		}
	return 1;
}

void reset()
{
	set( "chat_chance", 15 );
}

int my_tactic()
{
	object victim, weapon;
	int wc;

	if( random(20)>4 ) return 0;
	if( !(victim= query_attacker()) ) return 0;
	if( !(weapon = victim->query("weapon1")) )
		weapon = victim->query("weapon2");
	if( !weapon ) return 0;
	tell_room( environment(), 
		"�������߾���������" + victim->query("c_cap_name") + "��" + 
		weapon->query("c_name") + "����ॡ�һ��������ȥ��\n",
		({ this_object(), victim }) );
	tell_object( victim,
		"�������߾������������" + 
		weapon->query("c_name") + "����ॡ�һ��������ȥ��\n");
	wc = weapon->query("weapon_class");
	wc -= weapon->query("wc_damaged");
	if( !weapon->query("wc_damaged") ) {
		weapon->add( "short", " (����)" );
	}
	weapon->add( "wc_damaged", wc/2 );
	victim->calc_weapon_class();
	return 1;
}

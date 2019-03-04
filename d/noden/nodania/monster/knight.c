// This is inherited of the monsters belongs to the Royal Knights who
// helps each other in the fight.
#include <mudlib.h>

inherit MONSTER;

int stop_attack(object player)
{
	object *obj;
	int i;

	obj = all_inventory( environment() );
	obj -= ({ this_object() });
	obj->help_me_fight(this_player());
	return 0;
}

void help_me_fight(object player)
{
	if( attackers && member_array(player, attackers)!=-1 ) return;
	kill_ob(player);
}

void init()
{
	string kni;

	add_action("order_me","order");
	if( (int)this_player()->query("war_score") > (int)query("war_score") 
	&& this_player()->query("knighthood") ) {
		tell_room( environment(this_player()),
            sprintf("%s��������������%s���˸����񣺡�%s���ˣ���\n",
		query("c_name"),this_player()->query("c_name"),to_chinese( this_player()->query("knighthood") ) )
	          );
	}
}

int order_me(string arg)
{
	object master;
	object new_guard;
	object* eqs;	
	int wealth;
	int i;
	
	master = this_player();
	if (!master) return 0;

	wealth = master->query("wealth/silver");
	if (wealth < query("war_score") ) return 
		notify_fail("�����ϵ�Ǯ������֧������нˮ��\n");
	if (!id(arg)) return notify_fail("��������˭����ָ��?\n");
	if (!master->query("knighthood"))
		return notify_fail("��û�з��, ƾʲ���������?\n");
	if ( master->query("war_score")<query("war_score")*10)
		return notify_fail("���ս������, û�ʸ���������\n");
	if ( master->query_temp("now_guard") ) 
		return notify_fail("���Ѿ���һ������������, ��������?\n");	
	if (!query("body_guard")) {
		write(this_object()->query("c_name")+
		"˵��:������ְ������, �޷�������ˡ�\n");
		return 1;
	}
	eqs=all_inventory(this_object());
	this_object()->delete("weapon1");
	this_object()->delete("weapon2");
	for ( i=sizeof(eqs)-1 ; i >-1 ; i--) {
		if (eqs[i]->query("equipped")) eqs[i]->delete("equipped");
		eqs[i]->remove();
	}	
	master->set_temp("now_guard",1);
	tell_room(environment(master),sprintf(
	"%s˵��:����, ��������˼�ӳ�������, ������%s����ָ�ӡ�\n%s����ææ���뿪�ˡ�\n",
	this_object()->query("c_name"),
	master->query("c_name"),
	this_object()->query("c_name"))
	);
	new_guard=new(query("body_guard"));	
	new_guard->set_master(master,this_object());
	new_guard->set( "natural_armor_class", 0 );
	new_guard->move_player(environment(master),"");
	write ( sprintf("���ó�%dö���Ҹ�������������ĳ����:p\n",
		query("war_score") ) );
	master->set("wealth/silver",wealth-query("war_score") );	
	this_object()->remove();
        return 1;
}

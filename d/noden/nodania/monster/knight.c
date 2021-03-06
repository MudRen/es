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
            sprintf("%s恭敬地立正，向%s行了个军礼：「%s大人！」\n",
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
		notify_fail("你身上的钱不足以支付他的薪水。\n");
	if (!id(arg)) return notify_fail("你想命令谁听你指挥?\n");
	if (!master->query("knighthood"))
		return notify_fail("你没有封爵, 凭什麽命令别人?\n");
	if ( master->query("war_score")<query("war_score")*10)
		return notify_fail("你的战功不够, 没资格命令他。\n");
	if ( master->query_temp("now_guard") ) 
		return notify_fail("你已经有一个贴身侍卫了, 还想怎样?\n");	
	if (!query("body_guard")) {
		write(this_object()->query("c_name")+
		"说道:属下有职责在身, 无法跟随大人。\n");
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
	"%s说道:遵命, 在下向雷思队长报备後, 就听从%s大人指挥。\n%s急急忙忙的离开了。\n",
	this_object()->query("c_name"),
	master->query("c_name"),
	this_object()->query("c_name"))
	);
	new_guard=new(query("body_guard"));	
	new_guard->set_master(master,this_object());
	new_guard->set( "natural_armor_class", 0 );
	new_guard->move_player(environment(master),"");
	write ( sprintf("你拿出%d枚银币给你的侍卫当他的出差费:p\n",
		query("war_score") ) );
	master->set("wealth/silver",wealth-query("war_score") );	
	this_object()->remove();
        return 1;
}

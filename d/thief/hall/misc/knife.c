#include <mudlib.h>
#define MASK_OBJ "/d/thief/hall/misc/mask"
#define MAKE_SKILL "anatomlogy"
inherit OBJECT;

init()
{
	add_action("do_cut","cut");
}

void create()
{
	seteuid(getuid());
	set_name( "knife","割皮小刀" );
	set_short( "割皮小刀" );
	set_long( @LONG
    这是一把轻薄锐利的小刀, 是擅长制造面具的人常用的工具之一。
你可以用 cut skin from corpse 取一块皮来做面具。
LONG
	);
	set( "weight",10 );
	set( "unit","把");
	set( "value",({ 230,"silver" }));
}
int check_skill(object me)
{
	int skill1,skill2,rate;
	if ( (string) me->query("class") != "thief" ) 
		return 0;
	if ( ( skill1 = (int) me->query_skill(MAKE_SKILL) ) == 0 )
		return 0;
	if (random(skill1 + (int) me->query_stat("piety") ) > 20 )
		return 1;
	else 
		return 0;
}

int query_sp_cost(object me)
{
	return ( 80 - (int)me->query_skill(MAKE_SKILL) ) ;
}

do_cut(string arg)
{
	string *args,tmp;
	int sz,i,skill;
	object *inv,env,mask,corpse,mob;

	if ( ! arg ) 
		return notify_fail("你想要割什麽?\n");
	if ( sscanf(arg,"skin from %s",tmp) != 1)
		return 0;
	if ( !this_player()->query_vision() )
		return notify_fail("这里一片漆黑 ! 你什麽也看不到 !!\n");
	env = environment(this_player());
	if ( ! (corpse = present(tmp,env)) ) 
		return notify_fail("这里没有这种□体 。\n");
	if (sscanf((string)corpse->query("short"),"%s的尸体",tmp) < 1 || tmp == "腐烂") {
		return notify_fail("这□体已经发臭了, 做成面具可能会得皮肤病, 你敢吗?? \n");
	}
	if ( (i = query_sp_cost(this_player())) > (int)this_player()->query("spell_points") ) {
		return notify_fail("你精神力太低了, 无法做这种精细的工作。\n");
	}

	this_player()->add("spell_points",-i);
	if ( ! (tmp = (string) corpse->query("npc")) ) 
		return notify_fail("割下皮後,你觉得这种材料并不适合做面具。\n");
	mob = new(tmp);
	if ( nullp(mob) ) {
		write("这边有 bug, 请通知巫师!\n");
		return 1;
	}

	if ( check_skill(this_player()) ) {
		tell_room(env,sprintf("%s在□体上划几刀, 取下某样东西。\n",this_player()->query("c_name") ), this_player() );
		write(sprintf("你小心翼翼的从□体上取下脸皮, 顺利的完成了%s的面具。\n",(string)mob->query("c_name") ));
		mask = new(MASK_OBJ);	
		mask->set_short(mob->query("short")+"的面具");
		mask->set("mask_name", mob->query("name") );
		mask->set("c_mask_name",mob->query("short") );
		mask->add("extra_ids",mob->query("id"));
		mask->move(this_player());
		corpse->remove();
		mob->remove();
		return 1;
	} else {
	tell_room(env,sprintf("%s试著从□体上取下脸皮, 结果失败了!\n",this_player()->query("c_name") ), this_player() );
		corpse->remove();
		mob->remove();
		return notify_fail("你一个不小心, 割坏了皮, 不能用了!!\n");
	}
}


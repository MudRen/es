// cube.c  For magic-cube spell     By Yueh@Eastern_Story 1995/3/2  
// special thanks for Ega's help////#pragma save_binary
#include <move.h>
#include <mudlib.h>
#include <money.h>
#include "/d/magic/magic.c"
#define TYPE "misc"
inherit OBJECT;

#define TRANSFER_SP 10
#define G_EXP 4
string query_long();

void create()
{
	set_name("magic cube", "魔法方块");
	add( "id", ({ "cube" }) );
	set_short("魔法方块");
	set("long", "@@query_long");
	set( "extra_look", "$N身旁飘浮著一个发著奇异光芒的魔法方块。\n");
	set("weight", 0);
	set("weight_apply", 0 );
	set("max_load", 400);
	set("value", ({ 1500, "silver" }));
	set("prevent_insert", 1);
	set("prevent_drop",1);
	set("prevent_put_money", 1);
}

void init()
{
   add_action("do_transfer","transfer");
}
   
int receive_object(object ob)
{
        int weight ;
        weight = ob->query("weight") ;
        if ( weight + this_object()->query("load") >
                this_object()->query("max_load") )
                return 0;
        this_object()->add("load",weight);
        return 1;
}

int release_object(object ob)
{
        this_object()->add("load",-ob->query("weight"));
        return 1;
}
   
int help ()
{
return notify_fail( "指令格式: transfer <东西> into cube \n指令格式: transfer <东西> from cube \n");
}

int query_sp_cost(object caster)
{
	return modify_sp_cost(caster, TRANSFER_SP, TYPE, 25);
}

int transfer_into (string this)
{
	int res, num, has,sp;
	object ths,tht,ob;
	string that ,c_word;
 
	sp = query_sp_cost(this_player());
	if (this_player()->query("spell_points") < sp){
		write ("你的法力不够！\n");
		return 1;
	}

	ths = present(this, this_player());
 
	if(!ths) {
		write( "你没有这样东西。\n");
		return 1;
	}

	if((int)ths->query("prevent_drop")) {
		write( "你没有办法将这个东西转送进去。\n");
		return 1;
	}
 
	if((int)ths->query("prevent_insert")) {
		write( "你不能把这种东西转放进去。\n");
		return 1;
	}

	res = (int)ths->move(this_object());

	if(res == MOVE_OK) {
		c_word = ths->query("short");
		write( "你口中念著咒语，你手上的" + c_word + "渐渐消失在魔法方块里。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "口中念著咒语，他手上的" + c_word + "渐渐消失在魔法方块里。\n",
			this_player());
		this_player()->add("spell_points", -sp );
		gain_spell_experience(this_player(), TYPE, G_EXP);
		return 1;
	}
 
	if(res == MOVE_NO_ROOM) 
		write( "里面空间不够。\n");
 
	else if(res == MOVE_TOO_HEAVY) 
		write( "它的重量太重了。\n");
 
	else if(res == MOVE_NOT_ALLOWED) 
		write( "你不能在里面放东西。\n");
 
	return 1;

}

int transfer_from(string this)
{
	int res, i,j, num, has, sp;
	object ths, tht, *contents;
	string that, c_word;
 
// Check for the form "transfer thing from sack".

	sp = query_sp_cost(this_player());
	if (this_player()->query("spell_points") < sp){
		write ("你的法力不够！\n");
		return 1;
	}

	tht = this_object();

	if (this != "all") {
		ths = present(this, tht);
		if(!ths) {
			write( "你没有这样东西。\n");
			return 1;
		}

		c_word = ths->query("short");
		res = (int)ths->move(this_player());
		if( res == MOVE_OK ) {
			write ( "你口中念著咒语，从魔法方块中飞出"+c_word+"渐渐成形在你手里。\n");
			tell_room( environment(this_player()), 
				this_player()->query("c_name")+"口中念著咒语，从魔法方块中飞出"+c_word+"渐渐成形在他手里。\n",
					this_player() );
			this_player()->add("spell_points", -sp );
			gain_spell_experience(this_player(), TYPE, G_EXP);
			return 1;
		}
		if( res == MOVE_NOT_ALLOWED ) 
			notify_fail( "你没有办法拿起这样东西。\n");
		if( res == MOVE_NO_ROOM )
			notify_fail( "你身上没有多馀的空位。\n");
			// This should never happen.
		if( res == MOVE_TOO_HEAVY )
			notify_fail("太重了，你拿不动□n");
		return 0;
	}

// If we got here, it means we're doing a "transfer all from cube".
	contents = all_inventory(tht);
	j = sizeof(contents);
	if ( j> 0 ) {
		for (i=0;i<j;i++) {
			ths = contents[i];
 
			if((int)ths->query("prevent_get")) {
				write( "你不能拿走" + ths->query("short") + "。\n");
				continue;
			}
 
			c_word = ths->query("short");
			res = (int)ths->move(this_player());
			if (res == MOVE_OK) {
			write ( "你口中念著咒语，从魔法方块中飞出"+c_word+"渐渐成形在你手里。\n");
			tell_room( environment(this_player()), 
				this_player()->query("c_name")+"口中念著咒语，从魔法方块中飞出"+c_word+"渐渐成形在他手里。\n",
					this_player() );
			this_player()->add("spell_points", -sp );
			gain_spell_experience(this_player(), TYPE, G_EXP);
			}
		}
	}
	else {
		write( "那里面什麽也没有。\n");
		return 1;
	}
}

int do_transfer(string str)
{
	int num;
	string this;
	if (!str) return help();
	if(!this_player()->query("vision")) {
		write( "你什麽也看不见。\n");
		return 1;
	}
	if(sscanf(str,"%d %s into cube",num, this)==2) {
	if ((this == "platinum") || (this == "gold") || (this == "silver") || (this == "copper"))
		{
		write( "对不起, 我不替人保管钱。\n");
		return 1;
		}
	return help();
	}
	if (sscanf(str, "%s into cube", this) == 1) {
		transfer_into(this);
		return 1;
	}
	if (sscanf(str, "%s from cube", this) == 1){
		transfer_from(this);
		return 1;
	}
	return help();
}

string query_long()
{
	object *inv;
	int i,j;
	mixed desc;

	desc = "这是一个飘浮在空中发著奇异光芒的魔法方块，似乎可以储存不少东西。\n";
		inv = all_inventory(this_object());
		j = sizeof(inv);
		if ( j > 0 ) {
			desc += "里面有:\n";
			for(i=0; i<j; i++)
				desc += sprintf("  %s (%s).\n", (string)inv[i]->query("short"), (string)inv[i]->query("name"));
		}
	return desc;
}

void disappear()
{
    int i;
    object me, ths, *contents;
	me = this_object();
	contents = all_inventory(me);
	if (sizeof(contents) > 0 ) {
                tell_room(find_object_or_load("/d/mage/tower/library"),
			"一阵光芒使你睁不开眼睛。\n");

		tell_room(find_object("/d/mage/tower/library"),
			"光芒渐渐消失你又能看见了。\n");
		
		contents->move("/d/mage/tower/library");
	}
    tell_room( environment(environment(me)),
      "魔法方块闪了几下，消失了。\n");

    me->remove();
}

int move( mixed place )
{
    if( objectp(place) && !living(place) )
        disappear();
    return ::move(place);
}

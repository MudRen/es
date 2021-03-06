#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Mahogany Kirs","桃木短刀" );
	add( "id",({ "kirs" }) );
	set_short( "桃木短刀" );
	set_long(@LONG
	这是一把用桃木削成的剑，具有斩妖除魔的功用。如果你
	觉得谁是邪魔，只要将这短刀丢(throw)向他就可以了。
LONG
		);
	set( "unit","把" );
	set( "weight",50 );
	setup_weapon( "dagger",15,10,18 );
	set( "value",({ 10,"gold" }) );
	set( "no_sale",1 );
}

void init(){ add_action( "to_throw","throw" ); }

int to_throw(string arg)
{
	object holder,env,victim;
	string weapon,target,me;
	
	holder=this_player();
	env=environment(holder);
	
	if( !arg || sscanf(arg,"%s to %s",weapon,target)!=2 )
		return notify_fail( "Usage: throw <item> to <target>\n" );
	if( weapon!="kirs" )
		return notify_fail( "你确定要把这样东西丢出去？\n" );
	if( target!="vampire" )
		return notify_fail( "你突然觉的做这种事很缺德，所以下不了手。\n" );
	if( !(victim=present("kill_vampire1",env)) )
		return notify_fail( "这里并没有吸血鬼，再四处找找吧!\n" );
	if( undefinedp(this_object()->query("charge")) ){
	tell_object( holder,"你将短刀射向吸血鬼，但是很可惜的没射中。\n" );
	this_object()->remove();	
	return 1;
	}
	if( victim->query("hurt") )
		return notify_fail( "一把鲜红的短刀已经插在吸血鬼身上了，没必要插第二把。\n" );
	me=holder->query( "c_name" );
	tell_object( holder,set_color(
	"\n你手中的桃木剑化成一道红光向吸血鬼疾射而去，正中吸血鬼的心脏。\n\n","HIR") );
	tell_room( env,set_color(
	"\n"+me+"手中的桃木剑化成一道红光向吸血鬼疾射而去，正中吸血鬼的心脏。\n\n","HIR"),holder );
	victim->receive_damage( 3000 );
	victim->set( "conditions/bleeding",({ 2,10,500 }) );
	victim->set( "hurt",1 );
	tell_room( env,"\n吸血鬼痛苦的呻吟著说：想不到你用这种卑劣的手段对付我！\n\n" );
	this_object()->remove();
	return 1;
}

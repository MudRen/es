#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("minor spirit pill", "提神丹" );
	add( "id", ({"spirit", "pill"}) );
	set_short("a minor spirit pill", "提神丹");
	set_long(
		"You see a small white pill with cool smell.\n",
		"这是一粒散发著清凉味道的白色丹药。\n"
	);
	set( "medication", 20 );
	set( "effect_critical",20);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 250, "silver" }) );
}

void eat(object player)
{
	int max, sp;

	if( !max = player->query("max_sp") ) return;
	if( (sp=player->query("spell_points")) >= max ) return;
          if(this_player()->query("class")=="mage")
    {
	tell_object( player, "你觉得你的法力恢复了！\n" );
    }
         else { tell_object(player, "你觉得你的精神力恢复了 ！\n" ); }
	if( sp + 50 > max ) player->set("spell_points", max);
	else player->set("spell_points", sp+50 );
}

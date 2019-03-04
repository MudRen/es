#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("speed pill", "��ң��" );
	add( "id", ({"pill"}) );
	set_short("��ң��");
	set_long(
		"�������̴����з����Ľ�ҩ,ר�Ž��������Ե�֢״��\n"
		"�������ü��⽩Ӳ,��(eat)����Ӧ�в����Ч��!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "��" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
	set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/slow") ) return;
	tell_object( player, can_read_chinese(player)?
		"����ü��ⲻ�ٽ�Ӳ�ˣ�\n": "You recover from poison!\n" );
	stat = (int) player->query("slow");
	player->modify_stat("dex",stat);	
	"/std/conditions/slow"->remove_effect(player);
}

#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson amulet", "�ʺ�ɫ�����" );
	add( "id", ({ "amulet" }) );
	set_short( "�ʺ�ɫ�����" );
	set_long(
		"����һ���ʺ�ɫ��Բ�θ��ң���������һ�������εı�ǡ�\n"
	);
	set( "type", "misc" );
	set( "material", "leather" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
    set( "special_defense",
           ([ "evil":5, "magic":5, "divine":-10 ]) );
    set( "extra_skills", ([ "target":10 ]) );       
	set( "weight", 10 );
	set( "value", ({ 840, "silver" }) );
	set( "no_sale", 1 );
}

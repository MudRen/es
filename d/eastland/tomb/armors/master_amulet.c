#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "master amulet", "��ʦ����" );
	add( "id", ({ "amulet" }) );
	set_short( "��ʦ����" );
	set_long(
		"һ��Ư���Ļ�������������һЩ����������ħ�����ţ��㿴����\n"
		"�ڻ�Щʲ�ᡣ\n"
	);
	set( "unit", "��" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 7 );
	set( "special_defense",
	     ([ "fire":20, "cold":20, "electric":10, "energy":10 ]) );
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 3500, "silver" }) );
}

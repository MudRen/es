#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
   set_name( "saliva of chocobo", "½����Ŀ�ˮ" );
   add( "id", ({ "saliva", "water" }) );
   set_short( "½����Ŀ�ˮ" );
	set_long(
           "����½����Ŀ�ˮ, ��������԰�������ȥ��\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
   set( "unit", "̲" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}

#include <mudlib.h>
inherit "/std/reagent";

void create()
{
	set_name( "neo grass", "ţ���" );
	add("id",({"grass","neo"}) );
	set_short("ţ���" );
	set_long(
	"��˵������һֻţ����ţ���֮��, ��·���������һ��, ���������˾������ƺ���\n"
	"����Գ���(taste)����ζ����\n"
	);
	set( "ident", "NEO_GRASS" );
	set( "unit", "��" );
        set( "weight", 1 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 10, "silver" }) );
}


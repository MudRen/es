#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "purple ratter", "������" );
	add("id",({"ratter"}) );
	set_short("������" );
	set_long(
		"��������ٱ�������ɫ��, ������������ȴ����������ɫ������Գ���(taste)����ζ����\n"
	);
	set( "ident", "PURPLE_RATTER" );
	set( "unit", "��" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 100, "silver" }) );
}


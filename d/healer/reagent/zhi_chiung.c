#include <mudlib.h>
inherit "/std/reagent";

void create()
{
	set_name( "zhi chiung", "֪��" );
	add("id",({"grass","chiung"}) );
	set_short("֪��" );
	set_long(
	"֪�������ڿ��Ĳ�ԭ, ������, ��Լֻ�����硣\n"
	"����Գ���(taste)����ζ����\n"
	);
	set( "ident", "ZHI_CHIUNG" );
	set( "unit", "��" );
        set( "weight", 1 );
	set( "savour","bitter");
	set( "effect","weak");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 30, "silver" }) );
}


#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "tiger's bone", "����" );
         set("no_sale",1);
	add( "id", ({ "bone" }) );
	set_short( "����" );
	set_long(
                "�����ϻ���ͷ��, ������Ϊһ��ҩ�ġ�����Գ���(taste)����\n"
	);
    set( "ident","BONE");
	set( "unit", "��" );
        set( "weight",3 );
	set( "savour","acidity");
	set( "value", ({ 300, "silver" }) );
}

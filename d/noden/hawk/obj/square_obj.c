#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Valor Amulet", "��������");
        add( "id", ({ "valor amulet","amulet" }) );
        set_short( "��������" );
        set("long","����һ��������С���£��������һ��СС���ġ�\n");
        set( "weight", 5 );
/*	 set( "prevent_drop", 1);
	 set( "prevent_insert", 1);	*/
        set( "unit", "ö" );
}


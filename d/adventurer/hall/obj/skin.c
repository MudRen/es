#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid(getuid());
	set_name("skin","ëƤ");
	set_short("ëƤ");
	set( "long","@@query_long");
	set( "unit", "��" );
	set( "weight",10 );
	set( "value",({10,"silver"}));
	set( "no_sale", 1);
	set( "c_skin_name","ëƤ");
	set( "skin_name","skin"); 
	set( "extra_ids",({}));
}

string query_long()
{
	if ( (string) this_object()->query("c_skin_name") != "skin" )
		return "����һ��" + (string) this_object()->query("c_skin_name") + "��ëƤ��\n";
	else
		return "����һ��ëƤ��\n";	
}



#include <mudlib.h>
inherit OBJECT;

void create()
{
	set_name( "Hwai", "»±Ä¾" );
	add("id",({"plant","tree","hwai"}) );
	set_short("»±Ä¾");
	set_long( "ÕâÊÇÒ»¶Î»±Ä¾µÄÊ÷Ö¦¡£\n");
	set( "ident", "HWAI" );
	set( "unit", "¶Î" );
        set( "weight", 4 );
	set( "value", ({ 10, "silver" }) );
}


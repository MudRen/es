#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "key of forever", "����֮Կ" );
	add( "id", ({ "key" }) );
   set_short( "����֮Կ" );
	set_long(
		"һ����ҫ�������â�������κ���ʯԿ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "ASTERISM_2" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
        
}

void init()
{
   
}


  

#include <../hole.h>

inherit WEAPON;
void create() 
{
	set_name( "Comb","����" );
	add( "id",({ "comb" }) );
	set_short( "Comb","����" );
	set_long(@LONG
	������������ͷ���Ĺ���
LONG
            );
	set( "unit","��" );
	set( "weight",9 );
	set( "value",({ 100,"silver" }) );
	setup_weapon( "blunt",8,5,15 );
	  set( "no_sale",1 );
}
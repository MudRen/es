#include <../hole.h>

inherit WEAPON;
void create() 
{
	set_name( "Baseball Bat","����Ũ���" );
	add( "id",({ "bat" }) );
	set_short( "Baseball Bat","����Ũ���" );
	set_long(@LONG
	������������С��������л����ν����
	������һ�����������򣬶�������������Ӿ�
	����������ģ���������Ҳ�����������˰� !
LONG
            );
	set( "unit","֧" );
	set( "weight",9 );
	set( "value",({ 100,"silver" }) );
	setup_weapon( "blunt",8,5,15 );
	set( "no_sale",1 );
}

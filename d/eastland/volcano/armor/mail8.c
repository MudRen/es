#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red mail", "���ۼ�" );
	add( "id", ({ "mail" }) );
	set_short( "���ۼ�" );
	set_long( 
             @LONG
����ۼ�����������ϵ���Ƭ�����˿���ƶ��ɡ�
LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 23 );
	set( "defense_bonus", 5);
	set( "special_defense",
	     ([ "energy":15, "cold":-5 ]) );
	set( "weight", 200 );
	set( "value", ({ 3000, "silver" }) );
}

#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "chainmail", "����" );
	add( "id", ({ "chain", "mail" }) );
   set_short( "����" );
	set_long(
		"����������в��ٱ������������ĺۼ�����������ԭ��������һ��\n"
		"����ս��\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 12 );
    set( "special_defense",
           ([ "acid":1, "poison":1 ]) );
	
	set( "weight", 180 );
	set( "value", ({ 80, "silver" }) );
}

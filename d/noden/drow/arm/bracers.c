#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("copper bracers", "��ͭ�ֻ�");
   add( "id", ({ "bracers" }) );
	set_short( "��ͭ�ֻ�" );
        set_long(
@C_LONG
���ǻ�ͭ������ֻ����������к��صĸо���
C_LONG
        );
	set( "unit", "��");
        set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "defense_bonus", 2 );                       
	set( "weight", 60 );
	set( "value", ({ 170, "silver" }) );
}

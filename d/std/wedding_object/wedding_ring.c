#include <mudlib.h>
inherit ARMOR;
void create()
{
	set_name( "wedding ring", "����ָ" );
	add( "id", ({ "ring" }) );
	set_short( "a wedding ring", "����ָ" );
	set_long(
	"This is a beautiful diamond wedding ring. And what even more\n"
	"beautiful is what it means - love.\n",
	"����һ��������������ʯ��ָ�����������������������������: ����\n"
	"����İ��顣\n");
	set("prevent_drop",1);
	set("no_sale",1);
	set("material","cloth");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "weight", 0 );
}
int query_auto_load() { return 1; }

#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather saddle", "Ƥ����" );
	add( "id", ({ "saddle" }) );
	set_short( "Ƥ����" );
	set_long(
	"����һ����ͨ��Ƥ����������ʿ�Ƕ���Ϊ�Լ��İ���ѡ�����ʵ�����\n" 
	);
	set( "type", "saddle" );
	set( "material", "leather" );
	set( "armor_class", 3 );
	set( "weight", 75 );
	set( "value", ({ 230, "silver" }) );
}

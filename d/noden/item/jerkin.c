#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "leather jerkin", "Ƥ�ƶ���" );
	add( "id", ({ "jerkin" }) );
   set_short( "Ƥ�ƶ���" );
	set_long(
		"���Ƥ�ƶ��������൱ϸ�ģ��ӷ촦���ýϴֵ�Ƥ��������㷢��"
		"���µĿڴ��ϻ��÷ۺ�ɫ��˿����������ķ����������\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "leather");
	set( "armor_class", 7 );
	set( "weight", 90 );
	set( "value", ({ 25, "silver" }) );
}

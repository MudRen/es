#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black swallaw-tail coat", "��ɫ��β��" );
	add( "id", ({ "coat" }) );
	set_short( "��ɫ��β��" );
	set_long( @LONG
���Ǽ��൱˧�������, ��ʿ������ʽ�ĳ��ϴ�ഩ���������·���
�������˵, ����·������ӻ�����, ����Ҳ�൱���ġ�
LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 18 );
	set( "weight", 30 );
	set( "value", ({ 500, "silver" }) );
}

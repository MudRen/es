#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "eagle bracers", "��ӥ��\������" );
	add( "id", ({ "bracers" }) );
	set_short( "��ӥ��\������" );
	set_long(@C_LONG
����ӥצ�ŵ�����֮�����ഫ���ܹ�����һ���˵Ļ����ڹ�\������
������������ĳ�ֺ�ɫ��˿�����ɵģ���������һֻ��ɫ��ӥ��
C_LONG
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "no_sale", 1 );
	set( "armor_class", 1 );
	set( "extra_skills", (["inner-force":5]) );
        set("material","cloth");
	set( "weight", 70 );
	set( "value", ({ 1760, "silver" }) );
}

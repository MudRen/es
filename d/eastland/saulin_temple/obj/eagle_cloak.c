#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver cloak", "��ӥ֮��" );
	add( "id", ({ "cloak" }) );
	set_short( "��ӥ֮��" );
	set_long(@C_LONG
��ӥ��˵�Ǿ�ס�ڸ�ɽ���ļ�ϡ�����������ë��˵ʮ�ֵ����
��ӥ֮��������ӥ����ë���ɵ����ӣ��ֱ�ů���м��ѵı���Ч����
C_LONG
                );
	set( "unit", "��" );
	set( "type", "cloak" );
	set( "armor_class", 8 );
	set( "material", "leather" );
	set( "defense_bonus", 4 );
	set( "weight", 100 );
	set( "value", ({ 2530, "silver" }) );
}

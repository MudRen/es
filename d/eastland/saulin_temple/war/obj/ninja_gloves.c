
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja gloves", "��������" );
        add( "id", ({ "gloves" }) );
        set_short( "��������" );
        set_long(@C_LONG
����һ˫����ר�õĺ�ɫƤ���ף������۵�����£�ȴ��������
ƽ���ĸ�������ʹ�ô��������������κ�ƽ����ǽ�ڡ��ݶ���ȥ
���磬�����������൱�ء�
C_LONG
        );
        set( "unit", "˫" );
        set( "type", "hands" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "weight", 80 );	
	set( "value", ({ 950, "silver" }) );
}

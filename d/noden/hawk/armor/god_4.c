#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hades Veil","�ڵ�˹��ɴ" );
        add( "id", ({ "veil","hades veil" }) );
        set_short( "�ڵ�˹��ɴ" );
        set_long(
                "��ֻ��ɫ����ɴ���滭�������а���ͼ��, ��������ڤ���"+
                "��˹���õġ�\n"
        );
        set( "unit", "ֻ" );
	set("material","cloth");
	set( "type", "head" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}

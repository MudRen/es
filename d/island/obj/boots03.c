#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("black tiger boots","�ڻ�ѥ");
        add( "id", ({ "boots" }) );
        set_short("�ڻ�ѥ");
        set_long(@C_LONG
��˫Ƥѥ������һͷ��ɫ���ϻ��������ż��ˡ�        
C_LONG
        );
        set("unit", "˫");
        set("type", "feet" );
        set("armor_class", 9 );
        set("material","leather");
        set("defense_bonus", 1 );
        set("weight", 30 );
        set("value", ({ 900, "silver" }) );
}

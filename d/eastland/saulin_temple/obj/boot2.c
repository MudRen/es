#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("silver dragon boots", "����ѥ");
        add( "id", ({ "boots", "boot" }) );
        set_short("����ѥ");
        set_long(@C_LONG
�����й�������֮��, ����ѥ�ഫ������͸������ʵ۵�����֮Ь, 
���ɳ�͢�͸����ֶ��᲻����ʧ... ���ڿ����������־ɵġ�
C_LONG
        );
        set("unit", "˫");
        set("type", "feet" );
        set("armor_class", 8 );
        set("material","monk");
        set("defense_bonus", 3 );
        set("weight", 30 );
        set("value", ({ 2600, "silver" }) );
}

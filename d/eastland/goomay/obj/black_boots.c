#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name("black boots", "��ѥ");
        add( "id", ({ "boots","boot" }) );
        set_short("a pair of black boots", "��ѥ");
        set_long(
                "A pair of boots made of cloth  .\n",
"һ˫մ����͵ĺ�ɫѥ�ӣ���˵�ǰ�������������ģ����������� \n" 
"ʱ�����ᱧ��ѥ��ʹ��... \n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set("material","leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 600, "silver" }) );
}

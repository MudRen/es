#include "../zeus.h"

inherit ARMOR;

void create()
{
        set_name("comfortable boots", "���ⱡѥ");
        add( "id", ({ "boots","boot" }) );
        set_short("���ⱡѥ");
        set_long(@AA
����һ˫����Ƥ�����Ƴɵı��׿�ѥ�������������������Ь���е���Ʒ��
AA
);
        set( "unit", "˫");
        set( "type", "feet" );
        set("material","leather");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 40 );
        set( "value", ({ 600, "silver" }) );
        }
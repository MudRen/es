#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "karate_clothes", "���ֵ���");
        add( "id", ({ "cloth","clothes" }) );
        set_short("karate_clothes", "���ֵ��� ");
        set_long(
           "һ�������ֵ��������ĵ��� \n"
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 10 );
        set( "defense_bonus", 1 );
        set("cloth");
        set( "weight", 100 );
        set( "no_sale",1);
        set( "value", ({ 300, "silver
        " }) );
}

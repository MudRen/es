#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Cold jade armor","�������");
        add("id",({"armor","jade"}) );
        set_short( "�������");
        set_long(
"����һ������ɫ����ף�����Ըо�����͸��˿˿�ĺ��⡣\n"
        );
        set( "unit", "��" );
        set( "weight", 80 );
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 5 );
        set( "value", ({ 320, "gold" }) );
        set( "special_defense", ([ "fire": 10 , "cold":  -10]) );
        set("no_sale",1);
 }


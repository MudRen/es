#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Sky Cloth","����");
        add("id",({"cloth"}) );
        set_short( "@@title");
        set_long(
"��˵���������޷�ģ�����㿴��������·�����Ҳ����ӷ죬��֪��
������Ƴɵġ�\n"
        );
        set( "unit", "��" );
        set( "weight", 120 );
        set( "type", "body" );
        set( "light", 1);
        set( "material", "cloth");
        set( "armor_class", 32 );
        set( "defense_bonus", 8 );
        set( "value", ({ 199, "gold" }) );
        set( "special_defense", ([ "fire":10,"cold":10,"evil":10 ]) );
        set("no_sale",1);
}

string title()
{
	return set_color("����","HIW");
}
#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gin plate", "�ᾧ����");
        add( "id", ({ "plate" }) );
        set_short("gin plate", "�ᾧ����");
        set_long(@AAA
����һ����ʯӢ��ʯ������ɣ��������Ե�Ӣ�˻�������â���䡣
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 35 );
        set( "defense_bonus", 10 );
        set("material","element");
        set("special_defense",(["fire":15])) ;
        set( "weight", 400 );
        set( "value", ({ 1000, "silver" }) );
}


#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("wraith flamen ring", "�����˾֮��");
        add( "id", ({ "ring" }) );
        set_short("�����˾֮��");
        set_long(
     "������������������˾����ʱ������ʥ�ӵ�����ϵ�Ȩ����������\n"
        );
	set("unit","ֻ");
        set( "type", "finger" );
        set( "material" ,"element" );
        set( "defense_bonus", 6 );
	set("special_defense",(["evil":15]));
        set( "weight", 5 );
        set( "no_sale",1);
}

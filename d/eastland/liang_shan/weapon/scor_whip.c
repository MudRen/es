#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tail of scorpion","Ы��β��");
       add("id",({"whip","tail",}) );
       set_short("Ы��β��");
	   set_long(
	   "����һֻЫ�ӵ�β�ͣ�ĩ�����������ĵ��̣�Ҳ�����������������...\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 25 );
        set("type","whip");
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 10 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1 );
    set_c_verbs(({
    "%s�ӳ�һ���ȷ磬����%s",
    "%s����һ�ӣ����̴���%s",
    "%s�߸߾����ɿ������߰��ֱϮ��%s",}));
}


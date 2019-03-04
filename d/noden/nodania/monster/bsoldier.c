#include <mudlib.h>
#include "/d/noden/nodania/nodania.h"
inherit "/d/noden/nodania/monster/guard" ;

void init()
{
	::init();
	add_action("order_me","order_guard");
	add_action("help_order", "help_guard");
}

void create()
{
        ::create();
        set_level(6);
        set_name("body guard","��������");
        add( "id", ({ "guard" }) );
        set_short( "�Ҳ������˵���������");
        set_long(
@C_LONG
��λ�����������ڲ�����, ��������������, ������һ��bug������ȥ
�������� *puke*
��������������ˣ�������� order_guard <commands> ���������¡�
���⻹��һЩָ��, ����Դ�help_guard������
C_LONG
        );
        set("post_name","'s body guard");
        set("c_post_name","����������");
        set("prevent_give_money", 1);
        setenv("C_MMIN","$N���������������˹���");
        setenv("C_MMOUT","$N�������������߿�");
	set_perm_stat("str", 10 );
	set_skill("polearm", 35);
	set_skill("parry", 35);
	set_skill("defend",35);
	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 20 );
	set( "war_score", 100 );
	set( "alignment", 300 );

	wield_weapon(NODANIA"obj/pike");
	equip_armor(NODANIA"obj/chainvest");
}

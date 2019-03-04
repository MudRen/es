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
        set_level(14);
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
	set_perm_stat("str", 20 );
	set_perm_stat("dex", 20 );
	set_perm_stat("con", 20 );
	set_skill("axe", 75);
	set_skill("parry", 75);
	set_skill("block", 75);
	set_skill("defend",75);
	set_natural_armor( 30, 6 );
	set_natural_weapon( 10, 4, 8 );

	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 600 );
	set( "wealth/silver", 300 );
	set( "special_defense", ([ "all": 25 ]) );
	set( "war_score", 5000 );
	wield_weapon("/d/knight/fortress/weapons/battleaxe");
	equip_armor(NODANIA"obj/shield");
	equip_armor(NODANIA"obj/breast_plate");
}

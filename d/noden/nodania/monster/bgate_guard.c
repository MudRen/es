#include <mudlib.h>
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
        set_level(10);
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
	set_perm_stat("str", 13 );
	set_skill("longblade", 55);
	set_skill("parry", 55);
	
	set( "race", "human" );
	set( "gender", "male" );
	set( "natural_armor_class", 40 );
	set( "war_score", 500 );
	set_skill("defend",55);
	wield_weapon("/d/knight/fortress/weapons/longsword");
	equip_armor("/d/knight/fortress/armors/chainmail");

}


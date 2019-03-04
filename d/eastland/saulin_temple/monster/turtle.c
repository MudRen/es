#include "/d/noden/moyada/moyada.h"
inherit MONSTER;

void create ()
{
    object ob1;
	::create();
	seteuid( getuid() );
	set_level(14);
	set_name( "Fast turtle", "���ٹ�" );
	add ("id", ({ "turtle", }) );
	set_short( "���ٹ�" );
	set_long( @C_LONG
�㿴��һֻ����Ь��ͷ���С�ڹ�,����һ˫�����۾�,���̵�����...
���Ǵ�˵�з��������ڹ�,�ɱ�����һ���Ӿ�������!!!��
C_LONG
	);
	set( "alignment", 2000 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 1500);
	set ("hit_points", 1500);
	set ("natural_weapon_class1", 250);
	set ("natural_defense_bonus",10);
	set ("natural_armor_class", 25);
	set ("natural_min_damage1", 3); 
	set ("natural_max_damage1", 5);
	setenv( "C_MIN", "һֻ$N�ܿ�����˹�����");
	setenv( "C_MOUT", "$N���ٵ���$D�������ˡ�");
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 1, ]) );
	set ("special_defense",
	    ([ "all" : 10, "none" : 10 ]) );
	set ("wimpy", 50);
	set ("moving", 1);
        set ("speed",50);
    set ("weight", 100);
    set ("exp_reward", 3000);
    set ("chat_chance",14);
    set ("chat_output", ({
"����֪���������� �ڹ�Ϊʲ���Ӯ��? ��Ϊ�����Ҵ���μ���!!!��������!!!��\n"
    }) );
    
set("att_chat_output",({
   "������!!! ƾ������ץ�����ҵ���!!! \n" ,
   "������!!! ������!!! ȥץ��������!!! ����Ϻ!!! :p\n"
   }));
 
    set_c_verbs( ({ "һ�µ��������Ĺ��������ı���", "��β��ɨ����Դ�",
                    "����ı��ϻ�һֻ���ڹ�!!!" }) );
    set_c_limbs( ({ "���","��֫","β��","����"  }) );
    set( "c_death_msg", 
"%s˵:����� ������!!! ������������ڹ�ȥ��������!!!����ҡҡͷ,Ȼ������ˡ�\n" );
    ob1=new( "/u/a/angel/item/ac.c" );
    ob1->move(this_object()); 
}


int catch_huntee( object who )
{
    tell_room( this_object(), 
      "���ٹ꿴�� "+who->query("c_name")+" ��С����ǻ���!�����ŵش��\n"
    ,  ({ this_object(), who }) );
    tell_object( who, 
      "���ٹ꿴����֮�ᣬ��С����ǻ���!!!��Ѹ�ٵ��ӿ�\n" 
    );
    return 1;
}

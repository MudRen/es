#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "chau", "���޼�" );
	add( "id", ({ "chau" }) );
	set_short( "���޼�" );
	set_long(@C_LONG
���޼�˵����ͺ���,�ƺ���Ҳ����,˵�������,ȴ��ȫȻ����, ��֮����ʮ�굽
��ʮ��֮��,��ò˵�󲻳�,˵��������һ�������������,������������д�˭
Ҳ��֪������������ʲ��? 
C_LONG	
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1200 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "kar", 20 );
        set_perm_stat( "dex", 30 );
	set_skill( "parry", 50 );
        set_skill( "block", 50 );
	set_skill( "dodge", 50 );
        set_skill( "unarmed", 50 );
        set("special_defense", ([ "all": 35,"none":40]) );
        set( "aim_difficulty",([ 
               "critical":60,"weakest":40,"ganglion":50,"vascular":80 ]) );
	set( "wealth/gold", 110 );
        set( "hit_points", 480);
        set( "max_hp", 480);
        set("max_fp", 400);
        set("force_points", 400);
        set("force_effect", 5);
        set_natural_armor(65,55);
        set_natural_weapon(55,23,33);
        equip_armor(DARMOR"chau_cloth");
        set("chat_chance",5);
        set("chat_output",({
          "���޼�������˵��:ԭ�����,ԭ����ˡ���֪���,�ڲ���������������,���к���?\n"
        }) );
        set_c_verbs( ({ "%sʹ��һ�С�͵��ת���%s���˹�ȥ",
                        "%s����һʽ ���󽭶�ȥ������%s",
                        "%s��֧��ҡҡ��������%s͵Ϯ"
        }) );
}
int stop_attack()
{
	object slave, *tmp;

	slave = present( "donkey", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "��¿˵��:���ҹ����ҵ����ˣ���Ҫ���ˣ�\n" 
		"��¿�������˹�����\n"
	);
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( slave, tmp )==-1 ) {
		add_temp( "protectors", ({ slave }) );
		slave->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = slave->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		slave->kill_ob( this_player() );
}
void init()
{
    ::init();
    add_action("do_mount","mount");
}
int do_mount(string arg)
{
     object me;
     me=this_player();
     if (!(me->query("class")=="knight"))
        return 0;
     tell_object(me,"���޼�˵��:����͵�ҵ�¿�Ӱ�?\n");    
     return 1;
}
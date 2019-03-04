
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(16);
	set_name( "Doctor Angelina", "Ůҽ��������" );
	add( "id", ({ "doctor", "angelina", }) );
	set_short( "a female doctor Angelina", "Ůҽ��������" );
	set_long(
		"NEED TRANSLATION.\n",@DESC
һ��ҽ��������Ůҽ��,������ϸ�ĺ�����֮��,������˵�սʿ�Ƕ��ܺ�
��Ŀ���.
DESC
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set_perm_stat( "int", 26 );
	set_perm_stat( "kar", 28 );
	set_perm_stat( "dex", 14 );
	set_skill( "dodge", 99 );
	set_skill( "dagger", 87 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "vascular" );
	set( "max_hp", 330 );
	set( "hit_points", 330 );
	set_natural_armor(88,22);
	set_natural_weapon(10,16,22);
	set( "special_defense", ([ "all": 28 ,"none":10]) );
	set( "aim_difficulty",([ "critical": 20, "weakest":30 , "vascular":30]) );
	set( "alignment", 1200 );
    equip_armor(Armour"/necklace01");
	wield_weapon(Weapon"/dagger05");
    set( "tactic_func", "aim_point");
    set ( "inquiry",([
	      "queen":"@@ask_queen",
	      "litterateur":"@@ask_litterateur",
	      ]) );
}

int aim_point()
{
    if (random(10)<5)
      set( "aiming_loc", "vascular" );
    else
      set( "aiming_loc", "weakest" );
      
      return 0;
}

int accept_item(object ob1,object ob2)
{
    if ( !ob2 ) return 0;
    if (ob2->query("echo_pearl")) {
       tell_object(ob1,@MSG1
������Ц������˵:лл�������,
���Ѿ�Ѱ���ⶫ���ܾ���,��ʱ�������ֵ�ʱ��,�Ҳ�С�İ�����Ҵ��ı�
����ʧ��,�벻����������������ֻص��ҵ�����.
������С�Ľ����ذ��鱦��������.
MSG1
);
       ob2->remove();
       ob1->set_explore("deathland#30");
       call_out("tell_secret",10,ob1);
       return 1;
       }
    else return 0;   
}

void tell_secret(object ob1)
{
     tell_object(ob1,@MSG2
������������˵:�����Ҳ�Ӧ��������ܡ�¶��ȥ,����Ҳ����������
��������ܹ���æ���峤�ϵ��鷳.�����ڰ��峤�ϵ��ſ�˵�����е�����
(intelligence)��Ϳ��Լ���������İ��˳�����.
MSG2
);
     return ;
}

void ask_queen(object who)
{
     tell_object(who,@MSG3
�����Ļʺ�, �Դ����Ĵ��������֮��, �Ҿ���Ҳû�м���
����Ц����, ��Ȼ�Ҳ���Ȱ��, ����ʼ��û��������. ����
���Ƕ���ĺ�����, Ϊ�˰�����, ��Ҳ���˲�������. ����
��һ���������õķ���, �ʺ���һ��ϲ����ѧ����, �����
�����˰��������Ƿ��ܹ����ʺ�������ѧ, �ûʺ��ע����
�ܹ�ת�Ƶ���ϲ������ѧ��, �����������ɥ��֮ʹ, ����
���ʫ��ȴ�����˴����ͳ�, �޷������ʺ�......
������Ǹ��������ѧ��(litterateur)Ҳ����ܹ������ʺ��.
MSG3
                );
     return;
}

void ask_litterateur(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/good_poet")) {
           tell_object(who,@MSG4
ԭ�����Ǹ���ѧ���Ұ�! ����һ��Ҳ\��\���ܰ����ʺ�ָ������յ�
Ц��Ҳ˵����.
�������ó�һ��С���θ���.
������˵��:�����������, �����ø���������(show),����������
�ʺ�̸̸.
MSG4
           );
           items[i]->set("quest_item/doctor_headband",1);
           who->set_explore("deathland#26");
           return;
           }
     tell_object(who,"�Ե�, �Ҿ���ֻ���������ѧ�ҿ��԰������ǵĻʺ�.\n");
     return;      
}
